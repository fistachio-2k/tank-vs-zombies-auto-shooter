// Fill out your copyright notice in the Description page of Project Settings.


#include "TraceHitNotify.h"

#include "TankVsZombies/Weapons/MeleeWeapon.h"
#include "TankVsZombies/Zombies/ZombieCharacter.h"

void UTraceHitNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (const AZombieCharacter* Zombie = Cast<AZombieCharacter>(MeshComp->GetOwner()))
	{
		Zombie->MeleeWeapon->ToggleTrace(true);
	}
}

void UTraceHitNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (const AZombieCharacter* Zombie = Cast<AZombieCharacter>(MeshComp->GetOwner()))
	{
		Zombie->MeleeWeapon->ToggleTrace(false);
	}
}
