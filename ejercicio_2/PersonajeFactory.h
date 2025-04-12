#pragma once
#include "../ejercicio_1/Personajes.h"
#include "../ejercicio_1/Armas.h"
#include <iostream>
#include <memory>
#include <string>

class PersonajeFactory {
    public:
        static std::shared_ptr<Personaje> crearPersonaje(const std::string& tipo);
        static std::shared_ptr<Armas> crearArma(const std::string& tipo);
        static std::shared_ptr<Personaje> PersonajeArmado(const std::string& tipo, const std::string& armaTipo);
        //uso static porque me permite no tener que instanciar la clase
        //uso unique_ptr porque cada personaje es duenio de una unica arma, no es que una arma la utilizan todos los personajes a la vez

};

std::string tipoMagoAleatorio();
std::string tipoGuerreroAleatorio();
std::string tipoArmaMagicaAleatoria();
std::string tipoArmaCombateAleatoria();

