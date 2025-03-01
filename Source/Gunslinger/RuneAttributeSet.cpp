// Fill out your copyright notice in the Description page of Project Settings.


#include "RuneAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

URuneAttributeSet::URuneAttributeSet()
{

}

void URuneAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, WeaponDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, DamageReceived, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, CriticalDamageReceived, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, CritChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, CritDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, MoveSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, DodgeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, GoldFind, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, DropChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Pierce, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Toxin, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Current, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Bleed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Frost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Blaze, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Corruption, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, AfflictionResist, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, CooldownReduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, ExperienceForNextLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, CurrentExperience, COND_None, REPNOTIFY_Always);
}

void URuneAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.AttributeName == "DamageReceived")
	{
		AssignDamage();
	}

	if (Data.EvaluatedData.Attribute.AttributeName == "CriticalDamageReceived")
	{
		AssignCriticalDamage();
	}
}

void URuneAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute.AttributeName == "CurrentHealth")
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void URuneAttributeSet::PostAttributeBaseChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) const
{
}

void URuneAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute.AttributeName == "CurrentHealth")
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void URuneAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
}

void URuneAttributeSet::OnRep_WeaponDamage(const FGameplayAttributeData& OldWeaponDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, WeaponDamage, OldWeaponDamage);
}

void URuneAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, CurrentHealth, OldCurrentHealth);
}

void URuneAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, MaxHealth, OldMaxHealth);
}

void URuneAttributeSet::OnRep_DamageReceived(const FGameplayAttributeData& OldDamageReceived)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, DamageReceived, OldDamageReceived);
}

void URuneAttributeSet::OnRep_CriticalDamageReceived(const FGameplayAttributeData& OldCriticalDamageReceived)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, CriticalDamageReceived, OldCriticalDamageReceived);
}

void URuneAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Armor, OldArmor);
}

void URuneAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldCritChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, CritChance, OldCritChance);
}

void URuneAttributeSet::OnRep_CritDamage(const FGameplayAttributeData& OldCritDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, CritDamage, OldCritDamage);
}

void URuneAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, MoveSpeed, OldMoveSpeed);
}

void URuneAttributeSet::OnRep_DodgeChance(const FGameplayAttributeData& OldDodgeChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, DodgeChance, OldDodgeChance);
}

void URuneAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, AttackSpeed, OldAttackSpeed);
}

void URuneAttributeSet::OnRep_GoldFind(const FGameplayAttributeData& OldGoldFind)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, GoldFind, OldGoldFind);
}

void URuneAttributeSet::OnRep_DropChance(const FGameplayAttributeData& OldDropChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, DropChance, OldDropChance);
}

void URuneAttributeSet::OnRep_Pierce(const FGameplayAttributeData& OldPierce)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Pierce, OldPierce);
}

void URuneAttributeSet::OnRep_Toxin(const FGameplayAttributeData& OldToxin)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Toxin, OldToxin);
}

void URuneAttributeSet::OnRep_Current(const FGameplayAttributeData& OldCurrent)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Current, OldCurrent);
}

void URuneAttributeSet::OnRep_Bleed(const FGameplayAttributeData& OldBleed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Bleed, OldBleed);
}

void URuneAttributeSet::OnRep_Frost(const FGameplayAttributeData& OldFrost)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Frost, OldFrost);
}

void URuneAttributeSet::OnRep_Blaze(const FGameplayAttributeData& OldBlaze)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Blaze, OldBlaze);
}

void URuneAttributeSet::OnRep_Corruption(const FGameplayAttributeData& OldCorruption)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Corruption, OldCorruption);
}

void URuneAttributeSet::OnRep_AfflictionResist(const FGameplayAttributeData& OldAfflictionResist)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, AfflictionResist, OldAfflictionResist);
}

void URuneAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, ArmorPenetration, OldArmorPenetration);
}

void URuneAttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, CooldownReduction, OldCooldownReduction);
}

void URuneAttributeSet::OnRep_ExperienceForNextLevel(const FGameplayAttributeData& OldExperienceForNextLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, ExperienceForNextLevel, OldExperienceForNextLevel);
}

void URuneAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Level, OldLevel);
}

void URuneAttributeSet::OnRep_CurrentExperience(const FGameplayAttributeData& OldCurrentExperience)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, CurrentExperience, OldCurrentExperience);
}

void URuneAttributeSet::AssignDamage()
{
	SetCurrentHealth(GetCurrentHealth() - GetDamageReceived());
	SetDamageReceived(0.f);
}

void URuneAttributeSet::AssignCriticalDamage()
{
	SetCurrentHealth(GetCurrentHealth() - GetCriticalDamageReceived() * GetCritDamage());
	SetCriticalDamageReceived(0.f);
}
