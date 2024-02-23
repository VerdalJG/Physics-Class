// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Forcefield.generated.h"

UCLASS()
class PRACTICA1_API AForcefield : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AForcefield();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* boxCollider;

	UPROPERTY(EditAnywhere)
	FVector force = FVector(300,0,0);

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ApplyImpulse(UPrimitiveComponent* otherComp);
	void ApplyForce(UPrimitiveComponent* otherComp);

private:
	TArray<UPrimitiveComponent*> overlappedComponents;

};
