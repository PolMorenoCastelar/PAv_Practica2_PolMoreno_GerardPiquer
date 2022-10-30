//
//  Organic.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef Organic_hpp
#define Organic_hpp

#include <stdio.h>
#include <string>
#include "ContenidorBrossa.hpp"

class Organic : public ContenidorBrossa {
public:
    Organic(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    std::string getReciclat();
    void toString();
    std::string getType();
    virtual ~Organic();
    void buidat(float pes);
    float quantReciclat();
    
private:
    float reciclat;
};

#endif /* Organic_hpp */
