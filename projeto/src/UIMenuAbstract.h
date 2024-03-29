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
#ifndef _UIMENUABSTRACT_H
#define _UIMENUABSTRACT_H

#include "GBF.h"
#include <deque>
#include "UIItemAbstract.h"
#include "TimerRegressive.h"
#include "Color.h"
#include "UserInterface.h"
#include "InputSystemUtility.h"

namespace UserInterface {

namespace Menu {

//Descri��o:
//    Classe para cria��o de menus
//Motiva��o:
//    Fornecer uma interface padr�o para cria��o de menus

class UIMenuAbstract : public GBF::Kernel::Input::InputSystemUtility
{

    protected:
        int selectedItem;

        int verticalSpace;

        GBF::Point point;

        std::deque<UIItemAbstract *> item;

        GBF::Kernel::Timer::TimerRegressive browseDelay;


    public:
        //Construtor
        UIMenuAbstract();

        //Destrutor
        virtual ~UIMenuAbstract();

        void setVerticalSpace(int space);

        void setBorderColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b);

        void setBackgroundColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b);

        //Define a posi��o x,y do menu
        void setPoint(int x, int y);

        //Centraliza o menu na tela de acordo com as coordenadas passadas
        //Obs.: Caso o par�metro de alinhamento seja HORIZONTAL ou VERTICAL ele usar� o par�metro
        //referente a outra posi��o para posicionar o menu na tela
        void center(int x, int y, UserInterface::UIAlinhamento alinhamento);

        bool execute();

        //Adiciona um item ao menu
        void add(UIItemAbstract * item);

        //Retorna o �ndice da op��o selecionada
        virtual int confirmSelection();


    protected:
        GBF::Point calcularAlinhamento(int caixaLargura, int caixaAltura);

        //desenha o menu na tela
        virtual void draw() = 0;

        //remove todos os itens do menu
        void clear();

        virtual void selection();

        virtual bool browse() = 0;

        int maxCharItem;

        UserInterface::UIAlinhamento eAlinhamento;

        GBF::Color::RGB corBorda;

        GBF::Color::RGB corFundo;

};

} // namespace UserInterface::Menu

} // namespace UserInterface

#endif
