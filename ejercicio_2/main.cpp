#include "PersonajeFactory.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>

int main(){
    std::srand(time(nullptr));

    int cant_Magos = 3 + std::rand() % 5; //3 + [0,4] dando un numero entre 3 y 7
    int cant_Guerreros = 3 + std::rand() % 5;

    std::cout<< "Se van a generar "<< cant_Magos<< "Magos y "<< cant_Guerreros<< "Guerreros." <<std::endl;

    std::vector<std::shared_ptr<Personaje>> personajes;

    for(int i = 0; i < cant_Magos; i++){
        auto mago = PersonajeFactory::PersonajeArmado("Mago", "ArmaMagica");
        if(mago){
            personajes.push_back(mago);
        }
    }

    for(int j = 0; j < cant_Guerreros; j++){
        auto guerrero = PersonajeFactory::PersonajeArmado("Guerrero", "ArmaCombate");
        if(guerrero){
            personajes.push_back(guerrero);
        }
    }

    for(const auto& personaje : personajes){
        personaje->mostrarEstado();
    }
    std::cout<< "Se han generado "<< personajes.size()<< "Personajes." <<std::endl;
    return 0;
}