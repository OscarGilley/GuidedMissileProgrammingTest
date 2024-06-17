// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketProjectile.h"

// Sets default values
ARocketProjectile::ARocketProjectile() 
{
	PrimaryActorTick.bCanEverTick = true;
	this->target = nullptr;
	this->turnSpeed = 2000.0f;
	this->speed = 600.0f;
	this->timeUntilHoming = 0.1f;
}
void ARocketProjectile::Init(AActor* _target)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->target = target;
}

// Called when the game starts or when spawned
void ARocketProjectile::BeginPlay()
{
	Super::BeginPlay();	

	float variationX = FMath::FRandRange(-0.25, 0.25);
	float variationY = FMath::FRandRange(-0.25, 0.25);

	this->velocity += FVector(variationX, variationY, 1) * this->turnSpeed; //fly up at a random angle
	this->velocity = this->velocity.GetSafeNormal() * this->speed;
}

void ARocketProjectile::SetTarget(AActor* _target)
{
	this->target = _target;
}

// Called every frame
void ARocketProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (startHoming && this->target != nullptr) 
	{
		this->HomeToTarget(DeltaTime);
	}

	if (!startHoming) {

		homingTimer += DeltaTime;

		if (homingTimer >= timeUntilHoming)
		{
			startHoming = true;
		}
	}
}

void ARocketProjectile::HomeToTarget(float DeltaTime)
{
	FVector targetDir = (target->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	targetDir += target->GetVelocity() * targetDir.Size() / 200.0f;
	this->velocity += targetDir * this->turnSpeed * DeltaTime;
	this->velocity = this->velocity.GetSafeNormal() * this->speed;
}

