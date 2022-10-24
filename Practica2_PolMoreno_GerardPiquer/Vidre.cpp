//
//  Vidre.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Vidre.hpp"
#include <iostream>

Vidre::Vidre(std::string codi, std::string ubicacio, int anyColocacio, float tara) :
    ContenidorBrossa(codi, ContenidorBrossa::VERD, ubicacio, anyColocacio, tara){
        this->reciclat = 0;
}

std::string Vidre::getReciclat() {
    return std::to_string(reciclat) + " envasos";
}

void Vidre::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << getReciclat() << std::endl;
}

std::string Vidre::getType() {
    return "Vidre";
}

Vidre::~Vidre() {
    
}

void Vidre::buidat(float pes) {
    reciclat = (pes - tara)*3;
}
