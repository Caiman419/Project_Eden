// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "EdenGameMode.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

EEnemyState AZombieEnemy::CheckConditionState()
{
	if (PlayBeAttackedAnim)
	{
		Aggression = 20;
		return EEnemyState::BeAttacked;
	}

	//Attack
	//��� ���¿��� ���ݰ��ɹ��� �ȿ� �÷��̾ �ִٸ� ����
	else if (bIsInAttack == true)
	{
		Aggression = 40;
		return EEnemyState::Attack;
	}

	//Track
	else if (Aggression >= 20 && Aggression <= 50)
	{
		return EEnemyState::Track;
	}
	else if (bIsInAttack == false && bIsPlayingAttackAnim == false)
	{
		if (CurState == EEnemyState::Attack)
		{
			return EEnemyState::Track;
		}
	}
	//Watch
	else if (Aggression < 20)
	{
		return EEnemyState::Watch;
	}


	return EEnemyState::Watch;
}

void AZombieEnemy::DoTrack()
{
	if (IsInSoundCircle())
	{
		FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		AAIController* AIController = Cast<AAIController>(GetController());

		//�ü������� �÷��̾���ġ
		//�ü� ������ ������
		GetCharacterMovement()->bOrientRotationToMovement = false;

		FRotator EnemyRotator = GetActorRotation();
		FRotator ChangeRotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), PlayerLocation);
		SetActorRotation(FRotator(EnemyRotator.Pitch, ChangeRotator.Yaw, EnemyRotator.Roll));

		if (AIController)
		{
			//�÷��̾� �Ѿư�
			Cast<AAIController>(GetController())->MoveToLocation(PlayerLocation);
		}
	}
	else
	{
		AggressionDown();
	}
}

void AZombieEnemy::EnterTrack()
{

}

void AZombieEnemy::OnDeath()
{
	if (!GetKilled())
	{
		Super::OnDeath();
		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
		GetMesh()->SetSimulatePhysics(true);

		auto gameMode = Cast<AEdenGameMode>(GetWorld()->GetAuthGameMode());
		gameMode->NumDeadEnemy[EEnemyType::ZombieEnemy] += 1;
	}
}