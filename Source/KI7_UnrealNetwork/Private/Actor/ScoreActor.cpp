// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/ScoreActor.h"

// Sets default values
AScoreActor::AScoreActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AScoreActor::OnOverlapEvent(AActor* OverlappedActor, AActor* OtherActor)
{
}


