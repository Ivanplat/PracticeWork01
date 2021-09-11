#pragma once
#include <vector>

class InfSystemHandler
{
public:
	explicit InfSystemHandler() noexcept = default;
	virtual ~InfSystemHandler() noexcept = default;
	void CalculateImage(unsigned long long Height, unsigned long long Width, unsigned long long NumOfColours);
	class Students
	{
	public:
		explicit Students(int CountOf5, int CountOf4, int CountOf3, int CountOf2) noexcept : CountOf5(CountOf5), CountOf4(CountOf4), CountOf3(CountOf3), CountOf2(CountOf2)
		{ AllCount = CountOf2 + CountOf3 + CountOf4 + CountOf5; };
		virtual ~Students() noexcept = default;
		float CalculateProbality(int Which)
		{
			switch (Which)
			{
			case 0: return ((float)CountOf2 / (float)AllCount); break;
			case 1: return ((float)CountOf3 / (float)AllCount); break;
			case 2: return ((float)CountOf4 / (float)AllCount); break;
			case 3: return ((float)CountOf5 / (float)AllCount); break;
			}
		}
	private:
		int CountOf5;
		int CountOf4;
		int CountOf3;
		int CountOf2;
		int AllCount;
	};
	void CalculateShenonInfoWeight(Students& Students);
};