/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>
#include <unistd.h>
#include <math.h>
#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m) {
	if (this != &m) {
		setCoeficiente(m.getCoeficiente());
		setGrado(m.getGrado());
		#ifndef NDEBUG
			assert(abs(getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(getGrado() == m.getGrado());
		#endif
	}

	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x) {
	setGrado(0);
	setCoeficiente(x);
	return *this;
	#ifndef NDEBUG
		assert(getGrado() == 0);
		assert(abs(getCoeficiente() - x) < COTA_ERROR);
	#endif
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m) {
	//precondicion
	#ifndef NDEBUG
	assert(this->getGrado()==m.getGrado());
	#endif
	double coeficiente=this->getCoeficiente();
	int grado=this->getGrado();

	this->setCoeficiente((this->getCoeficiente()+m.getCoeficiente()));
	//postcondicion
	#ifndef NDEBUG
	//assert(this->getCoeficiente()>coeficiente);
	assert(this->getGrado()==grado);
	 #endif
	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m) {
	#ifndef NDEBUG
		assert(getGrado() == m.getGrado());
	#endif
	double y = getCoeficiente();										
	setCoeficiente(getCoeficiente() - m.getCoeficiente());
	#ifndef NDEBUG
		assert(abs(getCoeficiente() - (y - m.getCoeficiente())) < COTA_ERROR);
	#endif
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m) {
	double y = getCoeficiente();		
	int z = getGrado();									
	setCoeficiente(getCoeficiente() * m.getCoeficiente());
	setGrado(getGrado() + m.getGrado());
	#ifndef NDEBUG
		assert(abs(getCoeficiente() - (y * m.getCoeficiente())) < COTA_ERROR);
		assert(getGrado() == z + m.getGrado());
	#endif
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m) {
	#ifndef NDEBUG
		assert(m.getGrado() <= getGrado());
		assert(m.getCoeficiente() != 0.0);
	#endif
	double y = getCoeficiente();		
	int z = getGrado();								
	setCoeficiente(getCoeficiente() / m.getCoeficiente());
	setGrado(getGrado() - m.getGrado());
	#ifndef NDEBUG
		assert(abs(getCoeficiente() - (y / m.getCoeficiente())) < COTA_ERROR);
		assert(getGrado() == z - m.getGrado());
	#endif
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double const &x) {
	double y = getCoeficiente();		
	int z = getGrado();	
	setCoeficiente(getCoeficiente()*x);
	#ifndef NDEBUG
		assert(abs(getCoeficiente() - (y * x)) < COTA_ERROR);
		assert(getGrado() == z);
	#endif		
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &x) {
	double y = getCoeficiente();		
	int z = getGrado();	
	setCoeficiente(getCoeficiente()/x);
	#ifndef NDEBUG
		assert(abs(getCoeficiente() - (y / x)) < COTA_ERROR);
		assert(getGrado() == z);
	#endif	
	return *this;
}	
///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio(){
	double c;
	int g;
	cout << "Introduce el coeficiente: ";
	cin >> c;
	cout << "Introduce el grado: ";
	cin >> g;
	setCoeficiente(c);
	setGrado(g);
}

void ed::Monomio::escribirMonomio(){
	if (getGrado() == 0) {
		cout << getCoeficiente();
	} else if (getCoeficiente() == 1 && getGrado() == 1) {
		cout << "x";
	} else if (getCoeficiente() == 1 && getGrado() != 0 && getGrado() != 1){
		cout << "x^" << getGrado();
	} else if (getCoeficiente() == -1 && getGrado() == 1) {
		cout << "-x";
	} else if (getCoeficiente() == -1 && getGrado() != 0 && getGrado() != 1){
		cout << "-x^" << getGrado();
	} else {
		cout << getCoeficiente() << "x^" << getGrado();
	}
}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor (double const &x) {
	return (getCoeficiente() * pow(x, getGrado()));
}

ed::Monomio & ed::Monomio::operator^(double const &x) {
	double y = getCoeficiente();		
	int z = getGrado();	
	setCoeficiente(pow(getCoeficiente(),x));
	setGrado(getGrado()*x);
	#ifndef NDEBUG
		assert(abs(getCoeficiente() - (pow(y,x))) < COTA_ERROR);
		assert(getGrado() == z * x);
	#endif	
	return *this;
}	
