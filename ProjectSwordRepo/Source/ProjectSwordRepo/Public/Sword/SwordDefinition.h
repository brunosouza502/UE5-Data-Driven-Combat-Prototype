// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SwordDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTSWORDREPO_API USwordDefinition : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sword")
	float Damage = 30.f;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sword")
	TObjectPtr<UStaticMesh> SwordMesh = nullptr;

};
