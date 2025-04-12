#include "ArmasMagicas.h"
#include <iostream>
#include <memory>
#include <string>

ArmaMagica::ArmaMagica(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica) : nombre(nombre), danio(danio), tipo(tipo), cargaMagica(cargaMagica) {}

std::string ArmaMagica::getNombre() const{
    return nombre;
}

int ArmaMagica::getDanio() const{
    return danio;
}

std::string ArmaMagica::getTipo() const{
    return "ArmaMagica";
}

void ArmaMagica::utilizar(){
    if (cargaMagica > 0){
        cargaMagica -= 1;
        std::cout << nombre << " ha sido utilizada. Carga mágica restante: " << cargaMagica << "\n";
    }else{
        std::cout << nombre << " no tiene carga mágica suficiente para ser utilizada.\n";
    }
}

void ArmaMagica::cargarMagia(int cantidad){
    cargaMagica += cantidad;
    std::cout << nombre << " ha sido recargada. Carga mágica actual: " << cargaMagica << "\n";
}

int ArmaMagica::getCargaMagica() const{
    return cargaMagica;
}

BastonMagico::BastonMagico(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica) : ArmaMagica(nombre, danio, tipo, cargaMagica) {}

void BastonMagico::moverSuelo(){
    if(cargaMagica > 5){
        danio += 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha movido el suelo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para mover el suelo.\n"<<std::endl;
    }
}

void BastonMagico::lanzarRayo(){
    if(cargaMagica > 5){
        danio+= 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha lanzado un rayo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para lanzar un rayo.\n"<<std::endl;
    }   
}

LibroDeHechizos::LibroDeHechizos(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica) : ArmaMagica(nombre, danio, tipo, cargaMagica) {}

void LibroDeHechizos::contieneMaldicion(){
    if(cargaMagica > 5){
        danio += 10;
        cargaMagica -= 2;
        std::cout << nombre << " contiene una maldición. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para contener una maldición.\n"<<std::endl;
    }
}

void LibroDeHechizos::hechizoProhibidoHabilitado(){
    if(cargaMagica > 5){
        danio += 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha habilitado un hechizo prohibido. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para habilitar un hechizo prohibido.\n"<<std::endl;
    }
}

Pocion::Pocion(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica) : ArmaMagica(nombre, danio, tipo, cargaMagica) {}

void Pocion::aumentarDanio(){
    if(cargaMagica > 5){
        danio += 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha aumentado el danioo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para aumentar el danio.\n"<<std::endl;
    }
}

void Pocion::aumentarCargaMagica(){
    if(cargaMagica > 5){
        cargaMagica += 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha aumentado la carga mágica. Carga mágica aumentada a: " << cargaMagica << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para aumentar la carga mágica.\n"<<std::endl;
    }
}

Amuleto::Amuleto(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica) : ArmaMagica(nombre, danio, tipo, cargaMagica) {}

void Amuleto::lanzarUltraLuz(){
    if(cargaMagica > 5){
        danio += 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha lanzado una ultra luz. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para lanzar una ultra luz.\n"<<std::endl;
    }
}

void Amuleto::refelajarAtaque(){
    if(cargaMagica > 5){
        danio += 10;
        cargaMagica -= 2;
        std::cout << nombre << " ha relajado el ataque. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << " no tiene suficiente carga mágica para relajar el ataque.\n"<<std::endl;
    }
}