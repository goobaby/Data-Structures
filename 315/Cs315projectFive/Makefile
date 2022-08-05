
projectFive.x: main.o DepGraph.o systemInterface.o Token.o Tokenizer.o MakeTree.o
	g++ -std=c++17 main.o DepGraph.o systemInterface.o Token.o Tokenizer.o MakeTree.o -o projectFive.x

main.o: main.cpp DepGraph.hpp Tokenizer.hpp MakeTree.hpp TreeNode.hpp GraphNode.hpp systemInterface.hpp systemInterface.hpp Token.hpp
	g++ -std=c++17 -c main.cpp -o main.o

DepGraph.o: DepGraph.hpp DepGraph.cpp MakeTree.hpp Token.hpp Tokenizer.hpp systemInterface.hpp GraphNode.hpp TreeNode.hpp
	g++ -std=c++17 -c DepGraph.cpp -o DepGraph.o

systemInterface.o: systemInterface.hpp systemInterface.cpp
	g++ -std=c++17 -c systemInterface.cpp -o systemInterface.o

Token.o: Token.cpp Token.hpp
	g++ -std=c++17 -c Token.cpp -o Token.o

MakeTree.o: MakeTree.cpp MakeTree.hpp TreeNode.hpp GraphNode.hpp systemInterface.hpp
	g++ -std=c++17 -c MakeTree.cpp -o MakeTree.o

Tokenizer.o: Tokenizer.cpp Tokenizer.hpp Token.hpp
	g++ -std=c++17 -c Tokenizer.cpp -o Tokenizer.o

clean:
	rm -fr projectFive.x *.o

