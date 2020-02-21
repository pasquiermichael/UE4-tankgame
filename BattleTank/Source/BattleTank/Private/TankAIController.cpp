// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Begin Play"));
	ATank* CurrentTank = nullptr;
	CurrentTank = GetControlledTank();
	if (CurrentTank == nullptr) {
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AI Begin Play %s"), *CurrentTank->GetName());

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AI Found player tank %s"), *PlayerTank->GetName());


}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}

	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}