// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

/**
 * 
 */
UCLASS()
class TANKVSZOMBIES_API ATankController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Inputs")
	UInputAction* MoveForwardAction;
	
	UPROPERTY(EditAnywhere, Category="Inputs")
	UInputAction* MoveRightAction;
};
