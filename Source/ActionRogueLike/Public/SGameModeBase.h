// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMonsterData.h"
#include "SSaveGame.h"
#include "Engine/DataTable.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/GameModeBase.h"
#include "SGameModeBase.generated.h"

class UEnvQuery;
class UEnvQueryInstanceBlueprintWrapper;

USTRUCT(BlueprintType)
struct FMonsterInfoRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	FMonsterInfoRow()
	{
		Weight = 1.0f;
		SpawnCost = 5.0f;
		KillReward = 20.0f;
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FPrimaryAssetId MonsterId;
		//USMonsterData* MonsterData;
		//TSubclassOf<AActor> MonsterClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float SpawnCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float KillReward;
};

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

	FString SlotName;

	UPROPERTY()
	USSaveGame* CurrentSaveGame;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		UDataTable* MonsterTable;

	//UPROPERTY(EditDefaultsOnly, Category = "AI")
		//TSubclassOf<AActor> MinionClass;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		UEnvQuery* SpawnBotQuery;

	FTimerHandle TimerHandle_SpawnBots;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SpawnTimerInterval;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		UCurveFloat* DifficultyCurve;

	UFUNCTION()
		void SpawnBotTimerElapsed();

	UFUNCTION()
		void OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);

	UFUNCTION()
		void RespawnPlayerElapsed(AController* Controller);

	void OnMonsterLoaded(FPrimaryAssetId LoadedId, FVector SpawnLocation);

public:

	ASGameModeBase();

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void StartPlay() override;

	void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	UFUNCTION(Exec)
	void KillAll();

	virtual void OnActorKilled(AActor* VictimActor, AActor* Killer);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
		void WriteSaveGame();

	void LoadSaveGame();
};