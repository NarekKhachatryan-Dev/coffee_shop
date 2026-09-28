CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic

TARGET = coffee

all: $(TARGET)

$(TARGET): main.cpp Beverage.h Decorators.h order.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean