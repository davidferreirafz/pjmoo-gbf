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
#include "UIWindowRecord.h"

namespace UserInterface {

namespace Window {

void UIWindowRecord::update()
{
    tempoEspera.update();

    textName.setValue(record.name);
    textScore.setValue(record.score);
}

/** Desenha o bot�o de a��o da janela */
void UIWindowRecord::drawForeground()
{
    if (showErro){
        writeManager->writeKeyText(fontNotice.name, fontNotice.point.x, fontNotice.point.y, "GBF_UIRecorde_warning");
    }
}

/** Desenha o conteudo da janela */
void UIWindowRecord::drawContent()
{
    // escrevendo titulo centralizado
    writeManager->writeKeyText(fontTitle.name, fontTitle.point.x, fontTitle.point.y, "GBF_UIRecorde_title");

    keyboard.execute();
    textName.execute();
    textScore.execute();
}

/** Efetua as a��es de acordo com a posi��o do cursor */
int UIWindowRecord::confirmSelection()
{
    int opcao = false;

    if ((inputSystem->keyboard->isKey(SDLK_RETURN)) || (inputSystem->joystick->isButtonA())){

        showErro = false;

        int selecao = keyboard.getIndex();

        if ((selecao >= 0) && (selecao < keyboard.getTotalCaracter())){
            record.name[nameIndex] = keyboard.getCaracter();
            nameIndex++;
        } else if (selecao == keyboard.getTotalCaracter()){//controle voltar
            nameIndex--;
        } else if (selecao == keyboard.getTotalCaracter() + 1){//controle avancar
            nameIndex++;
        } else if (selecao == keyboard.getTotalCaracter() + 2){//controle salvar
            //if (recorde.nome[0]!=' '){
            if (strlen(record.name) > 1){
                opcao = BUTTON_SAVE;
            } else {
                showErro = true;
            }
        }

        tempoEspera.setReset();
    }

    if (nameIndex < 0){
        nameIndex = 0;
    } else if (nameIndex > 9){
        nameIndex = 9;
    }

    textName.setCursorPosicao(nameIndex);

    return opcao;
}

const int UIWindowRecord::BUTTON_SAVE = 200;

/** Inicializa as configura��es da caixa de texto */
void UIWindowRecord::initialize()
{
    UIWindow::initialize();

    GBF::Dimension d = keyboard.getDimension();

    int pX = (point.x + dimension.w) / 2 - (d.w / 2);
    int pY = (point.y + dimension.h) / 2;

    keyboard.setPoint(pX, pY);


    pY = pY + keyboard.getDimension().h;
    fontNotice.point.x = pX;
    fontNotice.point.y = pY;

    pX = point.x + fontTitle.dimension.h;
    pY = point.y + (fontTitle.dimension.h * 1.5);

    textName.setPoint(pX, pY);

    pX = point.x + dimension.w - textScore.getDimension().w - fontTitle.dimension.h;

    textScore.setPoint(pX, pY);
}

UIWindowRecord::UIWindowRecord()
{
    keyboard.setCaracter("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _+-$%*,.:[]!=");
    keyboard.addControl(0, "GBF_UIRecorde_button_back");
    keyboard.addControl(1, "GBF_UIRecorde_button_next");
    keyboard.addControl(2, "GBF_UIRecorde_button_save");

    textName.setLabel("GBF_UIRecorde_title_player");
    textName.maxLength(10);
    textName.showCursor(true);

    textScore.setLabel("GBF_UIRecorde_title_points");
    textScore.maxLength(8);

    nameIndex = 0;
    point.x = 0;
    point.y = 0;
    background = NULL;

    tempoEspera.setInitialTime(1);
    tempoEspera.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoEspera.setReset();

    showErro = false;
}

/** Destrutor */
UIWindowRecord::~UIWindowRecord()
{
    if (background != NULL){
        delete(background);
    }
}

/** Estilo Visual a ser Aplicado no Componente */
void UIWindowRecord::setBackground(UserInterface::Look::UIBackgroundColor * background)
{
    this->background = background;

    textName.setBackground(background);
    textScore.setBackground(background);
    keyboard.setBackground(background);

    keyboard.setColorCursor(255, 255, 0);
}

/** Define a fonte a ser usada pelo Titulo */
void UIWindowRecord::setFontTitle(std::string font)
{
    fontTitle.name = font;
    fontTitle.dimension = writeManager->getFont(fontTitle.name)->getDimension();

    int tamanho = writeManager->getLineWidth(fontTitle.name, "GBF_UIRecorde_title");
    fontTitle.point.x = point.x + (dimension.w / 2) - (tamanho / 2);
    fontTitle.point.y = point.y;
}

void UIWindowRecord::setFontKeyboard(std::string keyFont, std::string controlFont)
{
    keyboard.setFontKey(keyFont);
    keyboard.setFontControl(controlFont);
}

void UIWindowRecord::setFontInput(std::string fontLabel, std::string fontValue)
{
    textName.setFont(fontLabel);
    textName.setFontInput(fontValue);

    textScore.setFont(fontLabel);
    textScore.setFontInput(fontValue);

    textScore.showCursor(false);

    fontNotice.name = fontLabel;
}

/** Retorna o TopSystemRecorde */
Score::Score UIWindowRecord::getRecord()
{
    return record;
}

/** Atribui um RSRecorde para complementar os dados */
void UIWindowRecord::setRecord(Score::Score record)
{
    this->record  = record;
    nameIndex    = 0;
    tempoEspera.setReset();
}

/** Gerencia o controle do cursor (navega��o) e as op��es selecionadas */
bool UIWindowRecord::isAction(int action)
{
    bool salva = false;

    if (tempoEspera.isFinish()){
        if (confirmSelection() == action) {
            salva = true;
        }
    }

    return salva;
}

} // namespace UserInterface::Window

} // namespace UserInterface
