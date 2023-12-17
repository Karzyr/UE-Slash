// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashOverlay.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USlashOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
		HealthProgressBar->SetPercent(Percent);
}

void USlashOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar)
		StaminaProgressBar->SetPercent(Percent);
}

void USlashOverlay::SetGold(int32 Gold)
{
	if (CoinText)
		CoinText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Gold)));
}

void USlashOverlay::SetSouls(int32 Souls)
{
	if (SoulText)
		SoulText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Souls)));
}
