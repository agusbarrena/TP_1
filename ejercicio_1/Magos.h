#pragma once
#include <iostream>
#include "Personajes.h"
#include "Guerreros.h"
#include "Armas.h"
#include <vector>
#include <string>
#include <memory>

class Magos : public Personaje{
    public:
        Magos(std::string nombre, std::string tipo, int HP, int poderMagico);
        virtual std::string getNombre() const override;
        virtual std::string getTipo() const override;
        virtual int getHP() const override;
        virtual void agregarArma(std::unique_ptr<Armas>) override;
        virtual void recibirDanio(int danio) override;
        virtual int atacar(Personaje& enemigo) override;
        virtual void mostrarEstado() const override;
        virtual int getpoderMagico() const;
        virtual void setpoderMagico(int poder);
        virtual const Armas* getArma() const override;
        virtual std::unique_ptr<Armas> quitarArma() override;
        virtual ~Magos() = default;

    protected:
    std::string nombre;
    std::string tipo;
    int HP;
    int poderMagico;
    std::vector<std::unique_ptr<Armas>> inventarioMago;
};

class Hechicero : public Magos{
    public:
        Hechicero(std::string nombre, std::string tipo, int HP, int poderMagico);
        void invocarFuego();
        void leermentes();
        int atacar(Personaje& enemigo) override;
        void recibirDanio(int danio) override;
    private:
    bool leyendoMentes = false;
    bool invocaFuego = false;
};

class Conjurador : public Magos{
    public:
    Conjurador(std::string nombre, std::string tipo, int HP, int poderMagico);
    void conjuraEspectrosNegros();
    void conjuraPrisionMagica();
    int atacar(Personaje& enemigo) override;
    void recibirDanio(int danio) override;

    private:
    bool espectrosNegrosInvocados = false;
    bool prisionMagicaActivada = false;
};

class Brujo : public Magos{
    public:
        Brujo(std::string nombre, std::string tipo, int HP, int poderMagico);
        void arrojaMaldiciones();
        void usaMagiaOscura();
        int atacar(Personaje& enemigo) override;
        void recibirDanio(int danio) override;
    
    private:
    bool maldicionArrojada = false;
    bool magiaOscuraUsada = false;
};

class Nigromante : public Magos{
    public:
        Nigromante(std::string nombre, std::string tipo, int HP, int poderMagico);
        void ojoSauron();
        void sobreviveSinCuerpo();
        void recibirDanio(int danio) override;

    private:
    bool ojoSauronActivado = false;
    bool sinCuerpo = false;
};