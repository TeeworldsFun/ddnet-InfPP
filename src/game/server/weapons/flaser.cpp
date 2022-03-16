
#include "flaser.h"
#include <game/generated/server_data.h>
#include <game/server/entities/laser.h>

bool CFLaser::LaserHit(CLaser *pLaser, vec2 HitPoint, CCharacter *pHit, bool OutOfEnergy)
{
	if(pHit)
	{
		if(pHit->GetPlayer()->GetCID() == pLaser->GetOwner())
			return false;

		pHit->Freeze(2);
        pHit->TakeDamage(vec2(4, 1), 0, pLaser->GetOwner(), pLaser->GetWeaponID(), WEAPON_LASER, false);
        return true;
	}

	return false;
}

void CFLaser::Fire(vec2 Direction)
{
	int ClientID = Character()->GetPlayer()->GetCID();

	new CLaser(
		GameWorld(),
		WEAPON_GUN, //Type
		GetWeaponID(), //WeaponID
		ClientID, //Owner
		Pos(), //Pos
		Direction, //Dir
		g_pData->m_Weapons.m_Laser.m_Reach, // StartEnergy
		CFLaser::LaserHit);

	GameWorld()->CreateSound(Character()->m_Pos, SOUND_LASER_FIRE);
}