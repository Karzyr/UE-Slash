// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	// Current Health
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Health;
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Stamina;
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxStamina;
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float StaminaRegenRate = 5.f; 

	
	UPROPERTY(VisibleAnywhere, Category = "Actor Attributes")
	int32 Gold;
	UPROPERTY(VisibleAnywhere, Category = "Actor Attributes")
	int32 Souls;

	

public:
	void ReceiveDamage(float Damage);
	void SetStamina(float StaminaCost);
	float GetHealthPercent();
	float GetStaminaPercent();
	bool IsAlive();
	void AddGold(int32 AmountGold);
	void AddSouls(int32 AmountSouls);
	FORCEINLINE int32 GetGold() { return Gold; }
	FORCEINLINE int32 GetSouls() { return Souls; }
	FORCEINLINE float GetStamina() { return Stamina; }
	
};
