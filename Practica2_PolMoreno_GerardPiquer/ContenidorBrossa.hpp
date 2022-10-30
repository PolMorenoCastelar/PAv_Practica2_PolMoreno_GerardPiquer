//
//  ContenidorBrossa.hpp
//  Practica2_PolMoreno_GerardPiquer
//
//  Created by Pol Moreno Castelar on 20/10/22.
//

#ifndef ContenidorBrossa_hpp
#define ContenidorBrossa_hpp

#include <stdio.h>
#include <string>

class ContenidorBrossa {
public:
    static const int GROC = 0, MARRO = 1, VERD = 2, GRIS = 3, BLAU = 4;
    ContenidorBrossa(std::string codi, int color, std::string ubicacio, int anyColocacio, float tara) noexcept(false);
    ContenidorBrossa(std::string codi, int color, int anyColocacio, float tara) noexcept(false);
    std::string getTipusBrossa();
    void retirarViaPublica() noexcept(false);
    std::string getUbicacio() noexcept(false);
    void setUbicacio(std::string ubicacio) noexcept(false);
    std::string getCodi();
    std::string getEstat();
    bool operator==(ContenidorBrossa *p);
    bool operator<(ContenidorBrossa *p);
    bool operator>(ContenidorBrossa *p);
    void toString();
    virtual void buidat(float pes) = 0;
    virtual std::string getType() = 0;
    virtual std::string getReciclat() = 0;
    virtual ~ContenidorBrossa();
    virtual float quantReciclat() = 0;
    std::string getColor();
    
private:
    std::string codi;
    int color;
    std::string ubicacio;
    int anyColocacio;
    int anyRetirada;
    void checkParams(std::string, int, int, float) noexcept(false);
    bool checkCodi(std::string codi);
    bool checkAny(int any);

protected:
    int tara;
};

#endif /* ContenidorBrossa_hpp */
