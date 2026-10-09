NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = main.o ScalarConverter.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

main.o: main.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


ScalarConverter.o: ScalarConverter.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -c ScalarConverter.cpp -o ScalarConverter.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re