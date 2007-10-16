#ifndef _SPRITEINTERFACE_H
#define _SPRITEINTERFACE_H

////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "GraphicSystemImageBuffer.h"
#include "GBF_define.h"

struct Frame
{
    int atual;

    int total;

};
class Animacao
{
  public:
    //Construtor
    Animacao();

    //Ajusta a area de corte do sprite - posicionamento nos frames
    void ajustarCorte(int direcao, int largura);

    //Informa a quantidade de quadros e a taxa de repeti��o
    void config(int quantidade, int taxaRepeticao);

    //Informa se anima��o est� no fim - �ltimo frame
    bool isFim();

    //Informa se anima��o est� no inicio - primeiro frame
    bool isInicio();

    //Retorna a dimens�o do quadro
    SDL_Rect getDimensaoFrame();

    int processar();

    //Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem 
    void processarManual();

    //Define se a anima��o � autom�tica ou manual 
    void setAutomatico(bool automatico);

    //Define a dimens�o do quadro
    void setDimensaoFrame(const SDL_Rect & area);

    //Coloca a anima��o no primeiro frame
    void setInicio();


  protected:
    bool automatico;

    SDL_Rect areaCorte;

    Frame frame;

    Frame repeticao;

    //Informa o quadro a ser usado na anima��o
    void setFrame(int quadro);


  private:
    //Anima o Sprite de forma autom�tica 
    int animar();

  friend class SpriteItem;
};
class SpriteInterface
{
  public:
    //Destrutor
    virtual ~SpriteInterface();

    void criar(int left, int top, int largura, int altura, GraphicSystemImageBuffer * gsiBuffer);


  protected:
    //Construtor
    SpriteInterface();

    GraphicSystemImageBuffer * imagem;

    SDL_Rect posicao;

    SDL_Rect tamanho;


  public:
    Animacao animacao;

};
#endif
