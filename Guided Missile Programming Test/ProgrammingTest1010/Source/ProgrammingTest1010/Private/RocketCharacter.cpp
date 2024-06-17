// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketCharacter.h"
#include "RocketProjectile.h"

// Sets default values
ARocketCharacter::ARocketCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->findingTargets = false;
	this->targets = {};

}

// Called when the game starts or when spawned
void ARocketCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARocketCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ARocketCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARocketCharacter::AddTarget(AActor* _target)
{
	if (this->targets.FindByKey(_target))
	{
		return;
	}
	this->targets.Add(_target);
	
}

void ARocketCharacter::ClearTargets()
{
	this->targets.Empty();
}


