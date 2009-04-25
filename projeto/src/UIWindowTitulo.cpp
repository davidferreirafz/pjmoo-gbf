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

#include "UIWindowTitulo.h"

namespace UserInterface {

namespace Window {

UIWindowTitulo::UIWindowTitulo() 
{
    titulo.setAlinhamento(Texto::TEXTO_CENTRALIZADO);
}
UIWindowTitulo::~UIWindowTitulo(){
}

void UIWindowTitulo::desenharConteudo() 
{
    UIWindowDialog::desenharConteudo();

    int posicaoTextoHorizontal = 0;
    int posicaoTextoVertical   = posicao.y+int(titulo.getDimensaoLetra().h*0.2);

    if (titulo.getAlinhamento()==Texto::TEXTO_CENTRALIZADO){
        int auxiliar = wsManager->getLarguraLinha(titulo.getFonte(),titulo.getChaveTexto());
        posicaoTextoHorizontal=int (posicao.x+(dimensao.w/2)-(auxiliar/2));
    } else {
        posicaoTextoHorizontal = posicao.x+titulo.getDimensaoLetra().w;
    }

    wsManager->escreverLocalizado(titulo.getFonte(),posicaoTextoHorizontal,posicaoTextoVertical,titulo.getChaveTexto());

}
//Inicializa as configura��es da caixa de texto

//Inicializa as configura��es da caixa de texto
void UIWindowTitulo::inicializar() 
{
    UIWindowDialog::inicializar();
    titulo.setDimensaoLetra(wsManager->getFonte(titulo.getFonte())->getDimensao());
    espacoAntesTexto=int(titulo.getDimensaoLetra().h*titulo.ENTRELINHA_UMA_MEIA);
}

} // namespace UserInterface::Window

} // namespace UserInterface