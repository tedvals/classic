#ifndef _PLAYERBOTPRIESTAI_H
#define _PLAYERBOTPRIESTAI_H

#include "PlayerbotClassAI.h"

enum
{
    SPELL_HOLY,
    SPELL_SHADOWMAGIC,
    SPELL_DISCIPLINE
};

enum PriestSpells
{
    ABOLISH_DISEASE_1               = 552,    
    BLESSED_HEALING_1               = 70772,    
    CURE_DISEASE_1                  = 528,
    DESPERATE_PRAYER_1              = 19236,
    DEVOURING_PLAGUE_1              = 2944,
    DISPEL_MAGIC_1                  = 527,        
    DIVINE_SPIRIT_1                 = 14752,
	ELUNES_GRACE_1                  = 2651,
    FADE_1                          = 586,
    FEAR_WARD_1                     = 6346,
    FLASH_HEAL_1                    = 2061,
    GREATER_HEAL_1                  = 2060,
    HEAL_1                          = 6064,
    HOLY_FIRE_1                     = 14914,
    HOLY_NOVA_1                     = 15237,    
    INNER_FIRE_1                    = 588,
    INNER_FOCUS_1                   = 14751,
    LESSER_HEAL_1                   = 2050,
    LEVITATE_1                      = 1706,
    LIGHTWELL_1                     = 724,
    MANA_BURN_1                     = 8129,    
    MIND_BLAST_1                    = 8092,
    MIND_CONTROL_1                  = 605,
    MIND_FLAY_1                     = 15407,
    MIND_SOOTHE_1                   = 453,
    MIND_VISION_1                   = 2096,
    PAIN_SUPPRESSION_1              = 33206,
    POWER_INFUSION_1                = 10060,
    POWER_WORD_FORTITUDE_1          = 1243,
    POWER_WORD_SHIELD_1             = 17,
    PRAYER_OF_FORTITUDE_1           = 21562,
    PRAYER_OF_HEALING_1             = 596,    
    PRAYER_OF_SHADOW_PROTECTION_1   = 27683,
    PRAYER_OF_SPIRIT_1              = 27681,    
    PSYCHIC_SCREAM_1                = 8122,
    RENEW_1                         = 139,
    RESURRECTION_1                  = 2006,
    SHACKLE_UNDEAD_1                = 9484,
    SHADOW_PROTECTION_1             = 976,    
    SHADOW_WORD_PAIN_1              = 589,    
    SHADOWFORM_1                    = 15473,
    SHOOT_1                         = 5019,
    SILENCE_1                       = 15487,
    SMITE_1                         = 585,
	Touch_of_Weakness_1             =2652,
    VAMPIRIC_EMBRACE_1              = 15286,    
	WEAKNED_SOUL                    = 6788
};
//class Player;

class MANGOS_DLL_SPEC PlayerbotPriestAI : PlayerbotClassAI
{
public:
    PlayerbotPriestAI(Player * const master, Player * const bot, PlayerbotAI * const ai);
    virtual ~PlayerbotPriestAI();

    // all combat actions go here
    CombatManeuverReturns DoFirstCombatManeuver(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuver(Unit* pTarget);

    // all non combat actions go here, ex buffs, heals, rezzes
    void DoNonCombatActions();

    // Utility Functions
    bool CastHoTOnTank();

private:
    CombatManeuverReturns DoFirstCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVE(Unit* pTarget);
    CombatManeuverReturns DoFirstCombatManeuverPVP(Unit* pTarget);
    CombatManeuverReturns DoNextCombatManeuverPVP(Unit* pTarget);


    CombatManeuverReturns CastSpell(uint32 nextAction, Unit *pTarget = nullptr) { return CastSpellWand(nextAction, pTarget, SHOOT); }


    // Heals the target based off its hps
    CombatManeuverReturns HealPlayer(Player* target);

    static bool BuffHelper(PlayerbotAI* ai, uint32 spellId, Unit *target);

    // holy
	uint32 
		CLEARCASTING,
		DESPERATE_PRAYER,
		FLASH_HEAL,
		GREATER_HEAL,
		HEAL,
		HOLY_FIRE,
		HOLY_NOVA,
		LESSER_HEAL,
		MANA_BURN,
		PRAYER_OF_HEALING,		
		RENEW,
		RESURRECTION,
		SMITE,
		CURE_DISEASE,
		DISPEL_MAGI,
		ABOLISH_DISEASE;
           
    // ranged
    uint32 SHOOT;

    // shadowmagic
	uint32 FADE,
		SHADOW_WORD_PAIN,
		MIND_BLAST,
		SCREAM,
		MIND_FLAY,
		DEVOURING_PLAGUE,
		SHADOW_PROTECTION,		
		PRAYER_OF_SHADOW_PROTECTION,				
		SHADOWFORM,
		VAMPIRIC_EMBRACE,
		SHACKLE_UNDEAD,
		Touch_of_Weakness;
    // discipline
    uint32 POWER_WORD_SHIELD,
           INNER_FIRE,
           POWER_WORD_FORTITUDE,
           PRAYER_OF_FORTITUDE,
           FEAR_WARD,
           POWER_INFUSION,
           MASS_DISPEL,           
           DIVINE_SPIRIT,
           PRAYER_OF_SPIRIT,
           INNER_FOCUS;

    // racial
    uint32 STONEFORM,
		   ELUNES_GRACE,
           ESCAPE_ARTIST,
           PERCEPTION,
           SHADOWMELD,
           WAR_STOMP,
           BERSERKING,
           WILL_OF_THE_FORSAKEN;
};

#endif