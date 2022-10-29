//
//  Poblacio.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Poblacio.hpp"
#include <iostream>
#include <time.h>
#include <string.h>

Poblacio::Poblacio(){
    contenidor = new node*[5];
    contenidor[0] = nullptr;
    contenidor[1] = nullptr;
    contenidor[2] = nullptr;
    contenidor[3] = nullptr;
    contenidor[4] = nullptr;
}

Poblacio::Poblacio(ContenidorBrossa *c) : Poblacio() {
    afegirContenidor(c);
}

void Poblacio::afegirContenidor(ContenidorBrossa *p) {
    std::string tipus = p->getType();
    int index = p->colorContenidor(tipus);
    if (hiEsContenidor(p, *contenidor)) {
        throw "Aquest contenidor ja es troba al magatzem";
    }
    node *aux = new node();
    aux->con = p;
    aux->seg = contenidor[index];
    *contenidor = aux;
}

bool Poblacio::hiEsContenidor(ContenidorBrossa *c, node *contenidor) {
    while (contenidor != nullptr) {
        if (c->getCodi() == contenidor->con->getCodi()) {
            return true;
        }
        contenidor = contenidor->seg;
    }
    return false;
}

void Poblacio::afegirContenidor(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {
    //no se com fer-el
}

std::string Poblacio::hiEs(std::string codi) {
    node *aux = *contenidor;
    while (aux != nullptr) {
        if (aux->con->getCodi() == codi) {
            return "El contenidor amb codi " + codi + " es de color " + aux->con->getColor();
        }
       aux = aux->seg;
    }
    throw "No es troba a la població";
}

void Poblacio::eliminarContenidor(ContenidorBrossa *c) {
    std::string tipus = c->getType();
    int index = c->colorContenidor(tipus);
    if (!(hiEsContenidor(c, contenidor[index]))) {
        throw "El contenidor no es troba al magatzem";
    }
    node *aux = nullptr;
    if (*(contenidor[index]->con) == c) {
        aux = contenidor[index];
        contenidor[index] = contenidor[index]->seg;
    }
    else {
        node* anterior = contenidor[index];
        aux = contenidor[index]->seg;
        while (!(*(aux->con) == c)) {
            anterior = aux;
            aux = aux->seg;
        }
        anterior->seg = aux->seg;
    }
    delete aux->con;
    delete aux;
}

ContenidorBrossa* Poblacio::mesRendiment() {
    int mesRendiment = 0;
    if (contenidor == nullptr) {
        throw "La població no té cap contenidor";
    }
    node *aux = *contenidor;
    while (aux != nullptr) {
        mesRendiment = aux->con->getReciclat(); //com fer pk el metode retorni nomes l'atribut
    }
}

int Poblacio::getQuants(int color) {
    int cont = 0;
    node *aux = contenidor[color];
    while (aux != nullptr) {
        cont++;
        aux = aux->seg;
    }
    return cont;
}

int Poblacio::getQuants() {
    int cont = 0;
    for (int i=0; i<5; i++) {
        cont+=getQuants(i);
    }
    return cont;
}

bool Poblacio::operator==(Poblacio d) {
    return this->getQuants() == d.getQuants();
}

bool Poblacio::operator<(Poblacio d) {
    return this->getQuants() < d.getQuants();
}

bool Poblacio::operator>(Poblacio d) {
    return !(*this == d || *this < d);
}

void Poblacio::toString() {
    node *groc = contenidor[0];
    node *marro = contenidor[1];
    node *verd = contenidor[2];
    node *gris = contenidor[3];
    node *blau = contenidor[4];
    while (groc != nullptr) {
        std::cout << "Contenidors grocs" << std::endl;
        groc->con->toString();
        groc = groc->seg;
    }
    while (marro != nullptr) {
        std::cout << "Contenidors marrons" << std::endl;
        marro->con->toString();
        marro = marro->seg;
    }
    while (verd != nullptr) {
        std::cout << "Contenidors verds" << std::endl;
        verd->con->toString();
        verd = verd->seg;
    }
    while (gris != nullptr) {
        std::cout << "Contenidors grisos" << std::endl;
        gris->con->toString();
        gris = gris->seg;
    }
    while (blau != nullptr) {
        std::cout << "Contenidors balus" << std::endl;
        blau->con->toString();
        blau = blau->seg;
    }
}

Poblacio::~Poblacio() {
    eliminarRecursivament(contenidor[0]);
    eliminarRecursivament(contenidor[1]);
    eliminarRecursivament(contenidor[2]);
    eliminarRecursivament(contenidor[3]);
    eliminarRecursivament(contenidor[4]);
    delete contenidor;
}

void Poblacio::eliminarRecursivament(node *n) {
    if (n == nullptr) return;
    eliminarRecursivament(n->seg);
    delete n->con;
    delete n;
}

           

