/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
using namespace std;
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	double _coef;
	int _grado;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	///! \name Constructores de la clase Monomio 									/* --- CONSTRUCTORES --- */

	/*!
		\brief	Constructor que crea un monomio a partir de su coeficiente y su grado
		\note 	Función inline
		\param 	coeficiente: valor del coeficiente del monomio. Valor por defecto: 0.0
		\param	grado: valor del grado del monomio. Valor por defecto: 0
		\pre 		El valor del grado debe ser igual o mayor que 0
		\post 	El coeficiente del monomio debe tener el valor del parámetro "coeficiente"
		\post 	El grado del monomio debe tener el valor del parámetro "grado"
		\sa 		setCoeficiente(), setGrado()
	*/

	inline Monomio(double coeficiente = 0.0, int grado = 0) {
		#ifndef NDEBUG
			assert(grado >= 0);
		#endif

		setCoeficiente(coeficiente);
		setGrado(grado);

		#ifndef NDEBUG
			assert(abs(getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(getGrado() == grado);
		#endif
	}

	/*!
		\brief	Constructor que crea un monomio a partir de otro monomio
		\note 	Función inline
		\param 	m: Monomio del que se tomarán los valores del nuevo Monomio
		\pre 		Ninguna
		\post 	El coeficiente del monomio debe tener el valor del coeficiente del Monomio m
		\post 	El grado del monomio debe tener el valor del grado del Monomio m
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/

	inline Monomio(Monomio const &m) {
		setCoeficiente(m.getCoeficiente());
		setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(abs(getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(getGrado() == m.getGrado());
		#endif
	}

	//! \name Observadores: funciones de consulta de la clase Monomio 		/* --- OBSERVADORES --- */

	/*!
		\brief	Función que devuelve el valor del coeficiente de un Monomio
		\note 	Función inline
		\pre 		Ninguna
		\post 	Ninguna
	*/

	inline double getCoeficiente() const{
		return _coef;
	}

	/*!
		\brief	Función que devuelve el valor del grado de un Monomio
		\note 	Función inline
		\pre 		Ninguna
		\post 	Ninguna
	*/

	inline int getGrado() const{
		return _grado;
	}

	//! \name Funciones de modificación de la clase Monomio 						/* --- MODIFICADORES --- */

	/*!
		\brief	Función que asigna un valor al coeficiente de un Monomio
		\note 	Función inline
		\param 	c: nuevo valor del coeficiente del Monomio
		\pre 		Ninguna
		\post 	El coeficiente del monomio debe ser igual a "c"
		\sa 		setGrado()
	*/

	inline void setCoeficiente(double c){
		_coef = c;
		#ifndef NDEBUG
			assert(abs(getCoeficiente() - c) < COTA_ERROR);
		#endif
	}

	/*!
		\brief	Función que asigna un valor al grado de un Monomio
		\note 	Función inline
		\param 	g: nuevo valor del coeficiente del Monomio
		\pre 		Ninguna
		\post 	El grado del monomio debe ser igual a "g"
		\sa 		setCoeficiente()
	*/

	inline void setGrado(int g){
		_grado = g;
		#ifndef NDEBUG
			assert(getGrado() == g);
		#endif
	}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

	/*!
		\brief	Sobrecarga del operador de asignación "="
		\param 	m: Monomio del que se tomarán los valores
		\pre 		Ninguna
		\post 	El coeficiente del monomio debe tener el valor del coeficiente del Monomio m
		\post 	El grado del monomio debe tener el valor del grado del Monomio m
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/

		Monomio & operator=(Monomio const &m);

	/*!
		\brief	Sobrecarga del operador de asignación "="
		\param 	x: double del que se tomará el valor del coeficiente
		\pre 		Ninguna
		\post 	El coeficiente del monomio debe tener el valor del double x
		\post 	El grado del monomio debe tener el valor 0
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

	/*!
		\brief	Sobrecarga del operador de operacion y asignación "+="
		\param 	m: Monomio del que se tomarán los valores
		\pre 		El Monomio m tiene el mismo grado que el Monomio actual
		\post 	El coeficiente del monomio se ha incrementado con el coeficiente del Monomio m
		\post 	El grado del monomio actual no ha sido modificado
		\sa 		getCoeficiente(), getGrado(), setCoeficiente()
	*/

		Monomio & operator+=(Monomio const &m);

	/*!
		\brief	Sobrecarga del operador de operacion y asignación "-="
		\param 	m: Monomio del que se tomarán los valores
		\pre 		El Monomio m tiene el mismo grado que el Monomio actual
		\post 	El coeficiente del monomio se ha decrementado con el coeficiente del Monomio m
		\post 	El grado del monomio actual no ha sido modificado
		\sa 		getCoeficiente(), getGrado(), setCoeficiente()
	*/

		Monomio & operator-=(Monomio const &m);

	/*!
		\brief	Sobrecarga del operador de operacion y asignación "*="
		\param 	m: Monomio del que se tomarán los valores
		\pre 		Ninguna
		\post 	El coeficiente del monomio actual se ha multiplicado por el coeficiente del Monomio m
		\post 	El grado del monomio actual se ha incrementado con el grado del Monomio m
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/

		Monomio & operator*=(Monomio const &m);

	/*!
		\brief	Sobrecarga del operador de operacion y asignación "/="
		\param 	m: Monomio del que se tomarán los valores
		\pre 		El grado del monomio “m” es igual o inferior al grado del monomio actual
		\pre 		El coeficiente del monomio “m” no es 0.0
		\post 	El coeficiente del monomio actual se ha dividido por el coeficiente del Monomio m
		\post 	El grado del monomio actual se ha decrementado con el grado del Monomio m
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/

		Monomio & operator/=(Monomio const &m);

	/*!
		\brief	Sobrecarga del operador de operacion y asignación "*="
		\param 	x: double que se utilizará como multiplicando
		\pre 		Ninguna
		\post 	El coeficiente del monomio actual se ha multiplicado por el valor de x
		\post 	El grado del monomio actual no ha sido modificado
		\sa 		getCoeficiente(), getGrado(), setCoeficiente()
	*/	

		Monomio & operator*=(double const &x);

	/*!
		\brief	Sobrecarga del operador de operacion y asignación "/="
		\param 	x: double que se utilizará como divisor
		\pre 		El número x no es 0.0
		\post 	El coeficiente del monomio actual se ha dividido por el valor de x
		\post 	El grado del monomio actual no ha sido modificado
		\sa 		getCoeficiente(), getGrado(), setCoeficiente()
	*/	

		Monomio & operator/=(double const &x);
	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	/*!
		\brief	Funcion que recoge los parámetros de un Monomio
	*/	

	void leerMonomio();

	/*!
		\brief	Funcion que imprime los parámetros de un Monomio
	*/	
	void escribirMonomio();


	///////////////////////////////////////////////////////////////////////

		double calcularValor (double const &x);

	//! \name Funciones extra de la clase Monomio

	/*!
		\brief	Sobrecarga del operador "^"
		\param 	x: double que se utilizará como potencia
		\post 	El coeficiente del monomio actual se ha elevado a la potencia de x
		\post 	El grado del monomio actual se ha multiplicado por x
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	Monomio & operator^(double const &x);

	/*!
		\brief	Función que obtiene la derivada de un monomio
		\post 	El coeficiente del monomio actual se ha multiplicado por el valor del grado
		\post 	El grado del monomio actual se ha reducido en 1
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/	

	inline Monomio getDerivada(){
		ed::Monomio *nuevo = new ed::Monomio();
		double y = getCoeficiente();		
		int z = getGrado();	
		nuevo->setCoeficiente(y * z);
		nuevo->setGrado(z - 1);
		#ifndef NDEBUG
			assert(abs(nuevo->getCoeficiente() - (y * z)) < COTA_ERROR);
			assert(nuevo->getGrado() == z - 1);
		#endif	
		return *nuevo;
	}



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
