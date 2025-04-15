#pragma once
#include <iostream>
#include "../ejercicio_2/PersonajeFactory.h"
#include "../ejercicio_1/Guerreros.h"
#include "../ejercicio_1/Magos.h"
#include "../ejercicio_1/ArmasCombate.h"
#include "../ejercicio_1/ArmasMagicas.h"
#include "../ejercicio_1/Personajes.h"
#include "../ejercicio_1/Armas.h"
#include <memory>
#include <string>
#include <vector>

enum class Accion { GOLPE_FUERTE = 1, GOLPE_RAPIDO, DEFENSA_Y_GOLPE };
std::string accionToString(Accion accion);
void batalla(std::shared_ptr<Personaje>& personaje1, std::shared_ptr<Personaje>& personaje2, Accion accion1, Accion accion2);
Accion opcionUsuario();
Accion opcionMaquina();
std::string tipoJugadorAleatorio();
