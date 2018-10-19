#ifndef __Triangulo_h__
#define __Triangulo_h__
#include "Figura.h"
class CTriangulo : public CFigura
{
public:
	CTriangulo(int x, int y, int dx, int ancho, int alto) :CFigura(x, y, dx, ancho/2, alto) {

	}
	~CTriangulo() {}
	void dibujar(Graphics^g) {
		g->DrawLine(Pens::Blue, x, y, x - ancho, y + alto);
		g->DrawLine(Pens::Blue, x - ancho, y + alto, x + ancho, y + alto);
		g->DrawLine(Pens::Blue, x, y, x + ancho, y + alto);
	}
private:

};

#endif // !__Triangulo_h__
