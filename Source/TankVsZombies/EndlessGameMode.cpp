// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessGameMode.h"

#include "Tank/TankPawn.h"

void AEndlessGameMode::ActorDied(AActor* Actor)
{
	if (Actor->GetClass() == ATankPawn::StaticClass())
	{
		// player lose
	}
	else
	{
		// player gain score
	}
}
