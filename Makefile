SVR_SRC = server.c 
CLNT_SRC = client.c
SERVER = server
CLIENT = client
SVR_OBJ = $(SVR_SRC:%.c=%.o)
CLNT_OBJ = $(CLNT_SRC:%.c=%.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
$(SERVER): $(SVR_OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(SVR_OBJ) $(LIBFT) -o server
$(CLIENT): $(CLNT_OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(CLNT_OBJ) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SVR_OBJ) $(CLNT_OBJ)
fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(SERVER) $(CLIENT)
re: fclean all
