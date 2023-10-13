// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Machinist/CodeMachinist.h"

void ACodeMachinist::Attacks()
{
	//UE_LOG(LogTemp, Warning, TEXT("Machinist Attacks"));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Machinist Attacks"));
	Weapon->Attack();
}
