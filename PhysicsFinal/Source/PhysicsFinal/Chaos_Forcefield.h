// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chaos_Forcefield.generated.h"

UCLASS()
class PHYSICSFINAL_API AChaos_Forcefield : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChaos_Forcefield();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* boxCollider;

	UPROPERTY(EditAnywhere)
	FVector force = FVector(300, 0, 0);

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp,
		int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ApplyImpulse(UPrimitiveComponent* otherComp);
	void ApplyForce(UPrimitiveComponent* otherComp);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TArray<UPrimitiveComponent*> overlappedComponents;
};
