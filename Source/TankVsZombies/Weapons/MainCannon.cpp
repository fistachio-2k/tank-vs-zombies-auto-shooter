// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCannon.h"

#include "Projectile.h"


// Sets default values
AMainCannon::AMainCannon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMainCannon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCannon::FireInternal()
{
	Super::FireInternal();
	AProjectile* const Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
	Projectile->SetOwner(this);
}

