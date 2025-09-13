# =================
# VARIABLES SECTION
# =================

CC       := clang++
CFLAGS   := -g									#-Wall -Wextra -Werror
BUILD    := build

SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:%.cpp=$(BUILD)/%.o)
TARGET   := $(BUILD)/main.exe
LEAKS    := $(BUILD)/leaks.out

# =================
# RULES
# =================

$(BUILD):
	mkdir -p $(BUILD)

$(TARGET): $(OBJS) | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD)/%.o: %.cpp | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(LEAKS): $(TARGET)
	leaks --atExit -- $(TARGET)

all: $(TARGET)

leaks: $(LEAKS)

clean:
	rm -rf $(BUILD)

.PHONY: all clean leaks
