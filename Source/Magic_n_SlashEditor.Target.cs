// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Magic_n_SlashEditorTarget : TargetRules
{
	public Magic_n_SlashEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Magic_n_Slash" } );
	}
}
