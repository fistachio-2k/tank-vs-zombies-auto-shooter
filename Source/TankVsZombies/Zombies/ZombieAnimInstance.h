// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ZombieAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TANKVSZOMBIES_API UZombieAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintGetter, meta = (BlueprintThreadSafe))
	float GetSpeed();
	
	UFUNCTION(BlueprintGetter, meta = (BlueprintThreadSafe))
	float GetAngle();

	UPROPERTY(BlueprintGetter=GetSpeed)
	float Speed;

	UPROPERTY(BlueprintGetter=GetAngle)
	float Angle;
};
