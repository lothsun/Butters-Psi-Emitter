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
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BBPRE\scripts\3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BBPRE\scripts\4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"BBPRE\scripts\5_Mission"
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

		class EnergyManager {
            hasIcon                  = 1;      // show battery icon in inventory
            energyStorageMax         = 10000;  // max “charge” (in joules)
            energyAtSpawn            = 0;      // start drained
            convertEnergyToQuantity  = 1;      // tie into varQuantity bars (optional)
            reduceMaxEnergyByDamageCoef = 1;   // damage → less capacity
            energyUsagePerSecond     = 5;      // watts consumed when “on”
            updateInterval           = 1;      // how often (sec) DeviceUpdate fires

            // (optional—you only need these if you want sockets/cords)
            plugType                 = 1;      // which socket type it uses
            compatiblePlugTypes[]    = {1,2};  // generator/battery types it accepts
            powerSocketsCount        = 1;      // how many sockets it exposes
            cordLength               = 5;      // max cable length (m)
            wetnessExposure          = 0;    // how quickly rain drains power
        };
    };
};