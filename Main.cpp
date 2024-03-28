#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

#include "Codigo/Tijolo.h"
#include "Codigo/Pirula.h"

#include "Codigo/Pacman.h"
//#include "Codigo/Placar.h"

using namespace std;

const float FPS = 60;
const int SCREEN_W = 1200; //Largura
const int SCREEN_H = 750; //Altura

const int TAMANHO_BLOCO = 30;

void carregarMapa(const char* nomeArquivo, vector<vector<char>>& mapa) {
    ifstream arquivo(nomeArquivo);
    string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            vector<char> linhaMapa;
            for (char caractere : linha) {
                if (caractere != ' ') {
                    linhaMapa.push_back(caractere);
                }
            }
            mapa.push_back(linhaMapa);
        }
        arquivo.close();
    }
    else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}


int main(int argc, char** argv) {

    // Inicialização do Allegro
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();

    // Criação da janela e do display
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);

    al_set_window_title(display, "Pacman");

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();


    // Criação de um timer para o jogo

    ALLEGRO_TIMER* timer = NULL;//Timer

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    vector<vector<char>> mapa;
    carregarMapa("mapa.txt", mapa);

    int altura = mapa.size();
    int largura = mapa[0].size();

    vector<Tijolo>Tijolos;
    vector<Pirula>Pirulas;

    // Carregamento dos bitmaps
    ALLEGRO_BITMAP* bmptijolo = al_load_bitmap("Imagens/Parede.png");
    ALLEGRO_BITMAP* bmpestrada = al_load_bitmap("Imagens/Estrada.png");
    ALLEGRO_BITMAP* bmppirula = al_load_bitmap("Imagens/EstradaMinion.png");

    // Definição dos elementos do mapa
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (mapa[i][j] == 'T')
            {
                Tijolos.push_back(Tijolo(j, i, bmptijolo));
            }
            else if (mapa[i][j] == 'P')
            {
                Pirulas.push_back(Pirula(j, i, bmppirula));
            }
            else if (mapa[i][j] == 'E')
            {
                Pirulas.push_back(Pirula(j, i, bmpestrada));
            }
        }

    }
    // Carregamento da imagem original
    ALLEGRO_BITMAP* imagemOriginal = al_load_bitmap("Imagens/NasusSpriteCompleto.png");
    if (!imagemOriginal) {
        fprintf(stderr, "Falha ao carregar a imagem original.\n");
        return -1;
    }

    // Criação do bitmap redimensionado
    int novaLargura = 150;
    int novaAltura = 120;
    ALLEGRO_BITMAP* imagemRedimensionada = al_create_bitmap(novaLargura, novaAltura);
    if (!imagemRedimensionada) {
        fprintf(stderr, "Falha ao criar o bitmap redimensionado.\n");
        al_destroy_bitmap(imagemOriginal);
        return -1;
    }

    ALLEGRO_FONT* Fonte = NULL;

    Fonte = al_load_font("Fontes/Roboto-Regular.ttf", 30, 0);

    Pacman Jogador(30, 30);

    // Configuração da fila de eventos
    al_register_event_source(event_queue, al_get_display_event_source(display));
    
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//Evento de tempo

    al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado

    al_start_timer(timer);

    //Vetor de Teclas
    bool teclas[255] = { false };
    
    bool re_desenha = true;

    int sprite = 0, fator = 1;
    int tempo, miliseg = 200;

    int proximaIntrucao = 0;


    // Loop principal do jogo
    bool running = true;
    while (running) {

        Jogador.PosicaoPacman();
        Jogador.PacmanPegaPirula(mapa);


        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        tempo = al_get_timer_count(timer);

        if (ev.type == ALLEGRO_EVENT_TIMER) {


            //Timer para trocar de bitmap
            if (tempo == ((FPS * miliseg) / 1000) || tempo > ((FPS * miliseg) / 1000)) {
                al_set_timer_count(timer, 0);
                sprite = sprite + fator;
                if (sprite == 0) fator = 1;
                if (sprite == 4) fator = -1;
            }


            //Recebe o comando do teclado

            if (teclas[ALLEGRO_KEY_UP])
            {
                proximaIntrucao = ALLEGRO_KEY_UP;
            }
            if (teclas[ALLEGRO_KEY_DOWN])
            {
                proximaIntrucao = ALLEGRO_KEY_DOWN;
            }
            if (teclas[ALLEGRO_KEY_LEFT])
            {
                proximaIntrucao = ALLEGRO_KEY_LEFT;
            }
            if (teclas[ALLEGRO_KEY_RIGHT])
            {
                proximaIntrucao = ALLEGRO_KEY_RIGHT;

            }

            Jogador.ComandosPacman(proximaIntrucao, mapa);
            Jogador.MovimentacaoPacman(mapa);

            re_desenha = true;
        }

        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            teclas[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[ev.keyboard.keycode] = false;

        }
        
        //Redesenha se a fila de eventos esta vazia
        if (re_desenha && al_is_event_queue_empty(event_queue)) { 

            re_desenha = false;

            al_clear_to_color(al_map_rgb(0, 0, 0));

            //Chamada dos elementos do mapa

            for (const auto& elemento : Tijolos) {
                elemento.desenhaTijolo();
            }
            for (const auto& elemento : Pirulas) {
                elemento.desenhaPirula();
                
            }

            for (size_t i = 0; i < Pirulas.size(); i++) {
                if (Jogador.getPacmanXMatriz() == Pirulas[i].getPirulaX() && Jogador.getPacmanYMatriz() == Pirulas[i].getPirulaY())
                {
                    Pirulas[i].setPirulaImg(bmpestrada);
                }
            }

            //Desenha o pacman

            // Configuração do bitmap redimensionado como o alvo de desenho
            al_set_target_bitmap(imagemRedimensionada);

            // Desenho da imagem original no bitmap redimensionado
            al_draw_scaled_bitmap(imagemOriginal, 0, 0, al_get_bitmap_width(imagemOriginal), al_get_bitmap_height(imagemOriginal),
                0, 0, novaLargura, novaAltura, 0);

            // Restauração do alvo de desenho
            al_set_target_backbuffer(display);

            // Desenho do bitmap redimensionado no display
            Jogador.~Pacman();
            Jogador.DesenhaPacman(sprite, imagemRedimensionada);
            al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 1000, 0, 0, "Stacks");
            al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 1050, 35, ALLEGRO_ALIGN_CENTER, "%d", Jogador.getPlacar());

            al_flip_display();

        }
        if (Jogador.getPlacar() == 83)
        {
            running = false;
        }
    }

    // Destrua os bitmaps carregados
    al_destroy_bitmap(bmptijolo);
    al_destroy_bitmap(bmppirula);
    al_destroy_bitmap(bmpestrada);

    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;

}