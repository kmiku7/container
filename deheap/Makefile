

TARGET = $(basename $(wildcard test_*.cpp))
HRDS = $(wildcard *.h)
INCLUDES = -I.
OBJS = $(addsuffix .o, $(TARGET))

.PHONY: all clean
all:$(TARGET)
	@echo "done"

clean:
	rm -fr *.o
	rm -fr $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $@.o
	

%.o:%.cpp $(HRDS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

