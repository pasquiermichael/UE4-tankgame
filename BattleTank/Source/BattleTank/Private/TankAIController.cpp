#include "TankAIController.h"
#include "BattleTank.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

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

void ATankAIController::Tick(float Deltatime)
{
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();
	if (!ControlledTank || !PlayerTank) {
		return;
	}
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
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