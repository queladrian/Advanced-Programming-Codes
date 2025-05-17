
CXX = g++
CXXFLAGS = -std=c++17 -Ilibs/CLI11 -Wall -Wextra -O2
LDFLAGS = -Wl,-subsystem:console  


TARGET = retail_analytics


SRC = main.cpp


all: $(TARGET)


$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)


clean:
	rm -f $(TARGET)

.PHONY: all clean
