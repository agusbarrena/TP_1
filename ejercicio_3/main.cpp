#include "simularBatalla.h"
#include "../ejercicio_2/PersonajeFactory.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>
#include <vector>
#include <limits>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "=== BATALLA ENTRE DOS PERSONAJES ===\n";

    std::string tipoJugador1;
    std::cout << "Ingrese tipo de personaje {Mago o Guerrero}: ";
    std::cin >> tipoJugador1;
    std::string subtipoJugador1;
    std::cout <<"Ingrese que tipo de " << tipoJugador1 << " desea ser Mago{Hechicero, Conjurador, Brujo, Nigromante} o si es Guerrero{Barbaro, Paladin, Caballero, Mercenario} o 0 para aleatorio: ";
    std::cin >> subtipoJugador1;
    
    std::string tipoArma1;
    if(tipoJugador1 == "Mago"){
        tipoArma1 = "ArmaMagica";
    }else{
        tipoArma1 = "ArmaCombate";
    }
    
    std::string subtipoArma1;
    std::cout << "Ingrese que tipo de " << tipoArma1 <<": ArmaMagica{Baston Magico, Libro de Hechizos, Pocion y Amuleto} o si es  ArmaCombate{Hacha Simple, Hacha Doble, Espada, Lanza o Garrote} o 0 para aleatorio: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, subtipoArma1);

    auto jugador1 = PersonajeFactory::PersonajeArmado(tipoJugador1, subtipoJugador1, tipoArma1, subtipoArma1);

    auto tipoJugador2 = tipoJugadorAleatorio();

    std::string tipoArma2;
    if(tipoJugador2 == "Mago"){
        tipoArma2 = "ArmaMagica";   
    }else{
        tipoArma2 = "ArmaCombate";
    }

    auto jugador2 = PersonajeFactory::PersonajeArmado(tipoJugador2, "0", tipoArma2, "0"); // aleatorio

    if (!jugador1 ) {
        std::cerr << "Error al generar personajes.\n";
        return 1;
    }

    if(!jugador1->getArma()){
        std::cout << "Jugador 1: " <<jugador1->getNombre() << " con ningun arma \n" <<std::endl; 
    }else{
        std::cout << "Jugador 1: " << jugador1->getNombre() << " con " << (jugador1->getArma())->getNombre() << "\n";  
    }
    if(!jugador2->getArma()){
        std::cout << "Jugador 2: " <<jugador2->getNombre() << " con ningun arma \n" <<std::endl; 
    }else{
        std::cout << "Jugador 2: " << jugador2->getNombre() << " con " << (jugador2->getArma())->getNombre() << "\n"; //va a mostrar solo primer arma del inventario puede tener mas ya que, se pueden crear de [0..2]
    }
    
    while (jugador1->getHP() > 0 && jugador2->getHP() > 0) {
        std::cout << "\n== Estado Actual ==\n";
        std::cout << "Jugador 1 HP: " << jugador1->getHP() << "\n";
        std::cout << "Jugador 2 HP: " << jugador2->getHP() << "\n";

        Accion accion1 = opcionUsuario();
        Accion accion2 = opcionMaquina();

        batalla(jugador1, jugador2, accion1, accion2);
    }

    std::cout << "\n=== RESULTADO FINAL ===\n";
    std::cout << "Jugador 1 HP: " << jugador1->getHP() << "\n";
    std::cout << "Jugador 2 HP: " << jugador2->getHP() << "\n";

    if (jugador1->getHP() <= 0)
        std::cout << jugador2->getNombre() <<" ha ganado!\n";
    else
        std::cout <<  jugador1->getNombre() <<" ha ganado!\n";

    return 0;
}
