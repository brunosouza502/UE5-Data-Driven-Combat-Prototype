#include "Ability/LightAttackAbilityCpp.h"

#include "UAbilityDefinition.h"              // sua UAbilityDefinition
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "CollisionShape.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "../../Public/Ability/LightAttackAbilityCpp.h"

void ULightAttackAbilityCpp::ExecuteHit()
{
    UE_LOG(LogTemp, Warning, TEXT("ExecuteHit in LightAbilityCPP"));
    if (!OwnerCharacter || !Definition || !bIsActive)
    {
        return;
    }

    UWorld* World = OwnerCharacter->GetWorld();
    if (!World)
    {
        return;
    }

    const FVector Start = OwnerCharacter->GetActorLocation();
    const FVector Forward = OwnerCharacter->GetActorForwardVector();
    const FVector End = Start + (Forward * Definition->TraceDistance);

    FCollisionQueryParams Params(SCENE_QUERY_STAT(LightAttackSweep), false);
    Params.AddIgnoredActor(OwnerCharacter);

    FHitResult Hit;
    const FCollisionShape Sphere = FCollisionShape::MakeSphere(Definition->TraceRadius);

    const bool bHit = World->SweepSingleByChannel(
        Hit,
        Start,
        End,
        FQuat::Identity,
        Definition->TraceChannel,
        Sphere,
        Params
    );

    if (bHit && Hit.GetActor())
    {
        UGameplayStatics::ApplyDamage(
            Hit.GetActor(),
            Definition->Damage,
            OwnerCharacter->GetController(),
            OwnerCharacter,
            UDamageType::StaticClass()
        );
    }

    //Encerrar após o hit (ou controlar via montage end event)
    EndAbility();
    UE_LOG(LogTemp, Warning, TEXT("ExecuteHit in LightAbilityCPP"));
}

/*void ULightAttackAbilityCpp::Init(UAbilityDefinition* InDefinition)
{
    Definition = InDefinition;
}*/

