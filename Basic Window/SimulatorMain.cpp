#include <Windows.h>
#include "types.h"

#include "SimulatorMain.h"

#include "BasicWindowExport.h"


int main()
{
	int8_t s8RetVal = 0;
	int8_t s8WindowQuitBtn = 0;

	int32_t s32cnt = 0;
	do {

		s8WindowQuitBtn = DrawWindowMain();


	} while (s8WindowQuitBtn != 1);

	return s8RetVal;
}