#include "../ejercicio_2/PersonajeFactory.h"
#include "../ejercicio_1/Guerreros.h"
#include "../ejercicio_1/Magos.h"
#include "../ejercicio_1/ArmasCombate.h"
#include "../ejercicio_1/ArmasMagicas.h"
#include "../ejercicio_1/Personajes.h"
#include "../ejercicio_1/Armas.h"
#include "simularBatalla.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

std::string accionToString(Accion accion) {
    switch (accion) {
        case Accion::GOLPE_FUERTE: return "Golpe Fuerte";
        case Accion::GOLPE_RAPIDO: return "Golpe Rápido";
        case Accion::DEFENSA_Y_GOLPE: return "Defensa y Golpe";
        default: return "Desconocido";
    }
}



// Función que determina como se desarrolla la batalla con la estructura de un piedra, papel y tijera
void batalla(std::unique_ptr<Personaje>& personaje1, std::unique_ptr<Personaje>& personaje2, Accion accion1, Accion accion2) {
    
    //utilizo los metodos de ataque implementados en el ejercicio_1 
    if (auto barbaro = dynamic_cast<Barbaro*>(personaje1.get())) barbaro->modoViolento();
    if (auto mercenario = dynamic_cast<Mercenario*>(personaje1.get())) mercenario->conocePuntoDebil();
    if (auto conjurador = dynamic_cast<Conjurador*>(personaje1.get())) conjurador->conjuraEspectrosNegros();
    if (auto brujo = dynamic_cast<Brujo*>(personaje1.get())) brujo->usaMagiaOscura();
    if(auto caballero = dynamic_cast<Caballero*>(personaje2.get())) caballero->afinidadConEspada();
    if (auto hechicero = dynamic_cast<Hechicero*>(personaje1.get())) hechicero->invocarFuego();
    if (auto mercenario = dynamic_cast<Mercenario*>(personaje1.get())) mercenario->robarArmaEnemigo(*personaje2);
    if (auto mercenario = dynamic_cast<Mercenario*>(personaje2.get())) mercenario->robarArmaEnemigo(*personaje1);

    std::cout << personaje1->getNombre() << " usa " << accionToString(accion1) << "\n";
    std::cout << personaje2->getNombre() << " usa " << accionToString(accion2) << "\n";

    if (accion1 == accion2) {
        std::cout << "¡Empate! No hay daño.\n";
        return;
    }

    //se define quien gana la ronda
    if ((accion1 == Accion::GOLPE_FUERTE && accion2 == Accion::GOLPE_RAPIDO) || (accion1 == Accion::GOLPE_RAPIDO && accion2 == Accion::DEFENSA_Y_GOLPE) || (accion1 == Accion::DEFENSA_Y_GOLPE && accion2 == Accion::GOLPE_FUERTE)) {
        int danio1 = 0;
        danio1 = personaje1->atacar(*personaje2);  //ya el danio es aplicado en el ataque
        if(!personaje1->getArma()){
            std::cout<< personaje1->getNombre() <<" ataca sin arma haciendo " << danio1 << " puntos de daño.\n";
        }else{
            std::cout << personaje1->getNombre() << " ataca con " << personaje1->getArma()->getNombre() << " y hace " << danio1 << " puntos de daño.\n";
        }

    } else {
        int danio2 = 0;
        danio2 = personaje2->atacar(*personaje1);  //ya el danio es aplicado en el ataque
        if(!personaje2->getArma()){
            std::cout<< personaje2->getNombre() <<" ataca sin arma haciendo " << danio2 << " puntos de daño.\n";
        }else{
            std::cout << personaje2->getNombre() << " ataca con " << personaje2->getArma()->getNombre() << " y hace " << danio2 << " puntos de daño.\n";
        }
    }

    //utilizo los metodos de defensa implementados en el ejercicio_1
    if (auto paladin = dynamic_cast<Paladin*>(personaje1.get())){
        paladin->escudoSagrado();
        paladin->habilidadesDeSanacion();
    }
    if (auto caballero = dynamic_cast<Caballero*>(personaje1.get())) caballero->usoDeArmadura();
    if (auto hechicero = dynamic_cast<Hechicero*>(personaje2.get())) hechicero->leermentes();
    if (auto nigromante = dynamic_cast<Nigromante*>(personaje1.get())) {
        nigromante->ojoSauron();
        nigromante->sobreviveSinCuerpo();
    }
    if (auto barbaro = dynamic_cast<Barbaro*>(personaje2.get())) barbaro->montaBestia();
    if(auto caballero = dynamic_cast<Caballero*>(personaje2.get())) caballero->usoDeArmadura();
    if (auto conjurador = dynamic_cast<Conjurador*>(personaje2.get())) conjurador->conjuraPrisionMagica();
    if (auto brujo = dynamic_cast<Brujo*>(personaje2.get())) brujo->arrojaMaldiciones();
}

Accion opcionUsuario() {
    int opcion;
    std::cout << "Elija una opcion: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe :";
    std::cin >> opcion;

    while (opcion < 1 || opcion > 3) {
        std::cout << "Opcion invalida, intente nuevamente: ";
        std::cin >> opcion;
    }

    return static_cast<Accion>(opcion);
}

Accion opcionMaquina() {
    return static_cast<Accion>(1 + std::rand() % 3);
}

std::string tipoJugadorAleatorio(){
    int tipoJugador2 = std::rand() % 2;

    if(tipoJugador2 == 0){
        return "Mago";
    }else{
        return "Guerrero";
    }
}

