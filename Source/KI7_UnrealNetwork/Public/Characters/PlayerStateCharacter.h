// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerStateCharacter.generated.h"

UCLASS()
class KI7_UNREALNETWORK_API APlayerStateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerStateCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Server, Reliable)
	void Server_AddScore(int32 Point);

public:
	UFUNCTION(BlueprintCallable, Category = "Test")
	void TestAddScore();
};
