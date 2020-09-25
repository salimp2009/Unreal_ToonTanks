// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;
	APlayerControllerBase* PlayerControllerRef;

	int32 GetTargetTurretCount();
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

public:
	void ActorDied(AActor* DeadActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Loop")
	int32 StartDelay=3;

	//TODO: TESTING FOR CHALLENGE PURPOSES ; added a Blueprint of each Turrets value; create a widget to display
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Score") 
	int32 ScorePlayer = 0;

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

};
