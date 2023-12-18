// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "CharacterTypes.h"
#include "Interfaces/PickUpInterface.h"
#include "SlashCharacter.generated.h"


class USlashOverlay;
class ASlashHUD;
struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;
class UInputMappingContext;
class UInputAction;

UCLASS()
class SLASH_API ASlashCharacter : public ABaseCharacter, public IPickUpInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();

	virtual void Tick(float DeltaSeconds) override;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, const AActor* Hitter) override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	void InitializeSlashOverlay();
	virtual void SetOverlappingItem(AItem* Item) override;
	virtual void AddSouls(ASoul* Soul) override;
	virtual void AddGold(ATreasure* Gold) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputMappingContext* SlashContext;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* EquipAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* AttackAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* DodgeAction;
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Equip();
	void Dodge();
	virtual void Attack() override;
	virtual void Jump() override;
	
	/** Combat */
	void EquipWeapon(AWeapon* Weapon);
	virtual void AttackEnd() override;
	virtual void DodgeEnd() override;
	UFUNCTION(BlueprintCallable)
	void HitReactEnd();
	virtual bool CanAttack() override;
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();
	void PlayEquipMontage(const FName& SectionName);

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

private:

	/** Character components */

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

	virtual void Die() override;
	void HandleDamage(float DamageAmount) override;

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};
