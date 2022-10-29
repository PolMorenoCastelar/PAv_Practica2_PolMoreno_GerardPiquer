//
//  main.cpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 18/10/22.
//

#include <iostream>
#include "Poblacio.hpp"
#include "Paper.hpp"
#include "Plastic.hpp"
#include "Rebuig.hpp"
#include "Vidre.hpp"
#include "Organic.hpp"


using namespace std;

int main() {
    Poblacio vic;
    ContenidorBrossa** taula;
    taula = new ContenidorBrossa*[5];
    try {
        taula[4] = new Paper("AA-3245", "Carrer de la Riera, 17", 2005, 100.5);
        taula[3] = new Rebuig("TG-1234", "Carrer de la Maria, 6", 2003, 90.7);
        taula[2] = new Vidre("CD-3629", "Carrer d'en Marc, 23", 2006, 130.5);
        taula[1] = new Organic("OR-9876", "Carrer d'en Pepito, 2", 2012, 160.3);
        taula[0] = new Plastic("PL-2005", "Carrer Francesc, 18", 2000, 80.5);
    } catch (char *t) {
        std::cout << "S'ha trobat una excepció" << std::endl;
    }
    
    Organic *contenidorOrganic = new Organic("OR-1001", "Carrer d'en Pepet, 30", 2010, 150.3);
    vic.afegirContenidor(contenidorOrganic);
    vic.afegirContenidor("PA-5030", 0, "Carrer Francesc Arimany, 28", 2020, 200.3);
    std::cout << vic.getQuants(0) << std::endl;
    std::cout << vic.getQuants() << std::endl;
    vic.toString();
    taula[4]->toString();
    taula[3]->toString();
    taula[2]->toString();
    taula[1]->toString();
    taula[0]->toString();
    delete taula[4];
    delete taula[3];
    delete taula[2];
    delete taula[1];
    delete taula[0];
    delete taula;
}
