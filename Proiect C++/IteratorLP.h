#pragma once
#include "Lista.h"

class IteratorLP{
	friend class Lista;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container

	IteratorLP(const Lista& lista);

	//contine o referinta catre containerul pe care il itereaza
	const Lista& lista;

	/* aici e reprezentarea  specifica a iteratorului */
    PNod curent;
	
public:

		//reseteaza pozitia iteratorului la inceputul containerului
        //Θ(1)
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
        //Θ(1)
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
        //Θ(1)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
        //Θ(1)
		TElem element() const;

};


