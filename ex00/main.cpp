#include "ScalarConverter.hpp"

int main()
{
    std::cout << "\nTest : a" << std::endl;
    ScalarConverter::convert("a");

    std::cout << "\nTest : 65" << std::endl;
    ScalarConverter::convert("65");

    std::cout << "\nTest : 42.5f" << std::endl;
    ScalarConverter::convert("42.5f");

    std::cout << "\nTest : -12.8" << std::endl;
    ScalarConverter::convert("-12.8");

    std::cout << "\nTest : INT_MAX" << std::endl;
    ScalarConverter::convert("2147483647");

    std::cout << "\nTest : INT_MAX + 0.9" << std::endl;
    ScalarConverter::convert("2147483647.9");

    std::cout << "\nTest : INT_MIN" << std::endl;
    ScalarConverter::convert("-2147483648");

    std::cout << "\nTest : INT_MIN - 0.9" << std::endl;
    ScalarConverter::convert("-2147483648.9");

    std::cout << "\nTest : nan" << std::endl;
    ScalarConverter::convert("nan");

    std::cout << "\nTest : erreur ERANGE" << std::endl;
    ScalarConverter::convert("1e9999");

    std::cout << "\nTest : suffixe invalide" << std::endl;
    ScalarConverter::convert("42ff");

    std::cout << "\nTest : texte invalide" << std::endl;
    ScalarConverter::convert("abc");

    std::cout << "\nTest : chaine vide" << std::endl;
    ScalarConverter::convert("");

    return 0;
}