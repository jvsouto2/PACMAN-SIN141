#include <iostream>
#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#ifndef PACMAN_H
#define PACMAN_H

using namespace std;

class Pacman
{
public:
	Pacman();
	Pacman(int,int);

	void PosicaoPacman();

	bool ColisaoPacman(vector<vector<char>>& mapa);

	void PacmanPegaPirula(vector<vector<char>> &mapa);
    int getPlacar();

	bool ColisaoPacmanCima(vector<vector<char>>& mapa);
	bool ColisaoPacmanBaixo(vector<vector<char>>& mapa);
	bool ColisaoPacmanDireita(vector<vector<char>>& mapa);
	bool ColisaoPacmanEsquerda(vector<vector<char>>& mapa);

	int getPacmanXMatriz();
	int getPacmanYMatriz();

    float getPacmanX();
    float getPacmanY();

    void setPacmanX(float);
    void setPacmanY(float);

	void ComandosPacman(int, vector<vector<char>>& mapa);
	void MovimentacaoPacman(vector<vector<char>>& mapa);

	void DesenhaPacman(int, ALLEGRO_BITMAP*);

	~Pacman();

private:

    //Player
    float PlayerX;
    float PlayerY;

    //Player Matriz
    int PlayerColisaoX;
    int PlayerColisaoY;

    //Cima
    int CimaX, CimaY;
    int CimaAredondadoX, CimaAredondadoY;

    //Baixo
    int BaixoX, BaixoY;
    int BaixoAredondadoX, BaixoAredondadoY;

    //Direita
    int DireitaX, DireitaY;
    int DireitaAredondadoX, DireitaAredondadoY;

    //Esquerda
    int EsquerdaX, EsquerdaY;
    int EsquerdaAredondadoX, EsquerdaAredondadoY;

    int Placar;

    //Altura e Largura
	int PacmanAltura;
	int PacmanLargura;

	// Direcoes
	bool up;
    bool down;
	bool right;
	bool left;

    //Lado
	int lado;

};
#endif