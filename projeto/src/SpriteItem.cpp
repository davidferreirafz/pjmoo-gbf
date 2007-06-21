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
////////////////////////////////////////////////////////////////////////

#include "SpriteItem.h"

//Destrutor 
SpriteItem::~SpriteItem() 
{

}
void SpriteItem::setPosicao(Ponto ponto) 
{
    SpriteAbstract::setPosicao(ponto.x,ponto.y);
}
void SpriteItem::desenhar(int x, int y) 
{
    quadro.x= (0)* (tamanho.w * frameTotal);

    SpriteAbstract::desenhar(x,y);
}
//Construtor 
SpriteItem::SpriteItem() 
{
    automatico=false;
}
