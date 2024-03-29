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
#include "FXManager.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
FXManager::~FXManager()
{
//    UtilLog::subSistema("Removendo SoundSystemFxManager");
    Mix_HaltChannel(-1);
    std::map<std::string,FX*>::iterator it;

    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
            //UtilLog::tracer("SoundFx=%s",((*it).first).c_str());
        } catch(...){
           // UtilLog::tracer("SoundFx=Desconhecido(a)");
        }
        delete ((*it).second);
        (*it).second=NULL;
        //UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
//Toca uma efeito sonoro
void FXManager::play(std::string nome)
{

    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->play();
    }
}
//Carregar um arquivo de efeito sonoro para o gerenciador
void FXManager::loadFromFile(std::string nome, std::string arquivo)
{
    std::string fullpath=Kernel::Util::Path::getPath()+arquivo;

    FX *som = new FX();

    std::cout << "\tFXManager: " << nome << "=" << fullpath << std::endl;
    if ((status->isActive())&&(som->loadFromFile(fullpath))){
        objetomap[nome]=som;
    } else {
        delete(som);
    }
}
//Remove um efeito sonoro do gerenciador
void FXManager::remove(std::string nome)
{
    if (objetomap[nome]){
        delete(objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
//Pausa o efeito sonoro
void FXManager::pause()
{
    if (status->isActive()){
        Mix_Pause(-1);
    }
}
//Continuar a tocar o efeito sonoro
void FXManager::resume()
{
    if (status->isActive()){
        Mix_Resume(-1);
    }
}
//Toca um efeito sonoro de acordo com as coordenadas
void FXManager::playPanEffect(std::string nome, int left, int right)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        Mix_SetPanning(objetomap[nome]->play(),left,right-left);
    }
}
//Toca um efeito sonoro detectando em qual caixa est� mais pr�ximo
void FXManager::playPanEffect(std::string nome, int posicao)
{
    int E,D,c;
    E=D=0;

    c=(100*posicao)/(area_right-area_left);

    if (c<35){
        E=255; D=0;
    } else if ((c>=35)&&(c<=65)){
        E=128; D=128;
    } else {
        E=0;   D=255;
    }

    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        Mix_SetPanning(objetomap[nome]->play(),E,D);
    }
}
//Determina a �rea para calculo de efeito sonoro
void FXManager::setLimite(int left, int right)
{
    area_left=left;
    area_right=right;
}
//Configura o volume do efeito sonoro
//Obs.: Valor do volume de 0 ate 128
void FXManager::setVolume(std::string nome, int volume)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        //Mix_Pause(objetomap[NOME]->play());
        objetomap[nome]->setVolume(volume);
    }
}
//Construtor
FXManager::FXManager()
{
    std::cout << "GBF::Kernel::Sound::FXManager" << std::endl;
}

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
