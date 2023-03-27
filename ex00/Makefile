NAME 		= 	btc

CXX 		= 	c++
CFLAG 		= 	-Wall -Wextra -Werror -std=c++98
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

.PHONY: clean fclean all re
