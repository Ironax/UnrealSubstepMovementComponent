// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "SubstepMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Physics, Movement), meta = (BlueprintSpawnableComponent))
class SCRAPID_API USubstepMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSubstepDelegate, float, deltaTime);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSubstepDelegate, float, deltaTime, const FBodyInstance&, BodyInstance);

public:

	USubstepMovementComponent();

protected:

	virtual void BeginPlay() override; 
	virtual void InitializeComponent() override;
	virtual void TickComponent(float deltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//Substepping
	virtual void TickSubstepPhysics(float deltaTime, FBodyInstance* BodyInstance);
	FCalculateCustomPhysics OnCalculateCustomPhysics;

	UMeshComponent* UpdatedMesh;
	FBodyInstance* UpdatedBodyInstance;

	UPROPERTY(BlueprintReadOnly)
	int Substeps = 0;

public :

	UPROPERTY(BlueprintAssignable)
	FOnSubstepDelegate OnSubstep;
};
