#include <iostream>
#include <string>

using namespace std;

// Clase abstracta Personaje
class Personaje {
protected:
    string nombre;
    string animal;
public:
    //Constructor
    Personaje(string nombre, string animal) : nombre(nombre), animal(animal) {}
    string getNombre() {
        return nombre;
    }
    //Metodos virtuales
    virtual void cantar() = 0;
    virtual void escapar() = 0;
};

// Clase abstracta Cosa
class Cosa {
protected:
    string nombre;
public:
    //Constructor
    Cosa(string nombre) : nombre(nombre) {}
};

// Clase Casa heredando de Cosa
class Casa : public Cosa {
private:
    string tipo;
public:
    //Constructor
    Casa(string nombre, string tipo) : Cosa(nombre), tipo(tipo) {}

    void destruir() {
        cout << "La casa de " << tipo << " ha sido destruida.\n";
        tipo = "destruida";
    }

    void entrar(Personaje* personaje) { //Recibe un objeto como parametro
        cout << personaje->getNombre() << " entra en la casa de " << tipo << ".\n";
    }

    string getTipo() {
        return tipo;
    }

    void setTipo(string tipo) {
        this->tipo = tipo;
    }
};

// Clase Cerdito heredando de Personaje
class Cerdito : public Personaje {
private:
    Casa* casa;     //Agregacion de Casa
public:
    //Constructor
    Cerdito(string nombre, string animal, Casa* casa) : Personaje(nombre, animal), casa(casa) {}

    void cantar() override {    //sobreescritura de metodos
        cout << nombre << " el " << animal << " canta felizmente.\n";
    }

    void escapar() override {   //sobreescritura de metodos
        cout << nombre << " corre a la siguiente casa.\n";
    }

    void construir(string tipoCasa) {   //sobreescritura de metodos
        cout << nombre << " construye una casa de " << tipoCasa << ".\n";
        casa->setTipo(tipoCasa);
    }
};

// Clase Lobo heredando de Personaje
class Lobo : public Personaje {
public:
    //constructor
    Lobo(string nombre, string animal) : Personaje(nombre, animal) {}

    void soplar(Casa* casa) {   //objeto casa como parámetro
        cout << nombre << " intenta soplar la casa de " << casa->getTipo() << ".\n";
        //metodo destruir de casa en caso tipo sea distinto de ladrillo
        if (casa->getTipo() != "ladrillos") {
            casa->destruir();
        } else {
            cout << "La casa no se puede destruir.\n";
        }
    }

    void cantar() override {    //sobreescritura de metodos
        cout << nombre << " canta de forma amenazadora.\n";
    }

    void escapar() override {   //sobreescritura de metodos
        cout << nombre << " huye frustrado.\n";
    }
};

int main() {
    // Crear casas para cada cerdito
    Casa casa1("Casa1", "paja");
    Casa casa2("Casa2", "madera");
    Casa casa3("Casa3", "ladrillos");

    // Crear cerditos asignando cada uno a su casa
    Cerdito cerdito1("Flautista", "cerdo", &casa1);
    Cerdito cerdito2("Violinista", "cerdo", &casa2);
    Cerdito cerdito3("Practico", "cerdo", &casa3);

    // Crear al lobo
    Lobo lobo("Lobo Feroz", "lobo");

    // Narrar la historia
    //Construccion de casas
    cerdito1.construir("paja");
    cerdito1.cantar();
    cerdito2.construir("madera");
    cerdito2.cantar();
    cerdito3.construir("ladrillos");
    cerdito3.cantar();

    //Lobo destruye las casas
    lobo.soplar(&casa1);
    cerdito1.escapar();

    lobo.soplar(&casa2);
    cerdito1.escapar();
    cerdito2.escapar();

    //Lobo intenta destruir la casa de practico
    lobo.soplar(&casa3);

    //Lobo no puede destruirlo y se vá
    lobo.escapar();
    cerdito1.cantar();
    cerdito2.cantar();
    cerdito3.cantar();

    return 0;
}
