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

#ifndef _PARTICLESYSTEMSPRITE_H
#define _PARTICLESYSTEMSPRITE_H

#include "ParticleSystemEfeito.h"
#include <deque>
#include "Sprite.h"

class ParticleSystemSprite : public ParticleSystemEfeito
{
  public:
    //Construtor
    ParticleSystemSprite();

    //Destrutor
    virtual ~ParticleSystemSprite();

    //Desenha todas as unidades
    virtual void desenhar();

    //Verifica se terminou a anima��o de todos os sprites
    virtual bool isTerminou();


  protected:
    std::deque<Sprite *> lista;

};
#endif
