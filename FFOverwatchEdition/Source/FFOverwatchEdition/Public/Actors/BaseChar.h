// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h" 
#include "EnhancedInputSubsystems.h" 
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "BaseWeapon.h"
#include "Components/ChildActorComponent.h"
#include "Art/BaseAnimInstance.h"
#include "BaseChar.generated.h"

class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class USpringArmComponent;
class UChildActorComponent;
class ABaseWeapon;
class UBaseAnimInstance;

UCLASS()
class FFOVERWATCHEDITION_API ABaseChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseChar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables|Animation")
		bool bIsAiming = false;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
		UBaseAnimInstance* AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		UChildActorComponent* WeaponComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TSubclassOf<ABaseWeapon> WeaponClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		ABaseWeapon* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputMappingContext* PlayerMovementContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputMappingContext* PlayerActionsContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
		UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
		UInputAction* CameraAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
		UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement")
		UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Actions")
		UInputAction* LeftClickAction;

	bool bIsDummy = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = "Actions|Functions")
		virtual void Attacks();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovementFunction(const FInputActionValue& Value);

	void CameraFunction(const FInputActionValue& Value);

	void AttackFunction(const FInputActionValue& Value);

};
