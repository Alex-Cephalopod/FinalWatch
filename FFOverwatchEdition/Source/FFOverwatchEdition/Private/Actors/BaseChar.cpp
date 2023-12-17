// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseChar.h"
//include core minimal.h
#include "CoreMinimal.h"

// Sets default values
ABaseChar::ABaseChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	WeaponComp = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponComp"));
	TPS_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TPS_Mesh"));
	FPS_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPS_Mesh"));
	TPS_WeaponChild = CreateDefaultSubobject<UChildActorComponent>(TEXT("TPS_WeaponChild"));

	//SpringArmComp->SetupAttachment(GetMesh(), "head");
	//CameraComp->SetupAttachment(SpringArmComp);

	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp->SetupAttachment(SpringArmComp);
	FPS_Mesh->SetupAttachment(CameraComp);
	//GetMesh()->SetupAttachment(SpringArmComp);

	WeaponComp->SetupAttachment(FPS_Mesh, "GripPoint");

	TPS_Mesh->SetupAttachment(RootComponent);

	TPS_WeaponChild->SetupAttachment(TPS_Mesh, "GunSocket");
}

// Called when the game starts or when spawned
void ABaseChar::BeginPlay()
{
	Super::BeginPlay();

	if (!bIsDummy)
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		if (PlayerController)
		{
			UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

			if (LocalPlayerSubsystem)
			{
				LocalPlayerSubsystem->AddMappingContext(PlayerMovementContext, 0);
				LocalPlayerSubsystem->AddMappingContext(PlayerActionsContext, 1);
			}
		}

		AnimInstance = Cast<UBaseAnimInstance>(FPS_Mesh->GetAnimInstance());
		TPS_AnimInstance = Cast<UBaseAnimInstance>(TPS_Mesh->GetAnimInstance());

		if (IsLocallyControlled())
			WeaponComp->SetChildActorClass(WeaponClass);
	
		if (!IsLocallyControlled())
			TPS_WeaponChild->SetChildActorClass(WeaponClass);

		//TPS_WeaponChild->SetChildActorClass(WeaponClass);
		
		Weapon = Cast<ABaseWeapon>(WeaponComp->GetChildActor());
		if (!Weapon)
		{
			Weapon = Cast<ABaseWeapon>(TPS_WeaponChild->GetChildActor());
		}

		Weapon->WeaponShoot.AddDynamic(AnimInstance, &UBaseAnimInstance::PlayAttackAnim);
		//Weapon->WeaponShoot.AddDynamic(TPS_AnimInstance, &UBaseAnimInstance::PlayAttackAnim);

		AnimInstance->OnShootingEnd.AddDynamic(Weapon, &ABaseWeapon::ShootingEnd);
		//TPS_AnimInstance->OnShootingEnd.AddDynamic(Weapon, &ABaseWeapon::ShootingEnd);
	}
}

void ABaseChar::Attacks()
{
	//Weapon->Attack();
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
		EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Triggered, this, &ABaseChar::AttackFunction);
	}
}

void ABaseChar::MovementFunction(const FInputActionValue& Value)
{
	const FVector2D MovementDirection = Value.Get<FVector2D>();

	//get controller rotation
	const FRotator ControllerRotation = GetControlRotation();

	FRotator NewRotation = FRotator(0.f, ControllerRotation.Yaw, 0.f);

	//get forward vector
	const FVector ForwardVector = FRotationMatrix(NewRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(NewRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardVector, MovementDirection.Y);
	AddMovementInput(RightVector, MovementDirection.X);

	/*AddMovementInput(GetActorForwardVector(), MovementDirection.Y);
	AddMovementInput(GetActorRightVector(), MovementDirection.X);*/
}

void ABaseChar::CameraFunction(const FInputActionValue& Value)
{
	const FVector2D CameraDirection = Value.Get<FVector2D>();

	AddControllerYawInput(CameraDirection.X);
	AddControllerPitchInput(-CameraDirection.Y);
}

void ABaseChar::AttackFunction(const FInputActionValue& Value)
{
	Attacks();
}

void ABaseChar::ServerShoot_Implementation()
{
	//if is server
	
}

//void ABaseChar::ServerSyncRotation(FRotator ControlRot)
//{
//	
//	ControllerSyncedRotation = ControlRot;
//
//	if (!IsLocallyControlled())
//	{
//		CameraComp->SetWorldRotation(ControllerSyncedRotation);
//	}
//	
//}

