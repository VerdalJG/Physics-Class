// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleSpawner.h"

// Sets default values
AParticleSpawner::AParticleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sceneComp = CreateDefaultSubobject<USceneComponent>("Root Scene Component");
}

// Called when the game starts or when spawned
void AParticleSpawner::BeginPlay()
{
	Super::BeginPlay();
	timer = 0;
}

// Called every frame
void AParticleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer += DeltaTime;

	if (timer >= 1)
	{
		
		SpawnParticle();
		timer = 0;
	}
	
		
}

void AParticleSpawner::SpawnParticle()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	}
	FTransform position = GetTransform();
	AParticle* particle = GetWorld()->SpawnActor<AParticle>(AParticle::StaticClass(), position.GetTranslation(), position.GetRotation().Rotator());
}

