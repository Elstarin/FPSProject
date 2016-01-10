// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "FPSCharacter.h"
#include "FPSProjectile.h"
#include "Creature.h"
// #include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
// #include "Runtime/Engine/Classes/GameFramework/InputSettings.h"
// #include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"

class PlayerChar : public Creature
{
private:
	FString name;
	int32 health;
	int32 magic;
	int32 stamina;
	int32 energy;
	int32 forwardSpeed;
	int32 strafeSpeed;
	int32 jumpHeight;
	
public:
	// Constructor and Destructor ////////////////////////////////////////////////
	PlayerChar(
		FString newName = "Unknown",
		int32 newHealth = 100,
		int32 newMagic = 100,
		int32 newStamina = 100,
		int32 newEnergy = 100,
		int32 newForwardSpeed = 1,
		int32 newStrafeSpeed = 1,
		int32 newJumpHeight = 1
		)
	{
		name = newName;
		health = newHealth;
		magic = newMagic;
		stamina = newStamina;
		energy = newEnergy;
		forwardSpeed = newForwardSpeed;
		strafeSpeed = newStrafeSpeed;
		jumpHeight = newJumpHeight;
	}

	~PlayerChar()
	{
		
	}
	//////////////////////////////////////////////////////////////////////////////
	
	// Handle name ///////////////////////////////////////////////////////////////
	FString GetName() const{return name;}
	
	void SetName(FString newName){name = newName;}
	//////////////////////////////////////////////////////////////////////////////
	
	// Handle health /////////////////////////////////////////////////////////////
	int32 GetHealth() const{return health;}
	
	void IncreaseHealth(int32 newHealth){health += newHealth;}
	void ReduceHealth(int32 newHealth){health -= newHealth;}
	void SetHealth(int32 newHealth){health = newHealth;}
	//////////////////////////////////////////////////////////////////////////////
	
	// Handle magic //////////////////////////////////////////////////////////////
	int32 GetMagic() const{return magic;}
	
	void IncreaseMagic(int32 newMagic){magic += newMagic;}
	void ReduceMagic(int32 newMagic){magic -= newMagic;}
	void SetMagic(int32 newMagic){magic = newMagic;}
	//////////////////////////////////////////////////////////////////////////////
	
	// Handle stamina //////////////////////////////////////////////////////////////
	int32 GetStamina() const{return stamina;}
	
	void IncreaseStamina(int32 newStamina){stamina += newStamina;}
	void ReduceStamina(int32 newStamina){stamina -= newStamina;}
	void SetStamina(int32 newStamina){stamina = newStamina;}
	//////////////////////////////////////////////////////////////////////////////
};

class Crusader : public PlayerChar
{
	
};

// Sets default values
AFPSCharacter::AFPSCharacter(){
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
}

AFPSCharacter::AFPSCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// EventHandlerComponent->OnLevelComplete.Broadcast(LevelIndex);
	
	OnActorBeginOverlap.AddDynamic(this, &AFPSCharacter::OnOverlap);
	// OnLevelComplete.AddDynamic(this, &AFPSCharacter::OnLevelCompleteHandler);
	// EventHandlerComponent->
	
	// Create a CameraComponent
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	
	// Position the camera a bit above the eyes
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 50.f + BaseEyeHeight);
	// FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 0);
	// FirstPersonCameraComponent->RelativeLocation = FVector(100.0f, 100.0f, 50.0f + BaseEyeHeight);
	// Allow the pawn to control rotation.
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	FirstPersonMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("FirstPersonMesh"));
	FirstPersonMesh->SetOnlyOwnerSee(true); // only the owning player will see this mesh
	FirstPersonMesh->AttachParent = FirstPersonCameraComponent;
	FirstPersonMesh->bCastDynamicShadow = false;
	FirstPersonMesh->CastShadow = false;
	
	// everyone but the owner can see the regular body mesh
	GetMesh()->SetOwnerNoSee(true);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent){
	Super::SetupPlayerInputComponent(InputComponent);

	// set up gameplay key bindings
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	
	InputComponent->BindAxis("Turn", this, &AFPSCharacter::Yaw);
	InputComponent->BindAxis("LookUp", this, &AFPSCharacter::Pitch);
	
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::OnStopJump);
	
	InputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::OnFire);
};

void AFPSCharacter::Yaw(float amount)
{
	AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::Pitch(float amount)
{
	AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::MoveForward(float Value){
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		Value = Value * fForwardSpeedMult;
		
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling() )
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::MoveRight(float Value){
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		Value = Value * fSideSpeedMult;
		
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::OnStartJump(){
	print("Jumping");
	bPressedJump = true;
}

void AFPSCharacter::OnStopJump(){
	bPressedJump = false;
}

void AFPSCharacter::OnFire(){
	// {
	// 	UParticleSystemComponent* ParticleTemp;
	// 	ParticleTemp = UGameplayStatics::SpawnEmitterAttached(TemplateSystem, RootComponent, NAME_None, GetActorLocation(), GetActorRotation(), EAttachLocation::KeepWorldPosition, false);
	// 	ParticleSystems.Add(ParticleTemp);
	// }
	
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		// Get the camera transform
		FVector CameraLoc;
		FRotator CameraRot;
		GetActorEyesViewPoint(CameraLoc, CameraRot);
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the camera to find the final muzzle position
		FVector const MuzzleLocation = CameraLoc + FTransform(CameraRot).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRot;
		MuzzleRotation.Pitch += 10.0f; // skew the aim upwards a bit
		UWorld* const World = GetWorld();
		
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			// spawn the projectile at the muzzle
			AFPSProjectile* const Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// find launch direction
				FVector const LaunchDir = MuzzleRotation.Vector();
				Projectile->InitVelocity(LaunchDir);
			}
		}
	}
}

void AFPSCharacter::OnOverlap(AActor* OtherActor){
	print("OVERLAP:", OtherActor, GetDisplay);
	// GetDisplay()
	
	// APlayerController* PController = GetWorld()->GetFirstPlayerController();
	
	// if (PController)
	// {
	// 	auto HUD = Cast<AFPSHUD>(PController->GetHUD());
	// 	// AFPSHUD * hud = Cast<FPSHUD>(PController->GetHUD());
	// 	HUD->addMessage(Message(NpcMessage, 5.f, FColor::White));
	// }
}

// EventHandlerComponent->OnLevelComplete.AddDynamic(this, &MyListenerClass::OnLevelCompleteHandler);
