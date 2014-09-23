

SPLIT_LINE = "--------------------"
TARGET = $(notdir $(shell find . -maxdepth 1 -type d \! -name ".*" \! -name "utility"))

.PHONY: all clean
all:
	@echo "DO NOTHING."

clean:
	@for item in $(TARGET); do\
		echo $(SPLIT_LINE); \
		echo $$item; \
		$(MAKE) -C $$item clean; \
	done

