// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TActor.generated.h"

UCLASS()
class SIXTH__API ATActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATActor();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Actor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Actor|Properties")
	float RotationSpeed = 90.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Actor|Properties")
	float DisappearDelay = 2.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle DisappearTimerHandle;

	UFUNCTION()
	void Disappear();
};
