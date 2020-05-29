class CfgPatches
{
	class fox_uniforms
	{
		name = "[FOX] Uniforms";
		author = "Phil";
		url = "http://sog-fox.com/";
		requiredVersion = 1.90;
		requiredAddons[] = { "VSM_Multicam_Config" };
		units[] = {};
		weapons[] = {};
	};
};

class cfgFactionClasses
{
	class fox
	{
		displayName="Force Operation X";
		priority=1;
		side=1;
		icon="\fox_uniforms\logo512.jpg";
	};
};

class cfgVehicleClasses
{
  class fox_units
  {
    displayName="Men";
  };
};

#define PREFIXSTR(NAME) [FOX] NAME
#define TP(FILE) \fox_uniforms\textures\##FILE##.paa
#define UCSTR(CAMO) fox_camo##CAMO##_uniform
#define NEW_UNIFORM(CAMO,NAME,UC,TEXTURE) \
        class fox_camo##CAMO##_uniform: VSM_Multicam_Casual_uniform \
        { \
          author=PREFIXSTR(Phil); \
          displayName=PREFIXSTR(NAME); \
          scope = 2; \
          scopeCurator = 2; \
          scopeArsenal = 2; \
          vehicleClass = "fox_units"; \
          faction="fox"; \
          uniformClass=#UC; \
          hiddenSelectionsTextures[]={ \
            TP(TEXTURE), \
            "VSM_Multicam\Data\VSM_ARD_Multicam_1.paa" \
          }; \
        };

#define NEW_UNIFORM_W(CAMO,NAME) \
        class fox_camo##CAMO: VSM_Multicam_casual_Camo \
        { \
          scope=2; \
          displayName=PREFIXSTR(NAME); \
          author=PREFIXSTR(Phil); \
          picture="\fox_uniforms\logo512.jpg"; \
          class ItemInfo: UniformItem \
          { \
            uniformClass=UCSTR(CAMO); \
            containerClass="Supply70"; \
            mass=35; \
          }; \
        };

class CfgVehicles{
  class B_Soldier_03_f;
  class VSM_Multicam_Casual_uniform;
  class VSM_Multicam_Crye_Uniform;

  NEW_UNIFORM(1,Uniform 1,fox_camo1,1);
  NEW_UNIFORM(2,Uniform 2,fox_camo2,2);
  NEW_UNIFORM(3,Uniform 3,fox_camo3,3);
  NEW_UNIFORM(4,Uniform 4,fox_camo4,4);
  NEW_UNIFORM(5,Uniform 5,fox_camo5,5);
  NEW_UNIFORM(6,Uniform 6,fox_camo6,6);
  NEW_UNIFORM(7,Uniform 7,fox_camo7,7);
  NEW_UNIFORM(8,Uniform 8,fox_camo8,8);
  NEW_UNIFORM(9,Uniform 9,fox_camo9,9);
  NEW_UNIFORM(10,Uniform 10,fox_camo10,10);
  NEW_UNIFORM(_phil,[Custom] Phil,fox_camo_phil,phil);
  NEW_UNIFORM(_assumaril,[Custom] Assumaril,fox_camo_assumaril,assumaril);
};
class cfgWeapons{
	class ItemCore;
	class UniformItem;
	class InventoryItem_Base_F;
	class HeadgearItem;
  class VSM_Multicam_casual_Camo;
	class Uniform_Base: ItemCore
	{
		class ItemInfo;
	};

  NEW_UNIFORM_W(1,Uniform 1);
  NEW_UNIFORM_W(2,Uniform 2);
  NEW_UNIFORM_W(3,Uniform 3);
  NEW_UNIFORM_W(4,Uniform 4);
  NEW_UNIFORM_W(5,Uniform 5);
  NEW_UNIFORM_W(6,Uniform 6);
  NEW_UNIFORM_W(7,Uniform 7);
  NEW_UNIFORM_W(8,Uniform 8);
  NEW_UNIFORM_W(9,Uniform 9);
  NEW_UNIFORM_W(10,Uniform 10);
	NEW_UNIFORM_W(_phil,[Custom] Phil);
	NEW_UNIFORM_W(_assumaril,[Custom] Assumaril);
};
