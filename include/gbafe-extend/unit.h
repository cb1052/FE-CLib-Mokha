#pragma once

#define UNIT_VAILD_MOKHA_JUDGE(aUnit)	( 0x202B000 != (0x202B000 & (uint32_t)aUnit) )

struct UnitDefinition* GetChapterAllyUnitDataPointer(); // FE8U 0x08083349
int CountForceDeployedUnits(void); // FE8U 809541C


