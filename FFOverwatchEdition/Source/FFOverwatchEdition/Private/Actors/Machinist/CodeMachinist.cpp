// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Machinist/CodeMachinist.h"

void ACodeMachinist::Attacks()
{
	//UE_LOG(LogTemp, Warning, TEXT("Machinist Attacks"));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Machinist Attacks"));

	if (Weapon->CanShoot())
	{
		/*FVector Forward = CameraComp->GetForwardVector();
		FVector WorldLocation = CameraComp->GetComponentLocation();
		//FVector WorldLocation = Weapon->GetActorLocation();
		//FVector WorldLocation = WeaponComp->GetSocketLocation("Muzzle");

		FVector EndPoint = (Forward * HitscanRange) + WorldLocation;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(GetOwner());

		FHitResult HitResult;

		UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), WorldLocation, EndPoint, ObjectTypes, true,
			ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Red, FLinearColor::Red); */

		FVector CameraLocation = CameraComp->GetComponentLocation();
		FRotator CameraRotation = CameraComp->GetComponentRotation();
		FVector MuzzleLocation = WeaponComp->GetSocketLocation("Muzzle");

		FVector EndPoint = (CameraComp->GetForwardVector() * Weapon->HitscanRange) + MuzzleLocation;

		FHitResult HitResult;

		//UKismetSystemLibrary::LineTraceSingle(GetWorld(), MuzzleLocation, EndPoint,

		Weapon->Attack();
	}

	//Weapon->Attack();
}
