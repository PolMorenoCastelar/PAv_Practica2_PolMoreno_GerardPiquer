//
//  Paper.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Paper.hpp"
#include <iostream>

Paper::Paper(std::string codi, std::string ubicacio, int anyColocacio, float tara) :
    ContenidorBrossa(codi, ContenidorBrossa::BLAU, ubicacio, anyColocacio, tara) {
        this->reciclat = 0;
}

std::string Paper::getReciclat() {
    return std::to_string(reciclat) + " quilograms";
}

void Paper::toString() {
    ContenidorBrossa::toString();
    std::cout << "Reciclat: " << getReciclat() << std::endl;
}

std::string Paper::getType() {
    return "Paper";
}

Paper::~Paper() {
    
}

void Paper::buidat(float pes) {
    reciclat = (pes - tara)*1.95;
}

float Paper::quantReciclat() {
    return reciclat;
}
