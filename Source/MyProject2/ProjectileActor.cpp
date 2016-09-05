// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject2.h"
#include "ProjectileActor.h"
#include "Actor_5.h"
#include "Actor_6.h"
#include "MyCharacter.h"

// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	
	Root->bGenerateOverlapEvents = true;
	Root->OnComponentBeginOverlap.AddDynamic(this, &AProjectileActor::OnOverlapBegin);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	MeshComp->AttachTo(RootComponent);

	Particle = CreateDefaultSubobject<UParticleSystemComponent>
		(TEXT("Particle"));
	Particle->bAutoActivate = true;
	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		ParticleSystem(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystem.Succeeded()) {
		Particle->SetTemplate(ParticleSystem.Object);
	}
	Particle->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = Root;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;
	
	InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	DefaultZ = GetActorLocation().Z;
	
}

// Called every frame
void AProjectileActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector Location = GetActorLocation();
	Location.Z = DefaultZ-30;
	SetActorLocation(Location);

}


void AProjectileActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	// colisão com inimigo
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AActor_5::StaticClass()))) {

		AActor_5* Actor_5 = Cast<AActor_5>(OtherActor);
		Actor_5->Destroy();
		Destroy();
	}

	// colisão com boss
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AActor_6::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		if (MyCharacter->GetScore() >= 10) {
			AActor_6* Actor_6 = Cast<AActor_6>(OtherActor);
			Actor_6->Vidas--;
			if (Actor_6->Vidas <= 0) {
				Actor_6->Destroy();
				UE_LOG(LogTemp, Warning, TEXT("VITORIA"));
			}
		}
		Destroy();
	}
}