//
//  Poblacio.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef Poblacio_hpp
#define Poblacio_hpp

#include <stdio.h>
#include "ContenidorBrossa.hpp"

class Poblacio {
public:

private:
    struct node {
        ContenidorBrossa *con;
        node* seg;
    };
};

#endif /* Poblacio_hpp */
