// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CollisionQueryParams.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("Aiming component %s aiming at %s from %s"), *GetOwner()->GetName(), *HitLocation.ToString(), *BarrelLocation);
	if (!Barrel) {
		return;
	}

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FCollisionResponseParams f;
	const TArray<AActor*> ActorToIgnoreArray;

	bool HasProjectileVelocity = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace, f, ActorToIgnoreArray, false);
	if (HasProjectileVelocity) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("Tank %s Aiming at %s"), *GetOwner()->GetName(), *AimDirection.ToString());

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("NO SLUTION FOUND"));

	}

}

void UTankAimingComponent::setBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;
	Barrel->Elevate(DeltaRotator.Pitch);
}

