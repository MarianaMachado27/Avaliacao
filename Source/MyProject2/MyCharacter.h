// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT2_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void SetLife(int NewLife);
	int GetLife();
	
	void SetScore(int NewScore);
	int GetScore();
	
	void OnDeath();

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComp;
	UPROPERTY(EditAnywhere)
		int Life = 3;
	UPROPERTY(EditAnywhere)
		int Score;
	
	FVector LocalizacaoInicial;
	
	// metodos responsaveis pela movimentacao
	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();
	
	// metodos responsaveis por fazer o perssonagem atirar
	void DropProjectile();
	void Turn(float Value);
	
};
