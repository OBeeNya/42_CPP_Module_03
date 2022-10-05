NAME =				DiamondTrap

SRCS =				main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp \
					DiamondTrap.cpp

OBJS =				${SRCS:.cpp=.o}

C++ =				c++

FLAGS =				-Wall -Werror -Wextra -std=c++98

RM =				rm -rf

all:				${NAME}

.c.o:
	${C++} ${FLAGS} -c $< -o

${NAME}:			${OBJS}
	${C++} ${FLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:				clean
	${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
