#ifndef _PlayerbotMageAI_H
#define _PlayerbotMageAI_H
#define  ManaAgate 5514
#define  ManaJade 5513
#define  ManaCitrine 8007
#define  ManaRuby 8008
#include "PlayerbotClassAI.h"

enum
{
    SPELL_FROST,
    SPELL_FIRE,
    SPELL_ARCANE
};

enum ManaStoneDisplayId
{
	
	ManaAgateSTONE_DISPLAYID = 6851,
	ManaJadeSTONE_DISPLAYID  = 7393,
	ManaCitrineSTONE_DISPLAYID  = 6496,
	ManaRubySTONE_DISPLAYID  = 7045


};

enum MageSpells
{
    AMPLIFY_MAGIC_1                 = 1008,
    ARCANE_BRILLIANCE_1             = 23028,
    ARCANE_EXPLOSION_1              = 1449,
    ARCANE_INTELLECT_1              = 1459,
    ARCANE_MISSILES_1               = 5143,
    ARCANE_POWER_1                  = 12042,
    BLAST_WAVE_1                    = 11113,
    BLINK_1                         = 1953,
    BLIZZARD_1                      = 10,
    COLD_SNAP_1                     = 12472,
    COMBUSTION_1                    = 11129,
    CONE_OF_COLD_1                  = 120,
    CONJURE_FOOD_1                  = 587,
    CONJURE_MANA_GEM_1              = 759,
	CONJURE_MANA_GEM_2              = 3552,
	CONJURE_MANA_GEM_3              = 10053,
	CONJURE_MANA_GEM_4              = 10054,
    CONJURE_WATER_1                 = 5504,
    COUNTERSPELL_1                  = 2139,
    DAMPEN_MAGIC_1                  = 604,
    EVOCATION_1                     = 12051,
    FIRE_BLAST_1                    = 2136,
    FIRE_WARD_1                     = 543,
    FIREBALL_1                      = 133,
    FLAMESTRIKE_1                   = 2120,
    FROST_ARMOR_1                   = 168,
    FROST_NOVA_1                    = 122,
    FROST_WARD_1                    = 6143,
    FROSTBOLT_1                     = 116,
    ICE_ARMOR_1                     = 7302,
    ICE_BARRIER_1                   = 11426,
    ICE_BLOCK_1                     = 11958,
    MAGE_ARMOR_1                    = 6117,
    MANA_SHIELD_1                   = 1463,
	Polymorph_1	                    = 118,
    PRESENCE_OF_MIND_1              = 12043,
    PYROBLAST_1                     = 11366,
    REMOVE_CURSE_MAGE_1             = 475,
    SCORCH_1                        = 2948,
    SHOOT_2                         = 5019,
    SLOW_FALL_1                     = 130
};
//class Player;

class MANGOS_DLL_SPEC PlayerbotMageAI : PlayerbotClassAI
{
public:
    PlayerbotMageAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
    virtual ~PlayerbotMageAI();

    // all combat actions go here
    CombatManeuverReturns DoFirstCombatManeuver(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuver(Unit* pTarget);

    // all non combat actions go here, ex buffs, heals, rezzes
    void DoNonCombatActions();

private:
    CombatManeuverReturns DoFirstCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoFirstCombatManeuverPVP(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVP(Unit* pTarget);
	CombatManeuverReturns HealPlayer(Player* target);


    CombatManeuverReturns CastSpell(uint32 nextAction, Unit *pTarget = nullptr) { return CastSpellWand(nextAction, pTarget, SHOOT); }


    static bool BuffHelper(PlayerbotAI* ai, uint32 spellId, Unit *target);

    // ARCANE
    uint32 ARCANE_MISSILES,
           ARCANE_EXPLOSION,
           COUNTERSPELL,
           ARCANE_POWER,
		   CONJURE_MANA_GEM,
		   CONJURE_MANA_JADE,
		   CONJURE_MANA_CITRINE,
		   Conjure_MANA_RUBY,
		   EVOCATION,
		   Polymorph,
	       Remove_Lesser_Curse,
		   PRESENCE_OF_MIND;
    // RANGED
    uint32 SHOOT;

    // FIRE
    uint32 FIREBALL,
           FIRE_BLAST,
           FLAMESTRIKE,
           SCORCH,
           PYROBLAST,
           BLAST_WAVE,
           COMBUSTION,           
           FIRE_WARD;

    // FROST
    uint32 FROSTBOLT,
           FROST_NOVA,
           BLIZZARD,
           CONE_OF_COLD,
           ICE_BARRIER,
           FROST_WARD,
           ICE_BLOCK,
           COLD_SNAP;

    // buffs
    uint32 FROST_ARMOR,
           ICE_ARMOR,
           MAGE_ARMOR,
           ARCANE_INTELLECT,
           ARCANE_BRILLIANCE,
           MANA_SHIELD,
           DAMPEN_MAGIC,
           AMPLIFY_MAGIC;

    // racial
    uint32 STONEFORM,
           ESCAPE_ARTIST,
		   PERCEPTION,
           SHADOWMELD,
           BLOOD_FURY,
           WAR_STOMP,
           BERSERKING,
           WILL_OF_THE_FORSAKEN;

	uint32 CONJURE_WATER,
		   CONJURE_FOOD,
		   SpellSequence,
		   SpellSequence1,
		   LastSpellArcane,
		   LastSpellFire,
		   LastSpellFrost;
};

#endif
