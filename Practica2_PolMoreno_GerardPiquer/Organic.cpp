//
//  Organic.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Organic.hpp"
#include <iostream>

Organic::Organic(std::string codi, std::string ubicacio, int anyColocacio, float tara) :
    ContenidorBrossa(codi, ContenidorBrossa::MARRO, ubicacio, anyColocacio, tara){
        this->reciclat = 0;
}

std::string Organic::getReciclat() {
    return std::to_string(reciclat) + " tones";
}

void Organic::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << getReciclat() << std::endl;
}

std::string Organic::getType() {
    return "Organic";
}

Organic::~Organic() {
    
}

void Organic::buidat(float pes) {
    reciclat = (pes - tara)*1.90;
}
