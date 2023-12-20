// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


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
	
	if (AIBehavior != nullptr)
	{
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this,0);
		if (PlayerPawn == nullptr)
		{
			return;
		}
	
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
	}
}

// Called every frame
void AZombieController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

