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
#include "Paper.hpp"
#include "Plastic.hpp"
#include "Vidre.hpp"
#include "Rebuig.hpp"
#include "Organic.hpp"


Poblacio::Poblacio() {
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

void Poblacio::afegirContenidor(ContenidorBrossa *p) noexcept(false) {
    int index = onVa(p);
    if (hiEsContenidor(p, contenidor[index])) {
        throw "Aquest contenidor ja es troba al magatzem";
    }
    node *nouNode = new node();
    nouNode->con = p;
    nouNode->seg = contenidor[index];
    contenidor[index] = nouNode;
}

int Poblacio::onVa(ContenidorBrossa *p) {
    if (p->getType().compare("PAPER") == 0) {
        return ContenidorBrossa::BLAU;
    } else if (p->getType().compare("PLASTIC") == 0) {
        return ContenidorBrossa::GROC;
    } else if (p->getType().compare("VIDRE") == 0) {
        return ContenidorBrossa::VERD;
    } else if (p->getType().compare("REBUIG") == 0) {
        return ContenidorBrossa::GRIS;
    } else if (p->getType().compare("ORGANIC") == 0) {
        return ContenidorBrossa::MARRO;
    }
    return -1;
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

void Poblacio::afegirContenidor(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) noexcept(false) {
    if (color == ContenidorBrossa::BLAU) {
        afegirContenidor(new Paper(codi, ubicacio, anyColocacio, tara));
    } else if (color == ContenidorBrossa::GROC) {
        afegirContenidor(new Plastic(codi, ubicacio, anyColocacio, tara));
    } else if (color == ContenidorBrossa::VERD) {
        afegirContenidor(new Vidre(codi, ubicacio, anyColocacio, tara));
    } else if (color == ContenidorBrossa::GRIS) {
        afegirContenidor(new Rebuig(codi, ubicacio, anyColocacio, tara));
    } else if (color == ContenidorBrossa::MARRO) {
        afegirContenidor(new Organic(codi, ubicacio, anyColocacio, tara));
    }
}

std::string Poblacio::hiEs(std::string codi) noexcept(false) {
    node *aux = *contenidor;
    while (aux != nullptr) {
        for (int i=0; i<5; i++) {
            node *aux2 = contenidor[i];
            if (aux2->con->getCodi() == codi) {
                return "El contenidor amb codi " + codi + " es de color " + aux2->con->getColor();
            }
            aux2 = aux2->seg;
        }
        aux = aux->seg;
    }
    throw "No es troba a la població";
}

void Poblacio::eliminarContenidor(ContenidorBrossa *c) noexcept(false) {
    int index = onVa(c);
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

ContenidorBrossa* Poblacio::mesRendiment() noexcept(false) {
    float mesRendiment = 0, rendiActual = 0;
    ContenidorBrossa* conMesRendiment = NULL;
    if (contenidor == nullptr) {
        throw "La població no té cap contenidor";
    }
    for (int i=0; i<5; i++){
        node *aux = contenidor[i];
        while (aux != nullptr) {
            rendiActual = aux->con->quantReciclat();
            if (rendiActual > mesRendiment) {
                conMesRendiment = aux->con;
                mesRendiment = rendiActual;
            }
            aux = aux->seg;
        }
    }
    return conMesRendiment;
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
        cont+=this->getQuants(i);
    }
    return cont;
}

bool Poblacio::operator==(Poblacio d) {
    return getQuants() == d.getQuants();
}

bool Poblacio::operator<(Poblacio d) {
    return getQuants() < d.getQuants();
}

bool Poblacio::operator>(Poblacio d) {
    return !(this->getQuants() == d.getQuants() || this->getQuants() < d.getQuants());
}

void Poblacio::toString() {
    node *groc = contenidor[0];
    node *marro = contenidor[1];
    node *verd = contenidor[2];
    node *gris = contenidor[3];
    node *blau = contenidor[4];
    std::cout << "Contenidors grocs" << std::endl;
    while (groc != nullptr) {
        groc->con->toString();
        groc = groc->seg;
    }
    std::cout << "Contenidors marrons" << std::endl;
    while (marro != nullptr) {
        marro->con->toString();
        marro = marro->seg;
    }
    std::cout << "Contenidors verds" << std::endl;
    while (verd != nullptr) {
        verd->con->toString();
        verd = verd->seg;
    }
    std::cout << "Contenidors grisos" << std::endl;
    while (gris != nullptr) {
        gris->con->toString();
        gris = gris->seg;
    }
    std::cout << "Contenidors blaus" << std::endl;
    while (blau != nullptr) {
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

           

