// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RActor.generated.h"

UCLASS()
class SIXTH__API ARActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARActor();

	float MoveSpeed = FMath::RandRange(200, 300);
	float MaxRange = FMath::RandRange(50, 300);
	float RotationSpeed = FMath::RandRange(50, 100);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Actor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation;
	FVector MoveDirection;
	int32 DirSign = 1;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
