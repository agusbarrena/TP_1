#pragma once
#include "../ejercicio_1/Personajes.h"
#include "../ejercicio_1/Armas.h"
#include <iostream>
#include <memory>
#include <string>

class PersonajeFactory {
    public:
        static std::unique_ptr<Personaje> crearPersonaje(const std::string& tipo, const std::string& subtipo);
        static std::unique_ptr<Armas> crearArma(const std::string& tipo, const std::string& subtipo);
        static std::unique_ptr<Personaje> PersonajeArmado(const std::string& tipo, const std::string& subtipoPersonaje, const std::string& armaTipo, const std::string& subtipoArma);
        //uso static porque me permite no tener que instanciar la clase
};

std::string tipoMagoAleatorio();
std::string tipoGuerreroAleatorio();
std::string tipoArmaMagicaAleatoria();
std::string tipoArmaCombateAleatoria();

