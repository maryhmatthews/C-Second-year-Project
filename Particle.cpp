//
// Created by ap15014 on 13/03/2017.
//
#include "Particle.h"
#include "Vector.h"
#include <cmath>
#include <cfloat>
void Particle::move(double t)
{
    Vector  delta=getVelocity();

    delta.scale(t);
    p+=delta;
}
double Particle::timeToCollision(const Particle &particle) const
{
    Vector r0=particle.getPosition()-p;
    Vector v=particle.getVelocity()-v1;

    double value_of_v=v.Vector::mod(v);

    if(value_of_v<0.000001)

        return  FLT_MAX;

    double tca=((-1)*(r0.Vector::dot(v)))/(v.Vector::modSqr(v));

    if(tca<0)return FLT_MAX;

    Vector s=v;
    s.scale(tca);

    double b_squared=r0.Vector::dot(r0)-s.Vector::dot(s);

    if(b_squared>(4*r*r)) return FLT_MAX;

    double d=sqrt((4*r*r)-(b_squared));
    double delta_t= d/(v.Vector::mod(v));
    double tcol=tca-delta_t;

    if(tcol>0)  return tcol;

    return FLT_MAX;
}
void Particle::collideParticles(Particle &particle)
{
    double time= timeToCollision(particle);


    if(time<0||(abs(time-FLT_MAX)<0.000001)) return;

    move(time);
    particle.move(time);

    Vector r1=getPosition();
    Vector r2=particle.getPosition();
    Vector n1=r2-r1;
    Vector n=n1.unit();
    Vector v1=n; Vector v2=n;
    Vector vel_of_p = getVelocity();

    double dot_product1= vel_of_p.dot(n);
    v1.scale(dot_product1);

    Vector vel_of_particle = particle.getVelocity();

    double dot_product2= vel_of_particle.dot(n);

    v2.scale(dot_product2);

    Vector deltaV= v2-v1;

    vel_of_p+=deltaV;
    vel_of_particle-=deltaV;

    setVelocity(vel_of_p.Vector::getx(),
                vel_of_p.Vector::gety(),
                vel_of_p.Vector::getz());

    particle.setVelocity(vel_of_particle.Vector::getx(),
                         vel_of_particle.Vector::gety(),
                         vel_of_particle.Vector::getz());
}