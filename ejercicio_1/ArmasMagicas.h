#pragma once
#include "Armas.h"
#include <iostream>

class ArmaMagica : public Armas {
public:
    ArmaMagica(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica);
    virtual std::string getNombre() const override;
    virtual int getDanio() const override;
    virtual std::string getTipo() const override;
    virtual void utilizar() override;
    virtual void cargarMagia(int cantidad);
    virtual int getCargaMagica() const;
    virtual ~ArmaMagica() = default;
protected:
    std::string nombre;
    int danio;
    std::string tipo;
    int cargaMagica;
};

class BastonMagico : public ArmaMagica {
    public:
    BastonMagico(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica);
    void moverSuelo();
    void lanzarRayo();
};

class LibroDeHechizos : public ArmaMagica {
    public:
    LibroDeHechizos(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica);
    void contieneMaldicion();
    void hechizoProhibidoHabilitado();
};

class Pocion : public ArmaMagica {
    public:
    Pocion(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica);
    void aumentarDanio();
    void aumentarCargaMagica();
};

class Amuleto : public ArmaMagica {
    public:
    Amuleto(const std::string& nombre, int danio, const std::string& tipo, int cargaMagica);
    void lanzarUltraLuz();
    void refelajarAtaque();
};

