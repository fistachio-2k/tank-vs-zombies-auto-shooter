// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Kismet/GameplayStatics.h"
#include "TankVsZombies/EndlessGameMode.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	GameMode = Cast<AEndlessGameMode>(UGameplayStatics::GetGameMode(this));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	UE_LOG(LogTemp, Warning, TEXT("%s health = %f"), *GetOwner()->GetName(), Health);
}


void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	if (Damage < 0.f || Health <= 0.f)
	{
		return;
	}

	Health -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("%s health = %f"), *GetOwner()->GetName(), Health);

	if (Health <= 0.f)
	{
		if (GameMode)
		{
			GameMode->ActorDied(DamagedActor);
		}
	}
}

