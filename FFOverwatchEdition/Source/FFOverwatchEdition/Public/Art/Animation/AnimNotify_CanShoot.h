// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Art/BaseAnimInstance.h"
#include "AnimNotify_CanShoot.generated.h"

/**
 * 
 */
UCLASS()
class FFOVERWATCHEDITION_API UAnimNotify_CanShoot : public UAnimNotify
{
	GENERATED_BODY()

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
};
