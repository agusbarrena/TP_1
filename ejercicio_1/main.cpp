#include "funciones.h"
#include <iostream>
#include <memory>

int main(){
    
    int main() {
        //genero empleados
        auto empleado1 = std::make_unique<Empleado>("Ana", "Desarrolladora", 3, 50000);
        auto empleado2 = std::make_unique<GerenteBajo>();
        auto empleado3 = std::make_unique<LiderEquipo>();
        auto empleado4 = std::make_unique<Manager>();
    
        // ii. Crear departamentos
        auto departamento1 = std::make_unique<Departamento>("Desarrollo", "Piso 1");
        auto departamento2 = std::make_unique<Departamento>("Marketing", "Piso 2");
    
        // Contratar empleados
        departamento1->contratarEmpleado(std::move(empleado1));
        departamento1->contratarEmpleado(std::move(empleado2));
        departamento2->contratarEmpleado(std::move(empleado3));
        departamento2->contratarEmpleado(std::move(empleado4));
    
        // Crear empresa
        auto empresa1 = std::make_unique<Empresa>();
        // Suponiendo que tenés un método agregarDepartamento
        // empresa1->agregarDepartamento(std::move(departamento1));
        // empresa1->agregarDepartamento(std::move(departamento2));
    
        // Crear central regional
        auto central1 = std::make_unique<CentralRegional>();
        // Suponiendo que tenés un método agregarEmpresa
        // central1->agregarEmpresa(std::move(empresa1));
    
        // Asignar países si fuera necesario
        // central1->agregarPais("Argentina");
    
        // Agregar la central a la organización general (opcional)
        auto organizacion = std::make_unique<EntidadOrganizativas>();
        organizacion->agregarSubentidad(central1.get());
    
        std::cout << "Organización creada con éxito." << std::endl;
        return 0;
    }
    
}