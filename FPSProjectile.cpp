// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "FPSProjectile.h"
// #include "MyStaticLibrary.h"

// Sets default values
AFPSProjectile::AFPSProjectile(){
	PrimaryActorTick.bCanEverTick = true;
}

AFPSProjectile::AFPSProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){
	// Projectile sphere /////////////////////////////////////////////////////////
	
	// Use a sphere as a simple collision representation
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
	CollisionComp->InitSphereRadius(15.0f);
	RootComponent = CollisionComp;
	
	// Create and position a mesh component so we can see where our sphere is
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->AttachTo(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}
	
	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.5f;
	
	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
	//////////////////////////////////////////////////////////////////////////////
	
	// Particle system ///////////////////////////////////////////////////////////
	// static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleObject(TEXT("ParticleSystem'/Game/Effects/Particles/Line_P.Line_P'"));
	
	// ParticleEffect = ObjectInitializer.CreateDefaultSubobject<UParticleSystem>(this, TEXT("ParticleObject"));
	
	// if (ParticleObject.Object != NULL)
	// {
	// 	ParticleEffect = ParticleObject.Object;
	// 	// ParticleEffect->bAutoActivate = false;
	// 	// ParticleEffect->SetHiddenInGame(false);
	//
	// 	UGameplayStatics::SpawnEmitterAttached(
	// 		ParticleEffect, // Particle system
	// 		CollisionComp, // Mesh to attach to
	// 		FName(), // Socket name
	// 		FVector(0, 0, 0), // Location relative to socket
	// 		FRotator(0, 0, 0), // Rotation
	// 		EAttachLocation::KeepRelativeOffset,
	// 		true // Will be deleted automatically
	// 	);
	// }
	
	// Create a particle system that we can activate or deactivate
	ParticleEffectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
	ParticleEffectComp->AttachTo(SphereVisual);
	ParticleEffectComp->bAutoActivate = false;
	ParticleEffectComp->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	// ParticleEffectComp->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	
	if (ParticleAsset.Succeeded())
	{
		ParticleEffectComp->SetTemplate(ParticleAsset.Object);
	}
	
	// Create a particle system that we can activate or deactivate
	ParticleEffectCompImpact = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticles"));
	ParticleEffectCompImpact->AttachTo(SphereVisual);
	ParticleEffectCompImpact->bAutoActivate = false;
	ParticleEffectCompImpact->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAssetImpact(TEXT("/Game/StarterContent/Particles/P_Explosion2.P_Explosion2"));
	
	if (ParticleAssetImpact.Succeeded())
	{
		ParticleEffectCompImpact->SetTemplate(ParticleAssetImpact.Object);
		// ParticleEffectCompImpact->SetWorldScale3D(FVector(15.5f));
		// ParticleEffectCompImpact->SetRelativeScale3D(FVector(2.0f));
	}
	
	// if (ParticleObject.Succeeded())
	// {
	// 	UGameplayStatics::SpawnEmitterAttached(
	// 		ParticleEffect, // Particle system
	// 		CollisionComp, // Mesh to attach to
	// 		FName(), // Socket name
	// 		FVector(0, 0, 64), // Location relative to socket
	// 		FRotator(0, 0, 0), // Rotation
	// 		EAttachLocation::KeepRelativeOffset,
	// 		true // Will be deleted automatically
	// 	);
	// }
	
	// if (ParticleObject.Succeeded())
	// {
	// 	ParticleEffect->Template = ParticleObject.Object;
	// }
	
	// ParticleEffect->AttachTo(Cast<USceneComponent>(FindComponentByClass(UStaticMeshComponent::StaticClass())));
	// ParticleEffect->AttachTo(CollisionComp);
	
	// ParticleEffect->ActivateSystem();
	// ParticleEffect->DeactivateSystem();
	
	//effect
	// UGameplayStatics::SpawnEmitterAttached(
	// 	ThePS, //UParticleSystem*
	// 	CurrentPower,
	// 	TipSocketName,
	// 	FVector(-10,0,0),
	// 	FRotator(0,90,0),
	// 	EAttachLocation::KeepRelativeOffset,
	// 	true
	// );
	
	// UGameplayStatics::SpawnEmitterAttached(
	// 	ThePS, // Particle system
	// 	Mesh, // Mesh to attach to
	// 	FName("Head"), // Socket name
	// 	FVector(0,0,64), // Location relative to socket
	// 	FRotator(0,0,0), // Rotation
	// 	EAttachLocation::KeepRelativeOffset,
	// 	true // Will be deleted automatically
	// );
	
	//////////////////////////////////////////////////////////////////////////////
	
	// UParticleSystemComponent* ParticleTemp;
	// UParticleSystemComponent
	
	// UParticleSystemComponent* ParticleTemp;
	// ParticleTemp = UGameplayStatics::SpawnEmitterAttached(ParticleTemplates[0], RootComponent, NAME_None, GetActorLocation(), GetActorRotation(), EAttachLocation::KeepWorldPosition, false);
	// ParticleSystems.Add(ParticleTemp);
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	ParticleToggle();
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
}

void AFPSProjectile::InitVelocity(const FVector& ShootDirection)
{
	if (ProjectileMovement)
	{
		// set the projectile's velocity to the desired direction
		ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
	}
}

void AFPSProjectile::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// If it exists and isn't itself
	if (OtherActor && (OtherActor != this) && (OtherComp != nullptr)){
		// Trigger explosion on impact
		if (ParticleEffectCompImpact && ParticleEffectCompImpact->Template)
		{
			ParticleEffectCompImpact->ToggleActive();
		}
		
		// If it has physics (AKA can we push it back?)
		if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(ProjectileMovement->Velocity * 100.0f, Hit.ImpactPoint);
		}
	}
}

void AFPSProjectile::ParticleToggle()
{
  if (ParticleEffectComp && ParticleEffectComp->Template)
  {
    ParticleEffectComp->ToggleActive();
  }
}
