// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	ATank* CurrentTank = nullptr;
	CurrentTank = GetControlledTank();
	if (CurrentTank == nullptr) {
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play %s"), *CurrentTank->GetName());


}

void ATankPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {
		return;
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}