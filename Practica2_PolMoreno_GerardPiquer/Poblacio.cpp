//
//  Poblacio.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#include "Poblacio.hpp"
#include <iostream>
#include <time.h>
#include <string.h>

Poblacio::Poblacio(){
    contenidor = new node*[1];
}
Poblacio::Poblacio(ContenidorBrossa *c){
    Poblacio();
    afegirContenidor(c);
}
void Poblacio::afegirContenidor(ContenidorBrossa *p){
    if(hiEsContenidor(p, *contenidor)){
        throw ("Aquest contenidor ja es troba al magatzem!");
    }
    
    node* aux= new node();
    aux->con=p;
    aux->seg=*contenidor;
    *contenidor = aux;
}

bool Poblacio::hiEsContenidor(ContenidorBrossa *c, node *contenidor){
           while(contenidor!=nullptr){
               if(*c == contenidor->con){
                   return true;
               }
               contenidor=contenidor->seg;
           }
           return false;
}
void Poblacio::afegirContenidor(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara){
    afegirContenidor(new ContenidorBrossa(codi,color,anyColocacio,tara));
}
std::string Poblacio::hiEs(std::string codi){
    node *x =*contenidor;
    while(x!=nullptr){
        if(x->con->getCodi()== codi){
            return "El contenidor amb codi"+codi+" es de color "+x->con->getColor();
        }
       x=x->seg;
    }
    throw ("No es troba a la població");
}

           

