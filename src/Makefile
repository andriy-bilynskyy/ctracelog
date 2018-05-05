PROJECT_NAME     := ctracelog

SRC_FILES += \
  main.c \
  trace_log.c \

INC_FOLDERS += \
  ./ \

LIB_FILES += \

CFLAGS += -O0
CFLAGS += -g3
CFLAGS += -Wall
CFLAGS += -c
CFLAGS += -fmessage-length=0

OBJ_FILES = $(SRC_FILES:.c=.o)

default: all

clean:
	rm -f $(PROJECT_NAME)
	rm -f $(OBJ_FILES)

all: build

build: $(PROJECT_NAME)
 
$(PROJECT_NAME): $(OBJ_FILES)
	gcc $(OBJ_FILES) -o $@ $(addprefix -l, $(LIB_FILES))


%.o:%.c
	gcc $(CFLAGS) $(CFLAGS) $(addprefix -I, $(INC_FOLDERS)) $< -o $@