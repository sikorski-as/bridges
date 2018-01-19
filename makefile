CXX = g++ -Wall -pedantic -Wextra -std=c++11

default: tests app

app: src/main.cpp src/Graph.cpp
	$(CXX) src/main.cpp src/Graph.cpp -o long_bridges
tests:  tests/tests.cpp src/Graph.cpp
	$(CXX) tests/tests.cpp src/Graph.cpp -o tests_long_bridges
	tests_long_bridges.exe
clean:
	del long_bridges.exe
	del tests_long_bridges.exe