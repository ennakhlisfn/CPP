NAME = UnnecessaryViolence
SRC= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ=$(SRC:.cpp=.o)
CCPP = c++ #-fsanitize=address -g
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME) : $(OBJ)
	$(CCPP) $(CPPFLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CCPP) $(CPPFLAGS) -c $? -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.SECONDARY : $(OBJ)