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

void Magos::agregarArma(std::shared_ptr<Armas> arma) {
    inventarioMago.push_back(arma);
}

void Magos::recibirDanio(int danio) {
    HP -= danio;
    if (HP < 0) {
        HP = 0;
    }
    std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
}

void Magos::atacar(Personaje& enemigo){
    if (!inventarioMago.empty()) {

        std::cout << nombre << " ataca a " << enemigo.getNombre() << " con " << inventarioMago[0]->getNombre() << "\n";

        int danio = inventarioMago[0]->getDanio();
        enemigo.recibirDanio(danio);

        //hay que ver si la carga magica esta ok y si quiero eliminar al emnemigo aca!!!!!
        inventarioMago[0]->utilizar();  // Usa el arma (reduce durabilidad o carga mágica)

    } else {
        std::cout << nombre << " no tiene armas para atacar.\n";
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
}

int Magos::getpoderMagico() const {
    return poderMagico;
}

void Magos::setpoderMagico(int poder) {
    poderMagico = poder;
}

std::shared_ptr<Armas> Magos::getArma() const {
    if (!inventarioMago.empty()) {
        return inventarioMago[0]; //devuelve primer arma del inventario que es con la que se ataca
    }
    return nullptr; // Si no hay armas, devuelve nullptr
}

std::shared_ptr<Armas> Magos::quitarArma() {
    if (!inventarioMago.empty()) {
        auto armaRobada = inventarioMago[0];
        inventarioMago.erase(inventarioMago.begin());
        return armaRobada;
    }
    return nullptr;
}

Hechicero::Hechicero(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Hechicero::invocarFuego(std::shared_ptr<Personaje> enemigo){
    if(poderMagico > 5){
        std::cout << nombre << " invoca fuego y lanza un hechizo a " << enemigo->getNombre() << "\n";
        poderMagico -= 2; //reduce el poder del hechicero
    } else {
        std::cout << nombre << " no tiene suficiente poder mágico para invocar fuego.\n";
    }
}

void Hechicero::leermentes(){
    if(poderMagico > 5){
        leyendoMentes = true;
        std::cout << nombre << " está leyendo mentes y anticipara los movimientos del enemigo.\n";
        poderMagico -= 2;
    }
    else {
        std::cout << nombre << " no tiene suficiente poder mágico para leer mentes.\n";
    }
}

void Hechicero::recibirDanio(int danio) {
    if (leyendoMentes) {
        std::cout << nombre << " anticipa el ataque gracias a su poder mental. Daño reducido.\n";
        danio /= 2;  //reduce el danio a la mitad
        leyendoMentes = false;  //se desactiva la lectura de mentes dsp de usarlo
    }

    HP -= danio;
    if (HP < 0) HP = 0;
    std::cout << nombre << " recibe " << danio << " de daño. HP restante: " << HP << "\n";
}

void Hechicero::atacar(Personaje& enemigo){
    if (!inventarioMago.empty()) {
        int danio = inventarioMago[0]->getDanio();

        if (leyendoMentes) {
            danio *= 2;
            leyendoMentes = false; //se desactiva la lectura de mentes después de usarlo
            std::cout << nombre << " ataca anticipando el movimiento del enemigo causando " << danio << " de danio.\n";
        } else {
            std::cout << nombre << " ataca causando " << danio << " de danio.\n";
        }

        enemigo.recibirDanio(danio);
        inventarioMago[0]->utilizar();
    } else {
        std::cout << nombre << " no tiene armas para atacar.\n";
    }
}

Conjurador::Conjurador(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Conjurador::conjuraEspectrosNegros() {
    if (poderMagico > 5) {
        espectrosNegrosInvocados = true;
        poderMagico -= 2;
        std::cout << nombre << " conjura espectros negros. Su próximo ataque será devastador.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder mágico para conjurar espectros negros.\n";
    }
}

void Conjurador::conjuraPrisionMagica() {
    if (poderMagico > 5) {
        prisionMagicaActivada = true;
        poderMagico -= 2;
        std::cout << nombre << " activa una prisión mágica. No lo pueden atacar temporalmente.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder mágico para conjurar prisión mágica.\n";
    }
}

void Conjurador::atacar(Personaje& enemigo) {
    if (!inventarioMago.empty()) {
        int danio = inventarioMago[0]->getDanio();

        if (espectrosNegrosInvocados) {
            danio *= 2;
            espectrosNegrosInvocados = false;
            std::cout << nombre << " ataca en compania de los Espectros Negros causando " << danio << " de danio.\n";
        } else {
            std::cout << nombre << " ataca causando " << danio << " de danio.\n";
        }

        enemigo.recibirDanio(danio);
        inventarioMago[0]->utilizar();
    } else {
        std::cout << nombre << " no tiene armas para atacar.\n";
    }
}

void Conjurador::recibirDanio(int danio){
    if (prisionMagicaActivada) {
        std::cout << nombre << " está protegido por una prision magica. No recibe danio.\n";
        prisionMagicaActivada = false; //se desactiva luego de ser usada
    } else {
        HP -= danio;
        if (HP < 0) HP = 0;
        std::cout << nombre << " recibe " << danio << " de danio. HP restante: " << HP << "\n";
    }
}

Brujo::Brujo(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Brujo::arrojaMaldiciones() {
    if (poderMagico > 5) {
        maldicionArrojada = true;
        poderMagico -= 2;
        std::cout << nombre << " arroja una maldición. En el proximo ataque del enemigo sera debilitado.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder magico para maldecir.\n";
    }
}

void Brujo::usaMagiaOscura() {
    if (poderMagico > 5) {
        magiaOscuraUsada = true;
        poderMagico -= 2;
        std::cout << nombre << " canaliza magia oscura.Su proximo ataque sera devastador.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder magico para usar magia oscura.\n";
    }
}

void Brujo::atacar(Personaje& enemigo) {
    if (!inventarioMago.empty()) {
        int danio = inventarioMago[0]->getDanio();

        if (magiaOscuraUsada) {
            danio *= 2;
            magiaOscuraUsada = false;
            std::cout << nombre << " desata un ataque de magia oscura causando " << danio << " de danio.\n";
        } else {
            std::cout << nombre << " ataca causando " << danio << " de danio.\n";
        }

        enemigo.recibirDanio(danio);
        inventarioMago[0]->utilizar();
    } else {
        std::cout << nombre << " no tiene armas para atacar.\n";
    }
}

void Brujo::recibirDanio(int danio) {
    if (maldicionArrojada) {
        danio /= 2;//reduce danio a la mitad
        maldicionArrojada = false;
        std::cout << nombre << " sufre danio reducido por la maldición activa. Danio recibido: " << danio << "\n";
    } else {
        std::cout << nombre << " recibe " << danio << " de danio.\n";
    }

    HP -= danio;
    if (HP < 0) HP = 0;
}


Nigromante::Nigromante(std::string nombre, std::string tipo, int HP, int poderMagico) : Magos(nombre, tipo, HP, poderMagico) {}

void Nigromante::ojoSauron() {
    if (poderMagico > 5) {
        ojoSauronActivado = true;
        poderMagico -= 2;
        std::cout << nombre << " activa el Ojo de Sauron. Detecta y anula el proximo ataque de su enemigo.\n";
    } else {
        std::cout << nombre << " no tiene suficiente poder magico para invocar el Ojo de Sauron.\n";
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
    if (ojoSauronActivado) {
        std::cout << nombre << " anticipa el ataque con el Ojo de Sauron, no recibe daño.\n";
        ojoSauronActivado = false; //se desactiva luego de usarse
        return;
    }

    std::cout << nombre << " recibe " << danio << " de danio.\n";
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
