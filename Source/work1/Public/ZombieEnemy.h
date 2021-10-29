// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HumanEnemy.h"
#include "ZombieEnemy.generated.h"

/**
 * 
 */
UCLASS()
class WORK1_API AZombieEnemy : public AHumanEnemy
{
	GENERATED_BODY()
	

public:
	virtual EEnemyState CheckConditionState() override;

	virtual void EnterTrack() override;
	virtual void DoTrack() override;
	virtual void OnDeath() override;
};
