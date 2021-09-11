#include "../public/NumberSystemHandler.h"
#include <string>
#include <iostream>

void NumberSystemHandler::IntegerToBinary(int Number, unsigned int BufferSize)
{
	bool Negative = (Number < 0) ? true : false;


	if (Negative)
	{
		Number *= (-1);
	}

	std::string str;

	while (Number > 0)
	{
		str += std::to_string((Number % 2));
		Number /= 2;
	}
	int Steps = BufferSize * 8 - str.size();
	if (Steps > 0)
	{
		for (int i = 0; i < Steps; i++)
		{
			str.push_back('0');
		}
	}
	std::reverse(str.begin(), str.end());
	if (Negative)
	{
		str[0] = '1';
	}

	std::cout << str<<std::endl;
}

void NumberSystemHandler::RealToBinary(float Number, unsigned int MantiseSize, unsigned int OrderSize)
{
	bool Negative = (Number < 0) ? true : false;


	if (Negative)
	{
		Number *= (-1);
	}

	float IntergerPartPtr;
	float FactionalPart = std::modf(Number, &IntergerPartPtr);
	int IntergerPart = (int)IntergerPartPtr;
	int Mantise = 0;
	if (IntergerPart == 0)
	{
		for (const auto i : std::to_string(FactionalPart))
		{
			Mantise++;
			if (i != '0')
			{
				Mantise *= (-1);
				break;
			}
		}
	}
	else
	{
		Mantise = std::to_string(IntergerPart).size();
	}

	std::string str;
	if (IntergerPart > 0)
	{
		while (IntergerPart > 0)
		{
			str += std::to_string((IntergerPart % 2));
			IntergerPart /= 2;
		}
	}
	else
	{
		str.push_back('0');
		str.push_back('0');
	}
	std::reverse(str.begin(), str.end());
	str.push_back(',');
	if (FactionalPart > 0)
	{
		while (FactionalPart > 0)
		{
			FactionalPart *= 2;
			if (FactionalPart >= 1)
			{
				str.push_back('1');
				FactionalPart -= 1.0f;
			}
			else
			{
				str.push_back('0');
			}
		}
		int Steps = MantiseSize * 8 - str.size();
		if (Steps > 0)
		{
			for (int i = 0; i < Steps; i++)
			{
				str.insert(str.begin(), '0');
			}
		}
		if (Negative)
		{
			str[0] = '1';
		}
	}
	else
	{
		str.push_back('0');
	}

	std::string mantstr;
	bool NegativeMantise = (Mantise < 0) ? true : false;
	if (NegativeMantise)
	{
		Mantise *= (-1);
	}
	while (Mantise > 0)
	{
		mantstr += std::to_string(Mantise % 2);
		Mantise /= 2;
	}
	int OrderSteps = OrderSize*8 - mantstr.size();
	if (OrderSteps > 0)
	{
		for (int i = 0; i < OrderSteps; i++)
		{
			mantstr.push_back('0');
		}
	}
	std::reverse(mantstr.begin(), mantstr.end());
	if (NegativeMantise)
	{
		mantstr[0] = '1';
	}
	std::string result = mantstr + " " + str;
	std::cout << result<<std::endl;

}
