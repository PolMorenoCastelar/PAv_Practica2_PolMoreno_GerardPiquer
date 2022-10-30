//
//  Rebuig.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Rebuig.hpp"
#include <iostream>

Rebuig::Rebuig(std::string codi, std::string ubicacio, int anyColocacio, float tara) :
    ContenidorBrossa(codi, ContenidorBrossa::GRIS, ubicacio, anyColocacio, tara){
        this->reciclat = 0;
}

std::string Rebuig::getReciclat() {
    return std::to_string(reciclat) + " tones";
}

void Rebuig::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << getReciclat() << std::endl;
}

std::string Rebuig::getType() {
    return "REBUIG";
}

Rebuig::~Rebuig() {
    
}

void Rebuig::buidat(float pes) {
    reciclat = (pes - tara)*1.75;
}

float Rebuig::quantReciclat() {
    return reciclat;
}
