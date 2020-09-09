// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	// TODO: Get references and game win/lose conditions

	// TODO: Call HandleGameStart(); initialize start countdown, turret activation, pawn check..
}


void ATankGameModeBase::HandleGameStart()
{
	// Initialize start countdown, turret activation, pawn check..
	// Call Blueprint version GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	// if all Turrets dies show win result

	// if Player destroyed show lose result

	// Call Blueprint version GameOver(bool)
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	// Check if which Actor died; if Turret, tally, if Player->go to lose condition
	UE_LOG(LogTemp, Warning, TEXT("A Pawn Died!"));
}


