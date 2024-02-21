// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particle.generated.h"

UCLASS()
class PRACTICA1_API AParticle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticle();
	void InitializeValues(FVector position, FVector velocity, FVector acceleration, float lifetime, float size, float mass);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* staticMeshComponent;

	/*USTRUCT()
		struct ParticleValues
	{
		GENERATED_BODY();

		FVector position;
		FVector velocity;
		FVector acceleration;
		float lifetime;
		float size;
		float mass;
	};*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector _position;
	FVector _velocity;
	FVector _acceleration;
	float _lifetime;
	float _size;
	float _mass;

	void Update(float DeltaTime);

};
