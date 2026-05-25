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

    //////////////////////////////////////////////

    // Se tiver montage na definição, toca.
    if (Definition && Definition->Montage && OwnerCharacter && OwnerCharacter->GetMesh())
    {
        if (UAnimInstance* AnimInst = OwnerCharacter->GetMesh()->GetAnimInstance())
        {
            AnimInst->Montage_Play(Definition->Montage);

            //Final da montage
            FOnMontageEnded EndDelegate;
            EndDelegate.BindUObject(this, &UAbilityBaseCpp::OnMontageEnded);
            AnimInst->Montage_SetEndDelegate(EndDelegate, Definition->Montage);
            ////
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

void UAbilityBaseCpp::Init(UAbilityDefinition* InDefinition, ACharacter* InCharacter)
{
    // Base: não faz nada. Implementação nas filhas.
    UE_LOG(LogTemp, Error, TEXT("Init"));
    Definition = InDefinition;
    OwnerCharacter = InCharacter;
}

void UAbilityBaseCpp::DebugPing()
{
    UE_LOG(LogTemp, Warning, TEXT("DEBUG PING WORKING"));
}

bool UAbilityBaseCpp::IsActive()
{
    return bIsActive;
}


//Montage ended
void UAbilityBaseCpp::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
    if (Definition && Montage == Definition->Montage)
    {
        UE_LOG(LogTemp, Warning, TEXT("Montage finished -> EndAbility()"));
        EndAbility();
    }
}


//Chama primeiro
void UAbilityBaseCpp::TryActivateAbility()
{
    if (!CanActivate())
    {
        UE_LOG(LogTemp, Warning, TEXT("TryActivate FAILED"));
        return;
    }

    ActivateAbility();
    
}


