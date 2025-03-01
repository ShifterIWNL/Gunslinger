// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RuneAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GUNSLINGER_API URuneAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	URuneAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>&OutLifetimeProps) const override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const override;
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;



	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData WeaponDamage;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, WeaponDamage);

	UFUNCTION()
	virtual void OnRep_WeaponDamage(const FGameplayAttributeData& OldWeaponDamage);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, CurrentHealth);

	UFUNCTION()
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, MaxHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DamageReceived;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, DamageReceived);

	UFUNCTION()
	virtual void OnRep_DamageReceived(const FGameplayAttributeData& OldDamageReceived);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CriticalDamageReceived;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, CriticalDamageReceived);

	UFUNCTION()
	virtual void OnRep_CriticalDamageReceived(const FGameplayAttributeData& OldCriticalDamageReceived);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Armor);

	UFUNCTION()
	virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CritChance;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, CritChance);

	UFUNCTION()
	virtual void OnRep_CritChance(const FGameplayAttributeData& OldCritChance);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CritDamage;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, CritDamage);

	UFUNCTION()
	virtual void OnRep_CritDamage(const FGameplayAttributeData& OldCritDamage);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, MoveSpeed);

	UFUNCTION()
	virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DodgeChance;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, DodgeChance);

	UFUNCTION()
	virtual void OnRep_DodgeChance(const FGameplayAttributeData& OldDodgeChance);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, AttackSpeed);

	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData GoldFind;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, GoldFind);

	UFUNCTION()
	virtual void OnRep_GoldFind(const FGameplayAttributeData& OldGoldFind);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DropChance;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, DropChance);

	UFUNCTION()
	virtual void OnRep_DropChance(const FGameplayAttributeData& OldDropChance);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Pierce;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Pierce);

	UFUNCTION()
	virtual void OnRep_Pierce(const FGameplayAttributeData& OldPierce);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Toxin;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Toxin);

	UFUNCTION()
	virtual void OnRep_Toxin(const FGameplayAttributeData& OldToxin);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Current;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Current);

	UFUNCTION()
	virtual void OnRep_Current(const FGameplayAttributeData& OldCurrent);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Bleed;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Bleed);

	UFUNCTION()
	virtual void OnRep_Bleed(const FGameplayAttributeData& OldBleed);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Frost;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Frost);

	UFUNCTION()
	virtual void OnRep_Frost(const FGameplayAttributeData& OldFrost);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Blaze;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Blaze);

	UFUNCTION()
	virtual void OnRep_Blaze(const FGameplayAttributeData& OldBlaze);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Corruption;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Corruption);

	UFUNCTION()
	virtual void OnRep_Corruption(const FGameplayAttributeData& OldCorruption);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AfflictionResist;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, AfflictionResist);

	UFUNCTION()
	virtual void OnRep_AfflictionResist(const FGameplayAttributeData& OldAfflictionResist);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, ArmorPenetration);

	UFUNCTION()
	virtual void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, CooldownReduction);

	UFUNCTION()
	virtual void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ExperienceForNextLevel;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, ExperienceForNextLevel);

	UFUNCTION()
	virtual void OnRep_ExperienceForNextLevel(const FGameplayAttributeData& OldExperienceForNextLevel);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, Level);

	UFUNCTION()
	virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CurrentExperience;
	ATTRIBUTE_ACCESSORS(URuneAttributeSet, CurrentExperience);

	UFUNCTION()
	virtual void OnRep_CurrentExperience(const FGameplayAttributeData& OldCurrentExperience);

private:
	void AssignDamage();
	void AssignCriticalDamage();
};
