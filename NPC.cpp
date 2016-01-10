// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "NPC.h"


// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ANPC::ANPC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ProxSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));
	ProxSphere->AttachTo(RootComponent);
	ProxSphere->SetSphereRadius(150.f);
	// ProxSphere->OnComponentHit.AddDynamic(this, &ANPC::OnHit);
	// ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::OnHit);
	NpcMessage = "Here's a test message!";
};

// void ANPC::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
// {
// 	// If it exists and isn't itself
// 	print("HIT?");
// 	if (OtherActor && (OtherActor != this) && (OtherComp != nullptr)){
//
// 		// APlayerController* PController = GetWorld()->GetFirstPlayerController();
// 		// if (PController)
// 		// {
// 		// 	FPSHUD * hud = Cast<FPSHUD>(PController->GetHUD());
// 		// 	hud->addMessage(Message(NpcMessage, 5.f, FColor::White));
// 		// }
// 	}
// }

// void ANPC::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
// {
// 	// If the overlapped actor is not the player, return
// 	if (Cast<AFPSCharacter>(OtherActor) == nullptr)
// 	{
// 		return;
// 	}
//
// 	APlayerController* PController = GetWorld()->GetFirstPlayerController();
// 	if (PController)
// 	{
// 		FPSHUD * hud = Cast<FPSHUD>(PController->GetHUD());
// 		hud->addMessage(Message(NpcMessage, 5.f, FColor::White));
// 	}
// }

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
