//
//  Paper.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef Paper_hpp
#define Paper_hpp

#include <stdio.h>
#include <string>
#include "ContenidorBrossa.hpp"

class Paper : public ContenidorBrossa {
public:
    Paper(std::string codi, std::string ubicacio, int anyColocacio, float tara);
    std::string getReciclat();
    void toString();
    std::string getType();
    virtual ~Paper();
    void buidat(float pes);
    float quantReciclat();
    
    
private:
    float reciclat;
};

#endif /* Paper_hpp */
