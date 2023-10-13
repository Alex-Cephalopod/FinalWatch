// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));

}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();

	//OwningChar = Cast<ABaseChar>(GetOwner());
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::Attack()
{

}

