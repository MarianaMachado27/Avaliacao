// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Actor_4.h"


// Sets default values
AActor_4::AActor_4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AActor_4::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActor_4::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	FVector LocalizacaoAtual = GetActorLocation();
	LocalizacaoAtual.X += Direcao;
	DistanciaDePercurso++;
	SetActorLocation(LocalizacaoAtual);
	
	if (DistanciaDePercurso > 400) {
		DistanciaDePercurso=0;
		Direcao=Direcao*-1;
	}
}

