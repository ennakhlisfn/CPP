NAME = Harl
SRC= main.cpp Harl.cpp
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
	rm -f *.replace

fclean: clean
	rm -f $(NAME)

re : fclean all

.SECONDARY : $(OBJ)