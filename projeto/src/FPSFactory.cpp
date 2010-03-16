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

#include "FPSFactory.h"


namespace GBF
{

namespace Kernel {

namespace FPS {

FPS * FPSFactory::create(FPSType  type)
{
    FPS * fps = NULL;

    switch (type) {

        case FPS_COUNTER:
            fps = new FPSCounter();
            break;

        default:
            fps = new FPSFixRate(type);
    }

    return fps;
}

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
