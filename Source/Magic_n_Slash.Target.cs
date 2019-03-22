// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Magic_n_SlashTarget : TargetRules
{
	public Magic_n_SlashTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Magic_n_Slash" } );
	}
}
