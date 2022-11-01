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
    Poblacio vic2;
    
    Organic *contenidorOrganic = new Organic("OR-1001", "Carrer d'en Pepet, 30", 2010, 150.3);
    Organic *contOrg2 = new Organic("OR-9876", "Carrer d'en Pepito, 2", 2012, 160.3);
    Paper *contenidorPaper = new Paper("AA-3245", "Carrer de la Riera, 17", 2005, 100.5);
    Rebuig *contenidorRebuig = new Rebuig("TG-1234", "Carrer de la Maria, 6", 2003, 90.7);
    Vidre *contenidorVidre = new Vidre("CD-3629", "Carrer d'en Marc, 23", 2006, 130.5);
    Plastic *contenidorPlastic = new Plastic("PL-2005", "Carrer Francesc, 18", 2000, 80.5);
    
    vic.afegirContenidor(contenidorOrganic);
    vic.afegirContenidor(contOrg2);
    vic.afegirContenidor(contenidorPaper);
    vic.afegirContenidor(contenidorRebuig);
    vic.afegirContenidor(contenidorVidre);
    vic.afegirContenidor(contenidorPlastic);
    
    std::cout << vic.hiEs("AA-3245") << std::endl;
    
    std::cout << vic.getQuants(1) << std::endl;
    std::cout << vic.getQuants() << std::endl;
    
    //vic.toString();
    
    /*vic2.afegirContenidor(contOrg2);
    vic2.afegirContenidor(contenidorPaper);
    vic2.afegirContenidor(contenidorRebuig);
    vic2.afegirContenidor(contenidorVidre);
    vic2.afegirContenidor(contenidorPlastic);
    if (vic > vic2) {
        std::cout << "Vic es mes gran que Vic2" << std::endl;
    } else {
        std::cout << "Vic2 es mes gran que Vic" << std::endl;
    }*/
    
    contenidorPaper->buidat(200);
    contenidorOrganic->buidat(300);
    contOrg2->buidat(400);
    contenidorRebuig->buidat(200);
    contenidorVidre->buidat(230);
    contenidorPlastic->buidat(190);
    
    ContenidorBrossa *x=vic.mesRendiment();
    x->toString();
    
    contenidorOrganic->setUbicacio("Prova ubicacio, 12");
    std::cout << contenidorOrganic->getUbicacio() << std::endl;
    std::cout << contenidorOrganic->getCodi() << std::endl;
    std::cout << contenidorOrganic->getEstat() << std::endl;
    std::cout << contenidorOrganic->getTipusBrossa() << std::endl;
    std::cout << contenidorOrganic->getColor() << std::endl;
}
