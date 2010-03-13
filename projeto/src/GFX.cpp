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

#include "GFX.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Destrutor
GFX::~GFX()
{
//    UtilLog::subSistema("Removendo GraphicSystemGFX");
    pScreen = NULL;
}
//Seta a cor a ser usada (Usado normalmente para transformar c�digo r,g,b em uma cor)
void GFX::setColor(GBF::Color::Pallete R, GBF::Color::Pallete G, GBF::Color::Pallete B)
{
    color = SDL_MapRGB(pScreen->format,R,G,B);
}
//Seta a cor a ser usada (Usar somente se a cor j� estiver sido mapeada para RGB)
void GFX::setColor(GBF::Color::Cor cor)
{
    color = cor;
}
//Desenha um pixel na tela (Usado para cores em formado decimal)
void GFX::putPixel(int x, int y, GBF::Color::Pallete R, GBF::Color::Pallete G, GBF::Color::Pallete B)
{
    putPixel(x,y,SDL_MapRGB(pScreen->format,R,G,B));
}
//Desenha um pixel na tela (Usado apenas se a cor j� estiver em formato RGB)
void GFX::putPixel(int x, int y, GBF::Color::Cor cor)
{
    if (offSetLimite(x,y)){
        Uint8 *pixel = (Uint8 *)pScreen->pixels + y * pScreen->pitch + x * bpp;

        switch(bpp) {
            case 1:
                    *pixel = cor;
                break;
            case 2:
                    *(Uint16 *)pixel = cor;
                break;
            case 3:
                    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                        pixel[0] = (cor >> 16) & 0xff;
                        pixel[1] = (cor >> 8) & 0xff;
                        pixel[2] = cor & 0xff;
                    } else {
                        pixel[0] = cor & 0xff;
                        pixel[1] = (cor >> 8) & 0xff;
                        pixel[2] = (cor >> 16) & 0xff;
                    }
                break;
            case 4:
                    *(Uint32 *)pixel = cor;
                break;
        }
    }
}
//Pegar a cor de um pixel na tela
GBF::Color::Cor GFX::getPixel(int x, int y)
{
    if (offSetLimite(x,y)){
        Uint8 *pixel = (Uint8 *)pScreen->pixels + y * pScreen->pitch + x * bpp;

        switch(bpp) {
            case 1:
                return *pixel;
            case 2:
                return *(Uint16 *)pixel;
            case 3:
                if (SDL_BYTEORDER == SDL_BIG_ENDIAN){
                    return pixel[0] << 16 | pixel[1] << 8 | pixel[2];
                } else {
                    return pixel[0] | pixel[1] << 8 | pixel[2] << 16;
                }
            case 4:
                return *(Uint32 *)pixel;
            default:
                return 0;
        }
    } else {
        return 0;
    }
}
//Desenha uma linha na tela
void GFX::linha(int XI, int YI, int XF, int YF)
{
    #define sgn(x) ((x<0)?-1:((x>0)?1:0))
    /* macro para retornar o seno de um numero */

    int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

    dx=XF-XI; /* the horizontal distance of the line */
    dy=YF-YI; /* the vertical distance of the line */
    dxabs=abs(dx);      dyabs=abs(dy);
    sdx=sgn(dx);        sdy=sgn(dy);
    x=dyabs>>1;         y=dxabs>>1;
    px=XI;              py=YI;

    gsScreen->lock();
    putPixel(px,py);
    /* the line is more horizontal than vertical */
    if (dxabs>=dyabs) {
        for(i=0;i<dxabs;i++) {
            y+=dyabs;
            if (y>=dxabs){
                y-=dxabs;
                py+=sdy;
            }
            px+=sdx;
            putPixel(px,py);
        }
    /* the line is more vertical than horizontal */
    } else {
        for(i=0;i<dyabs;i++){
            x+=dxabs;
            if (x>=dyabs){
                x-=dyabs;
                px+=sdx;
            }
            py+=sdy;
            putPixel(px,py);
        }
    }
    gsScreen->unlock();
}
//Desenha um circulo
void GFX::circulo(int X, int Y, int RAIO)
{
    float n=0,invradius=1/(float)RAIO;
    int dx=0,dy=RAIO-1;
    int Px=X, Py=Y;
    int dyoffset=Py;
    int dxoffset=Px;

    gsScreen->lock();
    while (dx<=dy){
        dxoffset = dx;
        dyoffset = dy;
        putPixel(Px+dy,Py-dxoffset);// octant 0
        putPixel(Px+dx,Py-dyoffset);// octant 1
        putPixel(Px-dx,Py-dyoffset);// octant 2
        putPixel(Px-dy,Py-dxoffset);// octant 3
        putPixel(Px-dy,Py+dxoffset);// octant 4
        putPixel(Px-dx,Py+dyoffset);// octant 5
        putPixel(Px+dx,Py+dyoffset);// octant 6
        putPixel(Px+dy,Py+dxoffset);// octant 7
        dx++;
        n+=invradius;
        dy=int(RAIO * sin(acos(n)));
    }
    gsScreen->unlock();
}
//Desenha um circulo preenchido
void GFX::circuloPreenchido(int X, int Y, int RAIO)
{
    float n=0,invradius=1/(float)RAIO;
    int dx=0,dy=RAIO-1;
    int Px=X, Py=Y;
    int dyoffset=Py;
    int dxoffset=Px;

    gsScreen->lock();
    while (dx<=dy)	{
        dxoffset = dx;
        dyoffset = dy;

        for(int i=dy;i>=dx;i--,dyoffset-=RAIO){
            putPixel(Px+i,Py-dxoffset); // octeto 0
            putPixel(Px+dx,Py-i);       // octeto 1
            putPixel(Px-dx,Py-i);       // octeto 2
            putPixel(Px-i,Py-dxoffset); // octeto 3
            putPixel(Px-i,Py+dxoffset); // octeto 4
            putPixel(Px-dx,Py+i);       // octeto 5
            putPixel(Px+dx,Py+i);       // octeto 6
            putPixel(Px+i,Py+dxoffset); // octeto 7
        }

        dx++;
        n+=invradius;
        dy=int(RAIO * sin(acos(n)));
    }
    gsScreen->unlock();
}
//Desenha um retangulo
void GFX::retangulo(int X, int Y, int W, int H)
{
    linha(X,Y,X+W,Y);
    linha(X,Y,X,Y+H);
    linha(X+W,Y,X+W,Y+H);
    linha(X,Y+H,X+W,Y+H);
}
//Desenha um retangulo preenchido
void GFX::retanguloPreenchido(int X, int Y, int W, int H)
{
    SDL_Rect retangulo;
    retangulo.x=X;
    retangulo.y=Y;
    retangulo.w=W;
    retangulo.h=H;

    SDL_FillRect(pScreen,&retangulo,color);
}
//Desenha cruzamentos com fechamento na parte superior (rever utilidade)
void GFX::gradeSuperior(int X, int Y, int W, int H)
{
    linha(X,Y,X+W,Y);
    linha(X,Y,X,Y+H);
}
//Desenha cruzamentos com fechamento na parte inferior (rever utilidade)
void GFX::gradeInferior(int X, int Y, int W, int H)
{
    linha(X+W,Y,X+W,Y+H);
    linha(X,Y+H,X+W,Y+H);
}
//Inicializa informa��es b�sicas
void GFX::inicializar()
{
//    UtilLog::comentario("Inicializando GraphicSystemGFX");
    pScreen  = gsScreen->getScreen();
    bpp      = pScreen->format->BytesPerPixel;
    setColor(0xFFFFFF);
}
//Verifica se o ponto (x,y) est� dentro dos limites
bool GFX::offSetLimite(int x, int y)
{
    if ((x<0)||(y<0)||(x>=pScreen->w)||(y>=pScreen->h)) {
        return false;
    } else {
        return true;
    }
}
Screen * GFX::gsScreen= NULL;

void GFX::setGraphicSystemScreen(Screen * screen)
{
    gsScreen = screen;
}
//Construtor
GFX::GFX()
{
    std::cout << "GBF::Kernel::Graphic::GFX" << std::endl;
    pScreen = NULL;
}
//Realiza um lock na surface
bool GFX::travar()
{
    return gsScreen->lock();
}
//Realiza um unlock na surface
void GFX::destravar()
{
    gsScreen->unlock();
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
