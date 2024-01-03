SVR_SRC = server.c 
CLNT_SRC = client.c
SVR_BONUS_SRC = server_bonus.c
CLNT_BONUS_SRC = client_bonus.c
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SERVER = server
CLIENT = client
SVR_OBJ = $(SVR_SRC:%.c=%.o)
CLNT_OBJ = $(CLNT_SRC:%.c=%.o)
SVR_BONUS_OBJ = $(SVR_BONUS_SRC:%.c=%.o)
CLNT_BONUS_OBJ = $(CLNT_BONUS_SRC:%.c=%.o)
CC = cc
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
$(SERVER_BONUS): $(SVR_BONUS_OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(SVR_BONUS_OBJ) $(LIBFT) -o server_bonus
$(CLIENT_BONUS): $(CLNT_BONUS_OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(CLNT_BONUS_OBJ) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SVR_OBJ) $(CLNT_OBJ)
	$(RM) $(SVR_BONUS_OBJ) $(CLNT_BONUS_OBJ)
fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(SERVER) $(CLIENT)
		$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
re: fclean all
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
