// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AFPSCharacter();
	
	// Constructor for AFPSCharacter
	AFPSCharacter(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	/** Capsule collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	UCapsuleComponent* TouchCapsule;
	
	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	UCameraComponent* FirstPersonCameraComponent;
	
	// Pawn mesh: 1st person view (arms; seen only by self)
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* FirstPersonMesh;
	
	// Gun muzzle's offset from the camera location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	// Projectile class to spawn
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AFPSProjectile> ProjectileClass;
	
	// Basic values //////////////////////////////////////////////////////////////
	/** Health level of our character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
	float HealthLevel;
	
	/** Stamina level of our character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
	float StaminaLevel;
	
	/** Power level of our character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
	float PowerLevel;
	
	/** Power multiplier for the speed of the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
	float SpeedFactor;
	
	/** Baseline speed of the character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
	float BaseSpeed;
	
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
	// END Basic values //////////////////////////////////////////////////////////
	
	float fForwardSpeedMult = 1.0;
	float fSideSpeedMult = 1.0;

protected:
	// /** Called when we press a key, to collect any batteries inside the SphereComponent. */
	// UFUNCTION(BlueprintCallable, Category = Power)
	// void CollectBatteries();

	// /** Called by CollectBatteries() to use the Blueprinted PowerUp functionality. */
	// UFUNCTION(BlueprintImplementableEvent, Category = Power)
	// void PowerUp(float BatteryPower);
	
	void Yaw(float amount);
	
	void Pitch(float amount);

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);
	
	//sets jump flag when key is pressed
	void OnStartJump();
	
	//clears jump flag when key is released
	void OnStopJump();
	
	//handles firing
	void OnFire();
	
	UFUNCTION()
	void OnOverlap(AActor* OtherActor);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
};
