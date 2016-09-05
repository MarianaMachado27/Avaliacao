// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Actor_6.h"


// Sets default values
AActor_6::AActor_6()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AActor_6::BeginPlay()
{
	Super::BeginPlay();
	LocalizacaoInicial = GetActorLocation();
}

// Called every frame
void AActor_6::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	FVector LocalizacaoAtual = GetActorLocation();
	
	// os seguintes ifs realizam o percurso do boss:
	
	if (A) {
		LocalizacaoAtual.Y += Direcao;
		DistanciaDePercurso--;
	}
	
	if (B) {
		LocalizacaoAtual.X += Direcao;
		DistanciaDePercurso--;
	}
	
	if (C) {
		LocalizacaoAtual.Y += Direcao;
		DistanciaDePercurso--;
	}
	
	if (D) {
		LocalizacaoAtual.X += Direcao;
		DistanciaDePercurso--;
	}
	
	if (E) {
		LocalizacaoAtual.Y -= Direcao;
		DistanciaDePercurso--;
	}
	
	if (F) {
		LocalizacaoAtual.X -= Direcao;
		DistanciaDePercurso--;
	}
	
	// os seguintes ifs finalizam cada percurso e iniciam o percursoseguinte:
	
	if (A && DistanciaDePercurso<=0) {
		A = false;
		DistanciaDePercurso = 140;
		B = true;
	}
	
	if (B && DistanciaDePercurso<=0) {
		B = false;
		DistanciaDePercurso = 330;
		C = true;
	}
	
	if (C && DistanciaDePercurso<=0) {
		C = false;
		DistanciaDePercurso = 240;
		D = true;
	}
	
	if (D && DistanciaDePercurso<=0) {
		D = false;
		DistanciaDePercurso = 680;
		E = true;
	}
	
	if (E && DistanciaDePercurso<=0) {
		E = false;
		DistanciaDePercurso = 380;
		F = true;
	}
	
	if (F && DistanciaDePercurso<=0) {
		F = false;
		DistanciaDePercurso = 350;
		A = true;
	}
	
	
	// a seguinte linha altera a localização atual realizando o update da posição do boss
	SetActorLocation(LocalizacaoAtual);
	
}

