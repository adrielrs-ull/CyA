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
  Cadena cadena;
  Alfabeto alfabeto;
  Cadena cadena_vacia("&");

  //Leo la cadena y el alfabeto del archivo de entrada
  while (archivo_entrada >> cadena >> alfabeto) {
    //cfeo el alfabeto asociado

    //compara si la cadena es la vacía o no
    if (cadena != cadena_vacia) {
      //después de comprobar si es distinta a la cadena vacía compruebo si todos sus símbolos existen en el alfabeto
      if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
        std::set<symbol> alfabeto_aux = cadena.AlfabetoAsociado(alfabeto);
        Alfabeto alfabeto_cadena(alfabeto_aux);
        //finalmente escribo en el archivo
        archivo_salida << alfabeto_cadena;
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
  Alfabeto alfabeto;
  Cadena cadena_vacia("&");
  while (archivo_entrada >> cadena >> alfabeto) {
    
    if (cadena != cadena_vacia) {
      
      //después de comprobar si es distinta a la cadena vacía compruebo si todos sus símbolos existen en el alfabeto
      if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {     
        //imprimo en el documento la longitud de cada cadena
        archivo_salida << "Longitud de " << cadena.GetCadena() << ": " << cadena.Longitud() << std::endl;
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
  Cadena cadena;
  Alfabeto alfabeto;
  Cadena cadena_vacia("&");

  //leo la cadena y el alfabeto para luego leer la cadena al revés e ir insertando en la nueva cadena los simbolos en orden inverso
  while (archivo_entrada >> cadena >> alfabeto) {
    //compruebo si todos sus símbolos existen en el alfabeto
    if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
      
      //muestro enel archivo el resultado
      archivo_salida << "La cadena inversa de " << cadena.GetCadena() << ": " << cadena.Inversa().GetCadena() << std::endl;
    }

  }

  archivo_entrada.close();
  archivo_salida.close();
}







void OpcionPrefijos(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  AperturaArchivos(archivo_entrada, archivo_salida);

  archivo_salida << "---PREFIJOS---" << std::endl;
  Cadena cadena;
  Alfabeto alfabeto;
  Cadena cadena_vacia("&");
  //creo un lenguaje para cada cadena
  while (archivo_entrada >> cadena >> alfabeto) {
    
    //compruebo si todos sus símbolos existen en el alfabeto
    if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
      std::set<Cadena> lenguaje_aux = cadena.Prefijos();
      Lenguaje lenguaje(lenguaje_aux);
      
      //finalmente escribo en el fichero el lenguaje
      archivo_salida << lenguaje << std::endl;
    }

  }

  archivo_entrada.close();
  archivo_salida.close();
}





void OpcionSufijos(std::ifstream& archivo_entrada, std::ofstream& archivo_salida) {
  AperturaArchivos(archivo_entrada, archivo_salida);

  archivo_salida << "---SUFIJOS---" << std::endl;
  Cadena cadena;
  Alfabeto alfabeto;
  Cadena cadena_vacia("&");
  //creo un lenguaje para cada cadena
  while (archivo_entrada >> cadena >> alfabeto) {
    
    //compruebo si todos sus símbolos existen en el alfabeto
    if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
      std::set<Cadena> lenguaje_aux = cadena.Sufijos();
      Lenguaje lenguaje(lenguaje_aux);
      //finalmente escribo en el fichero el lenguaje
      archivo_salida << lenguaje << std::endl;
    }
    
  }
  
  archivo_entrada.close();
  archivo_salida.close();
}


//Devuelve la potencia 'n' de una cadena

void OpcionPotencia(std::ifstream& archivo_entrada, std::ofstream& archivo_salida, const int potencia) {
  AperturaArchivos(archivo_entrada, archivo_salida);
  archivo_salida << "---POTENCIA CADENAS---" << std::endl;
  
  Cadena cadena;
  Alfabeto alfabeto;
  Cadena cadena_vacia("&");
  while (archivo_entrada >> cadena >> alfabeto) {
    if (potencia == 0 || cadena == cadena_vacia) {
      archivo_salida << "La potencia de " << cadena << ": &." << std::endl;
    } else if (cadena != cadena_vacia) {
        //compruebo si todos sus símbolos existen en el alfabeto
        if (SimbolosEnAlfabeto(cadena, alfabeto, archivo_salida)) {
          archivo_salida << "Potencia " << potencia << " de la cadena " << cadena.GetCadena() << ": " << cadena.Potencia(potencia).GetCadena() << std::endl;
        }
  
      }

  }

  archivo_entrada.close();
  archivo_salida.close();
}