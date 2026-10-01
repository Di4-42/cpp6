#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	(void)source;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& source)
{
	(void)source;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(const std::string& input)
{
	double number;
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		number = static_cast<double>(input[0]);
	convertToChar(number);
	convertToInt(number);
	convertToFloat(number);
	convertToDouble(number);
}
