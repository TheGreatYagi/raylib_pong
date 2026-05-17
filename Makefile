# Compiler and Target
CC = clang #can use alternative
TARGET = pong

# Paths based on your system configuration
RAYLIB_ROOT = #PATH TO RAYLIB
INCLUDE_PATH = $(RAYLIB_ROOT)/include
LIB_PATH = $(RAYLIB_ROOT)
LOCAL_INCLUDE = ./include

# Compilation Flags
# -I tells clang where to find the raylib.h header
CFLAGS = -Wall -std=c99 -I$(INCLUDE_PATH) -I$(LOCAL_INCLUDE)

# Linker Flags
# -L tells clang where to find libraylib.a
# -lraylib links the library
# -frameworks are required for macOS graphics/input
LDFLAGS = -L$(LIB_PATH) -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL

# Source and Object files
# We look inside the 'src' folder for your C files
SRCS = src/main.c src/player.c src/ball.c src/comm.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
	$(clean)l

# Compile the .c files in the src folder to .o files
# This puts the .o files right next to the .c files in the src folder
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f src/*.o 

remove: 
	rm -rf src/*.o $(TARGET)

# Build and run
run: all
	./$(TARGET)

.PHONY: all clean run