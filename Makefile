cambio: monedas.cpp
	g++ -o cambio monedas.cpp
testcambio:
	./cambio
clean: 
	rm -r *.o 
