NAME = a.out
CC = g++
CFLAGS = 
SRCS = IIHK.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY : all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
