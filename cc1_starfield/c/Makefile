TARGET :=	cc1_Starfield

BUILD_DIR 		:= ./build
SRC_DIRS			:= ./src
LOCAL_HEADERS := ./include

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

LLIBS := ../../libs

INCLUDE := $(LLIBS)/include
LDFLAGS := -L$(LLIBS)/lib -lSDL2 -lSDL2_gfx
CFLAGS	:= -I$(LOCAL_HEADERS) -I$(INCLUDE) -I/usr/include/SDL2

export LD_LIBRARY_PATH := $(LLIBS)/lib

.PHONY: run
run : $(BUILD_DIR)/$(TARGET)
	$(BUILD_DIR)/$(TARGET)

# Final build step
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Build step for c
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -rf build/*