#pragma once
#include <string>
#include <vector>

class NumberSystemHandler
{
public:
	explicit NumberSystemHandler() noexcept = default;
	virtual ~NumberSystemHandler() noexcept = default;
	void IntegerToBinary(int Number, unsigned int BufferSize, bool Additional = true);
	void RealToBinary(float Number, unsigned int MantiseSize, unsigned int OrderSize, bool Additional = true);
private:
	void ToBinary(int& Number, std::string& Output);
	void ToAdditional(std::string& NumberString);
};