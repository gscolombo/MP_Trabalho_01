all: velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall -c velha.cpp
	g++ -std=c++11 -Wall velha.o -o valida_velha
	./valida_velha

valida_velha : velha.cpp velha.hpp
	g++ -std=c++11 -Wall velha.o -o valida_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp

run : valida_velha
	./valida_velha

test : teste_velha.cpp
	cmake -S . -B test_files && cmake --build test_files && \
	cd test_files && ctest || rm -rf test_files

cpplint : teste_velha.cpp velha.cpp velha.hpp
	cpplint *.*

clean :
	rm -rf *.o valida_velha test_files