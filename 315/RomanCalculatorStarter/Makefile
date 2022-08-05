roman.x: Token.o Tokenizer.o main.o TokenIterator.o InfixToPostfix.o
	g++ -std=c++17 Token.o Tokenizer.o main.o TokenIterator.o InfixToPostfix.o -o roman.x

Token.o: Token.cpp Token.hpp
	g++ -std=c++17 Token.cpp -o Token.o -c

Tokenizer.o: Tokenizer.cpp Tokenizer.hpp
	g++ -std=c++17 Tokenizer.cpp -o Tokenizer.o -c

main.o: main.cpp Token.hpp InfixToPostfix.hpp
	g++ -std=c++17 main.cpp -o main.o -c

TokenIterator.o: TokenIterator.cpp TokenIterator.hpp Token.hpp
	g++ -std=c++17 TokenIterator.cpp -o TokenIterator.o -c

InfixToPostfix.o: InfixToPostfix.cpp InfixToPostfix.hpp TokenIterator.hpp Token.hpp
	g++ -std=c++17 InfixToPostfix.cpp -o InfixToPostfix.o -c