// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EdenGameMode.generated.h"

class AHumanEnemy;
class AEnemy;

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	HumanEnemy,
	ZombieEnemy,
};

UCLASS()
class WORK1_API AEdenGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	
	void AddEnemy(AEnemy* NewEnemy);
	void RemoveEnemy(AEnemy* OldEnemy);

	UFUNCTION(BlueprintCallable, Category = "EdenGameMode")
	void AggroUp(float Aggro);
	UFUNCTION(BlueprintCallable, Category = "EdenGameMode")
	TArray<AEnemy*>& GetEnemyList();

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TMap<EEnemyType, int> NumDeadEnemy;

	UFUNCTION(BlueprintCallable, Category = "NumDeadEnemy")
	int GetNumDeadHumanEnemy();

	UFUNCTION(BlueprintCallable, Category = "NumDeadEnemy")
	int GetNumDeadZombieEnemy();

private:
	TArray<AEnemy*> EnemyArray;
};
