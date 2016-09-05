// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Actor_7.h"
#include "MyCharacter.h"


// Sets default values
AActor_7::AActor_7()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AActor_7::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);
	
}

// Called when the game starts or when spawned
void AActor_7::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActor_7::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AActor_7::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) && 
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {
		
		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetScore(MyCharacter->GetScore() + 1);
		Destroy();

	}
}

