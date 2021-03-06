// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Actor_4.generated.h"

UCLASS()
class MYPROJECT2_API AActor_4 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActor_4();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
private:

	UPROPERTY(EditAnywhere)
	UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category=Tick)
	float RunningTime;
		
	float DistanciaDePercurso;
	float Direcao = 1;
};
