#include <Windows.h>
#include "types.h"

#include "SimulatorMain.h"

#include "BasicWindowExport.h"


int main()
{
	int8_t s8RetVal = 0;

	int32_t s32cnt = 0;
	do {

		ViewreMain();

		s32cnt++;
	} while (s32cnt < 1000000);

	return s8RetVal;
}