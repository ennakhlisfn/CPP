NAME = Account
SRC= tests.cpp Account.cpp
OBJ=$(SRC:.cpp=.o)
CCPP = c++ -std=c++98
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
