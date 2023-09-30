// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


class AEndlessGameMode;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TANKVSZOMBIES_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser);

private:
	UPROPERTY()
	AEndlessGameMode* GameMode;
	
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	float Health;

};
