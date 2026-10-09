#pragma once

#include <iostream>
#include <string>
#include <climits>
#include <cerrno>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& source);
        ScalarConverter& operator=(const ScalarConverter& source);
        ~ScalarConverter();
    
    public:
        static void convert(const std::string& input);

};
