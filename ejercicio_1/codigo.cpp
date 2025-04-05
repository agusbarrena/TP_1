#include "funciones.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

EntidadOrganizativas::EntidadOrganizativas(const std::string& nombre) : nombre(nombre) {}

std::string EntidadOrganizativas::getNombre() const {
    return nombre;
}

void EntidadOrganizativas::agregarSubentidad(EntidadOrganizativas* subentidad) {
    subentidades.push_back(subentidad);
}

int EntidadOrganizativas::contarSubentidades() const {
    return subentidades.size();
}

EntidadOrganizativas::~EntidadOrganizativas() {
    for (auto subentidad : subentidades) {
        delete subentidad;
    }
}

Empresa::Empresa(const std::string& nombre, const std::string& direccion) : EntidadOrganizativas(nombre), direccion(direccion) {}

void Empresa::agregarDepartamento(std::unique_ptr<Departamento> departamento) {
    departamentos.push_back(std::move(departamento)); //mueve el departamento en lugar de copiarlo
}

void Empresa::eliminarDepartamento(const std::string& nombreDepartamento) {
    for (auto temp = departamentos.begin(); temp != departamentos.end(); ++it) {
        if ((*temp)->getNombre() == nombreDepartamento) {
            departamentos.erase(temp);
            break;
        }
    }
}

std::string Empresa::getNombre() const {
    return nombre;
}

Departamento* Empresa::getDepByName(const std::string& nombre) const {
    for (const auto& departamento : departamentos) {
        if (departamento->getNombre() == nombre) {
            return departamento.get();
        }
    }
    return nullptr;
}

std::vector<std::string> Empresa::getDepNames() const {
    std::vector<std::string> nombres;
    for (const auto& departamento : departamentos) {
        nombres.push_back(departamento->getNombre());
    }
    return nombres;
}

CentralRegional::CentralRegional(const std::string& nombre, const std::vector<std::string>& paises) : EntidadOrganizativas(nombre), paises(paises) {
    
}

std::string CentralRegional::getNombre() const {
    return nombre;
}

int CentralRegional::getCantEmpleados() const {
    int cant = 0;
    for (const auto& empresa : empresas) {
        cant += empresa->contarEmpleados();
    }
    return cant;
}

std::vector<std::string> CentralRegional::getEmpNames() const {
    std::vector<std::string> nombres_empresas;
    for (const auto& empresa : empresas) {
        nombres_empresas.push_back(empresa->getNombre());
    }
    return nombres_empresas;
}

std::vector<GerenteAlto*> CentralRegional::getGerentesAlto() const {
    std::vector<GerenteAlto*> gerentes_alto;
    for (const auto& empresa : empresas) {
        for (const auto& gerente : empresa->getGerentesAlto()) {
            gerentes_alto.push_back(gerente.get());
        }
    }
    return gerentes_alto;
}

std::vector<GerenteMedio*> CentralRegional::getGerentesMedio() const {
    std::vector<GerenteMedio*> gerentes_medio;
    for (const auto& empresa : empresas) {
        for (const auto& gerente : empresa->getGerentesMedio()) {
            gerentes_medio.push_back(gerente.get());
        }
    }
    return gerentes_medio;
}

Departamento::Departamento(const std::string& nombre, const std::string& ubicacion) : nombre(nombre), ubicacion(ubicacion) {}

int Departamento::contarEmpleados() const {
    return empleados.size();
}

std::vector<Empleado*> Departamento::getEmployees() const {
    std::vector<Empleado*> employees;
    for (const auto& employee : empleados) {
        employees.push_back(employee.get());
    }
    return employees;
}

bool Departamento::contratarEmpleado(std::unique_ptr<Empleado> empleado) {
    empleados.push_back(std::move(empleado)); //mueve el empleado en lugar de copiarlo
    return true;
}

bool Departamento::despedirEmpleado(const std::string& nombreEmpleado) {
    for (auto temp = empleados.begin(); temp != empleados.end(); ++it) {
        if ((*temp)->getNombre() == nombreEmpleado) {
            empleados.erase(temp);
            return true;
        }
    }
    return false;
}

std::string Departamento::getNombre() const {
    return nombre;
}

Empleado::Empleado(const std::string& nombre, const std::string& puesto, int antiguedad, float salario) : nombre(nombre), puesto(puesto), antiguedad(antiguedad), salario(salario) {}

int Empleado::getAntiguedad() const {
    return antiguedad;
}

std::string Empleado::getNombre() const {
    return nombre;
}

std::string Empleado::getPuesto() const {
    return puesto;
}

bool Empleado::updateSalario(float nuevoSalario) {
    salario = nuevoSalario;
    return true;
}

float Empleado::getSalario() const {
    return salario;
}

GerenteAlto::GerenteAlto(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level) : Manager(nombre, puesto, antiguedad, salario, bono, level) {}

int GerenteAlto::getAntiguedad() const {
    return antiguedad;
}

bool GerenteAlto::updateSalario(float nuevoSalario) {
    salario = nuevoSalario;
    return true;
}

float GerenteAlto::getSalario() const {
    return salario;
}

std::string GerenteAlto::getNombre() const {
    return nombre;
}

std::string GerenteAlto::getPuesto() const {
    return puesto;
}

std::string GerenteAlto::getLevel() const {
    return level;
}

bool GerenteAlto::updateLevel(const std::string& nuevoLevel) {
    level = nuevoLevel;
    return true;
}

bool GerenteAlto::updateBono(float nuevoBono) {
    bono = nuevoBono;
    return true;
}

bool GerenteAlto::getBono() const {
    return bono;
}

bool GerenteAlto::setLevel(const std::string& nuevoNivel) {
    level = nuevoNivel;
    return true;
}

GerenteMedio::GerenteMedio(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level) : Manager(nombre, puesto, antiguedad, salario, bono, level) {}

int GerenteMedio::getAntiguedad() const {
    return antiguedad;
}   

bool GerenteMedio::updateSalario(float nuevoSalario) {
    salario = nuevoSalario;
    return true;
}

float GerenteMedio::getSalario() const {
    return salario;
}

std::string GerenteMedio::getNombre() const {
    return nombre;
}

std::string GerenteMedio::getPuesto() const {
    return puesto;
}

std::string GerenteMedio::getLevel() const {
    return level;
}

bool GerenteMedio::updateLevel(const std::string& nuevoLevel) {
    level = nuevoLevel;
    return true;
}

bool GerenteMedio::updateBono(float nuevoBono) {
    bono = nuevoBono;
    return true;
}

bool GerenteMedio::getBono() const {
    return bono;
}

bool GerenteMedio::setLevel(const std::string& nuevoNivel) {
    level = nuevoNivel;
    return true;
}

Manager::Manager(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level) : Empleado(nombre, puesto, antiguedad, salario), bono(bono), level(level) {}
int Manager::getAntiguedad() const {
    return antiguedad;
}
bool Manager::updateSalario(float nuevoSalario) {
    salario = nuevoSalario;
    return true;
}
float Manager::getSalario() const {
    return salario;
}
std::string Manager::getNombre() const {
    return nombre;
}
std::string Manager::getPuesto() const {
    return puesto;
}
bool Manager::updateBono(float nuevoBono) {
    bono = nuevoBono;
    return true;
}
bool Manager::getBono() const {
    return bono;
}
std::string Manager::setLevel(const std::string& nuevoNivel) {
    level = nuevoNivel;
    return true;
}

std::string Manager::getLevel() const {
    return level;
}

GerenteBajo::GerenteBajo(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level) : Manager(nombre, puesto, antiguedad, salario, bono, level) {}

int GerenteBajo::getAntiguedad() const {
    return antiguedad;
}

bool GerenteBajo::updateSalario(float nuevoSalario) {
    salario = nuevoSalario;
    return true;
}

float GerenteBajo::getSalario() const {
    return salario;
}

std::string GerenteBajo::getNombre() const {
    return nombre;
}

std::string GerenteBajo::getPuesto() const {
    return puesto;
}

std::string GerenteBajo::getLevel() const {
    return level;
}

bool GerenteBajo::updateLevel(const std::string& nuevoLevel) {
    level = nuevoLevel;
    return true;
}

bool GerenteBajo::updateBono(float nuevoBono) {
    bono = nuevoBono;
    return true;
}

bool GerenteBajo::getBono() const {
    return bono;
}

bool GerenteBajo::setLevel(const std::string& nuevoNivel) {
    level = nuevoNivel;
    return true;
}

LiderEquipo::LiderEquipo(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level) : Manager(nombre, puesto, antiguedad, salario, bono, level) {}
int LiderEquipo::getAntiguedad() const {
    return antiguedad;
}

bool LiderEquipo::updateSalario(float nuevoSalario) {
    salario = nuevoSalario;
    return true;
}

float LiderEquipo::getSalario() const {
    return salario;
}

std::string LiderEquipo::getNombre() const {
    return nombre;
}

std::string LiderEquipo::getPuesto() const {
    return puesto;
}

std::string LiderEquipo::getLevel() const {
    return level;
}

bool LiderEquipo::updateLevel(const std::string& nuevoLevel) {
    level = nuevoLevel;
    return true;
}

bool LiderEquipo::updateBono(float nuevoBono) {
    bono = nuevoBono;
    return true;
}

bool LiderEquipo::getBono() const {
    return bono;
}

bool LiderEquipo::setLevel(const std::string& nuevoNivel) {
    level = nuevoNivel;
    return true;
}

