// Fill out your copyright notice in the Description page of Project Settings.


#include "Forcefield.h"
#include "Components/BoxComponent.h"
#include "Particle.h"

// Sets default values
AForcefield::AForcefield()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating our Default Components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	// Attach Component
	boxCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AForcefield::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AForcefield::ActorOverlap);
	OnActorEndOverlap.AddDynamic(this, &AForcefield::ActorEndOverlap);
}

// Called every frame
void AForcefield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (UPrimitiveComponent* comp : overlappedComponents)
	{
		//ApplyForce(comp);
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("BeginOverlap"));
	}
}

void AForcefield::ActorOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	/*if (OtherActor->IsA(AParticle::StaticClass))
	{

	}*/

	Cast<AParticle>(OtherActor)->ApplyForce(force);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("BeginOverlap"));
	}
}

void AForcefield::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	/*if (OtherActor->IsA(AParticle::StaticClass))
	{
		Cast<AParticle>(OtherActor)->StopApplyForce();
	}*/

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("EndOverlap"));
	}
}

