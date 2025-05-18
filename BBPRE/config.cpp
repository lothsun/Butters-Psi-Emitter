class CfgPatches
{
	class ButtersBeyondPsiEmitter
	{
		units[]=
		{
			"BB_Psi_Emitter"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters"
		};
	};
};
class CfgMods
{
	class ButtersBeyondPsiEmitter
	{
		dir = "ButtersBeyondPsiEmitter";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ButtersBeyondPsiEmitter";
		creditsJson = "BBPRE/scripts/Credits.json";
		author = "Butters";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] =
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"BBPRE/scripts/4_world"
				};
			};
		};
	};
};

class CfgVehicles
{
    class ItemBase;

    class BB_Psi_Emitter: ItemBase
    {
        scope=2;
		displayName="Psi-Radiation Emitter";
		descriptionShort="A device with markings on the control panel that suggests it was made by zone scientists";
        model = "\BBPRE\BB_Psi_Emitter.p3d";
        weight = 30000;
        itemSize[]={4,7};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
    };
};