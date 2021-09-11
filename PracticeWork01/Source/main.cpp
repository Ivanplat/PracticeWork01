#include <iostream>
#include "public/NumberSystemHandler.h"
#include "public/InfSystemHandler.h"

int main()
{
	NumberSystemHandler NSH;
	InfSystemHandler ISH;

	NSH.IntegerToBinary(145, 2);
	NSH.IntegerToBinary(1276, 2);
	NSH.IntegerToBinary(-77, 1);
	NSH.RealToBinary(-446.15625f, 2, 1);
	NSH.RealToBinary(641.0f, 2, 1);
	ISH.CalculateImage(1080, 1920, 16777216);
	InfSystemHandler::Students Students(14, 7, 0, 4);
	ISH.CalculateShenonInfoWeight(Students);

	return 0;
}