// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "RActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RSpawn.generated.h"

UCLASS()
class SIXTH__API ARSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARSpawn();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ARActor> ActorToSpawn;

	int count = FMath::RandRange(1, 5);

	virtual void BeginPlay() override;

	void SpawnMyObject();
};
