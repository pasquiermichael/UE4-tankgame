// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "TankBarrel.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetName(), *HitLocation.ToString());
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::setBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->setBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::setTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->setTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing"));
	if (!Barrel) {
		return;
	}

	FVector Location = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator Rotation = FRotator(0, 0, 0);
	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);
}

