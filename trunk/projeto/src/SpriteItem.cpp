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

#include "SpriteItem.h"

//Destrutor 
SpriteItem::~SpriteItem() 
{

}
//Depreciado - observar para remover metodo
void SpriteItem::desenhar(int x, int y) 
{
    animacao.ajustarCorte(0,tamanho.w);

    Sprite::desenhar(x,y);
}
//Construtor 
SpriteItem::SpriteItem() 
{

}
