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
	convertToChar(number);
	convertToInt(number);
	convertToFloat(number);
	convertToDouble(number);
}




/*

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
	if (input.find_first_of(".eE") != std::string::npos) //42e10 42.0 42E2 c good || constante statique membre
		hasDecimal = true;

	if (input.empty() || input.find_first_not_of("0123456789+-.eE") != std::string::npos || (isFloat && !hasDecimal)) //42.0f = good
		return false;

	std::stringstream reader(input);

	if (isFloat) //42.5f
	{
		float value;
		if(!(reader >> value)) // si la lecture du float echoue;
			return false;
		number = static_cast<double>(value);
	}

	else if (hasDecimal) //42.5
	{
		if(!(reader >> value))
			return false;
	}

	
}*/