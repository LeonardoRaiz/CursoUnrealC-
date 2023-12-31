// Copyright Léo


#include "../Private/AtorFlutuante.h"

// Sets default values
AAtorFlutuante::AAtorFlutuante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TempoExecucao = 0.0f;
	AlturaDelta = 0.0f;
	NovaLocalizacao = FVector(0.f,0.f,0.f);
}

// Called when the game starts or when spawned
void AAtorFlutuante::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAtorFlutuante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//recebe o valor inicial x,y,z
	NovaLocalizacao = this->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Nova localização: %s\n"), *NovaLocalizacao.ToString());
	//calcula a altura em SENO onde vaira de + para - 
	AlturaDelta = (FMath::Sin(TempoExecucao + DeltaTime) - FMath::Sin(TempoExecucao));
	UE_LOG(LogTemp, Warning, TEXT("Altura Delta: %f\n"), AlturaDelta);
	//Acrescenta o valor novo em Z
	NovaLocalizacao.Z += AlturaDelta * 20.f;
	UE_LOG(LogTemp, Warning, TEXT("Nova localização: %s\n"), *NovaLocalizacao.ToString());
	//Soma o tempo de execução 
	TempoExecucao += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("Tempo Execução: %f\n"), TempoExecucao);
	this->SetActorLocation(NovaLocalizacao);
	
}

