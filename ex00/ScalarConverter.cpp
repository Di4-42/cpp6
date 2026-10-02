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

static void	impossible()
{}

static bool	special(std::string input)
{
}

static bool	readNumber(std::string input, double& number)
{
	bool	isFloat = false;
	bool	hasDecimal = false;

	if (input.empty())
		return false;
	if (input[input.size() - 1] == 'f')
	{
		isFloat = true;
		input.erase(input.size() - 1);
	}


}

static void     convertToChar(double number)
{
	std::cout << "char: ";
}

static void     convertToInt(double number)
{
	std::cout << "int: ";
}

static void     convertToFloat(double number)
{
	std::cout << "float: ";
}

static void	convertToDouble(double number)
{
	std::cout << "double: ";
}

void	ScalarConverter::convert(const std::string& input)
{
	if (special(input))
		return;
	double number;
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		number = static_cast<double>(input[0]);
	else if (!readNumber(input, number))
	{
		impossible();
		return;
	}
	convertToChar(number);
	convertToInt(number);
	convertToFloat(number);
	convertToDouble(number);
}
