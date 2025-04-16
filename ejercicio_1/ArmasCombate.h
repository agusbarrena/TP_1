#pragma once
#include "Armas.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ArmaCombate : public Armas {
    public:
    ArmaCombate(const std::string& nombre, int danio, const std::string& tipo, int durabilidad);
    virtual std::string getNombre() const override;
    virtual int getDanio() const override;
    virtual std::string getTipo() const override;
    virtual bool utilizar() override;
    virtual void setDurabilidad(int cantidad);
    virtual int getDurabilidad() const;
    virtual ~ArmaCombate() = default;

    protected:
    std::string nombre;
    int danio;
    std::string tipo;
    int durabilidad;
};

class HachaSimple : public ArmaCombate {
    public:
    HachaSimple(const std::string& nombre, int danio, const std::string& tipo, int durabilidad);
    void cortarExtremidad();
    void lanzarHacha();
};

class HachaDoble : public ArmaCombate{
    public: 
    HachaDoble(const std::string& nombre, int danio, const std::string& tipo, int durabilidad);
    void cortarCabeza();
    void lanzarHachaDoble();
};

class Espada : public ArmaCombate{
    public:
    Espada(const std::string& nombre, int danio, const std::string& tipo, int durabilidad);
    void cortarProfundo();
    void apunialarEnemigo();
};

class Lanza : public ArmaCombate{
    public:
    Lanza(const std::string& nombre, int danio, const std::string& tipo, int durabilidad);
    void clavarEnYugular();
    void clavarEnCorazon();
};

class Garrote : public ArmaCombate{
    public:
    Garrote(const std::string& nombre, int danio, const std::string& tipo, int durabilidad);
    void aturdirCabeza();
    void estrangularEnemigo();
};