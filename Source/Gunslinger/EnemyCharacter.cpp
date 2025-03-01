// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "AbilitySystemComponent.h"
#include "RuneAttributeSet.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("ASC");
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{	
	URuneAttributeSet* RuneAttributeSet = NewObject<URuneAttributeSet>(this);
	AbilitySystemComponent->AddAttributeSetSubobject(RuneAttributeSet);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	Super::BeginPlay();
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* AEnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

