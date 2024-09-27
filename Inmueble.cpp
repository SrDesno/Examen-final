#Include "Inmueble.hpp"

//Metodo construcrtor por defecto
Inmueble::Inmueble(){}

Inmueble::Inmueble(double _frente, double _fondo, double _ubicacion, string _valorCatastral){
  frente=_frente;
  fondo=_fondo;
  valorCatastral=_valorCatastral;
}

void Inmueble::printCaracteristicas(){
  cout << "Frente: " << frente << " metros" << endl;
  cout << "Fondo: " << fondo << " metros" << endl;
  cout << "Ubicación: " << ubicacion << endl;
  cout << "Valor Catastral: $" << valor_catastral << endl;
}

double Inmueble::precioVenta(){
  return valorCatastral;
}