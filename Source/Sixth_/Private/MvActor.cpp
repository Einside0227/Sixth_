// Fill out your copyright notice in the Description page of Project Settings.


#include "MvActor.h"

// Sets default values
AMvActor::AMvActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMvActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	MoveDirection = bUseRightDirection ? GetActorRightVector() : GetActorForwardVector();
	
}

// Called every frame
void AMvActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

