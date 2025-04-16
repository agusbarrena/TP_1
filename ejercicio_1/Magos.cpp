#include "Magos.h"
#include "Guerreros.h"
#include "Personajes.h"
#include <iostream>
#include <memory>


Magos::Magos(std::string nombre, std::string tipo, int HP, int poderMagico) : nombre(nombre), tipo(tipo), HP(HP), poderMagico(poderMagico) {}

std::string Magos::getNombre() const {
    return nombre;
}

std::string Magos::getTipo() const {
    return "Mago";
}

int Magos::getHP() const {
    return HP;
}

void Magos::agregarArma(std::unique_ptr<Armas> arma) {
    inventarioMago.push_back(std::move(arma));
}

void Magos::recibirDanio(int danio) {
    HP -= danio;
    if (HP < 0) {
        HP = 0;
    }
    std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
}

int Magos::atacar(Personaje& enemigo){
    if (!inventarioMago.empty() && inventarioMago[0]) {

        if(inventarioMago[0]->utilizar()){
            int danio = inventarioMago[0]->getDanio();
            enemigo.recibirDanio(danio);
            return danio;
        }else{
            inventarioMago.erase(inventarioMago.begin());  //saca el arma del inventario
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
        
    } else {
        int danio = 10; // si no tiene arma hace un ataque igual a 10 tb
        enemigo.recibirDanio(danio);
        return danio;
    }
}

void Magos::mostrarEstado() const {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "HP: " << HP << "\n";
    std::cout << "Poder Mágico: " << poderMagico << "\n";
    std::cout << "Armas:\n";
    for (const auto& arma : inventarioMago) {
        std::cout << "- " << arma->getNombre() << "\n";
    }
    std::cout << "------------------------\n";
}


int Magos::getpoderMagico() const {
    return poderMagico;
}

void Magos::setpoderMagico(int poder) {
    poderMagico = poder;
}

const Armas* Magos::getArma() const {
    if (!inventarioMago.empty()) {
        return inventarioMago[0].get(); //devuelve primer arma del inventario que es con la que se ataca
    }
    return nullptr; // si no hay armas devuelve nullptr
}

std::unique_ptr<Armas> Magos::quitarArma() {
    if (!inventarioMago.empty()) {
        auto armaRobada = std::move(inventarioMago[0]);
        inventarioMago.erase(inventarioMago.begin());
        return armaRobada;
    }
    return nullptr;
}

Hechicero::Hechicero(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Hechicero::invocarFuego(){
    if(poderMagico > 5  && inventarioMago[0]){
        invocaFuego = true;
        poderMagico -= 2; //reduce el poder del hechicero en este caso, pero siempre que usen su poder para las capacidades especiales se les reducira su poder
        std::cout<< nombre << " invoca al Fuego y es capaz de quemar a su enemigo.\n";
    } else if(poderMagico <= 5) {
        std::cout << nombre << " no tiene suficiente poder mágico para invocar fuego.\n";
    }else{
        std::cout << nombre << " no tiene arma para utilizar su capacidad de ataque especial.\n";
    }
}

void Hechicero::leermentes(){
    if(poderMagico > 5){
        leyendoMentes = true;
        std::cout << nombre << " está leyendo mentes y es capaz de anticipar el ataque enemigo en proximas jugadas.\n";
        poderMagico -= 2;
    }
    else {
        std::cout << nombre << " no tiene suficiente poder mágico para leer mentes.\n";
    }
}

void Hechicero::recibirDanio(int danio) {
    if (leyendoMentes) {
        std::cout << nombre << " anticipa el ataque gracias a su poder mental que activo anteriormente. Daño reducido.\n";
        danio /= 2;
        leyendoMentes = false;
    }

    HP -= danio;
    if (HP < 0) HP = 0;

    std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
}

int Hechicero::atacar(Personaje& enemigo) {
    if (!inventarioMago.empty() && inventarioMago[0]) {
        if (inventarioMago[0]->utilizar()) {
            int danio = inventarioMago[0]->getDanio();

            if (invocaFuego) {
                danio *= 2;
                invocaFuego = false;
                std::cout << nombre << " ataca causando más daño debido al fuego. Causa " << danio << " de daño.\n";
            }

            enemigo.recibirDanio(danio);
            return danio;
        } else {
            inventarioMago.erase(inventarioMago.begin());
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
    }else{
        int danio = 10;
        enemigo.recibirDanio(danio);
        return danio;
    }
}


Conjurador::Conjurador(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Conjurador::conjuraEspectrosNegros() {
    if (poderMagico > 5  && inventarioMago[0]) {
        poderMagico -= 2;
        espectrosNegrosInvocados = true;
        std::cout << nombre << " conjura espectros negros y es capaz de causar mayor daño.\n";
    } else if(poderMagico <= 5){
        std::cout << nombre << " no tiene suficiente poder mágico para conjurar espectros negros.\n";
    }else{
        std::cout << nombre << " no tiene arma para utilizar su capacidad de ataque especial.\n";
    }
}

void Conjurador::conjuraPrisionMagica() {
    if (poderMagico > 5) {
        poderMagico -= 2;
        prisionMagicaActivada = true;
        std::cout << nombre << " activa una prisión mágica. No lo pueden atacar temporalmente.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder mágico para conjurar prisión mágica.\n";
    }
}

int Conjurador::atacar(Personaje& enemigo) {
    if (!inventarioMago.empty() && inventarioMago[0]) {
        if (inventarioMago[0]->utilizar()) {
            int danio = inventarioMago[0]->getDanio();
    
            if (espectrosNegrosInvocados) {
                danio *= 2;
                espectrosNegrosInvocados = false;
                std::cout << nombre << " ataca en companía de los Espectros Negros causando " << danio << " de daño.\n";
            }
    
            enemigo.recibirDanio(danio);
            return danio;
        } else {
            inventarioMago.erase(inventarioMago.begin());
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
    }else{
        int danio = 10;
        enemigo.recibirDanio(danio);
        return danio;
    }
}


void Conjurador::recibirDanio(int danio){
    if (prisionMagicaActivada) {
        std::cout << nombre << " está protegido por una prisión magica conjurada anteriormente. No recibe daño.\n";
        prisionMagicaActivada = false; 
    } else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
    }
}

Brujo::Brujo(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Brujo::arrojaMaldiciones() {
    if (poderMagico > 5) {
        maldicionArrojada = true;
        poderMagico -= 2;
        std::cout << nombre << " arroja una maldición haciendo que el ataque de su enemigo sea debilitado en la proxima jugada.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder magico para maldecir.\n";
    }
}

void Brujo::usaMagiaOscura() {
    if (poderMagico > 5  && inventarioMago[0]) {
        magiaOscuraUsada = true;
        poderMagico -= 2;
        std::cout << nombre << " canaliza magia oscura, hará trizas a su enemigo.\n";
    } else if(poderMagico <= 5) {
        std::cout << nombre << " no tiene suficiente poder magico para usar magia oscura.\n";
    }else{
        std::cout << nombre << " no tiene arma para utilizar su capacidad de ataque especial.\n";
    }
}

int Brujo::atacar(Personaje& enemigo) {
    if (!inventarioMago.empty() && inventarioMago[0]) {
        if (inventarioMago[0]->utilizar()) {
            int danio = inventarioMago[0]->getDanio();
    
            if (magiaOscuraUsada) {
                danio *= 2;
                magiaOscuraUsada = false;
                std::cout << nombre << " desata un ataque de magia oscura causando " << danio << " de daño.\n";
            }
    
            enemigo.recibirDanio(danio);
            return danio;
        } else {
            inventarioMago.erase(inventarioMago.begin());
            return atacar(enemigo);//vuelve a atacar con el siguiente arma en inventario
        }
    }else{
        int danio = 10;
        enemigo.recibirDanio(danio);
        return danio;
    }
}

void Brujo::recibirDanio(int danio) {
    if (maldicionArrojada) {
        danio /= 2;//reduce danio a la mitad
        maldicionArrojada = false;
        std::cout << nombre << " sufre daño reducido por la maldición activa. Daño recibido: " << danio << "\n";
    } else {
        std::cout << nombre << " recibe " << danio << " de daño.\n";
    }

    HP -= danio;
    if (HP < 0) HP = 0;
}


Nigromante::Nigromante(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Nigromante::ojoSauron() {
    if (poderMagico > 5) {
        ojoSauronActivado = true;
        poderMagico -= 2;
        std::cout << nombre << " activa el Ojo de Sauron, capaz de detectar el ataque de su enemigo y anularlo en proxima jugada.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder magico para invocar el Ojo de Sauron para su proxima jugada.\n";
    }
}

void Nigromante::sobreviveSinCuerpo() {
    if (HP <= 0 && sinCuerpo) {
        HP = 100;
        sinCuerpo = false;//revive y vuelve a un cuerpo
        std::cout << nombre << " sobrevive sin cuerpo y regresa con 100 de HP.\n";
    }
}

void Nigromante::recibirDanio(int danio) {
    if (ojoSauronActivado && (poderMagico > 5)) {
        std::cout << nombre << " anticipa el ataque con el Ojo de Sauron que tenia activado, no recibe daño.\n";
        ojoSauronActivado = false; 
        return;
    }

    std::cout << nombre << " recibe " << danio << " de daño.\n";
    HP -= danio;
    if(HP < 0) {
        HP = 0;
        sinCuerpo = true; // se queda sin cuerpo
    }

    if (HP <= 0 && sinCuerpo) {
        sobreviveSinCuerpo(); // se revive automáticamente una vez
    } else if (HP < 0) {
        HP = 0; // por si fue atacado otra vez después
    }
}

