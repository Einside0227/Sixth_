// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MvActor.generated.h"

UCLASS()
class SIXTH__API AMvActor : public AActor
{
	GENERATED_BODY()
public:	
	AMvActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Properties")
	float MaxRange;

	FVector StartLocation;
	FVector MoveDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Properties")
	bool bUseRightDirection = false; // false=앞, true=옆

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
