TARGET = a.out
SOURCE = main.cpp circulararray.cpp
HEADER = circulararray.h

VER = -std=c++11

$(TARGET): $(SOURCE) $(HEADER)
	g++ $(VER) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
