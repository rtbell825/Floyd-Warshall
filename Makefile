# the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -Wall

  # the build target executable:
  TESTER = FW_tester
  TARGET = floyd-warshall

  all: $(TESTER)

  $(TESTER): $(TESTER).cpp
	$(CC) $(CFLAGS) -o $(TESTER) $(TESTER).cpp $(TARGET).cpp

  clean:
	$(RM) $(TESTER)
