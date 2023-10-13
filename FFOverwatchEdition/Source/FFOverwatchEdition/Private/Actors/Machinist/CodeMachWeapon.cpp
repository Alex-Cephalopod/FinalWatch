// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Machinist/CodeMachWeapon.h"

void ACodeMachWeapon::Attack()
{
	//UE_LOG(LogTemp, Warning, TEXT("Machinist Weapon Attack"));

	//FVector Forwards = OwningChar->CameraComp->GetForwardVector();
	//FVector WorldLocation = OwningChar->CameraComp->GetComponentLocation();

	//FVector End = (Forwards * HitscanRange) + WorldLocation;

	////line trace by channel
	//FCollisionQueryParams QueryParams;
	//QueryParams.AddIgnoredActor(this);
	////QueryParams.AddIgnoredActor(OwningChar);
	//QueryParams.bTraceComplex = true;
	//QueryParams.bReturnPhysicalMaterial = true;
	//	
	//FHitResult Hit;

	//bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, WorldLocation,
	//	End, ECollisionChannel::ECC_Visibility, QueryParams);

	////line trace by channel with line visibility for duration
	//DrawDebugLine(GetWorld(), WorldLocation, End, FColor::Red, false, 1.f, 0, 1.f);


	//we will not to the actors to ignore unless I create a new class for third person characters

	WeaponShoot.Broadcast();
}
