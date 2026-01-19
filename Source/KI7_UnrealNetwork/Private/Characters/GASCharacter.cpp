// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GASCharacter.h"
#include "GAS/TestAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
AGASCharacter::AGASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	ASC->SetIsReplicated(true);
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	// Minimal : 어트리뷰트와 큐만 오너와 다른 클라이언트에게 리플리케이션 (ex:NPC적)
	// Mixed : 미니멀 + (오너에게 모두 리플리케이션) (ex:자기 플레이어)
	// Full : 모두에게 모두 리플리케이션(디버깅, 관전 모드용)

	ResourceAttributeSet = CreateDefaultSubobject<UTestAttributeSet>(TEXT("ResourceAS"));

}

// Called when the game starts or when spawned
void AGASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (ASC)
	{
		FOnGameplayAttributeValueChange& onHealthChange =
			ASC->GetGameplayAttributeValueChangeDelegate(UTestAttributeSet::GetHealthAttribute());
		onHealthChange.AddUObject(this, &AGASCharacter::OnHealthChanged);
	}
}

// Called every frame
void AGASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGASCharacter::OnHealthChanged(const FOnAttributeChangeData& Data)
{
	const float NewHealth = Data.NewValue;
	UE_LOG(LogTemp, Log, TEXT("현재 체력 : %.1f"), NewHealth);
}

