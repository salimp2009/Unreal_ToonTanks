// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GamePlayStatics.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
	// Alternative way;
	//GetWorldTimerManager();
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	// To avoid expensive GamePlayStatics check, get the PlayerPawn casted to APawnTank
	// because this is a single Player game with the APawnTank being the Player
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer()>FireRange)
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	// if Player == null || isDead then NO FIRE
	if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
	{
		return;
	}

	// if Player is range then Fire()
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
	
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), this->GetActorLocation());
}
