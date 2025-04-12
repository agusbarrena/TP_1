#pragma once
#include "Personajes.h"
#include "Armas.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Guerrero : public Personaje{
    public:
        Guerrero(std::string nombre, std::string tipo, int HP, int habilidad);
        virtual std::string getNombre() const override;
        virtual std::string getTipo() const override;
        virtual int getHP() const override;
        virtual void agregarArma(std::shared_ptr<Armas>) override;
        virtual void recibirDanio(int danio) override;
        virtual void atacar(Personaje& enemigo) override;
        virtual void mostrarEstado() const override;
        virtual int getHabilidad() const;
        virtual void setHabilidad(int fuerza);
        virtual std::shared_ptr<Armas> getArma() const override;
        virtual std::shared_ptr<Armas> quitarArma() override;
        virtual ~Guerrero() = default;

    protected:
    std::string nombre;
    std::string tipo;
    int HP;
    int habilidad;
    std::vector<std::shared_ptr<Armas>> inventarioGuerrero;
};

class Barbaro : public Guerrero{
    public:
        Barbaro(std::string nombre, std::string tipo, int HP, int habilidad);
        void modoViolento();
        void montaBestia();
        void atacar(Personaje& enemigo) override;
        void recibirDanio(int danio) override;

    private:
    bool estaViolento = false;
    bool bestia = false;
};

class Paladin : public Guerrero{
    public:
        Paladin(std::string nombre, std::string tipo, int HP, int habilidad);
        void habilidadesDeSanacion();
        void escudoSagrado();
        void recibirDanio(int danio) override;

    private:
    bool modoSanador = false;
    bool escudo = false;
};

class Caballero : public Guerrero{
    public:
    Caballero(std::string nombre, std::string tipo, int HP, int habilidad);
    void afinidadConEspada(int danio);
    void usoDeArmadura();
    void atacar(Personaje& enemigo) override;
    void recibirDanio(int danio) override;

    private:
    bool armadura = false;
};

class Mercenario : public Guerrero{
    public:
        Mercenario(std::string nombre, std::string tipo, int HP, int habilidad);
        void robarArmaEnemigo(Personaje& enemigo);
        void conocePuntoDebil();
        void atacar(Personaje& enemigo) override;

    private:
    bool conoce = false;
};