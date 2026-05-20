#include "Ability/AbilityBaseCpp.h"

#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"
#include "UAbilityDefinition.h"

bool UAbilityBaseCpp::CanActivate() const
{
    return !bIsActive && OwnerCharacter && Definition;
}

void UAbilityBaseCpp::ActivateAbility()
{
    if (!CanActivate())
    {
        UE_LOG(LogTemp, Warning, TEXT("CanActivate FAILED"));
        return;
    }

    bIsActive = true;

    UE_LOG(LogTemp, Warning, TEXT("Activated"));

    //Verificar se Defnition, montage e character está null
    if (!Definition)
    {
        UE_LOG(LogTemp, Error, TEXT("Definition is NULL"));
    }

    if (!Definition->Montage)
    {
        UE_LOG(LogTemp, Error, TEXT("Montage is NULL"));
    }

    if (!OwnerCharacter)
    {
        UE_LOG(LogTemp, Error, TEXT("OwnerCharacter is NULL"));
    }

    //////////////////////////////////////////////

    // Se tiver montage na definição, toca.
    if (Definition && Definition->Montage && OwnerCharacter && OwnerCharacter->GetMesh())
    {
        if (UAnimInstance* AnimInst = OwnerCharacter->GetMesh()->GetAnimInstance())
        {
            AnimInst->Montage_Play(Definition->Montage);            
        }
    }
}

void UAbilityBaseCpp::EndAbility()
{
    bIsActive = false;
}

void UAbilityBaseCpp::ExecuteHit()
{
    // Base: não faz nada. Implementação nas filhas.
}

void UAbilityBaseCpp::Init(UAbilityDefinition* InDefinition)
{
    // Base: não faz nada. Implementação nas filhas.
    UE_LOG(LogTemp, Error, TEXT("Init"));
    Definition = InDefinition;
}

void UAbilityBaseCpp::DebugPing()
{
    UE_LOG(LogTemp, Warning, TEXT("DEBUG PING WORKING"));
}
