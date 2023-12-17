// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Machinist/CodeMachWeapon.h"

void ACodeMachWeapon::Attack()
{
	//UE_LOG(LogTemp, Warning, TEXT("Machinist Weapon Attack"));

	if (CanShoot())
	{
		
		bAnimating = true;
		WeaponShoot.Broadcast();
	}
}
