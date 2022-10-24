//
//  Vidre.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef Vidre_hpp
#define Vidre_hpp

#include <stdio.h>
#include <string>
#include "ContenidorBrossa.hpp"

class Vidre : public ContenidorBrossa {
public:
    Vidre(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    std::string getReciclat();
    void toString();
    std::string getType();
    virtual ~Vidre();
    void buidat(float pes);
    
    
private:
    long reciclat;
};

#endif /* Vidre_hpp */
