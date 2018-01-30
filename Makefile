TARGET = a.out
SOURCE = main.cpp
HEADER = circulararray_template.h

VER = -std=c++11

$(TARGET): $(SOURCE) $(HEADER)
	g++ $(VER) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
