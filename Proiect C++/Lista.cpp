
#include <exception>

#include "IteratorLP.h"
#include "Lista.h"

#include <iostream>

TElem Node::elem() {
    return this->val;
}

PNod Node::urmator(){
    return this->urm;
}

Node::Node(TElem val, PNod urmator) {
    this->val = val;
    this->urm = urmator;
}

Lista::Lista() {
    //Θ(1)
	n_prim = nullptr;
}

int Lista::dim() const {
    //Θ(n)
    int nr = 0;
    PNod p = n_prim;
    while (p != nullptr) {
        p = p->urm;
        nr++;
    }
	return nr;
}


bool Lista::vida() const {
	if(n_prim == nullptr)
	    return true;
    return false;
}

IteratorLP Lista::prim() const {
	/* de adaugat */
    return IteratorLP(*this);
}

TElem Lista::element(IteratorLP poz) const {
	/* de adaugat */
	return -1;
}

TElem Lista::sterge(IteratorLP& poz) {
	/* de adaugat */
	return -1;
}

IteratorLP Lista::cauta(TElem e) const{
	/* de adaugat */
	return IteratorLP(*this);
}

TElem Lista::modifica(IteratorLP poz, TElem e) {
	/* de adaugat */
	return -1;
}

void Lista::adauga(IteratorLP& poz, TElem e) {
	/* de adaugat */
}

void Lista::adaugaInceput(TElem e) {
    //Θ(1)
    PNod p = new Node(e,n_prim);

    if(n_prim== nullptr){
        n_ultim = p;
    }

    n_prim = p;
}

void Lista::adaugaSfarsit(TElem e) {
    //Θ(1)
    PNod p = new Node(e, nullptr);
    if(n_ultim != nullptr){
        n_ultim->urm = p;
    }else{
        n_prim = p;
    }
    n_ultim = p;
}

Lista::~Lista() {
    //Θ(n)
    while (n_prim != nullptr) {
        PNod p = n_prim;
        n_prim = n_prim->urm;
        delete p;
    }
}
