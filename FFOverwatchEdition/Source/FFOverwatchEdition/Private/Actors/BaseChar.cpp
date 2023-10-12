// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseChar.h"

// Sets default values
ABaseChar::ABaseChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));

	SpringArmComp->SetupAttachment(GetMesh(), "head");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ABaseChar::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

		if (LocalPlayerSubsystem)
		{
			LocalPlayerSubsystem->AddMappingContext(PlayerMovementContext, 0);

			/*UInputMappingContext* InputMappingContext = LocalPlayerSubsystem->GetInputMappingContext();
			MovementAction = InputMappingContext->GetInputActionByName("MovementAction");*/
			//UInputAction* AimAction = LocalPlayerSubsystem->GetInputActionByName("Aim");
			//MovementAction = LocalPlayerSubsystem->GetInp;
		}
	}

}

// Called every frame
void ABaseChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ABaseChar::MovementFunction);
		EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ABaseChar::CameraFunction);
	}
}

void ABaseChar::MovementFunction(const FInputActionValue& Value)
{
	const FVector2D MovementDirection = Value.Get<FVector2D>();

	//get controller rotation
	//const FRotator ControllerRotation = GetControlRotation();

	//FRotator NewRotation = FRotator(0.f, ControllerRotation.Yaw, 0.f);

	////get forward vector
	//const FVector ForwardVector = FRotationMatrix(NewRotation).GetUnitAxis(EAxis::X);
	//const FVector RightVector = FRotationMatrix(NewRotation).GetUnitAxis(EAxis::Y);

	//AddMovementInput(ForwardVector, MovementDirection.Y);
	//AddMovementInput(RightVector, MovementDirection.X);

	AddMovementInput(GetActorForwardVector(), MovementDirection.Y);
	AddMovementInput(GetActorRightVector(), MovementDirection.X);
}

void ABaseChar::CameraFunction(const FInputActionValue& Value)
{
	const FVector2D CameraDirection = Value.Get<FVector2D>();

	AddControllerYawInput(CameraDirection.X);
	AddControllerPitchInput(-CameraDirection.Y);
}

