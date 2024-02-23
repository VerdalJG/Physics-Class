// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Particle.h"
#include "Math/UnrealMathUtility.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ParticleSpawner.generated.h"

UCLASS()
class PRACTICA1_API AParticleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticleSpawner();
	void SpawnParticle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* spawnVolume;

	UPROPERTY(EditAnywhere)
	class TSubclassOf<AParticle> particleToSpawn;

	// Emission rate per second
	UPROPERTY(EditAnywhere)
	float emissionRate = 1.0f;

	UPROPERTY(EditAnywhere)
		FVector velocity;

	UPROPERTY(EditAnywhere)
		FVector acceleration;

	UPROPERTY(EditAnywhere)
		float lifetime;

	UPROPERTY(EditAnywhere)
		FColor color;

	UPROPERTY(EditAnywhere)
		float size;

	UPROPERTY(EditAnywhere)
		float mass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	FVector GetPositionInBounds(FVector initialPosition, UBoxComponent* box);

	float timer;
	TArray<AParticle*> particles;
};
