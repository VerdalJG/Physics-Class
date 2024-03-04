// Fill out your copyright notice in the Description page of Project Settings.


#include "ForcefieldComponent.h"
#include "Components/SphereComponent.h"	

// Sets default values for this component's properties
UForcefieldComponent::UForcefieldComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UForcefieldComponent::BeginPlay()
{
	Super::BeginPlay();
	collider = GetOwner()->CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	// Attach Component
	collider->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	if (collider)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FoundComponent"));
		collider->OnComponentBeginOverlap.AddDynamic(this, &UForcefieldComponent::OnBeginOverlap);
	}
	
}


// Called every frame
void UForcefieldComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UForcefieldComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ApplyImpulse(otherComp);
}

void UForcefieldComponent::ApplyImpulse(UPrimitiveComponent* otherComp)
{

	otherComp->AddImpulse(impulse);
}

