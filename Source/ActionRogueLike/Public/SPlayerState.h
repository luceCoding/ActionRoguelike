// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSaveGame.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

class ASPlayerState;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCreditsChanged, ASPlayerState*, PlayerState, int32, NewCredits, int32, Delta);

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASPlayerState : public APlayerState
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditDefaultsOnly, Category = "Credits")
		int32 Credits;

public:

	UFUNCTION(BlueprintCallable, Category = "Credits")
		int32 GetCredits() const;

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FOnCreditsChanged OnCreditsChanged;

	UFUNCTION(BlueprintNativeEvent)
		void SavePlayerState(USSaveGame* SaveObject);

	UFUNCTION(BlueprintNativeEvent)
		void LoadPlayerState(USSaveGame* SaveObject);
};
