// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SActionEffect.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USActionEffect : public USAction
{
	GENERATED_BODY()

public:
	void StartAction_Implementation(AActor* Instigator) override;

	void StopAction_Implementation(AActor* Instigator) override;

protected:

	FTimerHandle DurationHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effect")
		float Duration;

	FTimerHandle PeriodHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effect")
		float Period;

	UFUNCTION(BlueprintNativeEvent, Category = "Effect")
		void ExecutePeriodicEffect(AActor* Instigator);

public:
	USActionEffect();
};
