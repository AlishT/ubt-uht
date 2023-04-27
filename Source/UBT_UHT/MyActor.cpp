// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	GetProperty(Value);
	
	UE_LOG(LogTemp, Display, TEXT("Float Value: %.3f"), GetProperty(Value));
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMyActor::GetProperty(float FloatValue)
{
	FFloatProperty* FloatProp = FindField<FFloatProperty>(this->GetClass(), TEXT("TestFloat"));

	if (FloatProp != nullptr)
	{
		FloatValue = FloatProp->GetPropertyValue_InContainer(this);
	}

	return FloatValue;
}