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

#include "UserInterfaceBotao.h"

UserInterfaceBotao::UserInterfaceBotao(std::string fonte, std::string chaveTexto, const SDLKey & tecla){
    botao.setFonte(fonte);
    botao.setChaveTexto(chaveTexto);
    this->tecla=tecla;
}

UserInterfaceBotao::~UserInterfaceBotao(){
}

//Retorna a tecla correspondente ao bot�o

//Retorna a tecla correspondente ao bot�o
SDLKey UserInterfaceBotao::getTecla() 
{
    return tecla;
}
//Desenha os componentes visuais
void UserInterfaceBotao::desenhar() 
{
    wsManager->escreverLocalizado(botao.getFonte(),posicao.x,posicao.y,botao.getChaveTexto());
}
//atualiza as informa��es do componente (posicao, dimensao, estado)
void UserInterfaceBotao::atualizar() 
{
    //Dimensao dimensao = wsManager->getFonte(botao.getFonte())->getDimensao();
    //int tamanhoTexto = wsManager->getLarguraLinha(botao.getFonte(),botao.getChaveTexto());

    //posicao.x=posicao.x-tamanhoTexto;
    // posicao.y=int(posicao.y - (dimensao.h * 1.2));
}
