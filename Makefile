all: velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -c velha.cpp
	g++ -std=c++11 -Wall velha.o -o valida_velha
	./valida_velha

compile: velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -c velha.cpp
	g++ -std=c++11 -Wall velha.o -o valida_velha
	rm velha.o

valida_velha : velha.cpp velha.hpp
	g++ -std=c++11 -Wall velha.o -o valida_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp

run : valida_velha
	./valida_velha

test : teste_velha.cpp
	cmake -S . -B test_files && cmake --build test_files
	cp -r ./test_assets ./test_files
	cd test_files && ctest --output-on-failure 

cpplint : teste_velha.cpp velha.cpp velha.hpp
	cpplint *.*

gcov : teste_velha.cpp velha.cpp velha.hpp
	rm -r -f ./coverage/annotations
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	cd coverage && cmake -S . -B build && cmake --build build
	./coverage/build/testa_valida_velha
	gcov *.cpp
	mkdir ./coverage/annotations && mv *.gc* ./coverage/annotations
	gcovr --exclude '.*googletest.*' --exclude '.*velha.cpp.*' --html coverage/coverage.html # Generates coverage reports
	open coverage/coverage.html
	rm *.o

valgrind : velha.cpp velha.hpp velha.o valida_velha
	g++ -std=c++11 -Wall -c velha.cpp
	g++ -std=c++11 -Wall velha.o -o valida_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt -s ./valida_velha

debug : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	g++ -std=c++11 -Wall velha.o -o valida_velha
	gdb valida_velha

clean :
	rm -rf *.o *.gc* valida_velha test_files coverage/build coverage/annotations coverage/*.html valgrind.*