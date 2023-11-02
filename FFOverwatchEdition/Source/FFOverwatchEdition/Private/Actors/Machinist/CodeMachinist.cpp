// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Machinist/CodeMachinist.h"

void ACodeMachinist::Attacks()
{
	//UE_LOG(LogTemp, Warning, TEXT("Machinist Attacks"));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Machinist Attacks"));

	if (Weapon->CanShoot())
	{
		FVector Forward = CameraComp->GetForwardVector();
		FVector WorldLocation = CameraComp->GetComponentLocation();

		FVector EndPoint = (Forward * HitscanRange) + WorldLocation;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(GetOwner());

		FHitResult HitResult;

		UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), WorldLocation, EndPoint, ObjectTypes, true,
			ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Red, FLinearColor::Red);

		Weapon->Attack();
	}

	//Weapon->Attack();
}
