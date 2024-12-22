NAME = hordeZombie
SRC= Zombie.cpp zombieHorde.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
CCPP = c++ -fsanitize=address -g
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

re : clear fclean all

clear:
	clear

.SECONDARY : $(OBJ)
.PHONY: all clean fclean re