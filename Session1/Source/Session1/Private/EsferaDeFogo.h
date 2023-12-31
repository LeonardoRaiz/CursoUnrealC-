// Copyright Léo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EsferaDeFogo.generated.h"

UCLASS()
class AEsferaDeFogo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEsferaDeFogo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Declaroção da variável ponteioro EsferaVisivel capaz de receber um endereço de memória de um recurso do tipo UStaticMeshComponent
	UPROPERTY(EditAnywhere, Category="Componentes")
	UStaticMeshComponent* EsferaVisivel;

	//class indica forward declaration
	UPROPERTY(EditAnywhere, Category="Componentes")
	class USphereComponent* EsferaDeColisao;
};
