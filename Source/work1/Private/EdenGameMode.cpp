#include "EdenGameMode.h"
#include "Enemy.h"

void AEdenGameMode::BeginPlay()
{
	Super::BeginPlay();
	//NumDeadEnemy[EEnemyType::HumanEnemy] = 0;
	//NumDeadEnemy[EEnemyType::ZombieEnemy] = 0;
}

void AEdenGameMode::AddEnemy(AEnemy* NewEnemy)
{
	EnemyArray.Add(NewEnemy);
}

void AEdenGameMode::RemoveEnemy(AEnemy* OldEnemy)
{
	EnemyArray.Remove(OldEnemy);
}

void AEdenGameMode::AggroUp(float Aggro)
{
	for (AEnemy* enemy : EnemyArray)
	{
		if (enemy->IsInSoundCircle() == true && enemy->IsInView() == false)
		{
			enemy->AggressionUp(Aggro);
		}
	}
}

TArray<AEnemy*>& AEdenGameMode::GetEnemyList()
{
	return EnemyArray;
}

int AEdenGameMode::GetNumDeadHumanEnemy()
{
	int Num = NumDeadEnemy[EEnemyType::HumanEnemy];
	return Num;
}

int AEdenGameMode::GetNumDeadZombieEnemy()
{
	int Num = NumDeadEnemy[EEnemyType::ZombieEnemy];
	return Num;
}