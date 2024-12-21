NAME = PhoneBook
SRC= Main.cpp
OBJ=$(SRC:.cpp=.o)
CCPP = c++
CPPFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME) : $(OBJ)
	$(CCPP) $(CPPFLAGS) $? -o $@

%.o : %.cpp
	$(CCPP) $(CPPFLAGS) $? -c -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)
