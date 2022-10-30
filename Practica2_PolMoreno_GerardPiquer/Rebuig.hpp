//
//  Rebuig.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef Rebuig_hpp
#define Rebuig_hpp

#include <stdio.h>
#include <string>
#include "ContenidorBrossa.hpp"

class Rebuig : public ContenidorBrossa {
public:
    Rebuig(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    std::string getReciclat();
    void toString();
    std::string getType();
    virtual ~Rebuig();
    void buidat(float pes);
    float quantReciclat();
    
private:
    float reciclat;
};

#endif /* Rebuig_hpp */
