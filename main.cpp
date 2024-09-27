#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase base 'Inmueble'
class Inmueble {
protected:
    double frente;
    double fondo;
    string ubicacion;
    double valor_catastral;

public:
    Inmueble(double frente, double fondo, const string& ubicacion, double valor_catastral)
        : frente(frente), fondo(fondo), ubicacion(ubicacion), valor_catastral(valor_catastral) {}

    void imprimir_caracteristicas() {
        cout << "Tipo de inmueble: " << "Inmueble" << endl;
        cout << "Frente: " << frente << " metros" << endl;
        cout << "Fondo: " << fondo << " metros" << endl;
        cout << "Ubicación: " << ubicacion << endl;
        cout << "Valor Catastral: $" << valor_catastral << endl;
    }

    double precio_venta() {
        return valor_catastral;
    }
};

// Clase 'Terreno'
class Terreno : public Inmueble {
private:
    bool servicios;

public:
    Terreno(double frente, double fondo, const string& ubicacion, double valor_catastral, bool servicios)
        : Inmueble(frente, fondo, ubicacion, valor_catastral), servicios(servicios) {}

    void imprimir_caracteristicas() {
        Inmueble::imprimir_caracteristicas();
        cout << "Servicios disponibles: " << (servicios ? "Sí" : "No") << endl;
    }

    double precio_venta() {
        double incremento = servicios ? 0.4 : 0.2;
        return valor_catastral * incremento / (1 + incremento);
    }
};

// Clase 'Local'
class Local : public Inmueble {
private:
    string tipo;

public:
    Local(double frente, double fondo, const string& ubicacion, double valor_catastral, const string& tipo)
        : Inmueble(frente, fondo, ubicacion, valor_catastral), tipo(tipo) {}

    void imprimir_caracteristicas() {
        Inmueble::imprimir_caracteristicas();
        cout << "Tipo de local: " << tipo << endl;
    }

    double precio_venta() {
        double incremento = (tipo == "Plaza comercial") ? 0.6 : 0.4;
        return valor_catastral * incremento / (1 + incremento);
    }
};

// Clase 'Casa'
class Casa : public Inmueble {
private:
    string ubicacion_calle;

public:
    Casa(double frente, double fondo, const string& ubicacion, double valor_catastral, const string& ubicacion_calle)
        : Inmueble(frente, fondo, ubicacion, valor_catastral), ubicacion_calle(ubicacion_calle) {}

    void imprimir_caracteristicas() {
        Inmueble::imprimir_caracteristicas();
        cout << "Ubicación de la casa: " << ubicacion_calle << endl;
    }

    double precio_venta() {
        double incremento = (ubicacion_calle == "Privada") ? 1.2 : 0.8;
        return valor_catastral * incremento / (1 + incremento);
    }
};

// Clase 'Departamento'
class Departamento : public Inmueble {
private:
    string piso;

public:
    Departamento(double frente, double fondo, const string& ubicacion, double valor_catastral, const string& piso)
        : Inmueble(frente, fondo, ubicacion, valor_catastral), piso(piso) {}

    void imprimir_caracteristicas() {
        Inmueble::imprimir_caracteristicas();
        cout << "Piso del departamento: " << piso << endl;
    }

    double precio_venta() {
        double incremento = (piso == "Primera planta") ? 0.8 : 0.5;
        return valor_catastral * incremento / (1 + incremento);
    }
};

int main() {
    // Creación de objetos y uso de polimorfismo
    vector<Inmueble> inmuebles = {
        Terreno(20, 30, "Ciudad", 500000, true),
        Local(15, 20, "Centro comercial", 800000, "Plaza comercial"),
        Casa(10, 15, "Residencial", 1200000, "Privada"),
        Departamento(8, 10, "Zona céntrica", 700000, "Segunda planta")
    };

    for (Inmueble& inmueble : inmuebles) {
        inmueble.imprimir_caracteristicas();
        cout << "Precio de venta: $" << inmueble.precio_venta() << endl;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}
