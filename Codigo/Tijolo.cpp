#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Tijolo.h"

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

Tijolo::Tijolo() {

	//Inicialização da cordenadas do objeto das Tijolo
	PosicaoX = 0;
	PosicaoY = 0;
	//Inicialização da imagem do objeto das Tijolo
	ImgTijolo = al_load_bitmap("Imagens/bloco.png");

}

Tijolo::Tijolo(int CorX, int CorY, ALLEGRO_BITMAP* Img) : PosicaoX(CorX), PosicaoY(CorY), ImgTijolo(Img) {}

void Tijolo::desenhaTijolo() const
{
	al_draw_bitmap(ImgTijolo, PosicaoX * 30, PosicaoY * 30, 0);
}
 
Tijolo::~Tijolo() {
	//al_destroy_bitmap(ImgTijolo);// destroi os tijolos
}
