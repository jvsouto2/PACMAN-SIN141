#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

using namespace std;

#ifndef TIJOLO_H
#define TIJOLO_H

class Tijolo {
	public:
		Tijolo();
		Tijolo(int, int, ALLEGRO_BITMAP*);
		void desenhaTijolo()const;
		~Tijolo();
	;private:
		ALLEGRO_BITMAP* ImgTijolo;
		int PosicaoX;
		int PosicaoY;
};

#endif // !BLOCO_H
