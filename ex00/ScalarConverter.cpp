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

void	convertToInt(const std::string input)
{
	//input = "a" [std::string];
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]))) 
	{
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl; // int: 97
		return;
	}
	char *endptr;
	errno = 0;
	double nb = std::strtod(input.c_str(), &endptr); // input = "42.5f" | endptr = 'f' | nb = 42.5

	if(endptr == input.c_str() || !(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0')) // "65" "65f" pass "65abc" "65ff" refusés.
			|| errno == ERANGE ||  nb != nb 
			|| nb <= static_cast<double>(INT_MIN) - 1.0
			|| nb >= static_cast<double>(INT_MAX) + 1.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;

}

static void     convertToChar(const std::string input)
{
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]))) //chek 1 char et pas de char negatif
	{
		if (std::isprint(static_cast<unsigned char>(input[0])))
			std::cout << "char: '" << input[0] << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		return;
	}

	char *endptr;
	errno = 0;
	double nb = std::strtod(input.c_str(), &endptr);

	 if(endptr == input.c_str() || !(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0'))
			 || errno == ERANGE ||  nb != nb 
			 || nb <= static_cast<double>(CHAR_MIN) - 1.0 
			 || nb >= static_cast<double>(CHAR_MAX) + 1.0)
	{
		 std::cout << "char: impossible" << std::endl;
		 return;
	}
	char c = static_cast<char>(nb);
	if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
	else
			std::cout << "char: Non displayable" << std::endl;
}

static void     convertToFloat(const std::string input)
{
	if (input == "nan" || input == "nanf" || input == "NAN" || input == "NaN" || input == "Nan" || input == "NANF" || input == "NaNF")
		return (void)(std::cout << "float: nanf" << std::endl);
	if (input == "+inf" || input == "+inff")
		return(void)(std::cout << "float: +inff" << std::endl);
	if (input == "-inf" || input == "-inff")
		return(void)(std::cout << "float: -inff" << std::endl);
	
	double value;
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		value = static_cast<double>(input[0]);
	else
	{
		char *endptr;
		errno = 0;
		value = std::strtod(input.c_str(), &endptr);

		if(endptr == input.c_str() || !(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0'))
			 || errno == ERANGE ||  value != value 
			 || value < -FLT_MAX || value > FLT_MAX)
			 return (void)(std::cout << "float: impossible" << std::endl);	
	}
	float nb = static_cast<float>(value);
	if (std::floor(nb) == nb)
	{
		std::stringstream os;
		os << std::fixed << std::setprecision(1) << nb;  // fixed Configure os : pas de notation scientifique || Configure os : 1 chiffre après le point
		std::cout << "float: " << os.str() << "f" << std::endl;
	}
	else
		std::cout << "float: " << nb << "f" << std::endl;
}

static void	convertToDouble(const std::string input)
{
	if (input == "nan" || input == "nanf" || input == "NAN" || input == "NaN" || input == "Nan" || input == "NANF" || input == "NaNF")
		return (void)(std::cout << "double: nan" << std::endl);
	if (input == "+inf" || input == "+inff")
		return(void)(std::cout << "double: +inf" << std::endl);
	if (input == "-inf" || input == "-inff")
		return(void)(std::cout << "double: -inf" << std::endl);
	
	double nb;
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		nb = static_cast<double>(input[0]);
	else
	{
		char *endptr;
		errno = 0;
		nb = std::strtod(input.c_str(), &endptr);

		if(endptr == input.c_str() || !(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0'))
			 || errno == ERANGE ||  nb != nb 
			 || nb < -DBL_MAX || nb > DBL_MAX)
			 return (void)(std::cout << "double: impossible" << std::endl);
	}
	if (std::floor(nb) == nb)
	{
		std::stringstream os;
		os << std::fixed << std::setprecision(1) << nb;  // fixed Configure os : pas de notation scientifique || Configure os : 1 chiffre après le point
		std::cout << "double: " << os.str() << std::endl;
	}
	else
		std::cout << "double: " << nb << std::endl;
	

}

void	ScalarConverter::convert(const std::string& input)
{
	convertToChar(input);
	convertToInt(input);
	convertToFloat(input);
	convertToDouble(input);
}



 	/*!(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0'))
						  ⬇
     		!('f' == '\0' || ('f' == 'f' && '\0' == '\0'))
				 		 ⬇
	  	       (false || (true && true))
				 		 ⬇
	     	  	   (false || true)
			 	 		 ⬇
			      	  !(true)
				  		⬇
			      	 (false)*/

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
