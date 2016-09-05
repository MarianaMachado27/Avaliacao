// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Actor_3.h"


// Sets default values
AActor_3::AActor_3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);
	
}

// Called when the game starts or when spawned
void AActor_3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActor_3::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	FVector LocalizacaoAtual = GetActorLocation();
	LocalizacaoAtual.Z += Direcao;
	DistanciaDePercurso++;
	SetActorLocation(LocalizacaoAtual);
	
	if (DistanciaDePercurso > 200) {
		DistanciaDePercurso=0;
		Direcao=Direcao*-1;
	}
	
}

