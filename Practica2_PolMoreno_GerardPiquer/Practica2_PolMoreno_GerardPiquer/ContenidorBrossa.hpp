//
//  ContenidorBrossa.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef ContenidorBrossa_hpp
#define ContenidorBrossa_hpp

#include <stdio.h>
#include <string>

class ContenidorBrossa {
public:
    static const int GROC = 1, MARRO = 2, VERD = 3, GRIS = 4, BLAU = 5;
    ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara);
    ContenidorBrossa(std::string codi, int color, int anyColocacio, int anyRetirada, float tara);
    std::string getTipusBrossa();
    void retirarViaPublica();
    std::string getUbicacio();
    void setUbicacio(std::string ubicacio);
    std::string getCodi();
    std::string getEstat();
    bool operator==(ContenidorBrossa *p);
    bool operator<(ContenidorBrossa *p);
    bool operator>(ContenidorBrossa *p);
    void toString();
    void buidat(float pes);
    std::string getType();
    std::string getReciclat();
    ~ContenidorBrossa();
    
private:
    bool checkCodi(std::string codi);
    bool checkAny(int any);
    std::string codi;
    int color;
    std::string ubicacio;
    int anyColocacio;
    int anyRetirada;

protected:
    int tara;
};

#endif /* ContenidorBrossa_hpp */
