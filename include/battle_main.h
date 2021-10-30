#ifndef GUARD_BATTLE_MAIN_H
#define GUARD_BATTLE_MAIN_H

struct TrainerMoney
{
    u8 classId;
    u8 value;
};

struct TrainerBall
{
    u8 classId;
    u8 Ball;
};

const struct TrainerBall gTrainerBallTable[] = {
    {TRAINER_CLASS_TEAM_AQUA, ITEM_NET_BALL},
    {TRAINER_CLASS_AQUA_ADMIN, ITEM_NET_BALL},
    {TRAINER_CLASS_AQUA_LEADER, ITEM_MASTER_BALL},
    {TRAINER_CLASS_AROMA_LADY, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_RUIN_MANIAC, ITEM_DUSK_BALL},
    {TRAINER_CLASS_INTERVIEWER, ITEM_REPEAT_BALL},
    {TRAINER_CLASS_TUBER_F, ITEM_DIVE_BALL},
    {TRAINER_CLASS_TUBER_M, ITEM_DIVE_BALL},
    {TRAINER_CLASS_SIS_AND_BRO, ITEM_POKE_BALL},
    {TRAINER_CLASS_COOLTRAINER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_HEX_MANIAC, ITEM_DUSK_BALL},
    {TRAINER_CLASS_LADY, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_BEAUTY, ITEM_LOVE_BALL},
    {TRAINER_CLASS_RICH_BOY, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_POKEMANIAC, ITEM_MOON_BALL},
    {TRAINER_CLASS_SWIMMER_M, ITEM_DIVE_BALL},
    {TRAINER_CLASS_BLACK_BELT, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_GUITARIST, ITEM_FAST_BALL},
    {TRAINER_CLASS_KINDLER, ITEM_POKE_BALL},
    {TRAINER_CLASS_CAMPER, ITEM_NEST_BALL},
    {TRAINER_CLASS_OLD_COUPLE, ITEM_POKE_BALL},
    {TRAINER_CLASS_BUG_MANIAC, ITEM_NET_BALL},
    {TRAINER_CLASS_PSYCHIC, ITEM_DREAM_BALL},
    {TRAINER_CLASS_GENTLEMAN, ITEM_LUXURY_BALL},
    {TRAINER_CLASS_ELITE_FOUR, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_LEADER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_SCHOOL_KID, ITEM_POKE_BALL},
    {TRAINER_CLASS_SR_AND_JR, ITEM_POKE_BALL},
    {TRAINER_CLASS_POKEFAN, ITEM_POKE_BALL},
    {TRAINER_CLASS_EXPERT, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_YOUNGSTER, ITEM_POKE_BALL},
    {TRAINER_CLASS_CHAMPION, ITEM_CHERISH_BALL},
    {TRAINER_CLASS_FISHERMAN, ITEM_LURE_BALL},
    {TRAINER_CLASS_TRIATHLETE, ITEM_FAST_BALL},
    {TRAINER_CLASS_DRAGON_TAMER, ITEM_ULTRA_BALL},
    {TRAINER_CLASS_BIRD_KEEPER, ITEM_QUICK_BALL},
    {TRAINER_CLASS_NINJA_BOY, ITEM_QUICK_BALL},
    {TRAINER_CLASS_BATTLE_GIRL, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_PARASOL_LADY, ITEM_POKE_BALL},
    {TRAINER_CLASS_SWIMMER_F, ITEM_DIVE_BALL},
    {TRAINER_CLASS_PICNICKER, ITEM_FRIEND_BALL},
    {TRAINER_CLASS_TWINS, ITEM_POKE_BALL},
    {TRAINER_CLASS_SAILOR, ITEM_DIVE_BALL},
    {TRAINER_CLASS_COLLECTOR, ITEM_REPEAT_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_3, ITEM_PREMIER_BALL},
    {TRAINER_CLASS_PKMN_BREEDER, ITEM_TIMER_BALL},
    {TRAINER_CLASS_PKMN_RANGER, ITEM_SAFARI_BALL},
    {TRAINER_CLASS_TEAM_MAGMA, ITEM_NEST_BALL},
    {TRAINER_CLASS_MAGMA_ADMIN, ITEM_NEST_BALL},
    {TRAINER_CLASS_MAGMA_LEADER, ITEM_MASTER_BALL},
    {TRAINER_CLASS_LASS, ITEM_POKE_BALL},
    {TRAINER_CLASS_BUG_CATCHER, ITEM_NET_BALL},
    {TRAINER_CLASS_HIKER, ITEM_HEAVY_BALL},
    {TRAINER_CLASS_YOUNG_COUPLE, ITEM_LOVE_BALL},
    {TRAINER_CLASS_WINSTRATE, ITEM_GREAT_BALL},
    {TRAINER_CLASS_PKMN_TRAINER_2, ITEM_HEAVY_BALL},
    {0xFF, ITEM_POKE_BALL},
};

// For displaying a multi battle partner's Pokémon in the party menu
struct MultiPartnerMenuPokemon
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 heldItem;
    /*0x04*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0F*/ u8 level;
    /*0x10*/ u16 hp;
    /*0x12*/ u16 maxhp;
    /*0x14*/ u32 status;
    /*0x18*/ u32 personality;
    /*0x1C*/ u8 gender;
    /*0x1D*/ u8 language;
};

#define TYPE_NAME_LENGTH 6
#define ABILITY_NAME_LENGTH 12

// defines for the u8 array gTypeEffectiveness
#define TYPE_EFFECT_ATK_TYPE(i)((gTypeEffectiveness[i + 0]))
#define TYPE_EFFECT_DEF_TYPE(i)((gTypeEffectiveness[i + 1]))
#define TYPE_EFFECT_MULTIPLIER(i)((gTypeEffectiveness[i + 2]))

// defines for the gTypeEffectiveness multipliers
#define TYPE_MUL_NO_EFFECT          0
#define TYPE_MUL_NOT_EFFECTIVE      5
#define TYPE_MUL_NORMAL             10
#define TYPE_MUL_SUPER_EFFECTIVE    20

// special type table Ids
#define TYPE_FORESIGHT  0xFE
#define TYPE_ENDTABLE   0xFF

// defines for the 'DoBounceEffect' function
#define BOUNCE_MON          0x0
#define BOUNCE_HEALTHBOX    0x1

void CB2_InitBattle(void);
void BattleMainCB2(void);
void CB2_QuitRecordedBattle(void);
void VBlankCB_Battle(void);
void SpriteCB_VsLetterDummy(struct Sprite *sprite);
void SpriteCB_VsLetterInit(struct Sprite *sprite);
void CB2_InitEndLinkBattle(void);
u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId);
u32 GetBattleWindowTemplatePixelWidth(u32 setId, u32 tableId);
void SpriteCb_WildMon(struct Sprite *sprite);
void SpriteCallbackDummy_2(struct Sprite *sprite);
void SpriteCB_FaintOpponentMon(struct Sprite *sprite);
void SpriteCb_ShowAsMoveTarget(struct Sprite *sprite);
void SpriteCb_HideAsMoveTarget(struct Sprite *sprite);
void SpriteCB_OpponentMonFromBall(struct Sprite *sprite);
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite);
void SpriteCB_FaintSlideAnim(struct Sprite *sprite);
void DoBounceEffect(u8 battlerId, u8 b, s8 c, s8 d);
void EndBounceEffect(u8 battlerId, bool8 b);
void SpriteCB_PlayerMonFromBall(struct Sprite *sprite);
void SpriteCB_TrainerThrowObject(struct Sprite *sprite);
void sub_8039E9C(struct Sprite *sprite);
void BeginBattleIntroDummy(void);
void BeginBattleIntro(void);
void SwitchInClearSetData(void);
void FaintClearSetData(void);
void BattleTurnPassed(void);
u8 IsRunningFromBattleImpossible(void);
void SwitchPartyOrder(u8 battlerId);
void SwapTurnOrder(u8 id1, u8 id2);
u8 GetWhoStrikesFirst(u8 battlerId1, u8 battlerId2, bool8 ignoreChosenMoves);
void RunBattleScriptCommands_PopCallbacksStack(void);
void RunBattleScriptCommands(void);
bool8 TryRunFromBattle(u8 battlerId);
void SpecialStatusesClear(void);

extern struct MultiPartnerMenuPokemon gMultiPartnerParty[MULTI_PARTY_SIZE];

extern const struct SpriteTemplate gUnusedBattleInitSprite;
extern const struct OamData gOamData_BattleSpriteOpponentSide;
extern const struct OamData gOamData_BattleSpritePlayerSide;
extern const u8 gTypeEffectiveness[336];
extern const u8 gTypeNames[NUMBER_OF_MON_TYPES][TYPE_NAME_LENGTH + 1];
extern const struct TrainerMoney gTrainerMoneyTable[];
extern const u8 gAbilityNames[][ABILITY_NAME_LENGTH + 1];
extern const u8 *const gAbilityDescriptionPointers[];

extern const u8 gStatusConditionString_PoisonJpn[8];
extern const u8 gStatusConditionString_SleepJpn[8];
extern const u8 gStatusConditionString_ParalysisJpn[8];
extern const u8 gStatusConditionString_BurnJpn[8];
extern const u8 gStatusConditionString_IceJpn[8];
extern const u8 gStatusConditionString_ConfusionJpn[8];
extern const u8 gStatusConditionString_LoveJpn[8];

extern const u8 *const gStatusConditionStringsTable[7][2];

#endif // GUARD_BATTLE_MAIN_H
