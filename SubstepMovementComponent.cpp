#pragma once

// Fill out your copyright notice in the Description page of Project Settings.

#include "SubstepMovementComponent.h"

USubstepMovementComponent::USubstepMovementComponent()
{

}

void USubstepMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdatedMesh = Cast<UMeshComponent>(UpdatedComponent);
	if(UpdatedMesh)
		UpdatedBodyInstance = UpdatedMesh->GetBodyInstance();

	OnCalculateCustomPhysics.BindUObject(this, &USubstepMovementComponent::TickSubstepPhysics);
}

void USubstepMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void USubstepMovementComponent::TickComponent(float deltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Substeps = 0;

	if (UpdatedMesh && UpdatedMesh->IsSimulatingPhysics())
		UpdatedMesh->BodyInstance.AddCustomPhysics(OnCalculateCustomPhysics);

	if (!UpdatedMesh)
	{
		if (!UpdatedComponent)
			return;
		UpdatedMesh = Cast<UMeshComponent>(UpdatedComponent);
		if (UpdatedMesh)
			UpdatedBodyInstance = UpdatedMesh->GetBodyInstance();
	}
}

void USubstepMovementComponent::TickSubstepPhysics(float deltaTime, FBodyInstance* BodyInstance)
{
	Substeps++;
	OnSubstep.Broadcast(deltaTime, *BodyInstance);
}
