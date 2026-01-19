// Fill out your copyright notice in the Description page of Project Settings.


#include "RSpawn.h"

// Sets default values
ARSpawn::ARSpawn()
{
 
}

void ARSpawn::BeginPlay()
{
    Super::BeginPlay();
    for (int i = 1; i <= count; i++) {
        SpawnMyObject();
    }

}

void ARSpawn::SpawnMyObject()
{
    if (!ActorToSpawn) return;

    const FVector SpawnLocation(
        FMath::FRandRange(2910.f, 4150.f),
        FMath::FRandRange(-1670.f, 1880.f),
        FMath::FRandRange(1330.f, 2255.f)
    );

    ARActor* Spawned = GetWorld()->SpawnActor<ARActor>(
        ActorToSpawn,
        SpawnLocation,
        FRotator::ZeroRotator
    );
}


