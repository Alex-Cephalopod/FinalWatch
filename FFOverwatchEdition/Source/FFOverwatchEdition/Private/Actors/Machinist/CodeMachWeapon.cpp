// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Machinist/CodeMachWeapon.h"

void ACodeMachWeapon::Attack()
{
	//UE_LOG(LogTemp, Warning, TEXT("Machinist Weapon Attack"));

	/*FVector Forwards = OwningChar->CameraComp->GetForwardVector();
	FVector WorldLocation = OwningChar->CameraComp->GetComponentLocation();

	FVector End = (Forwards * HitscanRange) + WorldLocation;*/

	if (CanShoot())
	{
		/*TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(GetOwner());

		FHitResult HitResult;

		UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), WorldLocation, End, ObjectTypes, false,
			ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true);*/
		bAnimating = true;
		WeaponShoot.Broadcast();
	}
}
