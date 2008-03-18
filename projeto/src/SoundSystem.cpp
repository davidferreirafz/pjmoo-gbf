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

#include "SoundSystem.h"

//Destrutor
SoundSystem::~SoundSystem() 
{
    if (musicManager){
        delete(musicManager);
    }
    if (fxManager){
        delete(fxManager);
    }
}
//Retorna uma inst�ncia de SoundSystem
SoundSystem * SoundSystem::getInstance()
{
    if (instance == NULL){
        instance = new SoundSystem();
    }

    return instance;
}
SoundSystem::SoundSystem() 
{
    musicManager = new SoundSystemMusicManager();
    fxManager    = new SoundSystemFxManager();
}
SoundSystem * SoundSystem::instance;
