// Copyright Léo


#include "../Private/EsferaDeFogo.h"

#include "Components/SphereComponent.h"
#include "Components/MeshComponent.h"

// Sets default values
AEsferaDeFogo::AEsferaDeFogo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Cria uma instancia de USphereComponent que será apontada por Esfera
	EsferaDeColisao = CreateDefaultSubobject<USphereComponent>(TEXT("Raiz"));
	// Define o tamanho do raio da esfera
	EsferaDeColisao->InitSphereRadius(100.f);
	//Define o nome do perfil de colisão
	EsferaDeColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	//Overlap: Sobrepor

	// Indica que a EsferaDecolisão será o componente Raiz da Hierarquia de componentes
	RootComponent = EsferaDeColisao;

	// Cria uma staticmesh e coloca o endereço de memória deste recurso no ponteiro EsferaVisivel
	EsferaVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Esfera"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>Esfera(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	ConstructorHelpers::FObjectFinder<UMaterialInterface>MaterialEsfera(TEXT("/Script/Engine.MaterialInstanceConstant'/Engine/TemplateResources/MI_Template_BaseGray_Metal.MI_Template_BaseGray_Metal'"));
    if (Esfera.Succeeded() && MaterialEsfera.Succeeded())
    {
	    EsferaVisivel->SetStaticMesh(Esfera.Object);
    	EsferaVisivel->SetMaterial(0, MaterialEsfera.Object);
    	EsferaVisivel->SetRelativeLocation(FVector(0.f,0.f,-60.f));
    }
	// Anexa este componente como sendo filho do componente raiz 
	EsferaVisivel->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEsferaDeFogo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEsferaDeFogo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

