/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

#include <bits/stdc++.h> 
// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"
#define COTA_ERROR 1.0e-6 
using namespace std;
// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

	vector <Monomio> _polinomio;  

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio
    /*! 
    \brief     Constructor que crea un polinomio a partir de un monomio nulo
    \attention Funcion sobrecargada        
    \note      Funcion inline
    \param     ninguno
    \pre       Ninguna
    \post      El polinomio creado es nulo
    \note    Se debe utilizar COTA_ERROR para controlar la precision de los nÃºmeros reales
  */
  	inline Polinomio() {
  		ed::Monomio *nuevo = new ed::Monomio();
  		_polinomio.push_back(*nuevo);
  		#ifndef NDEBUG
      assert(abs(_polinomio.at(0).getCoeficiente()-nuevo->getCoeficiente())<COTA_ERROR);
      assert((_polinomio.at(0).getGrado()-nuevo->getGrado())==0);
  		#endif
  	}
        /*! 
    \brief     Constructor que crea un polinomio a partir de otro polinomio
    \attention Funcion sobrecargada        
    \note      Funcion inline
    \param     p: polinomio el cual se va copiar
    \pre       los polinomios son distintos
    \post      el polinomio creado es igual al polinomio p
    \note      Se debe utilizar COTA_ERROR para controlar la precision de los nÃºmeros reales
  */
  	inline Polinomio(Polinomio  &p) {
      _polinomio = p._polinomio;
      #ifndef NDEBUG
      for(int i=0; i<=getGrado();i++){
        if(existeMonomio(i) && p.existeMonomio(i))
      assert(abs(getMonomio(i).getCoeficiente() - p.getMonomio(i).getCoeficiente()) < COTA_ERROR);
      assert(getMonomio(i).getGrado() == p.getMonomio(i).getGrado());
      }
      #endif
  	}
  	

  //! \name Observadores: funciones de consulta de la clase Polinomio
        /*! 
    \brief     Indicia si un polinomio es nulo o no       
    \note      Funcion inline
    \param     Ninguno
    \pre       Ninguna
    \post      Ninguna
  */
  inline bool esNulo() const {
      bool value = (getNumeroMonomios() == 1 && existeMonomio(0) && getMonomio(0).getCoeficiente() == 0.0);
      return value;
    }

  
            /*! 
    \brief     obtiene el grado del polinomio     
    \note      Funcion inline
    \param     Ninguno
    \pre       El polinomio debe estar ordenado 
    \post      Ninguna
    \note    
  */
    inline int getGrado()const {
      ed::Monomio *nuevo = new ed::Monomio();
      *nuevo = _polinomio.front();
      return nuevo->getGrado();
    }
    /*! 
    \brief     devuelve el numero de monomios que conforman el polinomio    
    \note      Funcion inline
    \param     Ninguno
    \pre       Ninguna
    \post      Ninguna
    \note    
  */
      inline int getNumeroMonomios() const {
      return _polinomio.size();
    }
        /*! 
    \brief     indica que si existe un monomio dentre del polinomio de grado in   
    \note      Funcion inline
    \param     in: grado del monomio que queremos encontrar
    \pre       El polinomio debe existir
    \post      Ninguna    
  */
    inline bool existeMonomio(int in) const {
      for (int i = 0; i < getNumeroMonomios(); i++) {
        if (_polinomio.at(i).getGrado() == in) {
          return true;
          break;
        }
      }
      return false;
    }
      /*!
    \brief     devuelve el monomio de grado de in dentro del polinomio 
    \note      Funcion inline
    \param     in: grado del monomio que vamos a devolver
    \pre       El polinomio debe existir
    \post      Ninguna    
  */
        inline Monomio getMonomio(int in) const
     {
      for (int i = 0; i < getNumeroMonomios(); i++) {
        if (_polinomio.at(i).getGrado() == in) {
          return _polinomio.at(i);
          break;
        }
      }
      return false;
    }


	//! \name Funciones de modificación de la clase Polinomio

	// COMPLETAR


 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	 /*! 
    \brief     Operador de asignacion: operador que asigna los valores de un polinomio a otro
    \attention Se sobrecarga el operador de asignacion "="
    \param     p: objeto de la clase polinomio pasado como referencia constante
    \pre       El polinomio “p” debe ser diferente del polinomio actual
    \post      El polinomio actual debe ser igual al polinomio “p”
  */
	Polinomio & operator=(Polinomio const &p);
     /*! 
    \brief     Operador de asignacion: operador que asigna los valores de un monomio a un polinomio
    \attention Se sobrecarga el operador de asignacion "="
    \param     m: objeto de la clase monomio pasado como referencia constante
    \pre       Ninguna
    \post      El polinomio actual debe tener un único monomio que será igual al monomio“m”
  */
	Polinomio & operator=(Monomio const &m);

	 /*! 
    \brief     Operador de asignacion: operador que asigna los valores de un entero a un polinomio
    \attention Se sobrecarga el operador de asignacion "="
    \param     x: variable de tipo entero pasado por referencia
    \pre       Ninguna
    \post      El polinomio actual debe ser igual al numero "x"
  */
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

	/*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al primer objeto polinomio la suma de ambos polinomios
  */
	Polinomio & operator+=(Polinomio const &p);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al objeto polinomio la suma de este con el monomio
  */
	Polinomio & operator+=(Monomio const &m);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al objeto polinomio la suma de este con el entero x
  */
  Polinomio & operator+=(double const &x);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al primero objeto polinomio la resta de ambos polinomios
  */
	Polinomio & operator-=(Polinomio const &p);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al objeto polinomio la resta de este con el monomio
  */
	Polinomio & operator-=(Monomio const &m);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al objeto polinomio la resta de este con el entero x
  */
  Polinomio & operator-=(double const &x);
    /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al primer objeto polinomio la multiplicacion de ambos polinomios
  */
	Polinomio & operator*=(Polinomio const &p);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al objeto polinomio la multiplicacion de este con el monomio
  */
	Polinomio & operator*=(Monomio const &m);
  /*! 
    \brief   Operador aritmetico y asignacion: operador que asigna al objeto polinomio la multiplicacion de este con el entero x
  */
  Polinomio & operator*=(double const &x);
	
  Polinomio & operator/=(Polinomio const &p);

  Polinomio & operator/=(Monomio const &m);


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio
  /*! 
    \brief     Funcion de lectura: lee desde el teclado los atributos de los monomios que conforman el polinomio
    \param     Ninguno
    \pre       Ninguna
    \post      Ninguna
  */  
	
  inline void leerPolinomio() {
      ed::Monomio *nuevo = new ed::Monomio();
      int i = 1;
      char aux;
      do{
        cout << "Monomio " << i << endl << endl;
        nuevo->leerMonomio();
        if (esNulo()) {
          _polinomio.erase(_polinomio.begin());
        }
        if(existeMonomio(nuevo->getGrado())){
          printf("polinomio incorrecto\n");
        }else{
        _polinomio.push_back(*nuevo);
        i++;
        }
        cout << "Introducir otro monomio?(S): ";
        cin >> aux;
        
      }while(aux == 'S' || aux == 's');
      ordenarpolinomio();
    }
      /*! 
    \brief     Funcion de escritura: Escribe por pantalla los atributos de los monomio que forman el polinomio con el formato: coeficiente X^grado y contantenados con el signo +
    \param     Ninguno
    \pre       Ninguna
    \post    Ninguna
  */
      inline void escribirPolinomio() {
      for (int i = 0; i < getNumeroMonomios(); i++) {
        _polinomio.at(i).escribirMonomio();
        if (i != getNumeroMonomios() - 1) { 
          cout << " + ";  
        }
      }
    }



	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio
      /*! 
    \brief     Funcion auxiliar: calcula el valor del polinomio para un numero real "x"
    \param     variable X (tipo double)
    \pre       Ninguna
    \post      Ninguna
  */  
  inline double calcularValor(double const &x){
  double res=0;
  ed::Monomio *aux= new ed::Monomio();
  for(int i=0; i<=getGrado();i++){
    if(existeMonomio(i)){
      *aux=getMonomio(i);
      res+=aux->calcularValor(x);
    }
  }
  return res;
}
    /*! 
    \brief     Funcion auxiliar: ordena los monomios que conforman el polinomio de manera descendente en funcion del grado
    \param     Ninguno
    \pre       Ninguna
    \post      Ninguna
  */
      inline void ordenarpolinomio(){
    ed::Monomio aux;
    int tam=_polinomio.size();
      for (int  i=1; i<tam; i++){
        for (int j=0 ; j<tam- 1; j++){
            if (_polinomio[j].getGrado() < _polinomio[j+1].getGrado()){
                aux = _polinomio[j];
                _polinomio.at(j) = _polinomio.at(j+1);
                _polinomio.at(j+1) = aux;
            }
          }
        }
    }
    /*! 
    \brief     Funcion auxiliar: suma los monomios del mismo grado en caso de que existiesen  
    \param     Ninguno
    \pre       Ninguna
    \post      Ninguna
  */
    inline void ajusta(){
     // int tam=_polinomio.size();
      for (int i = 0; i <getNumeroMonomios(); ++i)
      {
          for (int j = 0; j <getNumeroMonomios(); ++j)
          {
              if(_polinomio.at(j).getGrado()==_polinomio.at(j+1).getGrado()){
                _polinomio.at(j)+=_polinomio.at(j+1);
                _polinomio.erase(_polinomio.begin()+j+1);
              }
          }
      }
  }
  inline void eliminarcero(){
  	for(int i=0; i<getNumeroMonomios();i++){
  		if(! esNulo()){
  			if(_polinomio.at(i).getCoeficiente()<=COTA_ERROR){
  				_polinomio.erase(_polinomio.begin()+i);
  			}
  		}
  	}
  }

}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
