// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UAbilityDefinition.generated.h"



/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTSWORDREPO_API UAbilityDefinition : public UDataAsset
{

    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
    FName AbilityId = NAME_None;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Combat")
    float Damage = 20.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Combat")
    float TraceRadius = 75.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Combat")
    float TraceDistance = 150.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Animation")
    TObjectPtr<UAnimMontage> Montage = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Trace")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Pawn;

};
