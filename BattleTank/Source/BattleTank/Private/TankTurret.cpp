// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RotateSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank Turret"));
	RotateSpeed = FMath::Clamp<float>(RotateSpeed, -1, 1);
	auto ElevationChange = RotateSpeed ;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
	UE_LOG(LogTemp, Warning, TEXT("VECTOR %s"), *FRotator(0, RotateSpeed, 0).ToString());
	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}
