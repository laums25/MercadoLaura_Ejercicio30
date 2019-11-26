Ej30.png : Ej30.dat Ejercicio30.py
	python Ejercicio30.py

Ej30.dat : Ejer.x
	./Ejer.x

Ejer30.png : Ejer30.dat Ejercicio30.py
	python Ejercicio30.py

Ejer30.dat : Ejer.x
	./Ejer.x


Ejercicio30.png  : Ejercicio30.dat Ejercicio30.py
	python Ejercicio30.py

Ejercicio30.dat  : Ejer.x
	./Ejer.x 

Ejer.x : MercadoLaura_Ejercicio30.cpp
	c++ MercadoLaura_Ejercicio30.cpp -o Ejer.x
	
clean:
	rm -r *.x *.dat *.png
