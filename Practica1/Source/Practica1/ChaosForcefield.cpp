// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaosForcefield.h"
#include "Components/BoxComponent.h"

// Sets default values
AChaosForcefield::AChaosForcefield()
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
void AChaosForcefield::BeginPlay()
{
	Super::BeginPlay();
	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &AChaosForcefield::OnBoxBeginOverlap);
	boxCollider->OnComponentEndOverlap.AddDynamic(this, &AChaosForcefield::OnBoxEndOverlap);
}

// Called every frame
void AChaosForcefield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (UPrimitiveComponent* comp : overlappedComponents)
	{
		ApplyForce(comp);
	}
}

void AChaosForcefield::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	overlappedComponents.Add(OtherComp);
	//ApplyImpulse(OtherComp);
}

void AChaosForcefield::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	overlappedComponents.Remove(OtherComp);
}

void AChaosForcefield::ApplyImpulse(UPrimitiveComponent* comp)
{
	comp->AddImpulse(force);
}

void AChaosForcefield::ApplyForce(UPrimitiveComponent* comp)
{
	comp->AddForce(force);
}

