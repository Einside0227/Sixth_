// Fill out your copyright notice in the Description page of Project Settings.


#include "RActor.h"

// Sets default values
ARActor::ARActor()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void ARActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MoveDirection = GetActorRightVector();
}

void ARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    if (!FMath::IsNearlyZero(RotationSpeed)) {
        AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
    }

	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + (MoveDirection * MoveSpeed * DeltaTime);

	SetActorLocation(NewLocation);

	float Dist = FVector::Dist(StartLocation, GetActorLocation());

	if (Dist > MaxRange) {
		MoveDirection *= -1.0f;

		FVector ClampedLocation = StartLocation + (GetActorLocation() - StartLocation).GetSafeNormal() * MaxRange;
		SetActorLocation(ClampedLocation);
	}
}
