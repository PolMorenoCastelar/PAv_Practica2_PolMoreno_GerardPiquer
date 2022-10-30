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
    Poblacio();
    Poblacio(ContenidorBrossa* g);
    virtual ~Poblacio();
    void afegirContenidor(ContenidorBrossa *p) noexcept(false);
    void afegirContenidor(std::string codi, int color, std::string ubicacio,int anyColocacio,float tara) noexcept(false);
    std::string hiEs(std::string codi) noexcept(false);
    void eliminarContenidor(ContenidorBrossa *c) noexcept(false);
    ContenidorBrossa* mesRendiment() noexcept(false);
    int getQuants(int color);
    int getQuants();
    bool operator==(Poblacio d);
    bool operator<(Poblacio d);
    bool operator>(Poblacio d);
    void toString();
    
private:
    struct node {
        ContenidorBrossa *con;
        node* seg;
    };
    node** contenidor;
    bool hiEsContenidor(ContenidorBrossa *c, node *contenidor);
    void eliminarRecursivament(node*);
    int onVa(ContenidorBrossa *p);
};

#endif /* Poblacio_hpp */
