

SPLIT_LINE = "--------------------"
TARGET = $(notdir $(shell find . -d 1 -type d \! -name ".*"))

.PHONY: all clean
all:
	@echo "DO NOTHING."

clean:
	@for item in $(TARGET); do\
		echo $(SPLIT_LINE); \
		echo $$item; \
		$(MAKE) -C $$item clean; \
	done

