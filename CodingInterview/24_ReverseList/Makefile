CXXFLAGS = -Wall -g -std=c++11

ReverseList: ReverseList.o ../Utilities/List.o
	${CXX} ${CXXFLAGS} -o $@ $^

.PHONY: clean
clean:
	rm ReverseList  ReverseList.o ../Utilities/List.o
