NAME 		= 	RPN

CXX 		= 	c++
CFLAG 		= 	-Wall -Wextra -Werror -std=c++98 -ftrapv
INCLUDES	=	-I.
SRCDIR		=	./
SRCS		=	$(shell ls *.cpp)
OBJDIR		=	./obj/
OBJS		=	$(SRCS:%.cpp=$(OBJDIR)%.o)

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir obj

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $@ $^

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CFLAG) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

test: re
	@echo ""
	@echo "==== TEST ===="
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME)  "(1 + 1)"

.PHONY: clean fclean all re
