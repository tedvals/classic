#ifndef _PlayerbotWarlockAI_H
#define _PlayerbotWarlockAI_H

#include "PlayerbotClassAI.h"

#define SOUL_SHARD 6265
#define SPELLSTONE 5522
#define GREATER_SPELLSTONE 13602
#define MAJOR_SPELLSTONE 13603
#define LESSER_FIRESTONE 1254
#define FIRESTONE 13699
#define GREATER_FIRESTONE 13700
#define MAJOR_FIRESTONE 13701
#define MAX_SHARD_COUNT 15 // Maximum soul shard count bot should keep

enum
{
    SPELL_CURSES,
    SPELL_AFFLICTION,
    SPELL_DESTRUCTION,
    SPELL_DEMONOLOGY
};

enum StoneDisplayId
{
    FIRESTONE_DISPLAYID   = 24380,
    SPELLSTONE_DISPLAYID  = 21610,
    SOULSTONE_DISPLAYID   = 6009,
    HEALTHSTONE_DISPLAYID = 8026
};

enum DemonEntry
{
    DEMON_IMP        = 416,
    DEMON_VOIDWALKER = 1860,
    DEMON_SUCCUBUS   = 1863,
    DEMON_FELHUNTER  = 417,    
};

enum DemonSpellIconIds
{
    // Imp
    BLOOD_PACT_ICON       = 541,
    FIREBOLT_ICON         = 18,
    FIRE_SHIELD_ICON      = 16,    
    // Felhunter
    DEVOUR_MAGIC_ICON     = 47,
    SPELL_LOCK_ICON       = 77,
    // Succubus
    LASH_OF_PAIN_ICON     = 596,
    SEDUCTION_ICON        = 48,
    SOOTHING_KISS_ICON    = 694,
    // Voidwalker
    CONSUME_SHADOWS_ICON  = 207,
    SACRIFICE_ICON        = 693,
    SUFFERING_ICON        = 9,
    TORMENT_ICON          = 173
};

enum WarlockSpells
{
	Amplify_Curse_1                 =18288,  
	BANISH_1                        = 710,
    CONFLAGRATE_1                   = 17962,
    CORRUPTION_1                    = 172,
    CREATE_FIRESTONE_1              = 6366,
    CREATE_HEALTHSTONE_1            = 6201,
    CREATE_SOULSTONE_1              = 693,
    CREATE_SPELLSTONE_1             = 2362,
    CURSE_OF_AGONY_1                = 980,
    CURSE_OF_DOOM_1                 = 603,
    CURSE_OF_EXHAUSTION_1           = 18223,
    CURSE_OF_THE_ELEMENTS_1         = 1490,
    CURSE_OF_TONGUES_1              = 1714,
    CURSE_OF_WEAKNESS_1             = 702,
	CURSE_OF_RECKLESSNESS_1         = 704,
	CURSE_OF_SHADOW_1               = 17862,
    DARK_PACT_1                     = 18220,
    DEATH_COIL_WARLOCK_1            = 6789,
    DEMON_ARMOR_1                   = 706,
    DEMON_SKIN_1                    = 687,
    DETECT_INVISIBILITY_1           = 132,
    DRAIN_LIFE_1                    = 689,
    DRAIN_MANA_1                    = 5138,
    DRAIN_SOUL_1                    = 1120,
    ENSLAVE_DEMON_1                 = 1098,
    EYE_OF_KILROGG_1                = 126,
    FEAR_1                          = 5782,
    FEL_DOMINATION_1                = 18708,
    HEALTH_FUNNEL_1                 = 755,
    HELLFIRE_1                      = 1949,
    HOWL_OF_TERROR_1                = 5484,
    IMMOLATE_1                      = 348,
    INCINERATE_1                    = 29722,
    LIFE_TAP_1                      = 1454,
    RAIN_OF_FIRE_1                  = 5740,
    RITUAL_OF_DOOM_1                = 18540,
    RITUAL_OF_SOULS_1               = 29893,
    RITUAL_OF_SUMMONING_1           = 698,
    SEARING_PAIN_1                  = 5676,
    SENSE_DEMONS_1                  = 5500,
    SHADOW_BOLT_1                   = 686,
    SHADOW_WARD_1                   = 6229,
    SHADOWBURN_1                    = 17877,
    SHOOT_3                         = 5019,
    SOUL_FIRE_1                     = 6353,
    SOUL_LINK_1                     = 19028,
    SUMMON_FELHUNTER_1              = 691,
    SUMMON_IMP_1                    = 688,
    SUMMON_SUCCUBUS_1               = 712,
    SUMMON_VOIDWALKER_1             = 697,
    UNENDING_BREATH_1               = 5697,
    Siphon_Life_1                   = 18265      
};

//class Player;
class MANGOS_DLL_SPEC PlayerbotWarlockAI : PlayerbotClassAI
{
public:
    PlayerbotWarlockAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
    virtual ~PlayerbotWarlockAI();

    // all combat actions go here
    CombatManeuverReturns DoFirstCombatManeuver(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuver(Unit* pTarget);

    // all non combat actions go here, ex buffs, heals, rezzes
    void DoNonCombatActions();

    // buff a specific player, usually a real PC who is not in group
    //void BuffPlayer(Player *target);

private:
    CombatManeuverReturns DoFirstCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoFirstCombatManeuverPVP(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVP(Unit* pTarget);

    CombatManeuverReturns CastSpell(uint32 nextAction, Unit *pTarget = nullptr) { return CastSpellWand(nextAction, pTarget, SHOOT); }

	bool CheckCurse(uint32 spec, Unit* pTarget);
    void CheckDemon();

    // CURSES
    uint32 CURSE_OF_WEAKNESS,
           CURSE_OF_AGONY,
           CURSE_OF_EXHAUSTION,
           CURSE_OF_TONGUES,
           CURSE_OF_THE_ELEMENTS,
           CURSE_OF_DOOM,
		   CURSE_OF_RECKLESSNESS,
		   CURSE_OF_SHADOW;
           
    // RANGED
    uint32 SHOOT;

    // AFFLICTION
    uint32 CORRUPTION,
           DRAIN_SOUL,
           DRAIN_LIFE,
           DRAIN_MANA,
           LIFE_TAP,           
           DARK_PACT,
           HOWL_OF_TERROR,
           FEAR,
		   Siphon_Life,
		   DEATH_COIL,
		   AMPLIFY_CURSE;

    // DESTRUCTION
	uint32 SHADOW_BOLT,
		IMMOLATE,
		SEARING_PAIN,
		CONFLAGRATE,
		SOUL_FIRE,
		HELLFIRE,
		RAIN_OF_FIRE,
		SHADOWBURN;
           
    // DEMONOLOGY
	uint32 BANISH,
		   ENSLAVE_DEMON,
		   DEMON_SKIN,
           DEMON_ARMOR,
           SHADOW_WARD,
           SOUL_LINK,
           SOUL_LINK_AURA,
           HEALTH_FUNNEL,
           DETECT_INVISIBILITY,
           CREATE_FIRESTONE,
           CREATE_SOULSTONE,
           CREATE_HEALTHSTONE,
           CREATE_SPELLSTONE;

    // DEMON SUMMON
	uint32 SUMMON_IMP,
		SUMMON_VOIDWALKER,
		SUMMON_SUCCUBUS,
		SUMMON_FELHUNTER;
           
    // DEMON SKILLS
    uint32 BLOOD_PACT,
           FIREBOLT,
           FIRE_SHIELD,           
           DEVOUR_MAGIC,
           SPELL_LOCK,
           LASH_OF_PAIN,
           SEDUCTION,
           SOOTHING_KISS,
           CONSUME_SHADOWS,
           SACRIFICE,
           SUFFERING,
           TORMENT;

    // racial
    uint32 ESCAPE_ARTIST,
		   PERCEPTION,
           SHADOWMELD,
           BLOOD_FURY,
           WAR_STOMP,
           BERSERKING,
           WILL_OF_THE_FORSAKEN;

    uint32 m_lastDemon;      // Last demon entry used for spell initialization
    bool m_isTempImp;        // True if imp summoned temporarily until soul shard acquired for demon of choice.
	uint32 m_CurrentCurse;
	uint32 m_botguid;
};

#endif
