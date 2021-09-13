#include "../public/NumberSystemHandler.h"
#include <string>
#include <iostream>

void NumberSystemHandler::IntegerToBinary(int Number, unsigned int BufferSize, bool Additional)
{
	bool Negative = (Number < 0) ? true : false;


	if (Negative)
	{
		Number *= (-1);
	}

	std::string str;

	ToBinary(Number, str);

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
		if (Additional)
		{

			ToAdditional(str);
		}
	}

	std::cout << str << std::endl;

}


void NumberSystemHandler::RealToBinary(float Number, unsigned int MantiseSize, unsigned int OrderSize, bool Additional)
{
	bool Negative = (Number < 0) ? true : false;


	if (Negative)
	{
		Number *= (-1);
	}

	float IntergerPartPtr;
	float FactionalPart = std::modf(Number, &IntergerPartPtr);
	int IntergerPart = (int)IntergerPartPtr;
	int OrderPow = 0;
	if (IntergerPart == 0)
	{
		for (const auto i : std::to_string(FactionalPart))
		{
			OrderPow++;
			if (i != '0')
			{
				OrderPow *= (-1);
				break;
			}
		}
	}
	else
	{
		OrderPow = std::to_string(IntergerPart).size();
	}

	std::string str;
	if (IntergerPart > 0)
	{
		ToBinary(IntergerPart, str);
	}
	else
	{
		str.push_back('0');
		str.push_back('0');
	}
	std::reverse(str.begin(), str.end());
	if (Additional && Negative)
	{
		ToAdditional(str);
	}
	str.push_back(',');
	std::string fpstr;
	if (FactionalPart > 0)
	{
		while (FactionalPart > 0)
		{
			FactionalPart *= 2;
			if (FactionalPart >= 1)
			{
				fpstr.push_back('1');
				FactionalPart -= 1.0f;
			}
			else
			{
				fpstr.push_back('0');
			}
		}
		if (Additional && Negative)
		{
			ToAdditional(fpstr);
		}
		str += fpstr;
		int Steps = MantiseSize * 8 - str.size();
		if (Steps > 0)
		{
			if (Additional && Negative)
			{
				for (int i = 0; i < Steps; i++)
				{
					str.insert(str.begin(), '1');
				}
			}
			else
			{
				for (int i = 0; i < Steps; i++)
				{
					str.insert(str.begin(), '0');
				}
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

	std::string ordstr;
	bool NegativePow = (OrderPow < 0) ? true : false;
	if (NegativePow)
	{
		OrderPow *= (-1);
	}
	ToBinary(OrderPow, ordstr);

	int OrderSteps = OrderSize*8 - ordstr.size();
	if (OrderSteps > 0)
	{
		for (int i = 0; i < OrderSteps; i++)
		{
			ordstr.push_back('0');
		}
	}
	std::reverse(ordstr.begin(), ordstr.end());
	if (NegativePow)
	{
		ordstr[0] = '1';
	}
	if (Additional && Negative)
	{
		ToAdditional(ordstr);
	}
	std::string result = ordstr + " " + str;
	std::cout << result<<std::endl;

}

void NumberSystemHandler::ToBinary(int& Number, std::string& Output)
{
	while (Number > 0)
	{
		Output += std::to_string((Number % 2));
		Number /= 2;
	}
}

void NumberSystemHandler::ToAdditional(std::string& NumberString)
{
	for (int i = 1; i < NumberString.size(); i++)
	{
		int n = -(NumberString[i] - '0') + 1;
		NumberString[i] = std::to_string(n)[0];
	}
	if (NumberString[NumberString.size() - 1] == '1')
	{
		for (int j = NumberString.size() - 1; j > 0; j--)
		{
			if (NumberString[j] == '1')
			{
				NumberString[j] = '0';
			}
			else
			{
				NumberString[j] = '1';
				break;
			}
		}
	}
	else
	{
		NumberString[NumberString.size() - 1] = '1';
	}
}
