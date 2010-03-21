/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "Timer.h"

namespace GBF {

namespace Kernel {

namespace Timer {

/** Executa este m�todo quando o estado � CRONOMETRO_EXECUTAR */
void Timer::execute()
{
    tempoAtual = SDL_GetTicks();

    if (tempoAtual - tempoInicial >= tempoUnidade){
        tempoCorrente++;
        initialTick();
    }
}
/** Construtor */
Timer::Timer()
{
}
/** Destrutor */
Timer::~Timer()
{
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
