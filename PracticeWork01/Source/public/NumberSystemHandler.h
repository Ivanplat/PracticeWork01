#pragma once

class NumberSystemHandler
{
public:
	explicit NumberSystemHandler() noexcept = default;
	virtual ~NumberSystemHandler() noexcept = default;
	void IntegerToBinary(int Number, unsigned int BufferSize);
	void RealToBinary(float Number, unsigned int MantiseSize, unsigned int OrderSize);
};