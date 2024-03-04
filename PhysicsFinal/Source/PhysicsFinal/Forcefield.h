// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Forcefield.generated.h"

UCLASS()
class PHYSICSFINAL_API AForcefield : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForcefield();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* boxCollider;

	UPROPERTY(EditAnywhere)
	FVector force = FVector(300, 0, 0);

	UFUNCTION()
	void ActorOverlap(AActor* OverlappedActor, AActor* OtherActor);
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TArray<UPrimitiveComponent*> overlappedComponents;
};
