

TARGET = $(basename $(wildcard test_*.cpp))
HRDS = $(wildcard *.h)
OBJS = $(addsuffix .o, $(TARGET))
INCLUDES = -I. \
			-I../utility/output/include
DEPS = -lkm_utility
DEPSPATH = -L../utility/output/lib

.PHONY: all clean
all:$(TARGET)
	@echo "done"

clean:
	rm -fr *.o
	rm -fr $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $(DEPSPATH) $@.o $(DEPS)
	

%.o:%.cpp $(HRDS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

