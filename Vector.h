//
// Created by ap15015 on 28/02/2017.
//
#include <iostream>
#ifndef SEC1PARTA_CLASS_H
#define SEC1PARTA_CLASS_H

using namespace std;

class Vector {

private:
    double x, y ,z; //three private data members representing Cartesian Coordinates of a 3-D Vector

public:
    void  setx (double x1) {x=x1;} //function to set value of x coordinate
    double getx () const {return x;}; //constant function to get value of x coordinate
    void  sety (double y1) {y=y1;} //function to set value of y coordinate
    double   gety () const {return y;}; //constant function to get value of y coordinate
    void  setz (double z1)  {z=z1;} //function to set value of z coordinate
    double   getz () const {return z;}; //constant function to get value of z coordinate

    Vector (double x=0, double y=0, double z=0): x(x),y(y), z(z) {;}
    /*constructor initializing the values of the coordinates and in the event no values are
     passed, they are initialized to 0 */
    double  modSqr (Vector &v) const; //Declaration for modSqr
    double  mod  (Vector &v) const ;
    double  dot  (Vector &vec) const ;
    double  distance  ( Vector &vec) const ;
    void scale (double f);

    Vector unit ();
    Vector cross ( Vector &v );
    Vector & operator+= (const Vector & v){

        x+=v.x;
        y+=v.y;
        z+=v.z;
        return *this;
    };

    Vector operator+ (const Vector &v)
    {
        Vector v2(*this);
        return v2+=v;
    };
    Vector & operator-= (const Vector & v){

        x-=v.x;
        y-=v.y;
        z-=v.z;

        return *this;
    };
    Vector operator- (const Vector &v)
    {
        Vector v2(*this);
        return v2-=v;
    };
    Vector operator- () const
    {
        Vector v;

        v.x=(-x);
        v.y=(-y);
        v.z=(-z);
        return v;
    };
    Vector display()
    {
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
};
#endif //SEC1PARTA_CLASS_H