// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);


	// TODO Prevent double speed due to dual control use
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	UE_LOG(LogTemp, Warning, TEXT("Turn right throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}