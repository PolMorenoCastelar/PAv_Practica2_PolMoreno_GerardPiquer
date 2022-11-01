//
//  ContenidorBrossa.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "ContenidorBrossa.hpp"
#include <iostream>
#include <time.h>
#include <string.h>


ContenidorBrossa::ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) noexcept(false) {
    checkParams(codi, color, anyColocacio, tara);
    this->codi=codi;
    this->color=color;
    this->ubicacio=ubicacio;
    this->anyColocacio=anyColocacio;
    this->tara=tara;
    
}

ContenidorBrossa::ContenidorBrossa(std::string codi, int color, int anyColocacio,float tara) noexcept(false) : ContenidorBrossa(codi, color, NULL, anyColocacio, tara) {
}

void ContenidorBrossa::checkParams(std::string codi, int color, int anyColocacio, float tara) noexcept(false) {
    if (!checkCodi(codi)) {
        throw "Codi amb valor null";
    }
    if (color != GROC && color != MARRO && color != VERD && color != GRIS && color != BLAU) {
        throw "Color de contenidor no valid, ha de ser de color groc, marro, verd, gris o blau";
    }
    if (checkAny(anyColocacio) == false) {
        throw "L'any de colocacio ha de ser un enter de 4 xifres";
    }
    if (tara <= 0) {
        throw "Valor de tara inferior o igual a 0";
    }
}

bool ContenidorBrossa::checkCodi(std::string codi) {
    std::string lletres = codi.substr(0,2);
    std::string numeros = codi.substr(codi.size()-4);
    bool teLletres = lletres.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
    std::string::npos;
    bool teNumeros = numeros.find_first_not_of("0123456789") ==
    std::string::npos;
    return teLletres&&teNumeros;
}

bool ContenidorBrossa::checkAny(int any) {
    if (any > 999 && any <= 9999) {
        return true;
    }
    return false;
}

std::string ContenidorBrossa::getTipusBrossa() {
    switch (color) {
        case GROC: return "PLASTIC";
        case MARRO: return "ORGANIC";
        case VERD: return "VIDRE";
        case GRIS: return "REBUIG";
        case BLAU: return "PAPER";
    }
    return "";
}

std::string ContenidorBrossa::getColor() {
    switch (color) {
        case GROC: return "GROC";
        case MARRO: return "MARRO";
        case VERD: return "VERD";
        case GRIS: return "GRIS";
        case BLAU: return "BLAU";
    }
    return "";
}

void ContenidorBrossa::retirarViaPublica() noexcept(false) {
    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    int year = now_tm -> tm_year+1900;
    this->anyRetirada = year;
    this->ubicacio = nullptr;
    if (anyColocacio == 0) {
        throw "El contenidor no esta ubicat a la via publica";
    } else {
        this->anyColocacio = 0;
    }
}

std::string ContenidorBrossa::getUbicacio() noexcept(false) {
    if (anyColocacio == 0) {
        throw "El contenidor es troba al magatzem";
    }
    return ubicacio;
}

void ContenidorBrossa::setUbicacio(std::string ubicacio) noexcept(false) {
    if (ubicacio.empty()) {
        retirarViaPublica();
    }
    this->ubicacio = ubicacio;
}

std::string ContenidorBrossa::getCodi() {
    return codi;
}

std::string ContenidorBrossa::getEstat() {
    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    int year = now_tm -> tm_year+1900;
    int anys = year - anyColocacio;
    if (anyColocacio == 0) {
        return "retirat";
    }
    if (anys > 5) {
        return "vell";
    }
    if (anys >= 3 && anys <= 5) {
        return "seminou";
    }
    if (anys < 3) {
        return "nou";
    }
    return "";
}

bool ContenidorBrossa::operator==(ContenidorBrossa *p) {
    return codi.compare(p->codi);
}

bool ContenidorBrossa::operator<(ContenidorBrossa *p) {
    return codi.compare(p->codi)<0;
    
}

bool ContenidorBrossa::operator>(ContenidorBrossa *p) {
    return !(codi == p->codi || codi < p->codi);
}

void ContenidorBrossa::toString() {
    std::cout << "Codi: " << codi << std::endl;
    std::cout << "Color: " << getColor()<<std::endl;
    std::cout << "Ubicació: " << (anyRetirada == 0? ubicacio : "retirat") << std::endl;
    std::cout << "Tara: " << tara << std::endl;
}

ContenidorBrossa::~ContenidorBrossa() {
    
}


