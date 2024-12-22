NAME = Zombie
SRC= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ=$(SRC:.cpp=.o)
CCPP = c++ -std=c++98 #-fsanitize=address -g
CPPFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME) : $(OBJ)
	$(CCPP) $(CPPFLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CCPP) $(CPPFLAGS) $? -c -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)
