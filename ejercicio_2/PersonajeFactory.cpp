#include "PersonajeFactory.h"
#include "../ejercicio_1/Magos.h"
#include "../ejercicio_1/Guerreros.h"
#include "../ejercicio_1/ArmasCombate.h"
#include "../ejercicio_1/ArmasMagicas.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<Personaje> PersonajeFactory::crearPersonaje(const std::string& tipo, const std::string& subtipo) {
    if (subtipo == "0") { // se crea personaje aleatorio
        if (tipo == "Mago") {
            std::string tipoMago = tipoMagoAleatorio();
            if (tipoMago == "Hechicero") {
                return std::make_unique<Hechicero>("Hechicero", tipo, 100, 10);
            } else if (tipoMago == "Conjurador") {
                return std::make_unique<Conjurador>("Conjurador", tipo, 100, 10);
            } else if (tipoMago == "Brujo") {
                return std::make_unique<Brujo>("Brujo", tipo, 100, 10);
            } else if (tipoMago == "Nigromante") {
                return std::make_unique<Nigromante>("Nigromante", tipo, 100, 10);
            }
        } else if (tipo == "Guerrero") {
            std::string tipoGuerrero = tipoGuerreroAleatorio();
            if (tipoGuerrero == "Barbaro") {
                return std::make_unique<Barbaro>("Barbaro", tipo, 100, 10);
            } else if (tipoGuerrero == "Paladin") {
                return std::make_unique<Paladin>("Paladin", tipo, 100, 10);
            } else if (tipoGuerrero == "Caballero") {
                return std::make_unique<Caballero>("Caballero", tipo, 100, 10);
            } else if (tipoGuerrero == "Mercenario") {
                return std::make_unique<Mercenario>("Mercenario", tipo, 100, 10);
            }
        }
    }

    if (tipo == "Mago") {
        if (subtipo == "Hechicero") {
            return std::make_unique<Hechicero>("Hechicero", tipo, 100, 10);
        } else if (subtipo == "Conjurador") {
            return std::make_unique<Conjurador>("Conjurador", tipo, 100, 10);
        } else if (subtipo == "Brujo") {
            return std::make_unique<Brujo>("Brujo", tipo, 100, 10);
        } else if (subtipo == "Nigromante") {
            return std::make_unique<Nigromante>("Nigromante", tipo, 100, 10);
        }
    } else if (tipo == "Guerrero") {
        if (subtipo == "Barbaro") {
            return std::make_unique<Barbaro>("Barbaro", tipo, 100, 10);
        } else if (subtipo == "Paladin") {
            return std::make_unique<Paladin>("Paladin", tipo, 100, 10);
        } else if (subtipo == "Caballero") {
            return std::make_unique<Caballero>("Caballero", tipo, 100, 10);
        } else if (subtipo == "Mercenario") {
            return std::make_unique<Mercenario>("Mercenario", tipo, 100, 10);
        }
    }

    return nullptr; 
}

std::unique_ptr<Armas> PersonajeFactory::crearArma(const std::string& tipo, const std::string& subtipo) {
    if (subtipo == "0") {
        if (tipo == "ArmaMagica") {
            std::string tipoArmaMagica = tipoArmaMagicaAleatoria();
            if (tipoArmaMagica == "Baston Magico") {
                return std::make_unique<BastonMagico>("Baston Magico", 10, tipo, 10);
            } else if (tipoArmaMagica == "Libro de Hechizos") {
                return std::make_unique<LibroDeHechizos>("Libro de Hechizos", 10, tipo, 10);
            } else if (tipoArmaMagica == "Pocion") {
                return std::make_unique<Pocion>("Pocion", 10, tipo, 10);
            } else if (tipoArmaMagica == "Amuleto") {
                return std::make_unique<Amuleto>("Amuleto", 10, tipo, 10);
            }
        } else if (tipo == "ArmaCombate") {
            std::string tipoArmaCombate = tipoArmaCombateAleatoria();
            if (tipoArmaCombate == "Hacha Simple") {
                return std::make_unique<HachaSimple>("Hacha Simple", 10, tipo, 10);
            } else if (tipoArmaCombate == "Hacha Doble") {
                return std::make_unique<HachaDoble>("Hacha Doble", 10, tipo, 10);
            } else if (tipoArmaCombate == "Espada") {
                return std::make_unique<Espada>("Espada", 10 , tipo, 10);
            } else if (tipoArmaCombate == "Lanza") {
                return std::make_unique<Lanza>("Lanza", 10, tipo, 10);
            } else if (tipoArmaCombate == "Garrote") {
                return std::make_unique<Garrote>("Garrote", 10, tipo, 10);
            }
        }
    }

    if (tipo == "ArmaMagica") {
        if (subtipo == "Baston Magico") {
            return std::make_unique<BastonMagico>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Libro de Hechizos") {
            return std::make_unique<LibroDeHechizos>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Pocion") {
            return std::make_unique<Pocion>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Amuleto") {
            return std::make_unique<Amuleto>(subtipo, 10, tipo, 10);
        }
    } else if (tipo == "ArmaCombate") {
        if (subtipo == "Hacha Simple") {
            return std::make_unique<HachaSimple>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Hacha Doble") {
            return std::make_unique<HachaDoble>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Espada") {
            return std::make_unique<Espada>(subtipo, 10 , tipo, 10);
        } else if (subtipo == "Lanza") {
            return std::make_unique<Lanza>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Garrote") {
            return std::make_unique<Garrote>(subtipo, 10, tipo, 10);
        }
    }

    return nullptr; 
}

    
std::unique_ptr<Personaje> PersonajeFactory::PersonajeArmado(const std::string& tipo, const std::string& subtipoPersonaje, const std::string& armaTipo, const std::string& subtipoArma){
    auto personaje = crearPersonaje(tipo, subtipoPersonaje);
    if (!personaje) {
        return nullptr;
    }

    int cantidadArmas = std::rand() % 3;//genera un numero entre 0 y 2
    for(int i = 0; i < cantidadArmas; i++){
        auto arma = crearArma(armaTipo, subtipoArma);
        if(arma){
            personaje->agregarArma(std::move(arma));
        }
    }
    return personaje;
}

std::string tipoMagoAleatorio(){
    int tipoMago = std::rand() % 4;
    switch(tipoMago){
        case 0: return "Hechicero";
        case 1: return "Conjurador";
        case 2: return "Brujo";
        case 3: return "Nigromante";
        default: return "Hechicero"; //en caso de error usa Hechicero por defecto

    }
}

std::string tipoGuerreroAleatorio(){
    int tipoGuerrero = std::rand() % 4;
    switch(tipoGuerrero){
        case 0: return "Barbaro";
        case 1: return "Paladin";
        case 2: return "Caballero";
        case 3: return "Mercenario";
        default: return "Barbaro"; //en caso de error usa Barbaro por defecto

    }
}

std::string tipoArmaMagicaAleatoria(){
    int tipoArmaMagica = std::rand() % 4;
    switch(tipoArmaMagica){
        case 0: return "Baston Magico";
        case 1: return "Libro de Hechizos";
        case 2: return "Pocion";
        case 3: return "Amuleto";
        default: return "Baston Magico"; //en caso de error usa Baston Magico por defecto

    }
}

std::string tipoArmaCombateAleatoria(){
    int tipoArmaCombate = std::rand() % 5;
    switch(tipoArmaCombate){
        case 0: return "Hacha Simple";
        case 1: return "Hacha Doble";
        case 2: return "Espada";
        case 3: return "Lanza";
        case 4: return "Garrote";
        default: return "Hacha Simple";//en caso de error usa Espada por defecto

    }
}


