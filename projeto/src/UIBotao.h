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

#ifndef _UIBOTAO_H
#define _UIBOTAO_H

#include "UIComponente.h"
#include <string>

#include "UITexto.h"

namespace UserInterface {

namespace Componente {

class UIBotao : public UserInterface::UIComponente
{
  public:
    UIBotao(std::string fonte, std::string chaveTexto, const SDLKey & tecla);

    virtual ~UIBotao();

    //Retorna a tecla correspondente ao bot�o
    SDLKey getTecla();


  protected:
    SDLKey tecla;

    UserInterface::Texto::UITexto botao;

    //Desenha os componentes visuais
    virtual void desenhar();

};

} // namespace UserInterface::Componente

} // namespace UserInterface
#endif