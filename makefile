# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Menu.o fibonacci.o
SRCS = main.cpp Menu.cpp fibonacci.cpp
HEADERS = Menu.hpp fibonacci.hpp

lab10: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o lab10

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o lab10
