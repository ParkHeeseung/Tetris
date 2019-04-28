# Makefile example
CC = g++
TARGET = tetris
SOURCES = Tetris.cpp \
					Pane.cpp \
					BoardPane.cpp \
					InfoPane.cpp \
					HelpPane.cpp \
					StatPane.cpp \
					NextPane.cpp \
					ResultPane.cpp\
					Block.cpp\
					O_Block.cpp\
					I_Block.cpp\
					Z_Block.cpp\
					L_Block.cpp\
					J_Block.cpp\
					S_Block.cpp\
					T_Block.cpp\
					main.cpp \

LDFLAGS = -lncurses

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
