//
// Created by ap15015 on 28/02/2017.
//
#include "Vector.h"
#include <cmath>

double   Vector::modSqr (Vector &v) const
{
    double V = (v.getx()*v.getx()) + (v.gety()*v.gety()) + (v.getz()*v.getz());

    return V;
}//function to calculate the Modulus Squared of a vector using |v|^2=x^2+y^2+z^2

double  Vector:: mod (Vector &v)const
{
    double U = modSqr(v);
    double u = abs(sqrt(U));

    return u;
}//function to return the Modulus of vector i.e. |v|

double  Vector::  dot ( Vector &v) const
{
    double W = (v.getx()*x + v.gety()*y + v.getz()*z);

    return W;
}//function to calculate the Dot Product of two vectors (v and u) which is =(v(x).u(x))+(v(y).u(y))+(v(z).u(z))

double  Vector:: distance ( Vector &v) const
{
    Vector D;

    D.setx((v.getx()- x)); D.sety((v.gety()-y)); D.setz((v.getz()-z));

    double d=mod(D);
    return d;
}/*function to calculate the Distance between two vectors (u and v) which is
     =sqrt[((v(x)-u(x))^2)+((v(y)-u(y))^2)+((v(z)-u(z))^2)] */
void Vector::scale(double f)
{
    setx(getx()*f);
    sety(gety()*f);
    setz(getz()*f);
}

Vector Vector::unit ()
{
    Vector v;

    v.setx(x);
    v.sety(y);
    v.setz(z);

    double m=(1/(v.mod(v)));

    v.scale(m);
    return v;
}

Vector Vector::cross ( Vector &v )
{
    double wx= (gety()*(v.getz()))-(getz()*(v.gety()));
    double wy= (getz()*(v.getx()))-(getx()*(v.getz()));
    double wz= (getx()*(v.gety()))-(gety()*(v.getx()));

    Vector v1;

    v1.setx(wx);
    v1.sety(wy);
    v1.setz(wz);
    return v1;
}