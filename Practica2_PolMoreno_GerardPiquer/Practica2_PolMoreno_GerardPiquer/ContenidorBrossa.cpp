//
//  ContenidorBrossa.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "ContenidorBrossa.hpp"

ContenidorBrossa::ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) {
    //fer un metode privat check per comprovar si el codi es correcte
    if (!checkCodi(codi)) {
        throw "Codi amb valor null";
    }
    if (color != GROC && color != MARRO && color != VERD && color != GRIS && color != BLAU) {
        throw "Color de contenidor no valid, ha de ser de color groc, marro, verd, gris o blau";
    }
    //fer un metode private check per comprovar si l'any de colocacio es correcte
    if (checkAny(anyColocacio)) {
        throw "L'any de colocacio ha de ser un enter de 4 xifres";
    }
    if (tara <= 0) {
        throw "Valor de tara inferior o igual a 0";
    }
    

}
bool ContenidorBrossa::checkCodi(std::string codi){
    std::string lletres= codi.substr(0,2);
    std::string numeros= codi.substr(codi.size()-4);
    bool teLletres= lletres.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
    std::string::npos;
    bool teNumeros=numeros.find_first_not_of("0123456789") ==
    std::string::npos;
    return teLletres&&teNumeros;
    }
bool ContenidorBrossa::checkAny(int anyint){
    std::string any = std::to_string(anyint);
    if(any.size()==4 && any.find_first_not_of("0123456789")== std::string::npos){
        return true;
    }
    return false;
}
