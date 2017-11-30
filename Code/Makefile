main.exe: main.o parser.o interpreter.o memorydata.o
	g++ main.o memorydata.o parser.o interpreter.o -o main.exe

memorydata.o: memorydata.cpp memorydata.h
	g++ -c memorydata.cpp

interpreter.o: interpreter.cpp interpreter.h memorydata.h
	g++ -c interpreter.cpp

parser.o: parser.cpp parser.h memorydata.h
	g++ -c parser.cpp

main.o: main.cpp parser.h interpreter.h
	g++ -c main.cpp


