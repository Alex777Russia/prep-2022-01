TARGET = ./main.out
TST_TARGET = ./tests.out

HDRS_DIR = project/include

SRCS = \
	project/src/main.c \
	project/src/utils.c \
	project/src/read_and_print_data.c \

TST_SRCS = \
	project/src/test_main.c \
	project/src/utils.c \
	project/src/test_print_to_file.c \
	project/src/read_and_print_data.c \

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

$(TST_TARGET): $(TST_SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TST_TARGET) $(CFLAGS) $(TST_SRCS)

build: $(TARGET) $(TST_TARGET)

rebuild: clean build

check:
	./run_linters.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat
