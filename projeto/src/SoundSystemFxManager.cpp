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

#include "SoundSystemFxManager.h"

//Destrutor
SoundSystemFxManager::~SoundSystemFxManager() 
{
    UtilLog::subSistema("Removendo SoundSystemFxManager");
    Mix_HaltChannel(-1);
    std::map<std::string,SoundSystemFx*>::iterator it;

    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
            UtilLog::tracer("SoundFx=%s",((*it).first).c_str());
        } catch(...){
            UtilLog::tracer("SoundFx=Desconhecido(a)");
        }
        delete ((*it).second);
        (*it).second=NULL;
        UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
//Toca uma efeito sonoro
void SoundSystemFxManager::play(std::string nome) 
{

    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->play();
    }
}
//Carregar um arquivo de efeito sonoro para o gerenciador
void SoundSystemFxManager::carregar(std::string nome, std::string arquivo) 
{
    SoundSystemFx *som = new SoundSystemFx();

    std::string fullPath=pathBase+arquivo;

    UtilLog::tracer("SoundFxManager::carregar(%s)",nome.c_str());
    if ((status->isAtivo())&&(som->carregarArquivo(fullPath))){
        objetomap[nome]=som;
        UtilLog::comentario("[Ok]");
    } else {
        UtilLog::comentario("[Falhou]");
        delete(som);
    }
}
//Remove um efeito sonoro do gerenciador
void SoundSystemFxManager::apagar(std::string nome) 
{
    if (objetomap[nome]){
        delete(objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
//Pausa o efeito sonoro
void SoundSystemFxManager::pause() 
{
    if (status->isAtivo()){
        Mix_Pause(-1);
    }
}
//Continuar a tocar o efeito sonoro
void SoundSystemFxManager::resume() 
{
    if (status->isAtivo()){
        Mix_Resume(-1);
    }
}
//Toca um efeito sonoro de acordo com as coordenadas
void SoundSystemFxManager::playPanEffect(std::string nome, int left, int right) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        Mix_SetPanning(objetomap[nome]->play(),left,right-left);
    }
}
//Toca um efeito sonoro detectando em qual caixa est� mais pr�ximo
void SoundSystemFxManager::playPanEffect(std::string nome, int posicao) 
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
void SoundSystemFxManager::setLimite(int left, int right) 
{
    area_left=left;
    area_right=right;
}
//Configura o volume do efeito sonoro
//Obs.: Valor do volume de 0 ate 128
void SoundSystemFxManager::setVolume(std::string nome, int volume) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        //Mix_Pause(objetomap[NOME]->play());
        objetomap[nome]->setVolume(volume);
    }
}
//Construtor
SoundSystemFxManager::SoundSystemFxManager(SoundSystemStatus * status):SoundSystemInterfaceManager(status){
    UtilLog::subSistema("Instanciando SoundSystemFxManager");
}
