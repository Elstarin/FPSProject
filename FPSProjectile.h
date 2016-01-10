// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

//For the UGameplayStatics::SpawnEmitterAttached
// #include "EngineKismetLibraryClasses.h"

//All particle definitions for using functions of UParticleSystemComponent
#include "ParticleDefinitions.h"
#include "FPSProjectile.generated.h"

UCLASS()
class FPSPROJECT_API AFPSProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFPSProjectile();
	
	AFPSProjectile(const FObjectInitializer& ObjectInitializer);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	// Particle system reference
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Effects)
	// TSubobjectPtr<UParticleSystemComponent> MyParticleSystem;
	
	// Particle system array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ParticleSystem)
	TArray<UParticleSystem*> ParticleTemplates;
	
	/** Projectile particle effect */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ParticleSystem)
	UParticleSystem* ParticleEffect;
	
	/** Projectile particle effect component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ParticleSystem)
	UParticleSystemComponent* ParticleEffectComp;
	
	/** Projectile particle effect component impact */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ParticleSystem)
	UParticleSystemComponent* ParticleEffectCompImpact;
	
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;
	
	// Projectile movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement)
	UProjectileMovementComponent* ProjectileMovement;
	
	// called when projectile hits something
	UFUNCTION()
	void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	// inits velocity of the projectile in the shoot direction
	void InitVelocity(const FVector& ShootDirection);
	
	void ParticleToggle();
};
