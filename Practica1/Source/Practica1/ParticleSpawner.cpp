// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleSpawner.h"

// Sets default values
AParticleSpawner::AParticleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AParticleSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AParticleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpawnParticle();
}

void AParticleSpawner::SpawnParticle()
{
	FTransform position = GetTransform();
	AParticle* particle = GetWorld()->SpawnActor<AParticle>(position.GetTranslation(), position.GetRotation().Rotator());
}

