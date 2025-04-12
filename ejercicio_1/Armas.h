#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Armas {
public:
    virtual ~Armas() = default;
    virtual std::string getNombre() const = 0;
    virtual int getDanio() const = 0;
    virtual std::string getTipo() const = 0;
    virtual void utilizar() = 0;
};