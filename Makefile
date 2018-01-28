TARGET = a.out
SOURCE = main.cpp

VER = -std=c++11

$(TARGET): $(SOURCE)
	g++ $(VER) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
