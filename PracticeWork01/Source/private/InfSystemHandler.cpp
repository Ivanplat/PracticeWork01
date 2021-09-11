#include <iostream>
#include "../public/InfSystemHandler.h"


void InfSystemHandler::CalculateImage(unsigned long long Height, unsigned long long Width, unsigned long long NumOfColours)
{
	std::cout << Height * Width * NumOfColours<<std::endl;
}

void InfSystemHandler::CalculateShenonInfoWeight(Students& Students)
{
	float Weight = 0;
	for (int i = 0; i < 4; i++)
	{
		float Probality = Students.CalculateProbality(i);
		if (Probality > 0.0f)
		{
			Weight += -(Students.CalculateProbality(i) * log2(Probality));
		}
	}
	std::cout << Weight << std::endl;
}