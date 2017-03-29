//
// Created by ap15015 on 28/02/2017.
//
#include <iostream>
#include "functions.h"
#include <cmath>
#include "Vector.h"
#include "Particle.h"
#include <cfloat>

bool testfloat (double value, double test, double p){

    double diff = value - test;
    if (abs(diff) < p){
        return 1;
    }
    else {return 0;}
} /*function to test if two passed values namely 'value' and 'test' are (almost) equal i.e. the difference
 is less than the value of 'p': if it is less, it return 1, else returns 0 */
bool test1(){

    Vector object;
    Vector object2;

    object2.setx(10.0);
    object2.sety(20.0);
    object2.setz(30.0);

    bool b1=testfloat(object.getx(),0, 0.0001);
    bool b2=testfloat(object.gety(),0, 0.0001);
    bool b3=testfloat(object.getz(),0, 0.0001);
    bool b4=testfloat(object2.getx(),10.0, 0.0001);
    bool b5=testfloat(object2.gety(),20.0, 0.0001);
    bool b6=testfloat(object2.getz(),30.0, 0.0001);
    if(b1&&b2&&b3&&b4&&b5&&b6) {return 1;}

    return 0;
}/*function to test if the Vector object are storing the coordinate values as required and in case no
   values are given, is initializing them to 0: if all the conditions work, returns 1 else returns 0   */
bool testModulus (){

    Vector object1;

    object1.setx(1.);
    object1.sety(2.);
    object1.setz(3.);

    double x =object1.modSqr(object1);
    double y =object1.mod(object1);
    bool b1=testfloat(x,14, 0.0001);
    bool b2=testfloat(y, sqrt(14), 0.0001);

    if (b1&&b2) return 1;

    return 0;
}/*function to test if the functions modSqr and mod work : if all the conditions work, returns 1 else returns 0  */
bool testDistance()
{
    Vector v1, v2;

    v1.setx(1.);
    v1.sety(2.);
    v1.setz(3.);
    v2.setx(3.);
    v2.sety(2.);
    v2.setz(1.);

    double d=v1.distance(v2);
    bool b1=testfloat(d,sqrt(8), 0.0001);

    return b1;
} /*function to test if the function Distance works : if all the conditions work, returns 1 else returns 0  */
bool testDot()
{
    Vector v1, v2;

    v1.setx(1.);
    v1.sety(0.);
    v1.setz(1.);
    v2.setx(0.);
    v2.sety(1.);
    v2.setz(0.);

    double d=v1.dot(v2);
    bool b1=testfloat(d,0, 0.0001);

    return b1;
}
bool testscale()
{
    Vector v;

    v.setx(1); v.sety(1); v.setz(1);
    v.scale(3);

    bool b1=testfloat(v.getx(),3, 0.001 );
    bool b2=testfloat(v.gety(),3, 0.001 );
    bool b3=testfloat(v.getz(),3,0.001 );

    if(b1&&b2&&b3) {return 1;}

    return 0;
}
bool testUnit ()
{
    Vector v1, v2;

    v1.setx(3); v1.sety(3); v1.setz(3);
    v2=v1.unit();

    double x=v2.mod(v2);
    bool b1=testfloat(x, 1, 0.001);

    if(b1) {return 1;}

    return 0;
}
bool testCross ()
{
    Vector v1, v2, v3, v4, v5, v6;

    v1.setx(1); v1.sety(0); v1.setz(0);
    v2.setx(0); v2.sety(1); v2.setz(0);
    v3.setx(0); v3.sety(0); v3.setz(1);
    v4 = v1.cross(v2);
    v5 = v2.cross(v3);
    v6 = v3.cross(v1);

    double d1=v4.distance(v3);
    double d2=v5.distance(v1);
    double d3=v6.distance(v2);
    bool b1 = testfloat(d1, 0, 0.0001);
    bool b2 = testfloat(d2, 0, 0.0001);
    bool b3 = testfloat(d3, 0, 0.0001);

    if(b1&&b2&&b3) {return 1; }

    return 0;
}
bool testOperators()
{
    Vector v1, v2, v3, v4, v5, v6;

    v1.setx(1); v1.sety(2); v1.setz(3);
    v2.setx(2); v2.sety(4); v2.setz(6);
    v3=v1.operator+(v1);

    double d1=v2.distance(v3);
    bool b1=testfloat(d1,0, 0.001 );

    v4=v2.operator-(v1);

    double d2=v4.distance(v1);
    bool b2=testfloat(d2,0, 0.001 );

    v5 = v1.operator-();
    v6.setx(-1);
    v6.sety(-2);
    v6.setz(-3);

    double d3=v5.distance(v6);
    bool b3=testfloat(d3,0,0.0001);

    if(b1&&b2&&b3) return 1; return 0;
}
bool testParticle()
{
    Vector v,p;

    Particle particle1; //particles with position(0,0,0)and velocity (0,0,0).
    Particle newparticle(1,  v, p);//particles with position (4,5,6) and velocity (1,2,3).

    newparticle.setPosition(4,5,6);
    newparticle.setVelocity(1,2,3);

    Vector c=newparticle.getVelocity();
    Vector d=newparticle.getPosition();
    Vector a,b, a1, c1, a2, c2;

    a1.setx(0); a1.sety(0);a1.setz(0);
    c1.setx(0); c1.sety(0);c1.setz(0);
    a2=particle1.getPosition();
    c2=particle1.getVelocity();

    a.setx(1);
    a.sety(2);
    a.setz(3);
    b.setx(4);
    b.sety(5);
    b.setz(6);

    double x=a.distance(c);
    double y=b.distance(d);
    double y1=a1.distance(a2);
    double y2=c1.distance(c2);

    bool bl=testfloat(x,0,0.0001);
    bool b2=testfloat(y,0,0.0001);
    bool b3=testfloat(y1,0,0.0001);
    bool b4=testfloat(y2,0,0.0001);

    if(bl&&b2&&b3&&b4) return 1;

    return 0;
}
bool testMove() {

    Particle particle2; //particle2 with position (0,0,0) and velocity (0,0,0)
    particle2.setPosition(0, 0, 0);
    particle2.setVelocity(1, 1, 1);
    particle2.move(1);

    Vector b;

    b = particle2.getPosition();

    Vector a;

    a.setx(1.0);a.sety(1.0);a.setz(1.0);

    double c = a.distance(b);
    bool a1 = testfloat(c, 0, 0.0001);

    if (a1) return 1;

    return 0;
}
bool testcollision()
{
    Particle p1, p2;

    p1.setPosition(0,0,0);
    p1.setVelocity(1,0,0);
    p2.setPosition(12,0,0);
    p2.setVelocity(-1,0,0);

    double t1=p1.timeToCollision(p2);
    bool Test1=testfloat(t1, 5,0.0001);

    Particle p3, p4;

    p3.setPosition(0,0,0);
    p3.setVelocity(1,1,0);
    p4.setPosition(5,5,6.99999);
    p4.setVelocity(0,0,-1);

    double t2=p3.timeToCollision(p4);
    bool Test2=testfloat(t2, 5,0.0001);

    Particle p5, p6;

    p5.setPosition(0,3,0);
    p5.setVelocity(1,0,0);
    p6.setPosition(12,0,0);
    p6.setVelocity(-1,0,-1);

    double t3=p5.timeToCollision(p6);
    bool Test3=testfloat(t3, FLT_MAX,0.0001);

    if(Test1&&Test2&&Test3) return 1;

    return 0;
}
bool testcollision2()
{
    Particle p1, p2, p3, p4;
    Vector v1, v2, v3, v4,v5,v6;

    p1.setPosition(0.,0.,0.);
    p1.setVelocity (1.,0.,0.);
    p2.setPosition(5.,0.,0.);
    p2.setVelocity (0.,0.,0.);
    p1.collideParticles(p2);

    v1 = p1.getVelocity();
    v2 = p2.getVelocity();
    v3.setx(0.);v3.sety (0.);v3.setz(0.);
    v4.setx(1.); v4.sety(0.); v4.setz(0.);

    double d1=v1.distance(v3);
    double d2=v2.distance(v4);

    p3.setPosition(-0.,-0.,-0.);
    p3.setVelocity (1.,0.,0.);
    p4.setPosition (10.,0.,0.);
    p4.setVelocity(-0.5,0.,0.);
    p3.collideParticles(p4);

    v5 = p3.getVelocity();
    v6 = p4.getVelocity();

    double x1 = v5.getx();
    double x2 = v6.getx();

    bool b1 = testfloat(d1, 0., 0.0001);
    bool b2 = testfloat(d2, 0., 0.0001);
    bool b3 = testfloat(x1, -0.5, 0.0001);
    bool b4 = testfloat(x2, 1., 0.0001);

    if(b1&&b2&&b3&&b4) {return 1; }

    return 0;
}