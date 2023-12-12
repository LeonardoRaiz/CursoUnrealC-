// Copyright Léo


#include "../Private/MinhaPrimeiraClasse_ACTOR.h"

// Sets default values
AMinhaPrimeiraClasse_ACTOR::AMinhaPrimeiraClasse_ACTOR()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinhaPrimeiraClasse_ACTOR::BeginPlay()
{
	Super::BeginPlay();
	GLog->Log("Primeira Classe Unreal C++");
}

// Called every frame
void AMinhaPrimeiraClasse_ACTOR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//mantem o valor a cada interação
	static int32 x = 0;
	//GLog->Log("X = " + FString::FromInt(x));
	//Log Warning da propria Unreal
	UE_LOG(LogTemp, Warning, TEXT("X = %d DeltaTime = %f"), x, DeltaTime);
	x++;
}

