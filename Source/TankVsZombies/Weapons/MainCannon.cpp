// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCannon.h"


// Sets default values
AMainCannon::AMainCannon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainCannon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainCannon::Fire()
{
	Super::Fire();
	
}

