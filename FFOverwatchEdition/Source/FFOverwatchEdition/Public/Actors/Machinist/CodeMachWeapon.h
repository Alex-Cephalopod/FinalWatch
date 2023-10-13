// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseWeapon.h"
#include "CodeMachWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FFOVERWATCHEDITION_API ACodeMachWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:

protected:

public:

	void Attack() override;
};
