#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Pacman.h"

using namespace std;

Pacman::Pacman()
{
    //Player
    PlayerX = 30;
    PlayerY = 30;

    //Player Matrix
    PlayerColisaoX = 0;
    PlayerColisaoY = 0;

    //Cima
    CimaX = 0;
    CimaY = 0;
    CimaAredondadoX = 0;
    CimaAredondadoY = 0;

    //Baixo
    BaixoX = 0;
    BaixoY = 0;
    BaixoAredondadoX = 0;
    BaixoAredondadoY = 0;

    //Direita
    DireitaX = 0;
    DireitaY = 0;
    DireitaAredondadoX = 0;
    DireitaAredondadoY = 0;

    //Esquerda
    EsquerdaX = 0;
    EsquerdaY = 0;
    EsquerdaAredondadoX = 0;
    EsquerdaAredondadoY = 0; 

    Placar = 0;

    //Altura e Largura
    PacmanAltura = 30;
    PacmanLargura = 30;

    //Direçoes
    up = false;
    right = false;
    down = false;
    left = false;

    //Lado
    lado = 0;

}

Pacman::Pacman(int x, int y)
{
    //Player
    PlayerX = x;
    PlayerY = y;

    //Player Matrix
    PlayerColisaoX = 0;
    PlayerColisaoY = 0;

    //Cima
    CimaX = 0;
    CimaY = 0;
    CimaAredondadoX = 0;
    CimaAredondadoY = 0;

    //Baixo
    BaixoX = 0;
    BaixoY = 0;
    BaixoAredondadoX = 0;
    BaixoAredondadoY = 0;

    //Direita
    DireitaX = 0;
    DireitaY = 0;
    DireitaAredondadoX = 0;
    DireitaAredondadoY = 0;

    //Esquerda
    EsquerdaX = 0;
    EsquerdaY = 0;
    EsquerdaAredondadoX = 0;
    EsquerdaAredondadoY = 0; 

    Placar = 0;

    //Altura e Largura
    PacmanAltura = 30;
    PacmanLargura = 30;

    //Direçoes
    up = false;
    right = false;
    down = false;
    left = false;

    //Lado
    lado = 0;

}

void Pacman::PosicaoPacman() {
    //Player
    PlayerColisaoY = ((PlayerY) / 30);
    PlayerColisaoX = ((PlayerX) / 30);

    //Cima
    CimaY = ceil(((PlayerY) / 30));
    CimaX = ((PlayerX) / 30);
    CimaAredondadoY = ceil(((PlayerY) / 30));
    CimaAredondadoX = ceil(((PlayerX) / 30));

    //Baixo
    BaixoY = (((PlayerY) / 30));
    BaixoX = ceil(((PlayerX) / 30));
    BaixoAredondadoY = (((PlayerY) / 30));
    BaixoAredondadoX = (((PlayerX) / 30));

    //Direita
    DireitaY = ceil(((PlayerY) / 30));
    DireitaX = ((PlayerX) / 30);
    DireitaAredondadoY = ((PlayerY) / 30);
    DireitaAredondadoX = ((PlayerX) / 30);

    //Esquerda
    EsquerdaY = ceil(((PlayerY) / 30));
    EsquerdaX = ceil(((PlayerX) / 30));
    EsquerdaAredondadoY = ((PlayerY) / 30);
    EsquerdaAredondadoX = ceil(((PlayerX) / 30));

}

bool Pacman::ColisaoPacman(vector<vector<char>>& mapa) {
    if (mapa[PlayerColisaoY][PlayerColisaoX] != 'T')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Pacman::PacmanPegaPirula(vector<vector<char>>& mapa) {
    if (mapa[getPacmanYMatriz()][getPacmanXMatriz()] == 'P')
    {
        mapa[getPacmanYMatriz()][getPacmanXMatriz()] = 'E';
        Placar++;
    }

}

int Pacman::getPlacar() {
    return Placar;
}

bool Pacman::ColisaoPacmanCima(vector<vector<char>>& mapa) {
    if (mapa[CimaY - 1][CimaX] != 'T' && mapa[CimaAredondadoY - 1][CimaAredondadoX] != 'T')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pacman::ColisaoPacmanBaixo(vector<vector<char>>& mapa) {
    if (mapa[BaixoY + 1][BaixoX] != 'T' && mapa[BaixoAredondadoY + 1][BaixoAredondadoX] != 'T')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pacman::ColisaoPacmanDireita(vector<vector<char>>& mapa) {
    if (mapa[DireitaY][DireitaX + 1] != 'T' && mapa[DireitaAredondadoY][DireitaAredondadoX + 1] != 'T')
    {     
        return true;
    }
    else
    {
        return false;
    }
}
bool Pacman::ColisaoPacmanEsquerda(vector<vector<char>>& mapa) {
    if (mapa[EsquerdaY][EsquerdaX - 1] != 'T' && mapa[EsquerdaAredondadoY][EsquerdaAredondadoX - 1] != 'T')
    {
        return true;    
    }
    else
    {
        return false;
    }
}

int Pacman::getPacmanXMatriz() {
    return PlayerColisaoX;
}
int Pacman::getPacmanYMatriz() {
    return PlayerColisaoY;
}

float Pacman::getPacmanX() {
    return PlayerX;
}
float Pacman::getPacmanY() {
    return PlayerY;
}
void Pacman::setPacmanX(float X) {
    PlayerX = X;
}
void Pacman::setPacmanY(float Y) {
    PlayerY = Y;
}

void Pacman::ComandosPacman(int Comando, vector<vector<char>>& mapa) {
    // Cima
    if (Comando == ALLEGRO_KEY_UP && ColisaoPacmanCima(mapa) == true)
    {
        up = true;
        down = false;
        right = false;
        left = false; 
    }
    //Baixo
    if (Comando == ALLEGRO_KEY_DOWN && ColisaoPacmanBaixo(mapa) == true)
    {
        up = false;
        down = true;
        right = false;
        left = false; 
    }
    //Direita
    if (Comando == ALLEGRO_KEY_RIGHT && ColisaoPacmanDireita(mapa) == true)
    {
        up = false;
        down = false;
        right = true;
        left = false;

        lado = 1;
    }
    //Esquerda
    if (Comando == ALLEGRO_KEY_LEFT && ColisaoPacmanEsquerda(mapa) == true)
    {
        up = false;
        down = false;
        right = false;
        left = true;

        lado = 0;
    }
}

void Pacman::MovimentacaoPacman(vector<vector<char>>& mapa) {

    //Movimentação
    
    // Cima
    if (up == true && ColisaoPacmanCima(mapa) == true) 
    { 
        setPacmanY(getPacmanY() - 2.0);
    }
    //Baixo
    if (down == true && ColisaoPacmanBaixo(mapa) == true)
    { 
        setPacmanY(getPacmanY() + 2.0);
    }
    //Direita
    if (right == true && ColisaoPacmanDireita(mapa) == true)
    {
        setPacmanX(getPacmanX() + 2.0);
    }
    //Esquerda
    if (left == true && ColisaoPacmanEsquerda(mapa) == true) 
    { 
        setPacmanX(getPacmanX() - 2.0);
    }  
}

void Pacman::DesenhaPacman(int sprite, ALLEGRO_BITMAP* ImgPacman) {
    al_draw_bitmap_region(ImgPacman, sprite * PacmanLargura, lado * PacmanAltura, PacmanLargura, PacmanAltura, getPacmanX(), getPacmanY(), 0);
}

Pacman::~Pacman()
{

}

