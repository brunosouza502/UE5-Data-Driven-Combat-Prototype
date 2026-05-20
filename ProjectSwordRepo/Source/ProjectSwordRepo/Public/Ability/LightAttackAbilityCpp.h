#pragma once

#include "CoreMinimal.h"
#include "Ability/AbilityBaseCpp.h"
#include "LightAttackAbilityCpp.generated.h"

/**
 * Example C++ light attack ability:
 * - Uses data from UAbilityDefinition
 * - Performs a sweep (sphere) forward
 * - Applies generic damage on first hit actor
 */
UCLASS(BlueprintType)
class PROJECTSWORDREPO_API ULightAttackAbilityCpp : public UAbilityBaseCpp
{
    GENERATED_BODY()

public:
    virtual void ExecuteHit() override;
    //virtual void Init(UAbilityDefinition* InDefinition) override;
};
