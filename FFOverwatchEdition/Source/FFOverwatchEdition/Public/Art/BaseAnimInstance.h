// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimGraphRuntime/Public/KismetAnimationLibrary.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
class UAnimSequence;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackAnimEnd);


UCLASS()
class FFOVERWATCHEDITION_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
public:

	UPROPERTY()
		FAttackAnimEnd OnShootingEnd;

	UFUNCTION(BlueprintCallable, Category = "Actions|Functions")
		void PlayAttackAnim();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		float Direction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actions|Variables")
		UAnimSequence* AttackAnim;
};
