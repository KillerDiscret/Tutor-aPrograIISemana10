#ifndef __Figura_h__
#define __Figura_h__
using namespace System;
using namespace System::Drawing;
class CFigura
{
public:
	CFigura(int x, int y, int dx, int ancho, int alto){
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->ancho = ancho;
		this->alto = alto;
		aux_x = x;
		cont = 0;
		puesto = 0;
	}
	~CFigura(){}
	virtual void dibujar(Graphics^g) abstract;
	virtual void mover(int x_linea) {
		Random r;
		if (x + ancho >= x_linea)
		{
			x = aux_x;
			cont++;
			dx = r.Next(4, 15);
		}
		if(cont!=5)
			x += dx;
	}
	virtual int getCont() {
		return cont;
	}
	virtual int getpuesto() {
		return puesto;
	}
	virtual void setPuesto(int v) {
		puesto = v;
	}
protected:
		//Auxiliares
		int aux_x;
		//posicion
		int x;
		int y;
		//movimiento
		int dx;
		//tamaño
		int ancho;
		int alto;
		int cont;
		int puesto;
};

#endif // !__Figura_h__
//class CFigura
//{
//public:
//	CFigura(int x, int y, int dx, int ancho, int alto);
//	~CFigura();
//	virtual void dibujar(Graphics^g) abstract;
//	virtual void mover(int x_linea);
//private:
//	//Auxiliares
//	int aux_x;
//	//posicion
//	int x;
//	int y;
//	//movimiento
//	int dx;
//	//tamaño
//	int ancho;
//	int alto;
//};
//
//CFigura::CFigura(int x, int y, int dx, int ancho, int alto) {
//	this->x = x;
//	this->y = y;
//	this->dx = dx;
//	this->ancho = ancho;
//	this->alto = alto;
//	aux_x = x;
//}
//
//CFigura::~CFigura()
//{
//}
//void CFigura::mover(int x_linea) {
//	if (x + ancho >= x_linea)
//		x = aux_x;
//	x += dx;
//}