//
//  Plastic.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Plastic.hpp"
#include <iostream>

Plastic::Plastic(std::string codi, std::string ubicacio, int anyColocacio, float tara) :
    ContenidorBrossa(codi, ContenidorBrossa::GROC, ubicacio, anyColocacio, tara){
        this->reciclat = 0;
}

std::string Plastic::getReciclat() {
    return std::to_string(reciclat) + " quilograms";
}

void Plastic::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << getReciclat() << std::endl;
}

std::string Plastic::getType() {
    return "Plastic";
}

Plastic::~Plastic() {
    
}

void Plastic::buidat(float pes) {
    reciclat = (pes - tara)*1.80;
}

float Plastic::quantReciclat() {
    return reciclat;
}
