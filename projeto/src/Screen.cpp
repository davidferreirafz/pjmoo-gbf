////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#include "Screen.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Destrutor
Screen::~Screen()
{
//    UtilLog::subSistema("Removendo GraphicSystemScreen");
}
//Desenha uma surface na surface de v�deo
void Screen::blitSurface(SDL_Surface * origem, GBF::Point posicao)
{
    SDL_Rect rPosicao = toRect(posicao);
    SDL_BlitSurface(origem, NULL , pScreen, &rPosicao);
}

//Desenha uma surface na surface de v�deo
void Screen::blitSurface(SDL_Surface * origem, GBF::Area area, GBF::Point posicao)
{
    SDL_Rect rArea    = toRect(area);
    SDL_Rect rPosicao = toRect(posicao);


    SDL_BlitSurface(origem, &rArea , pScreen, &rPosicao);
}
//Retorna ponteiro para a surface de v�deo
SDL_Surface * Screen::getScreen()
{
    return pScreen;
}
//Trava a surface para desenhar
bool Screen::lock()
{
    if (SDL_MUSTLOCK(pScreen)) {
        if (SDL_LockSurface(pScreen) < 0) {
            return false;
        }
    }
    return true;
}
//Destrava a surface para desenhar
void Screen::unlock()
{
    if (SDL_MUSTLOCK(pScreen)) {
        SDL_UnlockSurface(pScreen);
    }
}
//Construtor
Screen::Screen()
{
//    UtilLog::subSistema("Instanciando GraphicSystemScreen");
}
//Informa qual a surface a ser usada e a configura��o
void Screen::setScreen(SDL_Surface * surface)
{
    pScreen = surface;
}

SDL_Rect Screen::toRect(GBF::Area area)
{
    SDL_Rect rect;

    rect.y = area.top;
    rect.x = area.left;
    rect.w = area.right;
    rect.h = area.bottom;

    return rect;
}

SDL_Rect Screen::toRect(GBF::Point point)
{
    SDL_Rect rect;

    rect.y = point.y;
    rect.x = point.x;
    rect.w = 0;
    rect.h = 0;

    return rect;
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
