#include "Guerreros.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Personajes.h"
Guerrero::Guerrero(std::string nombre, std::string tipo, int HP, int habilidad) : nombre(nombre), tipo(tipo), HP(HP), habilidad(habilidad) {}

std::string Guerrero::getNombre() const {
    return nombre;
}

std::string Guerrero::getTipo() const {
    return "Guerrero";
}

int Guerrero::getHP() const {
    return HP;
}

void Guerrero::agregarArma(std::shared_ptr<Armas> arma) {
    inventarioGuerrero.push_back(arma);
}

void Guerrero::recibirDanio(int danio) {
    HP -= danio;
    if (HP < 0) {
        HP = 0;
    }
}

void Guerrero::atacar(Personaje& enemigo) {
    if (!inventarioGuerrero.empty()) {
        std::cout << nombre << " ataca a " << enemigo.getNombre() << " con " << inventarioGuerrero[0]->getNombre() << "\n";

        int danio = inventarioGuerrero[0]->getDanio();
        enemigo.recibirDanio(danio);

        inventarioGuerrero[0]->utilizar();  // Usa el arma (reduce durabilidad o carga mágica)

    } else {
        std::cout << nombre << " no tiene armas para atacar.\n";
    }
}

void Guerrero::mostrarEstado() const {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "HP: " << HP << "\n";
    std::cout << "Habilidad: " << habilidad << "\n";
    std::cout << "Armas:\n";
    for (const auto& arma : inventarioGuerrero) {
        std::cout << "- " << arma->getNombre() << "\n";
    }
}

int Guerrero::getHabilidad() const {
    return habilidad;
}

void Guerrero::setHabilidad(int fuerza) {
    habilidad = fuerza;
}

std::shared_ptr<Armas> Guerrero::getArma() const {
    if (!inventarioGuerrero.empty()) {
        return inventarioGuerrero[0]; // Devuelve la primera arma del inventario que es con la que ataca
    }
    return nullptr; // si no hay armas, devuelve nullptr
}

std::shared_ptr<Armas> Guerrero::quitarArma() {
    if (!inventarioGuerrero.empty()) {
        auto armaRobada = inventarioGuerrero[0];
        inventarioGuerrero.erase(inventarioGuerrero.begin());
        return armaRobada;
    }
    return nullptr;
}

Barbaro::Barbaro(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Barbaro::modoViolento() {
    if(habilidad > 5){
        estaViolento = true;
        habilidad -= 2;
    }
    std::cout<< "No tiene suficiente habilidad para entrar en modo violento.\n" <<std::endl;
}

void Barbaro::montaBestia() {
    if(habilidad > 5){
        bestia = true;
        habilidad -= 2;
    }
    std::cout<< "No tiene suficiente habilidad para montar una bestia.\n" <<std::endl;
}

void Barbaro::atacar(Personaje& enemigo) {
    if (!inventarioGuerrero.empty()) {
        int danio = inventarioGuerrero[0]->getDanio();

        if (estaViolento) {
            danio *= 2;
            estaViolento = false; //se desactiva el modo violento después de usarlo
            std::cout << nombre << " ataca en modo violento causando " << danio << " de danio.\n"<< std::endl;
        } else {
            std::cout << nombre << " ataca causando " << danio << " de danio.\n"<< std::endl;
        }

        enemigo.recibirDanio(danio);
        inventarioGuerrero[0]->utilizar();
    } else {
        std::cout << nombre << " no tiene armas para atacar.\n"<< std::endl;
    }
}

void Barbaro::recibirDanio(int danio) {
    if (bestia) {
        std::cout << nombre << " está montando una bestia. No recibe danio.\n";
        bestia = false;//se desactiva luego de ser usada
    } else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de danio. HP restante: " << HP << "\n";
    }
}

Paladin::Paladin(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Paladin::habilidadesDeSanacion(){
    if(habilidad > 5){
        modoSanador = true;
        habilidad -= 2;
    }  
    std::cout<< "No tiene suficiente habilidad para usar habilidades de sanacion.\n" <<std::endl;
}

void Paladin::escudoSagrado(){
    if(habilidad > 5){
        escudo = true;
        habilidad -= 2;
    }  
    std::cout<< "No tiene suficiente habilidad para usar el escudo sagrado.\n" <<std::endl;
}

void Paladin::recibirDanio(int danio) {
    if (escudo) {
        std::cout << nombre << "esta utilizando el escudo sagrado. No recibe danio.\n"<< std::endl;
        escudo = false; //se desactiva luego de ser usada
    }else if(modoSanador){
        std::cout << nombre << "esta utilizando habilidades de sanacion. No recibe danio.\n"<< std::endl;
        modoSanador = false; //se desactiva luego de ser usada
    }
    else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de danio. HP restante: " << HP << "\n";
    }
}

Caballero::Caballero(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Caballero::usoDeArmadura(){
    if (habilidad > 5) {
        armadura = true;
        habilidad -= 2;
    } else {
        std::cout << nombre << " no tiene suficiente habilidad para usar armadura.\n";
    }
}

void Caballero::afinidadConEspada(int danio){
    danio *= 2;
    std::cout << nombre << " ataca con su espada causando " << danio << " de danio.\n"<<std::endl;
}

void Caballero::atacar(Personaje& enemigo){
    if(!inventarioGuerrero.empty()){
        int danio = inventarioGuerrero[0]->getDanio();

        if(inventarioGuerrero[0]->getNombre() == "Espada"){
            danio *= 2;
            std::cout<< "ataca con espada causando"<< danio << "de danio.\n" <<std::endl;
        }else{
            std::cout << nombre << " ataca causando " << danio << " de danio.\n"<< std::endl;
        }

        enemigo.recibirDanio(danio);
        inventarioGuerrero[0]->utilizar();
    }else{
        std::cout<<"No tiene armas para atacar"<<std::endl;
    }
}

void Caballero::recibirDanio(int danio){
    if (armadura) {
        std::cout << nombre << " esta usando una armadura. No recibe danio.\n";
        armadura = false;//se desactiva luego de ser usada
    } else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de danio. HP restante: " << HP << "\n";
    }
}

Mercenario::Mercenario(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Mercenario::robarArmaEnemigo(Personaje& enemigo) {
    if (inventarioGuerrero.empty()) {
        auto armaRobada = enemigo.quitarArma();
        if (armaRobada) {
            inventarioGuerrero.push_back(armaRobada);
            std::cout << nombre << " ha robado el arma : " << armaRobada->getNombre() << " de " << enemigo.getNombre() << "!\n";
        } else {
            std::cout << enemigo.getNombre() << " no tiene arma para robar.\n";
        }
    }
}

void Mercenario::conocePuntoDebil(){
    if(habilidad > 5){
        conoce = true;
        habilidad-= 2;
    }else{
        std::cout<< "No tiene la habilidad suficiente para identificar punto debil.\n" <<std::endl;
    }
}

void Mercenario::atacar(Personaje& enemigo) {

    robarArmaEnemigo(enemigo); //intenta robar el arma

    if (!inventarioGuerrero.empty()) {
        int danio = inventarioGuerrero[0]->getDanio();
        if (conoce) {
            danio *= 2;
            conoce = false;
            std::cout << nombre << " conoce el punto débil de " << enemigo.getNombre() << ".\n";
        }

        std::cout << nombre << " ataca causando " << danio << " de danio.\n";
        enemigo.recibirDanio(danio);
        inventarioGuerrero[0]->utilizar();
        
    } else {
        std::cout << nombre << " no tiene armas para atacar.\n";
    }
}






