friccion.png : proyectil.py datos.dat datos1.dat
	python proyectil.py

datos.dat : p.x
	./p.x 1 > datos.dat
	
datos1.dat : p.x
	./p.x 0 > datos1.dat
    
p.x : proyectil.cpp
	c++ proyectil.cpp -o p.x

clean:
	rm p.x  friccion.png datos.dat