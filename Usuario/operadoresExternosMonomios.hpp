/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;
using namespace std;
// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	/*!
		\brief	Sobrecarga del operador de igualdad "=="
		\param 	m1: Monomio pasado como referencia constante
		\param 	m2: Monomio pasado como referencia constante
		\pre 		Ninguna
		\post 	El valor devuelto es verdadero si los dos monomios tienen el mismo grado y coeficiente, 
					y falso en caso contrario
		\sa 		getCoeficiente(), getGrado()
	*/	

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief	Sobrecarga del operador de igualdad "=="
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		Ninguna
		\post 	El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual a x, y 
					falso en caso contrario
		\sa 		getCoeficiente(), getGrado()
	*/	

	bool operator==(ed::Monomio const & m1, double const &x);

	/*!
		\brief	Sobrecarga del operador de igualdad "=="
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		Ninguna
		\post 	El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual a x, y 
					falso en caso contrario
		\sa 		getCoeficiente(), getGrado()
	*/	

	bool operator==(double const &x, ed::Monomio const & m1);

	//! \name Operadores de desigualdad 

	/*!
		\brief	Sobrecarga del operador de igualdad "!="
		\param 	m1: Monomio pasado como referencia constante
		\param 	m2: Monomio pasado como referencia constante
		\pre 		Ninguna
		\post 	El valor devuelto es verdadero si los dos monomios no tienen el mismo grado o no tienen
					el mismo coeficiente, y falso en caso contrario
		\sa 		getCoeficiente(), getGrado()
	*/	

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief	Sobrecarga del operador de igualdad "!="
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		Ninguna
		\post 	El valor devuelto es verdadero si el monomio no tiene grado 0 o si su coeficiente no es igual a x,
					y falso en caso contrario
		\sa 		getCoeficiente(), getGrado()
	*/	

	bool operator!=(ed::Monomio const & m1, double const &x);

	/*!
		\brief	Sobrecarga del operador de igualdad "!="
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		Ninguna
		\post 	El valor devuelto es verdadero si el monomio no tiene grado 0 o si su coeficiente no es igual a x,
					y falso en caso contrario
		\sa 		getCoeficiente(), getGrado()
	*/	

	bool operator!=(double const &x, ed::Monomio const & m1);
	//! \name Operadores unarios prefijos

	/*!
		\brief	Sobrecarga del operador aritmético "+"
		\param 	m: Monomio pasado como referencia constante
		\pre 		Ninguna
		\post 	El monomio devuelto es igual a m, es decir, tiene su mismo grado y coeficiente
	*/		

	ed::Monomio & operator+(ed::Monomio const & m);

	/*!
		\brief	Sobrecarga del operador aritmético "-"
		\param 	m: Monomio pasado como referencia constante
		\pre 		Ninguna
		\post 	El monomio devuelto es igual a m, pero su coeficiente es el opuesto
	*/		

	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	/*!
		\brief	Sobrecarga del operador aritmético "+"
		\param 	m1: Monomio pasado como referencia constante
		\param 	m2: Monomio pasado como referencia constante
		\pre 		m1 y m2 tienen el mismo grado
		\post 	El monomio devuelto tiene el mismo grado que m1 y m2, y su coeficiente es la suma de ambos
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);

	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 

	/*!
		\brief	Sobrecarga del operador aritmético "-"
		\param 	m1: Monomio pasado como referencia constante
		\param 	m2: Monomio pasado como referencia constante
		\pre 		m1 y m2 tienen el mismo grado
		\post 	El monomio devuelto tiene el mismo grado que m1 y m2, y su coeficiente es la resta de ambos
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/		

	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);

	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 

	/*!
		\brief	Sobrecarga del operador aritmético "*"
		\param 	m1: Monomio pasado como referencia constante
		\param 	m2: Monomio pasado como referencia constante
		\pre 		Ninguna
		\post 	El monomio devuelto tiene como grado la suma de los grados de m1 y m2,
					y su coeficiente es el producto de los coeficientes de m1 y m2
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief	Sobrecarga del operador aritmético "*"
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		Ninguna
		\post 	El monomio devuelto tiene el mismo grado que m, 
					y su coeficiente es el producto del coeficiente de m por x
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator* (ed::Monomio const &m1, double const &x);


	/*!
		\brief	Sobrecarga del operador aritmético "*"
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		Ninguna
		\post 	El monomio devuelto tiene el mismo grado que m, 
					y su coeficiente es el producto del coeficiente de m por x
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator* (double const &x, ed::Monomio const &m1);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	/*!
		\brief	Sobrecarga del operador aritmético "/"
		\param 	m1: Monomio pasado como referencia constante
		\param 	m2: Monomio pasado como referencia constante
		\pre 		El grado de m2 es menor o igual que el grado de m1, y el coeficiente de m2 no es 0.0
		\post 	El monomio devuelto tiene como grado la resta de los grados de m1 y m2,
					y su coeficiente es la división de los coeficientes de m1 y m2
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief	Sobrecarga del operador aritmético "/"
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		x no es 0.0
		\post 	El monomio devuelto tiene el mismo grado que m, 
					y su coeficiente es la división del coeficiente de m por x
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator/ (ed::Monomio const &m1, double const &x);

	/*!
		\brief	Sobrecarga del operador aritmético "/"
		\param 	m1: Monomio pasado como referencia constante
		\param 	x: valor decimal pasado como referencia constante
		\pre 		El grado de m es 0 y su coeficiente es distinto de 0.0
		\post 	El monomio devuelto tiene grado igual a 0, 
					y su coeficiente es la división de x por el coeficiente de m
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	ed::Monomio & operator/ (double const &x, ed::Monomio const &m1);

	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*!
		\brief	Sobrecarga del operador de flujo de entrada ">>", lee los atributos separados por espacios
		\param 	m: Monomio pasado como referencia constante
		\param	stream: objeto en el que se recogerán los atributos
	*/	

	 istream &operator>>(istream &stream, ed::Monomio &m);

	/*!
		\brief	Sobrecarga del operador de flujo de salida "<<", escribe los atributos separados por espacios
		\param 	m: Monomio pasado como referencia constante
		\param	stream: objeto que almacena los atributos que van a ser imprimidos
	*/	

	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


