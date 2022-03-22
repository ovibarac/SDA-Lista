#pragma once

typedef int TElem;

class IteratorLP;
class Node;

typedef Node *PNod;

class Node{
private:
    //valoarea nodului
    TElem val;

    //adresa nodului urmator
    PNod urm;
public:
    friend class Lista;
    //constructor
    //Θ(1)
    Node(TElem val, PNod urmator);

    //valoarea
    //Θ(1)
    TElem elem();

    //pointer la urmatorul nod
    //Θ(1)
    PNod urmator();
};

class Lista {
private:
	friend class IteratorLP;
	/* aici e reprezentarea */

    //primul nod
    PNod n_prim;

    //ultimul nod
    PNod n_ultim;

public:

		// constructor
        //Θ(1)
		Lista ();

		// returnare dimensiune
        //Θ(n)
		int dim() const;

		// verifica daca lista e vida
        //Θ(1)
		bool vida() const;

		// prima pozitie din lista
        //Θ(1)
		IteratorLP prim() const;

		// returnare element de pe pozitia curenta
		//arunca exceptie daca poz nu e valid
        //Θ(1)
		TElem element(IteratorLP poz) const;

		// modifica element de pe pozitia poz si returneaza vechea valoare
		//arunca exceptie daca poz nu e valid
        //Θ(1)
		TElem modifica(IteratorLP poz, TElem e);

		// adaugare element la inceput
        //Θ(1)
		void adaugaInceput(TElem e);		

		// adaugare element la sfarsit
        //Θ(1)
		void adaugaSfarsit(TElem e);

		// adaugare element dupa o pozitie poz
		//dupa adaugare poz este pozitionat pe elementul adaugat
		//arunca exceptie daca poz nu e valid
        //Θ(1)
		void adauga(IteratorLP& poz, TElem e);

		// sterge element de pe o pozitie poz si returneaza elementul sters
		//dupa stergere poz este pozitionat pe elementul de dupa cel sters
		//arunca exceptia daca poz nu e valid
		TElem sterge(IteratorLP& poz);

		// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
        //Θ(n)
		IteratorLP cauta(TElem e) const;

		//destructor
        //Θ(n)
		~Lista();
};
