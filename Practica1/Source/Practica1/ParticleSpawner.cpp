// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleSpawner.h"

// Sets default values
AParticleSpawner::AParticleSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	spawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	spawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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

	if (timer >= 1/emissionRate)
	{
		SpawnParticle();
		timer = 0;
	}
}

void AParticleSpawner::SpawnParticle()
{
	FVector pos = GetActorLocation();
	FRotator rotation = GetActorRotation();
	AParticle* particle = GetWorld()->SpawnActor<AParticle>(particleToSpawn, pos, rotation);
	if (particle != nullptr)
	{
		particle->InitializeValues(position, velocity, acceleration, lifetime, size, mass);
		particles.Add(particle);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spawned"));
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Not spawned"));
		}
	}
	
}

