// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
}

bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}

float USAttributeComponent::GetHealthMax() const
{
	return HealthMax;
}

bool USAttributeComponent::ApplyHealthChange(float Delta)
{
	float oldHealth = Health;
	float NewHealth = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	float ActualDelta = NewHealth - oldHealth;

	Health += Delta;
	UE_LOG(LogTemp, Log, TEXT("OnHealthChanged on AI. Delta: %f, Health: %f, ActualDelta: %f"), Delta, Health, ActualDelta);
	OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);
	return ActualDelta != 0;
}
