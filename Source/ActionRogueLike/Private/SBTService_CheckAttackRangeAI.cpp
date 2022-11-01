// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTService_CheckAttackRangeAI.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void USBTService_CheckAttackRangeAI::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// Check distance between AI pawn and target actor
	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
	if (ensure(BlackBoardComp))
	{
		AActor* TargetActor = Cast<AActor>(BlackBoardComp->GetValueAsObject("TargetActor"));
		//AActor* TargetActor = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		if (TargetActor)
		{
			AAIController* MyController = OwnerComp.GetAIOwner();
			APawn* AIPawn = MyController->GetPawn();
			if (ensure(AIPawn))
			{
				float DistanceTo = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());
				bool bWithinRange = DistanceTo < 2000.f;

				bool bHasLOS = false;
				if (bWithinRange)
				{
					bHasLOS = MyController->LineOfSightTo(TargetActor);
				}

				BlackBoardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, (bWithinRange && bHasLOS));
			}
		}
	}
}
