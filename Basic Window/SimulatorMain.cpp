#include "types.h"

#include "SimulatorMain.h"
#include "SimulatorMainExport.h"


int main()
{
	int8_t s8RetVal = 0;

	int32_t s32cnt = 0;
	do {

		s32cnt++;
	} while (s32cnt < 1000);

	return s8RetVal;
}