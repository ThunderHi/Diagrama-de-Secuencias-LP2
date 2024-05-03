#include <iostream>
#include <string>
 
using namespace std;
 
//Clase abstracta Personaje
class Personaje {
protected:
    string nombre;
    string tipo;
public:
    //Constructor
    Personaje(string nombre, string tipo) : nombre(nombre), tipo(tipo) {}
    string getNombre() {
        return nombre;
    }
    //Métodos virtuales
    virtual void cantar() = 0;
    virtual void escapar() = 0;
};
 
//Clase abstracta Cosa
class Cosa {
protected:
    string nombre;
public:
    //Constructor
    Cosa(string nombre) : nombre(nombre) {}
};
 
//Clase Parra heredando de Cosa
class Parra : public Cosa {
private:
    string estado;
public:
    //Constructor
    Parra(string nombre, string estado) : Cosa(nombre), estado(estado) {}
 
    void cosechar() {
        cout<<"La parra de uvas esta siendo cosechada.\n";
        estado = "cosechada";
    }
 
    string getEstado() {
        return estado;
    }
 
    void setEstado(string estado) {
        this->estado = estado;
    }
};
 
//Clase Zorra heredando de Personaje
class Zorra : public Personaje {
private:
    Parra* parra;     //Agregación de Parra
public:
    //Constructor
    Zorra(string nombre, Parra* parra) : Personaje(nombre, "zorra"), parra(parra) {}
 
    void cantar() override {    //Sobreescritura de métodos
        cout<<nombre<<" grune y se lamenta por no poder alcanzar las uvas.\n";
    }
 
    void escapar() override {   //Sobreescritura de métodos
        cout<<nombre<<" se da por vencida y se aleja lentamente de la parra.\n";
    }
 
    void intentarAlcanzar() {
        cout<<nombre<<" salta tratando de alcanzar las uvas.\n";
        if (parra->getEstado() != "cosechada") {
            cout<<"Las uvas estan demasiado altas para alcanzarlas.\n";
        } else {
            cout<<"Las uvas están siendo cosechadas.\n";
        }
    }
};
 
int main() {
    //Crear la parra de uvas
    Parra parraDeUvas("Parra de Uvas", "alta");
 
    //Crear la zorra
    Zorra zorra("Zorra Astuta", &parraDeUvas);
 
    //Narrar la historia
    //Zorra intenta alcanzar las uvas
    zorra.intentarAlcanzar();
    zorra.cantar();
    zorra.escapar();
 
    return 0;
}
