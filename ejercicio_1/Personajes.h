#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "Armas.h"
class Personaje {
    public:
    virtual ~Personaje() = default;
    virtual std::string getNombre() const = 0;
    virtual std::string getTipo() const = 0;
    virtual int getHP() const = 0;
    virtual void agregarArma(std::unique_ptr<Armas>) = 0;
    virtual void recibirDanio(int danio) = 0;
    virtual int atacar(Personaje& enemigo) = 0;
    virtual void mostrarEstado() const = 0;
    virtual std::unique_ptr<Armas> quitarArma() = 0;
    virtual const Armas* getArma() const = 0;
};