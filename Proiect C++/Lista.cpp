
#include <exception>

#include "IteratorLP.h"
#include "Lista.h"

#include <iostream>

TElem Node::elem() {
    //Θ(1)
    return this->val;
}

PNod Node::urmator() {
    //Θ(1)
    return this->urm;
}

Node::Node(TElem val, PNod urmator) {
    //Θ(1)
    this->val = val;
    this->urm = urmator;
}

Lista::Lista() {
    //Θ(1)
    n_prim = nullptr;
    n_ultim = nullptr;
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
    //Θ(1)
    return n_prim == nullptr;
}

IteratorLP Lista::prim() const {
    //Θ(1)
    IteratorLP it = IteratorLP(*this);
    return it;
}

TElem Lista::element(IteratorLP poz) const {
    //Θ(1)
    if (poz.valid()) {
        return poz.element();
    }
    throw std::exception();
}

TElem Lista::sterge(IteratorLP &poz) {
    //Θ(n)
//    if(poz.curent == n_prim){
//        n_prim = poz.curent->urm;
//        PNod p = poz.curent;
//        delete poz.curent;
//        return p->elem();
//    }
//    if (poz.valid()) {
//        IteratorLP it = IteratorLP(*this);
//        while(it.curent != nullptr && it.valid()){
//            if(it.curent->urm == poz.curent){
//                it.curent->urm = poz.curent->urm;
//                PNod p = poz.curent;
//                delete poz.curent;
//                return p->elem();
//            }
//            it.urmator();
//        }
//    }
//
    return -1;
}

IteratorLP Lista::cauta(TElem e) const {
    //Θ(n)
    IteratorLP it = IteratorLP(*this);
    while(it.valid()){
        if(it.curent->elem() == e){
            return it;
        }
        it.urmator();
    }
    it.curent = nullptr;
    return it;
}

TElem Lista::modifica(IteratorLP poz, TElem e) {
    //Θ(1)
    if(poz.valid()){
        TElem p = poz.curent->val;
        poz.curent->val = e;
        return p;
    }
    else
        throw std::exception();
}

void Lista::adauga(IteratorLP &poz, TElem e) {
    //Θ(1)
    if(poz.valid()){
        PNod p = new Node(e, nullptr);
        p->urm = poz.curent->urm;
        poz.curent->urm = p;
    }else
        throw std::exception();
}

void Lista::adaugaInceput(TElem e) {
    //Θ(1)
    PNod p = new Node(e, n_prim);

    if (n_prim == nullptr) {
        n_ultim = p;
    }

    n_prim = p;
}

void Lista::adaugaSfarsit(TElem e) {
    //Θ(1)
    PNod p = new Node(e, nullptr);
    if (n_ultim != nullptr) {
        n_ultim->urm = p;
    } else {
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
