//
// Created by ap15014 on 16/03/2017.
//
#ifndef EX3_3_BOX_H
#define EX3_3_BOX_H
#include "Particle.h"
#include "Vector.h"
#include <vector>
#include <fstream>

using namespace std;

class Box {

    double size;
    vector <Particle> particles ;

public :

    Box (double size = 500): size(size){;}
    void addParticle (const Particle &particle);
    double timeToWallCollision (int wall, const Particle & particle);
    void doWallCollision (int wall, Particle & particle);
    double Step();
    double timeToNextCollision();
    vector <int> nParticlesOctant() const;
};
#endif //EX3_3_BOX_H