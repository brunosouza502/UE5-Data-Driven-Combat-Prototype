// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwordBase.generated.h"


class ACharacter;
class USwordDefinition;

UCLASS(BlueprintType, Blueprintable)
class PROJECTSWORDREPO_API ASwordBase : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadOnly, Category = "Sword")
	TObjectPtr<ACharacter> OwnerCharacter = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Sword")
	TObjectPtr<USwordDefinition> Definition = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Sword")
	float Damage = 0.0f;

	//
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sword", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> SwordStaticMesh;


public:	
	// Sets default values for this actor's properties
	ASwordBase();

	UFUNCTION(BlueprintCallable, Category = "Sword")
	virtual void Init(USwordDefinition* InDefinition, ACharacter* InCharacter);

};
