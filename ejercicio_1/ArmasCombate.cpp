#include "ArmasCombate.h"
#include <iostream>
#include <memory>
#include <string>

ArmaCombate::ArmaCombate(const std::string& nombre, int danio, const std::string& tipo, int durabilidad): nombre(nombre), danio(danio), tipo(tipo), durabilidad(durabilidad) {}

std::string ArmaCombate::getNombre() const{
    return nombre;
}

int ArmaCombate::getDanio() const{
    return danio;
}

std::string ArmaCombate::getTipo() const{
    return "ArmaCombate";
}

void ArmaCombate::utilizar() {
    if (durabilidad > 0){
        durabilidad -= 1;
        std::cout << nombre << " ha sido utilizada. Durabilidad restante: " << durabilidad << "\n";
    }else{
        std::cout << nombre << " no tiene durabilidad suficiente para ser utilizada.\n";
    }
}

void ArmaCombate::setDurabilidad(int cantidad){
    durabilidad = cantidad;
    std::cout << nombre << " ha sido reparada. Durabilidad actual: " << durabilidad << "\n";
}

int ArmaCombate::getDurabilidad() const{
    return durabilidad;
}

HachaSimple::HachaSimple(const std::string& nombre, int danio, const std::string& tipo, int durabilidad): ArmaCombate(nombre, danio, tipo, durabilidad) {}

void HachaSimple::cortarExtremidad(){
    if(durabilidad > 5){
        danio += 10;
        durabilidad -= 2;
        std::cout << nombre << " ha cortado una extremidad. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout<< nombre << "no tiene suficiente durabilidad para cortarle extremidades a su enemigo\n"<<std::endl;
    }
}

void HachaSimple::lanzarHacha(){
    if(durabilidad > 5){
        danio += 10;
        durabilidad -= 2;
        std::cout << nombre << " ha lanzado el hacha. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout<< nombre << "no tiene suficiente durabilidad para lanzar el hacha\n"<<std::endl;
    }
}

HachaDoble::HachaDoble(const std::string& nombre, int danio, const std::string& tipo, int durabilidad): ArmaCombate(nombre, danio, tipo, durabilidad) {}

void HachaDoble::cortarCabeza(){
    if(durabilidad > 5){
        danio += 25;
        durabilidad -= 2;
        std::cout<< nombre << "ha cortado la cabeza del enemigo. Danio aumentado a:"<< danio << "\n"<<std::endl;
    }else{
        std::cout<< nombre << "no tiene suficiente durabilidad para cortar la cabexa del enemigo\n"<<std::endl;
    }
}

void HachaDoble::lanzarHachaDoble(){
    if(durabilidad > 5){
        danio += 10;
        durabilidad -= 2;
        std::cout<< nombre << "ha lanzado el hacha doble. Danio aumentado a:"<< danio << "\n"<<std::endl;
    }else{
        std::cout<< nombre << "no tiene suficiente durabilidad para lanzar el hacha doble\n"<<std::endl;
    }
}

Espada::Espada(const std::string& nombre, int danio, const std::string& tipo, int durabilidad): ArmaCombate(nombre, danio, tipo, durabilidad) {}

void Espada::cortarProfundo(){
    if(durabilidad > 5){
        danio += 15;
        durabilidad -= 2;
        std::cout << nombre << "ha producido un corte profundo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << "no tiene suficiente durabilidad para realizar un corte profundo.\n"<<std::endl;
    }
}

void Espada::apunialarEnemigo(){
    if(durabilidad > 5){
        danio += 20;
        durabilidad -= 2;
        std::cout << nombre << "ha clavado la espada en el corazon del enemigo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << "no tiene suficiente durabilidad para clavar la espada en el corazon del enemigo.\n"<<std::endl;
    }
}

Lanza::Lanza(const std::string& nombre, int danio, const std::string& tipo, int durabilidad): ArmaCombate(nombre, danio, tipo, durabilidad) {}

void Lanza::clavarEnYugular(){
    if(durabilidad > 5){
        danio += 25;
        durabilidad -= 2;
        std::cout << nombre << "ha clavado la lanza en la yugular del enemigo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << "no tiene suficiente durabilidad para clavar la lanza en la yugular del enemigo.\n"<<std::endl;
    }
}

void Lanza::clavarEnCorazon(){
    if(durabilidad > 5){
        danio += 10;
        durabilidad -= 2;
        std::cout << nombre << "ha clavado la lanza en el corazon del enemigo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << "no tiene suficiente durabilidad para clavar la lanza en el corazon del enemigo.\n"<<std::endl;
    }
}

Garrote::Garrote(const std::string& nombre, int danio, const std::string& tipo, int durabilidad): ArmaCombate(nombre, danio, tipo, durabilidad) {}

void Garrote::aturdirCabeza(){
    if(durabilidad > 5){
        danio += 10;
        durabilidad -= 2;
        std::cout << nombre << "ha aturdido la cabeza del enemigo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << "no tiene suficiente durabilidad para aturdir la cabeza del enemigo.\n"<<std::endl;
    }
}

void Garrote::estrangularEnemigo(){
    if(durabilidad > 5){
        danio += 15;
        durabilidad -= 2;
        std::cout << nombre << "ha estrangulado al enemigo. Danio aumentado a: " << danio << "\n"<<std::endl;
    }else{
        std::cout << nombre << "no tiene suficiente durabilidad para estrangular al enemigo.\n"<<std::endl;
    }
}