// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeWeapon.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AMeleeWeapon::AMeleeWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(false);
}

// Called every frame
void AMeleeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TraceHit();
}

void AMeleeWeapon::TraceHit()
{
	const FVector Start = Mesh->GetSocketLocation(SocketName);
	const FVector End = Start; // Same as start for a single point trace

	TArray<FHitResult> OutHits;
	UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(),
		Start,
		End,
		TraceRadius,
		CollisionObjectType,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		OutHits,
		true);
	
	if(!OutHits.IsEmpty())
	{
		for (const FHitResult& HitResult : OutHits)
		{
			AActor* HitActor = HitResult.GetActor();
			if (!AlreadyHitActors.Contains(HitActor))
			{
				AlreadyHitActors.Emplace(HitActor);
				if (HitResult.GetActor())
				{
					UGameplayStatics::ApplyPointDamage(
						HitResult.GetActor(),
						Damage,
						HitResult.ImpactNormal,
						HitResult,
						GetInstigatorController(),
						this,
						UDamageType::StaticClass());
				}
			}
		}
	}
}

void AMeleeWeapon::ToggleTrace(const bool isEnabled)
{
	if (isEnabled)
	{
		AlreadyHitActors.Empty();
	}
	SetActorTickEnabled(isEnabled);
}

