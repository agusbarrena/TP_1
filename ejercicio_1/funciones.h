#include <iostream>
#include <vector>
#include <memory>
#include <string>

class EntidadOrganizativas {
    public:
        EntidadOrganizativas(const std::string& nombre);
        virtual std::string getNombre() const;
        void agregarSubentidad(EntidadOrganizativas* subentidad);
        int contarSubentidades() const;
        virtual ~EntidadOrganizativas() = default; //permite la eliminación de objetos derivados

    protected:
        std::string nombre;
        std::vector<EntidadOrganizativas*> subentidades;
};

class Empresa : public EntidadOrganizativas {
    public:
        Empresa(const std::string& nombre, const std::string& direccion);
        void agregarDepartamento(std::unique_ptr<Departamento> departamento);
        void eliminarDepartamento(const std::string& nombreDepartamento);
        std::string getNombre() const override;
        Departamento* getDepByName(const std::string& nombre) const;
        std::vector<std::string> getDepNames() const;

    private:
        std::string nombre;
        std::string direccion;
        std::vector<std::unique_ptr<Departamento>> departamentos;
};

class CentralRegional : public EntidadOrganizativas {
    public:
        CentralRegional(const std::string& nombre, const std::vector<std::string>& paises);
        std::string getNombre() const override;
        int getCantEmpleados() const;
        std::vector<std::string> getEmpNames() const;
        std::vector<GerenteAlto*> getGerentesAlto() const;
        std::vector<GerenteMedio*> getGerentesMedio() const;
        void agregarEmpresa(std::unique_ptr<Empresa> empresa);
        

    private:
        std::vector<std::unique_ptr<GerenteAlto>> gerentesAlto;
        std::vector<std::unique_ptr<GerenteMedio>> gerentesMedio;
        std::vector<std::unique_ptr<Empresa>> empresas;
        std::vector<std::string> paises;
};

class Departamento {
    public:
        Departamento(const std::string& nombre, const std::string& ubicacion);
        int contarEmpleados() const;
        std::vector<Empleado*> getEmployees() const;
        bool contratarEmpleado(std::unique_ptr<Empleado> empleado);
        bool despedirEmpleado(const std::string& nombreEmpleado);
        std::string getNombre() const;

    private:
        std::string nombre;
        std::string ubicacion;
        std::vector<std::unique_ptr<Empleado>> empleados;
};

class Empleado {
    public:
        Empleado(const std::string& nombre, const std::string& puesto, int antiguedad, float salario);
        int getAntiguedad() const;
        std::string getNombre() const;
        std::string getPuesto() const;
        bool updateSalario(float nuevoSalario);
        float getSalario() const;
        virtual ~Empleado() = default; //permite la eliminacion de los objetos derivados

    protected:
        std::string nombre;
        std::string puesto;
        int antiguedad;
        float salario;
};

class GerenteAlto : public Manager {
    public:
        GerenteAlto(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level);
        int getAntiguedad() const override;
        bool updateSalario(float nuevoSalario) override;
        float getSalario() const override;
        std::string getNombre() const override;
        std::string getPuesto() const override;
        std::string getLevel() const override;
        bool updateLevel(const std::string& nuevoLevel) override;
        bool updateBono(float nuevoBono) override;
        bool getBono() const override;
        bool setLevel(const std::string& nuevoNivel) override;
    private:
        float bono;
        std::string level;
};

class GerenteMedio : public Manager {
    public:
        GerenteMedio(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level);
        int getAntiguedad() const override;
        bool updateSalario(float nuevoSalario) override;
        float getSalario() const override;
        std::string getNombre() const override;
        std::string getPuesto() const override;
        std::string getLevel() const override;
        bool updateLevel(const std::string& nuevoLevel) override;
        bool updateBono(float nuevoBono) override;
        bool getBono() const override;
        bool setLevel(const std::string& nuevoNivel) override;
    private:
        float bono;
        std::string level;
};

class Manager: public Empleado{
    public:
        Manager(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level);
        int getAntiguedad() const override;
        bool updateSalario(float nuevoSalario) override;
        float getSalario() const override;
        std::string getNombre() const override;
        std::string getPuesto() const override;
        bool updateBono(float nuevoBono);
        bool getBono() const;
        bool setLevel(const std::string& nuevoNivel);
        std::string getLevel() const;

        virtual ~Manager() = default; //permite la eliminacion de los objetos derivados

    protected:
        float bono;
        std::string level;

};

class GerenteBajo : public Manager {
    public:
        GerenteBajo(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level);
        int getAntiguedad() const override;
        bool updateSalario(float nuevoSalario) override;
        float getSalario() const override;
        std::string getNombre() const override;
        std::string getPuesto() const override;
        std::string getLevel() const override;
        bool updateLevel(const std::string& nuevoLevel) override;
        bool updateBono(float nuevoBono) override;
        bool getBono() const override;
        bool setLevel(const std::string& nuevoNivel) override;

    private:
        float bono;
        std::string level;
};
class LiderEquipo : public Manager {
    public:
        LiderEquipo(const std::string& nombre, const std::string& puesto, int antiguedad, float salario, float bono, const std::string& level);
        int getAntiguedad() const override;
        bool updateSalario(float nuevoSalario) override;
        float getSalario() const override;
        std::string getNombre() const override;
        std::string getPuesto() const override;
        std::string getLevel() const override;
        bool updateLevel(const std::string& nuevoLevel) override;
        bool updateBono(float nuevoBono) override;
        bool getBono() const override;
        bool setLevel(const std::string& nuevoNivel) override;
    private:
        float bono;
        std::string level;
};


