// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RtActor.generated.h"

UCLASS()
class SIXTH__API ARtActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARtActor();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Actor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Actor|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
