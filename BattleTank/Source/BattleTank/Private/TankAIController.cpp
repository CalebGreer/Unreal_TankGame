// Copyright CalebGreer

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (ensure(PlayerTank && ControlledTank)) { return; }

	// TODO Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// TODO Fix Firing
	// ControlledTank->Fire();	// TODO limit firing rate

}
