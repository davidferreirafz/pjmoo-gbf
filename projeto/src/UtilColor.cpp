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

#include "UtilColor.h"

//Transforma de RGB para HSV 
HSV UtilColor::forHSV(RGB cor)
{

    HSV hsv;

    int minVal = menor(menor(cor.r,cor.g),cor.b);
    hsv.v = maior(maior(cor.r,cor.g),cor.b);
    float delta = hsv.v - minVal;

    if (hsv.v==0.0){
        hsv.s = 0.0;
    } else {
        hsv.s = delta/hsv.v;
    }

    if (hsv.s==0.0){
        hsv.h=0.0;
    } else {
        if (cor.r==hsv.v){
            hsv.h=60.0*(cor.g-cor.b)/delta;
        } else {
            if (cor.g==hsv.v){
                hsv.h=120.0+60.0*(cor.b-cor.r)/delta;
            } else {
                hsv.h=240.0+60.0*(cor.r-cor.g)/delta;
            }
        }
    }

    if (hsv.h<0.0){
        hsv.h=hsv.h+360.0;
    }

    hsv.v /= 255.0;

    return hsv;
}

//Transforma de HSV para RGB 
RGB UtilColor::forRGB(HSV cor)
{

    RGBf corRGB;
    float hTemp;

    if (cor.s==0){  //color is on black-and-white center line
        corRGB.r=cor.v; //achromatic: shades of gray
        corRGB.g=cor.v; //supposedly invalid for h=0 but who cares
        corRGB.b=cor.v;
    } else {  // 360 degrees same as 0 degrees
        if (cor.h==360){
            hTemp=0.0;
        } else {
            hTemp=cor.h;
        }

        hTemp=hTemp/60.0;       //-- h is now in [0,6)
        int i=(int) floor(hTemp);
        float f=hTemp-i;        //-- fractional part of h

        float p=cor.v*(1.0-cor.s);
        float q=cor.v*(1.0-(cor.s*f));
        float t=cor.v*(1.0-(cor.s*(1.0-f)));

        switch(i){
            case 0:
                    corRGB.r = cor.v;  corRGB.g = t;       corRGB.b = p;
                break;
            case 1:
                    corRGB.r = q;      corRGB.g = cor.v;   corRGB.b = p;
                break;
            case 2:
                    corRGB.r = p;      corRGB.g = cor.v;   corRGB.b = t;
                break;
            case 3:
                    corRGB.r = p;      corRGB.g = q;       corRGB.b = cor.v;
                break;
            case 4:
                    corRGB.r = t;      corRGB.g = p;       corRGB.b = cor.v;
                break;
            case 5:
                    corRGB.r = cor.v;  corRGB.g = p;       corRGB.b = q;
                break;
        }
    }

    corRGB.r*=255;       corRGB.g*=255;        corRGB.b*=255;

    RGB rgb;
    rgb.r = int(corRGB.r);
    rgb.g = int(corRGB.g);
    rgb.b = int(corRGB.b);

    return rgb;
}

//Retorna o menor valor 
int UtilColor::menor(int valor1, int valor2)
{
    if (valor1 <= valor2){
        return valor1;
    } else {
        return valor2;
    }
}

//Retorna o maior valor 
int UtilColor::maior(int valor1, int valor2)
{
    if (valor1 >= valor2){
        return valor1;
    } else {
        return valor2;
    }
}

