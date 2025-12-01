
TARGET=main

CFLAGS = -std=c++17

SOURCES = util.o day1.o main.o

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CFLAGS) -o $@ $(SOURCES)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	rm $(SOURCES) $(TARGET)
