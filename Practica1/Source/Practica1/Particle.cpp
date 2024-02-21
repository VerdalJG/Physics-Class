// Fill out your copyright notice in the Description page of Project Settings.


#include "Particle.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AParticle::AParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Creating our Default Components
	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	//Attaching the Component
	staticMeshComponent->SetupAttachment(RootComponent);
}

void AParticle::InitializeValues(FVector pos, FVector velocity, FVector acceleration, float lifetime, float size, float mass)
{
	_position = FVector(
		FMath::RandRange(pos.X - 200, pos.X + 200),
		FMath::RandRange(pos.Y - 200, pos.Y + 200),
		FMath::RandRange(pos.Z - 200, pos.Z + 200));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Not spawned"));
	}
	SetActorLocation(_position);
}

// Called when the game starts or when spawned
void AParticle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Update(DeltaTime);
}

void AParticle::Update(float DeltaTime)
{
	_position += _velocity * DeltaTime;
	_velocity += _acceleration * DeltaTime;
	//acceleration += 2 * DeltaTime / mass;
	_lifetime -= DeltaTime;
	if (_lifetime <= 0)
	{
		GetWorld()->DestroyActor(this);
	}


}

