// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCharacter.h"


// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	// Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponSocket);
	Super::BeginPlay();
}

