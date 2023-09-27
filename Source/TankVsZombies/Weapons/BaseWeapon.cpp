// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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

void ABaseWeapon::Fire()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(FireTimerHandle))
	{
		return;
	}
	
	if (Ammo > 0)
	{
		Ammo--;
	}

	if (bIsInfAmmo || Ammo > 0)
	{
		switch (FireType) {
		case Single:
			FireInternal();
			break;
		case Burst:
			GetWorld()->GetTimerManager().SetTimer(FireTimerHandle,
				FTimerDelegate::CreateUObject(this, &ABaseWeapon::FireInternal),
				FireRate,
				false);
			break;
		case Auto:
			GetWorld()->GetTimerManager().SetTimer(FireTimerHandle,
				FTimerDelegate::CreateUObject(this, &ABaseWeapon::FireInternal),
				FireRate,
				true);
			break;
		default: ;
		}
	}
}

void ABaseWeapon::FireInternal()
{
	GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, TEXT("Fire!"));
}

void ABaseWeapon::CeaseFire()
{
	GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
}

void ABaseWeapon::Reload(const int AmmoToAdd)
{
	if (AmmoToAdd > 0)
	{
		Ammo += AmmoToAdd;
	}
}

