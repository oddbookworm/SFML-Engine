CC=clang++
CC_FLAGS=-fcolor-diagnostics -fansi-escape-codes -o
EXE=bin/main
DEBUG_EXE=bin/main-debug
FILES=main.cpp src/*.cpp
LINK_FLAGS=-lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window -lsfml-system
DEBUG_FLAGS=-lsfml-audio-d -lsfml-graphics-d -lsfml-system-d -lsfml-window-d -lsfml-system-d
WARN_FLAGS=-Wall -Wextra -Wpedantic

default:
	$(CC) $(CC_FLAGS) $(EXE) $(FILES) $(LINK_FLAGS) $(WARN_FLAGS)

debug:
	$(CC) $(CC_FLAGS) $(DEBUG_EXE) $(FILES) $(DEBUG_FLAGS) $(WARN_FLAGS)