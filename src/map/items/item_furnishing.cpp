/*
===========================================================================

  Copyright (c) 2010-2015 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#include "item_furnishing.h"
#include "../map.h"

CItemFurnishing::CItemFurnishing(uint16 id) : CItem(id)
{
	setType(ITEM_FURNISHING);

	m_storage      = 0;
	m_moghancement = 0;
	m_element      = 0;
	m_aura         = 0;
}

CItemFurnishing::~CItemFurnishing()
{
}

void CItemFurnishing::setInstalled(bool installed)
{
    if (installed)
        WBUFB(m_extra, 0x01) |= 0x40;
    else
        WBUFB(m_extra, 0x01) &= ~0x40;
}

bool CItemFurnishing::isInstalled()
{
    return WBUFB(m_extra, 0x01) & 0x40;
}

void CItemFurnishing::setStorage(uint8 storage)
{
	m_storage = dsp_min(storage,80);
}

uint8 CItemFurnishing::getStorage()
{
	return m_storage;
}

void CItemFurnishing::setMoghancement(uint8 moghancement)
{
	m_moghancement = moghancement;
}

uint8 CItemFurnishing::getMoghancement()
{
	return m_moghancement;
}

void CItemFurnishing::setElement(uint8 element)
{
	m_element = element;
}

uint8 CItemFurnishing::getElement()
{
	return m_element;
}

void CItemFurnishing::setAura(uint8 aura)
{
	m_aura = aura;
}

uint8 CItemFurnishing::getAura()
{
	return m_aura;
}

void CItemFurnishing::setCol(uint8 col)
{
	WBUFB(m_extra, 0x06) = col;
}
	
uint8 CItemFurnishing::getCol()
{
    return RBUFB(m_extra, 0x06);
}

void CItemFurnishing::setRow(uint8 row)
{
    WBUFB(m_extra, 0x08) = row;
}

uint8 CItemFurnishing::getRow()
{
    return RBUFB(m_extra, 0x08);
}

void CItemFurnishing::setLevel(uint8 level)
{
    WBUFB(m_extra, 0x07) = level;
}

uint8 CItemFurnishing::getLevel()
{
    return RBUFB(m_extra, 0x07);
}

void CItemFurnishing::setRotation(uint8 rotation)
{
    WBUFB(m_extra, 0x09) = rotation;
}

uint8 CItemFurnishing::getRotation()
{
    return RBUFB(m_extra, 0x09);
}