#ifndef GAME_SERVER_GAMEMODES_H
#define GAME_SERVER_GAMEMODES_H

#include "gamemodes/ctf.h"
#include "gamemodes/dm.h"
#include "gamemodes/lms.h"
#include "gamemodes/lts.h"
#include "gamemodes/tdm.h"

#include "gamemodes/catch.h"
#include "gamemodes/instagib.h"

#endif

#ifdef REGISTER_GAME_TYPE
REGISTER_GAME_TYPE(tdm, CGameControllerTDM)
#endif