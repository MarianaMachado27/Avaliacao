// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Actor_1.h"
#include "ProjectileActor_1.h"



// Sets default values
AActor_1::AActor_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetCollisionProfileName("NoCollision");
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

	CountdownTime = 200.0f;
}

// Called when the game starts or when spawned
void AActor_1::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this,
		&AActor_1::TimerManager, 1.0f, true);
}

// Called every frame
void AActor_1::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AActor_1::TimerManager();
	if (CountdownTime <= 0) {
		CountdownTime = 200.0f;
	}
}

void AActor_1::DropProjectile() {
	FActorSpawnParameters SpawnParameters;
	UWorld* World = GetWorld();
	if (World != nullptr) {
		FRotator Rotation = MeshComp->GetComponentRotation();
		AProjectileActor_1* ProjectileActor_1 = World->SpawnActor<AProjectileActor_1>
			(GetActorLocation(), Rotation,
				SpawnParameters);
	}
}

void AActor_1::TimerManager() {
	CountdownTime -= 1.0f;
	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("FUNCIONOU"));
		AActor_1::DropProjectile();
	}
}

