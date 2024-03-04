// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particle.h"
#include "ParticleSpawner.generated.h"

UCLASS()
class PHYSICSFINAL_API AParticleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticleSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* spawnVolume;

	UPROPERTY(EditAnywhere)
	class TSubclassOf<AParticle> particleToSpawn;

	// Emission rate per second
	UPROPERTY(EditAnywhere)
	float emissionRate = 1.0f;

	UPROPERTY(EditAnywhere)
	FVector velocity = FVector(1, 1, 1);

	UPROPERTY(EditAnywhere)
	FVector acceleration = FVector(1, 1, 1);

	UPROPERTY(EditAnywhere)
	float lifetime = 5.0f;

	UPROPERTY(EditAnywhere)
	FColor color;

	UPROPERTY(EditAnywhere)
	float size = 5.0f;

	UPROPERTY(EditAnywhere)
	float mass = 200.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnParticle();


private:
	FVector GetPositionInBounds(FVector initialPosition, UBoxComponent* box);
	float timer;
	TArray<AParticle*> particles;
};
