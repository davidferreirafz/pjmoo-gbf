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

#ifndef _OBJETOBASE_H
#define _OBJETOBASE_H

class ObjetoBase
{
  public:
    ObjetoBase();

    virtual ~ObjetoBase();

    template<class T>
      inline bool isInstance() {
                if (dynamic_cast<T*>(this)){
                    return true;
                } else {
                    return false;
                }
            };

    template<class T>
      inline bool isInstance(T ) {
                if (dynamic_cast<T*>(this)){
                    return true;
                } else {
                    return false;
                }
            };

    template<class T>
      inline bool isInstance(T * t) {
                if (dynamic_cast<T*>(this)){
                    return true;
                } else {
                    return false;
                }
            };

};
#endif
