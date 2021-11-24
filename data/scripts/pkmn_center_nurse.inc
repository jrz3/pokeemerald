Common_EventScript_PkmnCenterNurse::
    lock
    faceplayer
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_HealPkmn::
    incrementgamestat GAME_STAT_USED_POKECENTER
    call EventScript_PkmnCenterNurse_IllTakeYourPkmn
    @    waitmessage
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn
    goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
    goto EventScript_PkmnCenterNurse_ReturnPkmn
    end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	return

EventScript_PkmnCenterNurse_ReturnPkmn::
    waitmessage
    applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
    waitmovement 0
    goto EventScript_PkmnCenterNurse_PlayerTurn
    return

EventScript_PkmnCenterNurse_CheckPokerus::
    specialvar VAR_RESULT, IsPokerusInParty
    compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_ExplainPokerus
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_PlayerTurn::
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    release
    end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end
