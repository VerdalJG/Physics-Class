// Fill out your copyright notice in the Description page of Project Settings.


#include "Particle.h"


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

void AParticle::InitializeValues(FVector pos, FVector velocity, FVector acceleration, float lifetime, float size, float mass, FColor color)
{
	_position = pos;
	_velocity = velocity * 100;
	_acceleration = acceleration * 100;
	_lifetime = lifetime;
	_size = size;
	_mass = mass;
	
	//staticMeshComponent->SetVectorParameterValueOnMaterials("m_Color", color);
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
	Update(DeltaTime);
}

void AParticle::SetVelocity(FVector value)
{
	_velocity = value;
}

void AParticle::ApplyForce(FVector force)
{
	_currentForce = force;
}

void AParticle::StopApplyForce()
{
	_currentForce = FVector(0,0,0);
}

void AParticle::Update(float DeltaTime)
{
	_lifetime -= DeltaTime;
	if (_lifetime <= 0)
	{
		GetWorld()->DestroyActor(this);
	}

	_acceleration = 2 * _currentForce * DeltaTime;
	_velocity += _acceleration * DeltaTime;
	_position += _velocity * DeltaTime;
	SetActorLocation(_position);
}

