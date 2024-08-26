# Nome do executável
EXEC = poketrunfo

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Arquivos fonte e objetos
SRCS = baralho.c carta.c fila.c jogo.c main.c Pikachu_Dancando.c pokemon.c
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra para compilar os arquivos .c em .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objetos e do executável
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
