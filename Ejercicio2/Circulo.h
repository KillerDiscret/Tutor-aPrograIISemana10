#ifndef __Circulo_h__
#define __Circulo_h__
#include "Figura.h"
class CCirculo : public CFigura
{
public:
	CCirculo(int x, int y, int dx, int ancho, int alto):CFigura(x, y, dx, ancho, alto){
		
	}
	~CCirculo(){}
	void dibujar(Graphics^g) {
		g->FillEllipse(Brushes::Blue, x, y, ancho, alto);
	}
private:

};

#endif // !__Circulo_h__
