// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAttributeComponent.h"
#include "GameFramework/Actor.h"
#include "STargetDummy.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASTargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTargetDummy();

	UPROPERTY(VisibleAnywhere)
		USAttributeComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComp;

	UFUNCTION()
		void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);
};
