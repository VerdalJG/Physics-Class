// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaosSphere.h"

// Sets default values
AChaosSphere::AChaosSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creating our Default Components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
}

// Called when the game starts or when spawned
void AChaosSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChaosSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

