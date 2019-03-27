/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	#ifndef NDEBUG
    for(int i=0; i<=getGrado();i++){
    	if(existeMonomio(i) && p.existeMonomio(i)){
    		assert(abs(getMonomio(i).getCoeficiente() - p.getMonomio(i).getCoeficiente()) <= COTA_ERROR);
     		}
     	}	
      #endif
    _polinomio.clear();
    int aux = p.getGrado();
    for (int i = aux; i >= 0; i--) {
          if (p.existeMonomio(i) == true) {
        _polinomio.push_back(p.getMonomio(i));
          }
    }
    
    ordenarpolinomio();
    #ifndef NDEBUG
    for(int i=0; i<=getGrado();i++){
    	if(existeMonomio(i) && p.existeMonomio(i)){
    		assert(abs(getMonomio(i).getCoeficiente() - p.getMonomio(i).getCoeficiente()) < COTA_ERROR);
    		assert(getMonomio(i).getGrado() == p.getMonomio(i).getGrado());
     		}
     	}	
      #endif
    return *this;

}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR
	_polinomio.clear();
	_polinomio.push_back(m);
	
	#ifndef NDEBUG
		assert(abs(_polinomio.at(0).getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
		assert(_polinomio.at(0).getGrado() == m.getGrado());
	#endif
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{	
	_polinomio.clear();
	ed::Monomio *nuevo = new ed::Monomio();
	nuevo->setGrado(0);
	nuevo->setCoeficiente(x);
	_polinomio.push_back(*nuevo);
	return *this;
}

//////////////////////////////////////////////////////////////


ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{	
    ed::Polinomio *nuevo = new ed::Polinomio();
    ed::Monomio *nuevo2 = new ed::Monomio();
    *nuevo = *this;
    _polinomio.clear();
    int aux = max(nuevo->getGrado(), p.getGrado());
     for (int i = 0; i <= aux; i++){
         if (p.existeMonomio(i) == false && nuevo->existeMonomio(i)) {
             _polinomio.push_back(nuevo->getMonomio(i));
             
         } else if (nuevo->existeMonomio(i) == false && p.existeMonomio(i)) {
             _polinomio.push_back(p.getMonomio(i));
            
         } else if (p.existeMonomio(i) && nuevo->existeMonomio(i)) {
             *nuevo2 = nuevo->getMonomio(i);
             *nuevo2 += p.getMonomio(i);
             _polinomio.push_back(*nuevo2);
         }
     }
    ordenarpolinomio();
    return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{	
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Monomio *nuevo2 = new ed::Monomio();
	*nuevo = *this;
	_polinomio.clear();
	for(int i=0; i<=nuevo->getGrado();i++){

		if(nuevo->existeMonomio(i)==true && i==0){
			*nuevo2 = nuevo->getMonomio(i);
			*nuevo2+=x;
			_polinomio.push_back(*nuevo2);
		}
		else if(nuevo->existeMonomio(i)==true){
			_polinomio.push_back(nuevo->getMonomio(i));
		}
        
	}
	ordenarpolinomio();
	// Se devuelve el objeto actual
	return *this;
	
}
ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m){
    ed::Polinomio *nuevo = new ed::Polinomio();
    ed::Monomio *nuevo2 = new ed::Monomio();
    *nuevo = *this;
    _polinomio.clear();
            for (int i = 0; i <= nuevo->getGrado(); i++){
                if (nuevo->existeMonomio(i) && (m.getGrado()==i)) {
                    *nuevo2 = nuevo->getMonomio(i);
                    *nuevo2 += m; 
                    _polinomio.push_back(*nuevo2);
                }
                else if(nuevo->existeMonomio(i)){
                    _polinomio.push_back(nuevo->getMonomio(i));
                }
            
        }
    ordenarpolinomio();
    return *this;
}
ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p){
    ed::Polinomio *nuevo = new ed::Polinomio();
    ed::Monomio *nuevo2 = new ed::Monomio();
    *nuevo = *this;
    _polinomio.clear();
    int aux = max(nuevo->getGrado(), p.getGrado());
     for (int i = 0; i <= aux; i++){
         if (p.existeMonomio(i) == false && nuevo->existeMonomio(i)) {
             _polinomio.push_back(nuevo->getMonomio(i));
             
         } else if (nuevo->existeMonomio(i) == false && p.existeMonomio(i)) {
             _polinomio.push_back(p.getMonomio(i));
            
         } else if (p.existeMonomio(i) && nuevo->existeMonomio(i)) {
             *nuevo2 = nuevo->getMonomio(i);
             *nuevo2 -= p.getMonomio(i);
             _polinomio.push_back(*nuevo2);
         }
     }
     eliminarcero();
    ordenarpolinomio();
     eliminarcero();
     eliminarcero();
    return *this;

}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m){
    ed::Polinomio *nuevo = new ed::Polinomio();
    ed::Monomio *nuevo2 = new ed::Monomio();
    *nuevo = *this;
    _polinomio.clear();
         if (nuevo->existeMonomio(m.getGrado())==false) {
             _polinomio.push_back(m);
             } 
        else{
            for (int i = 0; i <= nuevo->getGrado(); i++){
                if (nuevo->existeMonomio(i) && (m.getGrado()==i)) {
                    *nuevo2 = nuevo->getMonomio(i);
                    *nuevo2 -= m; 
                    _polinomio.push_back(*nuevo2);
                }
                else if(nuevo->existeMonomio(i)){
                    _polinomio.push_back(nuevo->getMonomio(i));
                }
            }
        }
    ordenarpolinomio();
     eliminarcero();
    return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{	
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Monomio *nuevo2 = new ed::Monomio();
	*nuevo = *this;
	_polinomio.clear();
	for(int i=0; i<=nuevo->getGrado();i++){

		if(nuevo->existeMonomio(i)==true && i==0){
			*nuevo2 = nuevo->getMonomio(i);
			*nuevo2-=x;
			_polinomio.push_back(*nuevo2);
		}
		else if(nuevo->existeMonomio(i)==true){
			_polinomio.push_back(nuevo->getMonomio(i));
		}
        
	}
	ordenarpolinomio();
	// Se devuelve el objeto actual
	return *this;
	
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p){
    ed::Polinomio *nuevo = new ed::Polinomio();
    ed::Monomio *nuevo2 = new ed::Monomio();
    *nuevo = *this;
    _polinomio.clear();
    int aux = max(nuevo->getGrado(), p.getGrado());
     for (int i = 0; i <= aux; i++){
        for(int j=0; j<=aux;j++){
            if(p.existeMonomio(j)==true && nuevo->existeMonomio(i) ){
                *nuevo2 = nuevo->getMonomio(i);
                *nuevo2 *= p.getMonomio(j); 
                _polinomio.push_back(*nuevo2);
            }
        }
     }
    //ajusta();
    ordenarpolinomio();
    return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m){
    ed::Polinomio *nuevo = new ed::Polinomio();
    ed::Monomio *nuevo2 = new ed::Monomio();
    *nuevo = *this;
    _polinomio.clear();
     for (int i = 0; i <= nuevo->getGrado() ; i++){
        if(nuevo->existeMonomio(i)){
            *nuevo2 = nuevo->getMonomio(i);
            *nuevo2*= m; 
            _polinomio.push_back(*nuevo2);
        }
     }
    //ajusta();
    ordenarpolinomio();
    return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{	
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Monomio *nuevo2 = new ed::Monomio();
	*nuevo = *this;
	_polinomio.clear();
	for(int i=0; i<=nuevo->getGrado();i++){
		if(nuevo->existeMonomio(i)){
			*nuevo2 = nuevo->getMonomio(i);
			*nuevo2 *=x;
			_polinomio.push_back(*nuevo2);
		}
        
	}
	ordenarpolinomio();
	// Se devuelve el objeto actual
	return *this;
	
}
ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p){
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Polinomio *p2 = new ed::Polinomio();
	ed::Monomio *nuevo2 = new ed::Monomio();
	*nuevo = *this;
	_polinomio.clear();
	while(p.getGrado()<=nuevo->getGrado()){
		*p2=p;
		*nuevo2 =(nuevo->getMonomio(nuevo->getGrado()))/(p.getMonomio(p.getGrado()));
		//std::cout<<"cociente"<<std::endl;
		//nuevo2->escribirMonomio();
		//std::cout<<std::endl;
		this->_polinomio.push_back(*nuevo2);
		*p2 *= *nuevo2;
		//std::cout<<"cociente por divisor"<<std::endl;
		//p2->escribirPolinomio();
		//std::cout<<std::endl;
		//std::cout<<"antiguo dividendo"<<std::endl;
		//nuevo->escribirPolinomio();
		*p2*=(-1);
		*nuevo+=*p2;
		nuevo->eliminarcero();
		//std::cout<<"nuevo dividendo"<<std::endl;
		//nuevo->escribirPolinomio();
		//std::cout<<std::endl;
	}
	
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m){
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Monomio *p2 = new ed::Monomio();
	ed::Monomio *nuevo2 = new ed::Monomio();
	*nuevo = *this;
	_polinomio.clear();
	while(m.getGrado()<=nuevo->getGrado()){
		*p2=m;
		*nuevo2 =(nuevo->getMonomio(nuevo->getGrado())/m);
		//std::cout<<"cociente"<<std::endl;
		//nuevo2->escribirMonomio();
		//std::cout<<std::endl;
		this->_polinomio.push_back(*nuevo2);
		*p2 *= *nuevo2;
		//std::cout<<"cociente por divisor"<<std::endl;
		//p2->escribirPolinomio();
		//std::cout<<std::endl;
		//std::cout<<"antiguo dividendo"<<std::endl;
		//nuevo->escribirPolinomio();
		*p2*=(-1);
		*nuevo+= *p2;
		nuevo->eliminarcero();
		//std::cout<<"nuevo dividendo"<<std::endl;
		//nuevo->escribirPolinomio();
		//std::cout<<std::endl;
	}
	
	return *this;
}
///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio
/*void escribirPolinomio(){
	for (int i = 0; i < counter_; ++i)
	{
		escribirPolinomio(Polinomio_[i]);
		if(i!=counter_-1)
			std::cout<<"x"<<std::endline;
	}
}*/



///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

