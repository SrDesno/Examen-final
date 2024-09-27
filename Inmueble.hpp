#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Se crea la clase padre "Inmueble"
class Inmueble{
  //Atributos de tipo protected para que las clases derivadas puedan acceder a ellos
  protected:
    double frente, fondo, valorCatastral;
    string ubicacion;
  public:
    Inmueble();
    Inmueble(double, double, double, string);
    void printCaracteristicas();
    double precioVenta();
}