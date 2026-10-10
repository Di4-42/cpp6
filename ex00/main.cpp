#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac < 2) {
        std::cout << "Input cannot be empty" << std::endl; return 1;
    }
    ScalarConverter::convert(av[1]);
    // std::cout << "\nCaractere : a" << std::endl;
    // ScalarConverter::convert("a");

    // std::cout << "\nEntier : 42" << std::endl;
    // ScalarConverter::convert("42");

    // std::cout << "\nDecimal : 42.5" << std::endl;
    // ScalarConverter::convert("42.5");

    // std::cout << "\nSuffixe f : 42.5f" << std::endl;
    // ScalarConverter::convert("42.5f");

    // std::cout << "\nNegatif : -12.8" << std::endl;
    // ScalarConverter::convert("-12.8");

    // std::cout << "\nNon affichable : 0" << std::endl;
    // ScalarConverter::convert("0");

    // std::cout << "\nNaN" << std::endl;
    // ScalarConverter::convert("nan");
    // ScalarConverter::convert("nanf");

    // std::cout << "\nInfini positif" << std::endl;
    // ScalarConverter::convert("+inf");
    // ScalarConverter::convert("+inff");

    // std::cout << "\nInfini negatif" << std::endl;
    // ScalarConverter::convert("-inf");
    // ScalarConverter::convert("-inff");

    // std::cout << "\nHors limites float : 1e39" << std::endl;
    // ScalarConverter::convert("1e39");
    // ScalarConverter::convert("-1e39");

    // std::cout << "\nErreur de plage : 1e9999" << std::endl;
    // ScalarConverter::convert("1e9999");

    // std::cout << "\nEntrees invalides" << std::endl;
    // ScalarConverter::convert("abc");
    // ScalarConverter::convert("42ff");
    // ScalarConverter::convert("");

    // return 0;
}