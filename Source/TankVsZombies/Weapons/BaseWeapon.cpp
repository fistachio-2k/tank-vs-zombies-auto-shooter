// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseWeapon::Fire()
{
	if (Ammo > 0)
	{
		Ammo--;
	}
}

void ABaseWeapon::Reload(const int AmmoToAdd)
{
	if (AmmoToAdd > 0)
	{
		Ammo += AmmoToAdd;
	}
}

