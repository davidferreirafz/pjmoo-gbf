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

#ifndef _GTMAQUINAESTADO_H
#define _GTMAQUINAESTADO_H

#include "TimerRegressive.h"

namespace GAT {

class GTMaquinaEstado
{

    private:
        static GBF::Kernel::Timer::TimerRegressive tempoEspera;


    public:
        //Construtor
        GTMaquinaEstado();

        //Destrutor
        virtual ~GTMaquinaEstado();


    protected:
        static bool isTempoEspera();

        static void reiniciarTempo();

        static void executarTempo();


};

} // namespace GAT

#endif
