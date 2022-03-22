#include "IteratorLP.h"
#include "Lista.h"
#include <exception>

IteratorLP::IteratorLP(const Lista& l):lista(l) {
    //Θ(1)
    curent = lista.n_prim;
}

void IteratorLP::prim(){
    //Θ(1)
	curent = lista.n_prim;
}

void IteratorLP::urmator(){
    //Θ(1)
    if(valid())
	    curent = curent->urmator();
    else
        throw std::exception();
}

bool IteratorLP::valid() const{
    //Θ(1)
	if(curent != nullptr)
        return true;
	return false;
}

TElem IteratorLP::element() const{
    //Θ(1)
	if(valid()){
        return curent->elem();
    }
    throw std::exception();
}


