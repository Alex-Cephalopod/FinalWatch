// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Actors/BaseChar.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class ABaseChar;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponAttack);

UCLASS()
class FFOVERWATCHEDITION_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		USkeletalMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		FOnWeaponAttack WeaponShoot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ABaseChar* OwningChar;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
		float HitscanRange;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Functions")
		virtual void Attack();

};
