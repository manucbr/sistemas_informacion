/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	
	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2) {
		bool value = (abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR 
							&& m1.getGrado() == m2.getGrado());
		#ifndef NDEBUG
			assert(value == (abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR 
									&& m1.getGrado() == m2.getGrado()));
		#endif
		return value;
	}

	bool operator==(ed::Monomio const & m1, double const &x) {
		bool value = (m1.getGrado() == 0 && abs(m1.getCoeficiente() - x) < COTA_ERROR);
		#ifndef NDEBUG
			assert(value == (m1.getGrado() == 0 && abs(m1.getCoeficiente() - x) < COTA_ERROR));
		#endif
		return value;
	}

	bool operator==(double const &x, ed::Monomio const & m1) {
		bool value = (m1.getGrado() == 0 && abs(m1.getCoeficiente() - x) < COTA_ERROR);
		#ifndef NDEBUG
			assert(value == (m1.getGrado() == 0 && abs(m1.getCoeficiente() - x) < COTA_ERROR));
		#endif
		return value;
	}

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool value = (abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR 
							|| m1.getGrado() != m2.getGrado());
		#ifndef NDEBUG
			assert(value == (abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR 
									|| m1.getGrado() != m2.getGrado()));
		#endif
		return value;
	}

	bool operator!=(ed::Monomio const & m1, double const &x){
		bool value = (m1.getGrado() != 0 || abs(m1.getCoeficiente() - x) > COTA_ERROR);
		#ifndef NDEBUG
			assert(value == (m1.getGrado() != 0 || abs(m1.getCoeficiente() - x) > COTA_ERROR));
		#endif
		return value;
	}

	bool operator!=(double const &x, ed::Monomio const & m1){
		bool value = (m1.getGrado() != 0 || abs(m1.getCoeficiente() - x) > COTA_ERROR);
		#ifndef NDEBUG
			assert(value == (m1.getGrado() != 0 || abs(m1.getCoeficiente() - x) > COTA_ERROR));
		#endif
		return value;
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m) {
		ed::Monomio *nuevo = new ed::Monomio();
		*nuevo = m;
		#ifndef NDEBUG
			assert(*nuevo == m);
		#endif
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m) {
		ed::Monomio *nuevo = new ed::Monomio();
		*nuevo = m;
		*nuevo *= -1;
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado() 
					&& abs(nuevo->getCoeficiente() + m.getCoeficiente()) < COTA_ERROR);
		#endif
		return *nuevo;
	}




	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif		
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(m1.getCoeficiente() + m2.getCoeficiente() - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif
		return *nuevo;
	}

	////////////
	// Resta

	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif		
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(m1.getCoeficiente() - m2.getCoeficiente() - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif
		return *nuevo;
	}

	//////////////////
	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2) {
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() + m2.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado() + m2.getGrado());
			assert(abs(m1.getCoeficiente() * m2.getCoeficiente() - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif	
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m1, double const &x) {
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(m1.getCoeficiente() * x - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif		
		return *nuevo;
	}

	ed::Monomio & operator* (double const &x, ed::Monomio const &m1) {
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(m1.getCoeficiente() * x - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif		
		return *nuevo;
	}


	////////////
	// División

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2) {
		#ifndef NDEBUG
			assert(m2.getGrado() <= m1.getGrado());
			assert(m2.getCoeficiente() != 0.0);
		#endif
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() / m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() - m2.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado() - m2.getGrado());
			assert(abs(m1.getCoeficiente() / m2.getCoeficiente() - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif	
		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m1, double const &x) {
		#ifndef NDEBUG
			assert(x != 0.0);
		#endif
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(m1.getCoeficiente() / x);
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(m1.getCoeficiente() / x - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif		
		return *nuevo;
	}

	ed::Monomio & operator/ (double const &x, ed::Monomio const &m1) {
		#ifndef NDEBUG
			assert(m1.getGrado() == 0);
			assert(m1.getCoeficiente() != 0.0);
		#endif
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente(x / m1.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
		#ifndef NDEBUG
			assert(nuevo->getGrado() == 0);
			assert(abs(x / m1.getCoeficiente() - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif		
		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		double c;
		int g;

		stream >> c;
		m.setCoeficiente(c);
		stream >> g;
		m.setGrado(g);
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		stream << m.getCoeficiente() << " " << m.getGrado();
		return stream;
	}


}  // namespace ed
