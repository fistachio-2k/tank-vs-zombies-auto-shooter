// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCharacter.h"

#include "TankVsZombies/Weapons/MeleeWeapon.h"


// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponClass != nullptr)
	{
		if (UWorld* World = GetWorld())
		{
			FActorSpawnParameters SpawnParameters;
			
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = this;

			if (AMeleeWeapon* WeaponActor = World->SpawnActor<AMeleeWeapon>(WeaponClass, GetActorTransform(), SpawnParameters))
			{
				MeleeWeapon = WeaponActor;
				WeaponActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponSocket);
			}
		}
	}
}

