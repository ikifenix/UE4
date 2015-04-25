#include "GoldenEgg.h"
#include "NPC.h"
#include "MyHUD.h"
#include "Avatar.h"



//ANPC::ANPC(const class FPostConstructInitializeProperties& PCIP) :Super(PCIP)
ANPC::ANPC(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Proximity Sphere"));
	ProxSphere->AttachTo(RootComponent);
	ProxSphere->SetSphereRadius(62.f);
	// Code to make ANPC::Prox() run when this proximity sphere
	// overlaps another actor.
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox);
	NpcMessage = "Hi, I'm Owen";//default message, can be edited
	// in blueprints
} // Note! Although this was declared ANPC::Prox() in the header,
// it is now ANPC::Prox_Implementation here.
void ANPC::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent*	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// This is where our code will go for what happens
	// when there is an intersection
	
	// if the overlapped actor is not the player,
	// you should just simply return from the function
	if (Cast<AAvatar>(OtherActor) == nullptr)
	{
		return;
	}
	APlayerController* PController = GetWorld() ->GetFirstPlayerController();
	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message(NpcMessage, 20.f, FColor::White, FColor::Black));
	}
}
















/*
ANPC::ANPC(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	ProxSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));
	
	// You must attach the ProxSphere to the root component, otherwise,
	// the ProxSphere will NOT be with the NPC!
	ProxSphere->AttachTo( RootComponent );
	ProxSphere->SetSphereRadius( 62.f );

	// Code to make ANPC::Prox() run when this proximity sphere
	// overlaps another actor.
	ProxSphere->OnComponentBeginOverlap.AddDynamic( this, &ANPC::Prox );
	NpcMessage = "Hi, I'm Owen";//default message, can be edited in blueprints
}

void ANPC::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// if the overlapped actor is not the player,
	// you should just simply return from the function
	if (Cast<AAvatar>(OtherActor) == nullptr)
	{
		return;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		AMyHUD * hud = Cast<AMyHUD>(PController->GetHUD());
		

		hud->addMessage(Message(NpcMessage, 5.f, FColor::White, FColor::Black));
	}
}

*/