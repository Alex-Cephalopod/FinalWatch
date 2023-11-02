// Fill out your copyright notice in the Description page of Project Settings.


#include "Art/Animation/AnimNotify_CanShoot.h"

void UAnimNotify_CanShoot::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UBaseAnimInstance* AnimInstance = Cast<UBaseAnimInstance>(MeshComp->GetAnimInstance());

	if (AnimInstance)
	{
		AnimInstance->OnShootingEnd.Broadcast();
	}
}
