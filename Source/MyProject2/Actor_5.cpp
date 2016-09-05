// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "Actor_5.h"
#include "MyCharacter.h"


// Sets default values
AActor_5::AActor_5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AActor_5::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AActor_5::BeginPlay()
{
	Super::BeginPlay();
	
	LocalizacaoInicial = GetActorLocation();
}

// Called every frame
void AActor_5::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector LocalizacaoAtual = GetActorLocation();
	LocalizacaoAtual.Y += Direcao;
	LocalizacaoAtual.X = LocalizacaoInicial.X;
	DistanciaDePercurso ++;
	SetActorLocation(LocalizacaoAtual);
	
	if (DistanciaDePercurso > 300) {
		DistanciaDePercurso=0;
		Direcao=Direcao*-1;
	}

}

void AActor_5::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
		MyCharacter->OnDeath();
		UE_LOG(LogTemp, Warning, TEXT("Life = %d"), MyCharacter->GetLife());
		Direcao=Direcao*-1;
	}
}
