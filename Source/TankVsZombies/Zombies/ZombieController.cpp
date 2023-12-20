// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieController.h"


// Sets default values
AZombieController::AZombieController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AZombieController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombieController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

