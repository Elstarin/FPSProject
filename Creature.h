// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 *
 */
class FPSPROJECT_API Creature
{
	protected:
		FString name;
		FString category;
		bool hostile;
		bool friendly;
		bool neutral;
		int32 health;
		int32 magic;
		int32 stamina;
		int32 energy;
		int32 forwardSpeed;
		int32 strafeSpeed;
		int32 jumpHeight;
	public:
		Creature();
		~Creature();
};

class FriendlyCreature : public Creature
{
	protected:
		FString name;
		FString category;
		bool hostile;
		bool friendly;
		bool neutral;
		int32 health;
		int32 magic;
		int32 stamina;
		int32 energy;
		int32 forwardSpeed;
		int32 strafeSpeed;
		int32 jumpHeight;
	public:
		FriendlyCreature();
		~FriendlyCreature();
};

class HostileCreature : public Creature
{
	protected:
		FString name;
		FString category;
		bool hostile;
		bool friendly;
		bool neutral;
		int32 health;
		int32 magic;
		int32 stamina;
		int32 energy;
		int32 forwardSpeed;
		int32 strafeSpeed;
		int32 jumpHeight;
	public:
		HostileCreature();
		~HostileCreature();
};
