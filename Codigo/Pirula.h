#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

using namespace std;

#ifndef PIRULA_H
#define PIRULA_H

class Pirula {
public:
	Pirula();
	Pirula(int, int, ALLEGRO_BITMAP*);
	int getPirulaX()const;
	int getPirulaY()const;
	void setPirulaImg(ALLEGRO_BITMAP* Img);
	void desenhaPirula()const;
	~Pirula();
; private:

	ALLEGRO_BITMAP* ImgPirula;
	int PosicaoX;
	int PosicaoY;
};

#endif // PIRULA_H
