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

void Guerrero::agregarArma(std::unique_ptr<Armas> arma) {
    inventarioGuerrero.push_back(std::move(arma));
}

void Guerrero::recibirDanio(int danio) {
    HP -= danio;
    if (HP < 0) {
        HP = 0;
    }
    std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
}

int Guerrero::atacar(Personaje& enemigo) {
    if (!inventarioGuerrero.empty() && inventarioGuerrero[0]) {

        if(inventarioGuerrero[0]->utilizar()){
            int danio = inventarioGuerrero[0]->getDanio();
            enemigo.recibirDanio(danio);
            return danio;
        }else{
            inventarioGuerrero.erase(inventarioGuerrero.begin());  //saca el arma del inventario
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
        
    } else {
        int danio = 10; // si no tiene arma hace un ataque igual a 10 tb
        enemigo.recibirDanio(danio);
        return danio;
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
    std::cout << "------------------------\n";
}

int Guerrero::getHabilidad() const {
    return habilidad;
}

void Guerrero::setHabilidad(int fuerza) {
    habilidad = fuerza;
}

const Armas* Guerrero::getArma() const {
    if (!inventarioGuerrero.empty()) {
        return inventarioGuerrero[0].get(); // devuelve la primera arma del inventario que es con la que ataca
    }
    return nullptr; // si no hay armas devuelve nullptr
}

std::unique_ptr<Armas> Guerrero::quitarArma() {
    if (!inventarioGuerrero.empty()) {
        auto armaRobada = std::move(inventarioGuerrero[0]);
        inventarioGuerrero.erase(inventarioGuerrero.begin());
        return armaRobada;
    }
    return nullptr;
}

Barbaro::Barbaro(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Barbaro::modoViolento() {
    if(habilidad > 5 && inventarioGuerrero[0]){
        estaViolento = true;
        habilidad -= 2;
        std::cout<< nombre << " está muy violento y causará mayor daño a su enemigo.\n";
    }else if(habilidad <= 5){
        std::cout<< nombre << " no tiene suficiente habilidad para entrar en modo violento.\n" <<std::endl;
    }else{
        std::cout << nombre << " no tiene arma para utilizar su capacidad de ataque especial.\n";
    }
}

void Barbaro::montaBestia() {
    if(habilidad > 5){
        bestia = true;
        habilidad -= 2;
        std::cout<< nombre << " está montando una bestia y esta recibirá el daño enemigo cuando lo ataquen en proximas jugadas.\n";
    }else{
        std::cout<< nombre << " no tiene suficiente habilidad para montar una bestia.\n" <<std::endl;
    }
}

int Barbaro::atacar(Personaje& enemigo) {
    if (!inventarioGuerrero.empty() && inventarioGuerrero[0]) {
        if (inventarioGuerrero[0]->utilizar()) {
            int danio = inventarioGuerrero[0]->getDanio();
    
            if (estaViolento) {
                danio *= 2;
                estaViolento = false; //se desactiva el modo violento después de usarlo
                std::cout << nombre << " ataca en modo violento causando " << danio << " de daño.\n"<< std::endl;
            } 
    
            enemigo.recibirDanio(danio);
            return danio;
        } else {
            inventarioGuerrero.erase(inventarioGuerrero.begin());
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
    }else{
        int danio = 10;
        enemigo.recibirDanio(danio);
        return danio;
    }
}

void Barbaro::recibirDanio(int danio) {
    if (bestia) {
        std::cout << nombre << " está montando una bestia. No recibe daño.\n";
        bestia = false;//se desactiva luego de ser usada
    } else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
    }
}

Paladin::Paladin(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Paladin::habilidadesDeSanacion(){
    if(habilidad > 5){
        modoSanador = true;
        std::cout << nombre << " activa sus habilidades de sanación y es capaz de curarse del proximo ataque.\n";
        habilidad -= 2;
    }else{
        std::cout<< nombre << " no tiene suficiente habilidad para usar habilidades de sanacion.\n" <<std::endl;
    }
}

void Paladin::escudoSagrado(){
    if(habilidad > 5){
        escudo = true;
        habilidad -= 2;
        std::cout << nombre << " activa su escudo sagrado que le brinda protección para cuando reciba el siguiente ataque.\n";
    }else{
        std::cout<< nombre <<" no tiene suficiente habilidad para usar el escudo sagrado.\n" <<std::endl;
    }
}

void Paladin::recibirDanio(int danio) {
    if (escudo) {
        std::cout << nombre << " esta utilizando el escudo sagrado. No recibe daño.\n"<< std::endl;
        escudo = false; //se desactiva luego de ser usada
    }else if(modoSanador){
        std::cout << nombre << " esta utilizando habilidades de sanacion. Se cura del daño que recibe.\n"<< std::endl;
        modoSanador = false; //se desactiva luego de ser usada
    }
    else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
    }
}

Caballero::Caballero(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Caballero::usoDeArmadura(){
    if (habilidad > 5) {
        armadura = true;
        habilidad -= 2;
        std::cout << nombre << " está utilizando su armadura que lo protege en el proximo ataque que reciba.\n";
    } else {
        std::cout << nombre << " no tiene suficiente habilidad para usar armadura.\n";
    }
}

void Caballero::afinidadConEspada(){
    if(habilidad >5 && inventarioGuerrero[0]){
        afinidad = true;
        habilidad -= 2;
        std::cout << nombre << " este caballero tiene una gran habilidad con su espada y causa mayor daño.\n";
    }else if( habilidad <= 5){
        std::cout<< nombre <<" no tiene suficiente habilidad para utilizar bien su espada\n" <<std::endl;
    }else{
        std::cout << nombre << " no tiene espada para utilizar su capacidad de ataque especial.\n";
    }

}

int Caballero::atacar(Personaje& enemigo){
    if (!inventarioGuerrero.empty() && inventarioGuerrero[0]) {
        if (inventarioGuerrero[0]->utilizar()) {
            int danio = inventarioGuerrero[0]->getDanio();
    
            if (inventarioGuerrero[0]->getNombre() == "Espada" && afinidad) {
                danio *= 2;
                afinidad = false; //se desactiva después de usarlo
                std::cout << nombre << " ataca teniendo afinidad con su espada causando " << danio << " de daño.\n"<< std::endl;
            } 
    
            enemigo.recibirDanio(danio);
            return danio;
        } else {
            inventarioGuerrero.erase(inventarioGuerrero.begin());
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
    }else{
        int danio = 10;
        enemigo.recibirDanio(danio);
        return danio;
    }
}

void Caballero::recibirDanio(int danio){
    if (armadura) {
        std::cout << nombre << " esta usando una armadura. No recibe daño.\n";
        armadura = false;//se desactiva luego de ser usada
    } else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
    }
}

Mercenario::Mercenario(std::string nombre, std::string tipo, int HP, int habilidad) : Guerrero(nombre, tipo, HP, habilidad) {}

void Mercenario::robarArmaEnemigo(Personaje& enemigo) {
    if (inventarioGuerrero.empty()) {
        auto armaRobada = enemigo.quitarArma();
        if (armaRobada) {
            inventarioGuerrero.push_back(std::move(armaRobada));
            std::cout << nombre << " ha robado el arma : " << armaRobada->getNombre() << " de " << enemigo.getNombre() << "!\n";
        } else {
            std::cout << enemigo.getNombre() << " no tiene arma para robar.\n";
        }
    }
}

void Mercenario::conocePuntoDebil(){
    if(habilidad > 5 && inventarioGuerrero[0]){
        conoce = true;
        habilidad-= 2;
    }else if(habilidad <= 5){
        std::cout<< nombre << " no tiene la habilidad suficiente para identificar punto debil.\n" <<std::endl;
    }else{
        std::cout << nombre << " no tiene arma para utilizar su capacidad de ataque especial.\n";
    }
}

int Mercenario::atacar(Personaje& enemigo) {

    robarArmaEnemigo(enemigo); //intenta robar el arma

    if (!inventarioGuerrero.empty() && inventarioGuerrero[0]) {
        if (inventarioGuerrero[0]->utilizar()) {
            int danio = inventarioGuerrero[0]->getDanio();
    
            if (conoce) {
                danio *= 2;
                conoce = false;
                std::cout << nombre << " conoce el punto débil de " << enemigo.getNombre() << ".\n";
            }
    
            enemigo.recibirDanio(danio);
            return danio;
        } else {
            inventarioGuerrero.erase(inventarioGuerrero.begin());
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
    }else{
        int danio = 10;
        enemigo.recibirDanio(danio);
        return danio;
    }
    
}






