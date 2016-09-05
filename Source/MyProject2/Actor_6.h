// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Actor_6.generated.h"

UCLASS()
class MYPROJECT2_API AActor_6 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActor_6();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere)
	UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category=Tick)
	
	FVector LocalizacaoInicial;
	float RunningTime;
	
	UPROPERTY(VisibleAnywhere)
	float DistanciaDePercurso = 350;
	
	UPROPERTY(VisibleAnywhere)
	int Vidas = 20;
	

private:
	
	float Direcao = 1;	

	//tragetorias:

	UPROPERTY(VisibleAnywhere)
	bool A = true;
	UPROPERTY(VisibleAnywhere)
	bool B = false;
	UPROPERTY(VisibleAnywhere)
	bool C = false;
	UPROPERTY(VisibleAnywhere)
	bool D = false;
	UPROPERTY(VisibleAnywhere)
	bool E = false;
	UPROPERTY(VisibleAnywhere)
	bool F = false;
	
	
};
