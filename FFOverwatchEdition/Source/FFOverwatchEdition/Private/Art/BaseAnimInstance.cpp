// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/BaseAnimInstance.h" 
#include "AnimGraphRuntime/Public/KismetAnimationLibrary.h"
#include "KismetAnimationLibrary.h"

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		Speed = Pawn->GetVelocity().Size();
		Direction = UKismetAnimationLibrary::CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
	}
}

void UBaseAnimInstance::PlayAttackAnim()
{
	PlaySlotAnimationAsDynamicMontage(AttackAnim, "Shoot");
}
