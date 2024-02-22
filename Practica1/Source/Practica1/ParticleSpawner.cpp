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
	FVector initialPosition = GetActorLocation();
	
	FVector particlePosition = GetPositionInBounds(initialPosition, spawnVolume);
	FRotator rotation = GetActorRotation();
	AParticle* particle = GetWorld()->SpawnActor<AParticle>(particleToSpawn, particlePosition, rotation);
	if (particle != nullptr)
	{
		particle->InitializeValues(particlePosition, velocity, acceleration, lifetime, size, mass, color);
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

FVector AParticleSpawner::GetPositionInBounds(FVector initialPosition, UBoxComponent* box)
{
	FVector boxExtents = box->GetUnscaledBoxExtent();
	FVector result = FVector(
		FMath::RandRange(initialPosition.X - boxExtents.X, initialPosition.X + boxExtents.X),
		FMath::RandRange(initialPosition.Y - boxExtents.Y, initialPosition.Y + boxExtents.Y),
		FMath::RandRange(initialPosition.Z - boxExtents.Z, initialPosition.Z + boxExtents.Z)
	);
	return result;
}

