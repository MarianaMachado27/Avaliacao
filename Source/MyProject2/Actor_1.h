// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Actor_1.generated.h"

UCLASS()
class MYPROJECT2_API AActor_1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActor_1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:

	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		int DamageAmount = 1;

	//metodo responsavel por atirar 
	void DropProjectile();
	
	FTimerHandle CountdownTimerHandle;
	float CountdownTime;
	void TimerManager();
};
