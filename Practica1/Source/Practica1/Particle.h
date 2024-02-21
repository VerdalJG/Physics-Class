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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* sceneComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector position;
	FVector velocity;
	FVector acceleration;
	float lifeTime;
	float size;
	float mass;

	void Update(float DeltaTime);

};
