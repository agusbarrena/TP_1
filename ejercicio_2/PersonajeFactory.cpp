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

std::shared_ptr<Personaje> PersonajeFactory::crearPersonaje(const std::string& tipo, const std::string& subtipo) {
    if (subtipo == "0") { // se crea personaje aleatorio
        if (tipo == "Mago") {
            std::string tipoMago = tipoMagoAleatorio();
            if (tipoMago == "Hechicero") {
                return std::make_shared<Hechicero>("Hechicero", tipo, 100, 10);
            } else if (tipoMago == "Conjurador") {
                return std::make_shared<Conjurador>("Conjurador", tipo, 100, 10);
            } else if (tipoMago == "Brujo") {
                return std::make_shared<Brujo>("Brujo", tipo, 100, 10);
            } else if (tipoMago == "Nigromante") {
                return std::make_shared<Nigromante>("Nigromante", tipo, 100, 10);
            }
        } else if (tipo == "Guerrero") {
            std::string tipoGuerrero = tipoGuerreroAleatorio();
            if (tipoGuerrero == "Barbaro") {
                return std::make_shared<Barbaro>("Barbaro", tipo, 100, 10);
            } else if (tipoGuerrero == "Paladin") {
                return std::make_shared<Paladin>("Paladin", tipo, 100, 10);
            } else if (tipoGuerrero == "Caballero") {
                return std::make_shared<Caballero>("Caballero", tipo, 100, 10);
            } else if (tipoGuerrero == "Mercenario") {
                return std::make_shared<Mercenario>("Mercenario", tipo, 100, 10);
            }
        }
    }

    if (tipo == "Mago") {
        if (subtipo == "Hechicero") {
            return std::make_shared<Hechicero>("Hechicero", tipo, 100, 10);
        } else if (subtipo == "Conjurador") {
            return std::make_shared<Conjurador>("Conjurador", tipo, 100, 10);
        } else if (subtipo == "Brujo") {
            return std::make_shared<Brujo>("Brujo", tipo, 100, 10);
        } else if (subtipo == "Nigromante") {
            return std::make_shared<Nigromante>("Nigromante", tipo, 100, 10);
        }
    } else if (tipo == "Guerrero") {
        if (subtipo == "Barbaro") {
            return std::make_shared<Barbaro>("Barbaro", tipo, 100, 10);
        } else if (subtipo == "Paladin") {
            return std::make_shared<Paladin>("Paladin", tipo, 100, 10);
        } else if (subtipo == "Caballero") {
            return std::make_shared<Caballero>("Caballero", tipo, 100, 10);
        } else if (subtipo == "Mercenario") {
            return std::make_shared<Mercenario>("Mercenario", tipo, 100, 10);
        }
    }

    return nullptr; 
}

std::shared_ptr<Armas> PersonajeFactory::crearArma(const std::string& tipo, const std::string& subtipo) {
    if (subtipo == "0") {
        if (tipo == "ArmaMagica") {
            std::string tipoArmaMagica = tipoArmaMagicaAleatoria();
            if (tipoArmaMagica == "Baston Magico") {
                return std::make_shared<BastonMagico>("Baston Magico", 10, tipo, 10);
            } else if (tipoArmaMagica == "Libro de Hechizos") {
                return std::make_shared<LibroDeHechizos>("Libro de Hechizos", 10, tipo, 10);
            } else if (tipoArmaMagica == "Pocion") {
                return std::make_shared<Pocion>("Pocion", 10, tipo, 10);
            } else if (tipoArmaMagica == "Amuleto") {
                return std::make_shared<Amuleto>("Amuleto", 10, tipo, 10);
            }
        } else if (tipo == "ArmaCombate") {
            std::string tipoArmaCombate = tipoArmaCombateAleatoria();
            if (tipoArmaCombate == "Hacha Simple") {
                return std::make_shared<HachaSimple>("Hacha Simple", 10, tipo, 10);
            } else if (tipoArmaCombate == "Hacha Doble") {
                return std::make_shared<HachaDoble>("Hacha Doble", 10, tipo, 10);
            } else if (tipoArmaCombate == "Espada") {
                return std::make_shared<Espada>("Espada", 10 , tipo, 10);
            } else if (tipoArmaCombate == "Lanza") {
                return std::make_shared<Lanza>("Lanza", 10, tipo, 10);
            } else if (tipoArmaCombate == "Garrote") {
                return std::make_shared<Garrote>("Garrote", 10, tipo, 10);
            }
        }
    }

    if (tipo == "ArmaMagica") {
        if (subtipo == "Baston Magico") {
            return std::make_shared<BastonMagico>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Libro de Hechizos") {
            return std::make_shared<LibroDeHechizos>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Pocion") {
            return std::make_shared<Pocion>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Amuleto") {
            return std::make_shared<Amuleto>(subtipo, 10, tipo, 10);
        }
    } else if (tipo == "ArmaCombate") {
        if (subtipo == "Hacha Simple") {
            return std::make_shared<HachaSimple>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Hacha Doble") {
            return std::make_shared<HachaDoble>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Espada") {
            return std::make_shared<Espada>(subtipo, 10 , tipo, 10);
        } else if (subtipo == "Lanza") {
            return std::make_shared<Lanza>(subtipo, 10, tipo, 10);
        } else if (subtipo == "Garrote") {
            return std::make_shared<Garrote>(subtipo, 10, tipo, 10);
        }
    }

    return nullptr; 
}

    
std::shared_ptr<Personaje> PersonajeFactory::PersonajeArmado(const std::string& tipo, const std::string& subtipoPersonaje, const std::string& armaTipo, const std::string& subtipoArma){
    auto personaje = crearPersonaje(tipo, subtipoPersonaje);
    if (!personaje) {
        return nullptr;
    }

    int cantidadArmas = std::rand() % 3;//genera un numero entre 0 y 2
    for(int i = 0; i < cantidadArmas; i++){
        auto arma = crearArma(armaTipo, subtipoArma);
        if(arma){
            personaje->agregarArma(arma);
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
        default: return "Hecehicero"; //en caso de error usa Hechicero por defecto

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


