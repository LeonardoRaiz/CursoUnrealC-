// Copyright Léo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AtorFlutuante.generated.h"

UCLASS()
class AAtorFlutuante : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAtorFlutuante();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	float TempoExecucao;
	float AlturaDelta;
	FVector NovaLocalizacao;
};
