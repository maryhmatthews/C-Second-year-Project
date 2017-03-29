//
// Created by ap15014 on 13/03/2017.
//
#ifndef EX3_3_PARTICLE_H
#define EX3_3_PARTICLE_H
#include "Vector.h"

class Particle
{
    Vector p, v1;
    double r;

public:
    Particle(double r=1,  const Vector &v1 = Vector(),  const Vector &p= Vector()): r(r), p(p), v1(v1)
    {;}
    void  setPosition(double px, double py, double pz)
    {
        p.setx(px);
        p.sety(py);
        p.setz(pz);
    };
    void setVelocity(double vx, double vy, double vz)
    {
        v1.setx(vx);
        v1.sety(vy);
        v1.setz(vz);
    };
    Vector getPosition() const
    { //Vector P;
        // P.setx(p.getx());
        // P.sety(p.gety());
        // P.setz(p.getz());
        return p;
    }
    Vector getVelocity() const
    { //Vector V;
        //V.setx(v1.getx());
        // V.sety(v1.gety());
        //V.setz(v1.getz());
        return v1;
    }
    double const getRadius()

    {return r;}

    void move (double t);
    double timeToCollision(const Particle &particle) const;
    void collideParticles(Particle &particle);
    // void collideParticles(Particle &particle);
};
#endif //EX3_3_PARTICLE_H