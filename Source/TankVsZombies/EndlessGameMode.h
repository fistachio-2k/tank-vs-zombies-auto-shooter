// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TANKVSZOMBIES_API AEndlessGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* Actor);
};
