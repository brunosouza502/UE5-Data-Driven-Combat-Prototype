#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AbilityBaseCpp.generated.h"


class ACharacter;
class UAbilityDefinition;



UCLASS(BlueprintType, Blueprintable)
class PROJECTSWORDREPO_API UAbilityBaseCpp : public UObject
{
    GENERATED_BODY()

public:
    /** Character that owns/executes this ability (set by the AbilitySystemComponent). */
    UPROPERTY(BlueprintReadOnly, Category = "Ability")
    TObjectPtr<ACharacter> OwnerCharacter = nullptr;

    /** Data-driven definition (C++ DataAsset type you already created). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
    TObjectPtr<UAbilityDefinition> Definition = nullptr;

    /** Simple active flag to gate re-entry. */
    UPROPERTY(BlueprintReadOnly, Category = "Ability")
    bool bIsActive = false;

public:
    /** Basic gate. You can expand this later (cooldown, stamina, etc.). */
    UFUNCTION(BlueprintCallable, Category = "Ability")
    virtual bool CanActivate() const;

    /** Plays montage (if provided) and marks ability active. */
    UFUNCTION(BlueprintCallable, Category = "Ability")
    virtual void ActivateAbility();

    /** Ends ability (clears active flag). */
    UFUNCTION(BlueprintCallable, Category = "Ability")
    virtual void EndAbility();

   
    /**
     * Called by AnimNotify (or AbilitySystem) at the hit frame.
     * Derived classes override this to apply gameplay effect / damage.
     */
    UFUNCTION(BlueprintCallable, Category = "Ability")
    virtual void ExecuteHit();

    //
    UFUNCTION(BlueprintCallable, Category = "Ability")
    virtual void Init(UAbilityDefinition* InDefinition);


    UFUNCTION(BlueprintCallable)
    virtual void DebugPing();

};
