// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

/**
 * 
 */
UCLASS()
class TANKVSZOMBIES_API ATankController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void SetupInputComponent() override;
	
public:
	UPROPERTY(EditAnywhere, Category="Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveForwardAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* TurnRightAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* RotateTurretAction;
};
