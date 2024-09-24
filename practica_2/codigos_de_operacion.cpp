// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Adriel Reyes Suárez
// Correo: alu0101640136@ull.edu.es
// Fecha: 17/09/2024
// Contiene la funci´on CheckCorrectParameters
// Archivo que contiene todas los codigos de operacion [1...5] que se nos piden en la práctica
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <fstream>
#include "codigos_de_operacion.h"
#include "clase_alfabeto.h"
#include "clase_cadena.h"
#include "comprobador_apertura_archivo.h"
#include "clase_lenguaje.h"
#include "cadena_vacia_funciones.h"
#include "simbolos_en_alfabeto.h"

//lleva a cabo el primer apartado de la práctica
void OpcionAlfabeto(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  AperturaArchivos(archivo_entrada, archivo_salida);

  //simplemente le pongo una cabecera al documento. En este caso como hemos "calculado" el alfabeto asociado pues lo pongo de título
  archivo_salida << "---ALFABETO ASOCIADO---" << std::endl;
  Cadena cadena, alfabeto; 
  Cadena cadena_vacia("&");

  //Leo la cadena y el alfabeto del archivo de entrada
  while (archivo_entrada >> cadena >> alfabeto) {
    
    //cfeo el alfabeto asociado
    Alfabeto alfabeto_cadena;
    
    //compara si la cadena es la vacía o no
    if (cadena != cadena_vacia) {
      
      //después de comprobar si es distinta a la cadena vacía compruebo si todos sus símbolos existen en el alfabeto
      if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
        
        //si un simbolo de la primera cadena está en el alfabeto lo inserto en su alfabeto asociado
        for (int i{0}; i < static_cast<int>(cadena.GetCadena().size()); i++) {
          for (int j{0}; j < static_cast<int>(alfabeto.GetCadena().size()); j++) {
            if (cadena.GetCadena()[i] == alfabeto.GetCadena()[j]) {
              alfabeto_cadena.InsertarEnAlfabeto(cadena.GetCadena()[i]);
            }
          }
        }
        
        //finalmente escribo en el archivo
        alfabeto_cadena.MostrarAlfabeto(archivo_salida);
      }

    } else {
      
      //Puesto que el alfabeto asociado está formado por los símbolos del alfabeto original que forman la cadena
      //como la cadena vacía se forma al no tomar ningún elemento, suponemos que el alfabeto asociado no existe
      CadenaVaciaAlfabeto(archivo_salida);
    }

    


  }

  archivo_salida.close();
  archivo_entrada.close();
}




//esta función devuelve la longitud de cada cadena del archivo
void OpcionLongitud(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  
  AperturaArchivos(archivo_entrada, archivo_salida);

  //título del documento
  archivo_salida << "---LONGITUD DE LAS CADENAS---" << std::endl;
  
  Cadena cadena;
  Cadena alfabeto;
  Cadena cadena_vacia("&");
  while (archivo_entrada >> cadena >> alfabeto) {
    
    if (cadena != cadena_vacia) {
      
      //después de comprobar si es distinta a la cadena vacía compruebo si todos sus símbolos existen en el alfabeto
      if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
        
        int longitud{static_cast<int>(cadena.GetCadena().size())}; //le doy el valor del size de la cadena a la variable longitud
        
        //imprimo en el documento la longitud de cada cadena
        archivo_salida << "Longitud de " << cadena.GetCadena() << ": " << longitud << std::endl;
      }


    } else {
      CadenaVaciaLongitud(archivo_salida);
    }

  }

  archivo_salida.close();
  archivo_entrada.close();

}





void OpcionInversa(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  AperturaArchivos(archivo_entrada, archivo_salida);

  archivo_salida << "---INVERSA DE LAS CADENAS---" << std::endl;
  Cadena cadena, alfabeto;
  Cadena cadena_vacia("&");

  //leo la cadena y el alfabeto para luego leer la cadena al revés e ir insertando en la nueva cadena los simbolos en orden inverso
  while (archivo_entrada >> cadena >> alfabeto) {
    //compruebo si todos sus símbolos existen en el alfabeto
    if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
      Cadena cadena_inversa;
      //añado a una nueva cadena los símbolos en orden invertido  
      for (int i{static_cast<int>(cadena.GetCadena().size()) - 1}; i >= 0; i--) {
        cadena_inversa.SetCadena(cadena.GetCadena()[i]);
      }
      //muestro enel archivo el resultado
      archivo_salida << "La cadena inversa de " << cadena.GetCadena() << ": " << cadena_inversa.GetCadena() << std::endl;
    }

  }

  archivo_entrada.close();
  archivo_salida.close();
}







void OpcionPrefijos(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  AperturaArchivos(archivo_entrada, archivo_salida);

  archivo_salida << "---PREFIJOS---" << std::endl;
  Cadena cadena, alfabeto;
  Cadena cadena_vacia("&");
  //creo un lenguaje para cada cadena
  while (archivo_entrada >> cadena >> alfabeto) {
    
    //compruebo si todos sus símbolos existen en el alfabeto
    if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
      Lenguaje lenguaje;
      
      //el bucle funciona de tal manera que lo que sería el límite va aumentando hasta el tamaño de la cadena. Por tanto el tamaño del prefijo aumenta también
      for (int i{0}; i < static_cast<int>(cadena.GetCadena().size()); i++) {
      
        //esta cadena auxiliar nos sirve para los prefijos
        Cadena prefijo;
        for (int j{0}; j <= i; j++) {
      
          //añado los simbolos de la cadena a prefijos
          prefijo.SetCadena(cadena.GetCadena()[j]);
        }
      
        //añado el prefijo al lenguaje
        lenguaje.AñadirCadena(prefijo);
      }
      
      //finalmente escribo en el fichero el lenguaje
      lenguaje.EscribirLenguaje(archivo_salida);
    }

  }

  archivo_entrada.close();
  archivo_salida.close();
}





void OpcionSufijos(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  AperturaArchivos(archivo_entrada, archivo_salida);

  archivo_salida << "---SUFIJOS---" << std::endl;
  Cadena cadena, alfabeto;
  Cadena cadena_vacia("&");
  //creo un lenguaje para cada cadena
  while (archivo_entrada >> cadena >> alfabeto) {
    
    //compruebo si todos sus símbolos existen en el alfabeto
    if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
      Lenguaje lenguaje;
      
      //el bucle funciona de tal manera que lo que sería el límite va aumentando hasta el tamaño de la cadena. Por tanto el tamaño del prefijo aumenta tmb
      for (int i{static_cast<int>(cadena.GetCadena().size()) - 1}; i >= 0 ; i--) {
      
        //esta cadena auxiliar nos sirve para los prefijos
        Cadena sufijo;
        for (int j{i}; j < static_cast<int>(cadena.GetCadena().size()); j++) {
      
          //añado los simbolos de la cadena a prefijos
          sufijo.SetCadena(cadena.GetCadena()[j]);
        }
      
        //añado el prefijo al lenguaje
        lenguaje.AñadirCadena(sufijo);
      }
      
      //finalmente escribo en el fichero el lenguaje
      lenguaje.EscribirLenguaje(archivo_salida);
    }
    
  }
  
  archivo_entrada.close();
  archivo_salida.close();
}