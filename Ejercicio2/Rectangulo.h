#ifndef __Rectangulo_h__
#define __Rectangulo_h__
#include "Figura.h"
class CRectangulo : public CFigura
{
public:
	CRectangulo(int x, int y, int dx, int ancho, int alto) :CFigura(x, y, dx, ancho, alto) {

	}
	~CRectangulo() {}
	void dibujar(Graphics^g) {
		g->FillRectangle(Brushes::Green,x, y, ancho, alto);
	}
private:

};

#endif // !__Rectangulo_h__
