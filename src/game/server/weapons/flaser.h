#ifndef GAME_SERVER_WEAPONS_FLASER_H
#define GAME_SERVER_WEAPONS_FLASER_H

#include "lasergun.h"

class CFLaser : public CLaserGun
{
public:
	CFLaser(CCharacter *pOwnerChar) :
		CLaserGun(pOwnerChar) 
    {
	    m_MaxAmmo = 5;
	    m_AmmoRegenTime = 10000;
    	m_FireDelay = 5000;
    	m_FullAuto = false;
    }

	void Fire(vec2 Direction) override;

	// callback
	static bool LaserHit(class CLaser *pLaser, vec2 HitPoint, CCharacter *pHit, bool OutOfEnergy);
};

#endif // GAME_SERVER_WEAPONS_FLASER_H
