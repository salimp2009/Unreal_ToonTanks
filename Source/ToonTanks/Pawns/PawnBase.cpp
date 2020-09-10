// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "PawnBase.h"
#include "ToonTanks/Actors/ProjectileBase.h"


// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint= CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}


void APawnBase::RotateTurret(FVector LookAtTarget)
{
	// Update TurretMesh Rotation to face towards LookAt Target passed from Child Classes
	// TurretMesh->SetWorldRotation();
	// We only want to rotate the turret x & y , the Z location should change therefore it should stay same the mesh
	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned-StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);

}

void APawnBase::Fire()
{
	// Get ProjectileSpawnPoint Location - >Spawn Projectile class at location firing towards rotation
	//UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked: FIRE..."));
	if (ProjectileClass)
	{
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}


}

void APawnBase::HandleDestruction()
{
	// Play Death effects particle, sound and camera shake

	// child classes override
	// PawnTurret; Inform the GameMode Turret died ->Then Destroy() self

	//PawnTank; Inform GameMode Player died ->Then Hide() all components && stop movement; Game Over :)
}

void APawnBase::PawnDestroyed()
{
	HandleDestruction();
}






