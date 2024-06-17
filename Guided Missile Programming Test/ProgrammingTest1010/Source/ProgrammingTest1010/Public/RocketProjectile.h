// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RocketProjectile.generated.h"

UCLASS()
class PROGRAMMINGTEST1010_API ARocketProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocketProjectile();

	void Init(AActor* _target);

	UFUNCTION(BlueprintCallable)
	void SetTarget(AActor* _target);

	void HomeToTarget(float DeltaTime);

	AActor* target;

	UPROPERTY(BlueprintReadOnly)
	FVector velocity;

	UPROPERTY(EditAnywhere)
	float speed;

	UPROPERTY(EditAnywhere)
	float turnSpeed;

	UPROPERTY(EditAnywhere)
	float timeUntilHoming;

	float homingTimer = 0.0f;
	bool startHoming = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
