// Fill out your copyright notice in the Description page of Project Settings.
#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
		GlobalStartingLocation = GetActorLocation();
		GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	}
}

void AMovingPlatform::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority() && ActiveTriggers > 0)
	{
		FVector Location = GetActorLocation();
		const float JourneyTraveled = (Location - GlobalStartingLocation).Size();

		if (JourneyTraveled >= JourneyLength)
		{
			const FVector Swap = GlobalStartingLocation;
			GlobalStartingLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
			JourneyLength = (GlobalTargetLocation - GlobalStartingLocation).Size();
			Direction = (GlobalTargetLocation - GlobalStartingLocation).GetSafeNormal();
		}

		Location += SpeedCentimetersPerSecond * DeltaSeconds * Direction;
		SetActorLocation(Location);
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	if (HasAuthority())
	{
		ActiveTriggers++;
	}
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (HasAuthority() && ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
