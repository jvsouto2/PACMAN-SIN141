#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Pirula.h"

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

Pirula::Pirula() {
	//Inicialização da cordenadas do objeto das Pirulas
	PosicaoX = 0;
	PosicaoY = 0;
	//Inicialização da imagem do objeto das Pirulas
	ImgPirula = NULL;
}

Pirula::Pirula(int CorX, int CorY, ALLEGRO_BITMAP* Img) : PosicaoX(CorX), PosicaoY(CorY), ImgPirula(Img) {}

int Pirula::getPirulaX()const
{
	return PosicaoX;
}

int Pirula::getPirulaY()const
{
	return PosicaoY;
}

void Pirula::setPirulaImg(ALLEGRO_BITMAP* Img)
{
	ImgPirula = Img;
}

void Pirula::desenhaPirula() const {
	al_draw_bitmap(ImgPirula, PosicaoX*30, PosicaoY*30, 0);
}


Pirula::~Pirula() {
	//al_destroy_bitmap(ImgPirula);// destroi os Pirulas
}
