CXXFLAGS = -Wall -g -std=c++11

MergeSortedLists: MergeSortedLists.o ../Utilities/List.o
	${CXX} ${CXXFLAGS} -o $@ $^

.PHONY:clean
clean:
	rm MergeSortedLists  MergeSortedLists.o ../Utilities/List.o 
