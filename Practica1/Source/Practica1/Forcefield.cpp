// Fill out your copyright notice in the Description page of Project Settings.


#include "Forcefield.h"

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
	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &AForcefield::OnBoxBeginOverlap);
	boxCollider->OnComponentEndOverlap.AddDynamic(this, &AForcefield::OnBoxEndOverlap);
}

// Called every frame
void AForcefield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (UPrimitiveComponent* comp : overlappedComponents)
	{
		ApplyForce(comp);
	}
	
}

void AForcefield::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	overlappedComponents.Add(OtherComp);
	//ApplyImpulse(OtherComp);
}

void AForcefield::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex)
{
	overlappedComponents.Remove(OtherComp);
}

void AForcefield::ApplyImpulse(UPrimitiveComponent* comp)
{
	comp->AddImpulse(force);
}

void AForcefield::ApplyForce(UPrimitiveComponent* comp)
{
	comp->AddForce(force);
}

