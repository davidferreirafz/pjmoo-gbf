/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _GRAPHICMODE_H
#define _GRAPHICMODE_H

#include <SDL/SDL.h>

#include <iostream>


namespace GBF {

namespace Kernel {

namespace Graphic {

//Informa��es da Configura��o de V�deo
struct VideoConfig
{
    int w;

    int h;

    int color;

    bool full;

};
class GraphicMode
{
  public:
    //Construtor
    GraphicMode();

    //Destrutor
    ~GraphicMode();

    //Coloca o v�deo em modo de tela cheia
    void setModeFullScreen();

    //Coloca o v�deo em modo de janela
    void setModeWindowScreen();

    //Retorna se o jogo esta rodando em modo de Tela Cheia
    bool isFullScreen();

    //Configura a resolu��o do modo gr�fico
    void setConfig(VideoConfig config);

    //Pega a Configura��o do modo gr�fico
    VideoConfig getConfig();

    //Retorna a Surface Primaria de V�deo (framebuffer)
    SDL_Surface * getScreen();


  protected:
    VideoConfig config;


  private:
    SDL_Surface * screen;

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
