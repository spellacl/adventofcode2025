
TARGET=main

CFLAGS = -g -std=c++20

SOURCES = util.o day1.o day2.o day3.o \
          day5.o day8.o main.o

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CFLAGS) -o $@ $(SOURCES)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	rm $(SOURCES) $(TARGET)
