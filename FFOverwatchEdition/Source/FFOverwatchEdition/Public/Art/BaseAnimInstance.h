// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FFOVERWATCHEDITION_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
public:

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		float Direction;

};
