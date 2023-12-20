// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServicePlayerLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTServicePlayerLocation::UBTServicePlayerLocation()
{
	TEXT("Update Player Location");
}

void UBTServicePlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this,0);
	if (PlayerPawn == nullptr)
	{
		return;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),PlayerPawn->GetActorLocation());
}
