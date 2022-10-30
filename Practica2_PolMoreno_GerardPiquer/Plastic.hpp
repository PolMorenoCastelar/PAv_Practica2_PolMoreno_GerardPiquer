//
//  Plastic.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef Plastic_hpp
#define Plastic_hpp

#include <stdio.h>
#include <string>
#include "ContenidorBrossa.hpp"

class Plastic : public ContenidorBrossa {
public:
    Plastic(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    std::string getReciclat();
    void toString();
    std::string getType();
    virtual ~Plastic();
    void buidat(float pes);
    float quantReciclat();
    
    
private:
    float reciclat;
};


#endif /* Plastic_hpp */
