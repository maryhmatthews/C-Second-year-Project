//
// Created by ap15014 on 16/03/2017.
//
#include "Box.h"
#include <cfloat>
#include <cstdlib>
#include <fstream>
using namespace std;
void Box::addParticle(const Particle &particle) {
    particles.push_back(particle);
}
double Box::timeToWallCollision(int wall, const Particle &particle) {

    double s = size / 2;
    double tx, ty, tz;

    Vector v1 = particle.Particle::getVelocity();
    Vector r1 = particle.Particle::getPosition();

    double vx = v1.getx();
    double vy = v1.gety();
    double vz = v1.getz();
    double rx = r1.getx();
    double ry = r1.gety();
    double rz = r1.getz();

    if (wall == 1) {
        if (vx > 0) {
            tx = (s - rx) / vx;
        }
        else if (vx < 0) {
            tx = ((-s) - (rx)) / vx;
        }
        else if (vx == 0) {
            tx = FLT_MAX;
        }
        return tx;
    }

    else if (wall == 2) {
        if (vy > 0) {
            ty = (s - ry) / vy;
        }
        else if (vy < 0) {
            ty = (-s - ry) / vy;
        }
        else if (vy == 0) {
            ty = FLT_MAX;
        }
        return ty;
    }

    else if (wall == 3) {
        if (vz > 0) {
            tz = (s - rz) / vz;
        }
        else if (vz < 0) {
            tz = (-s - rz) / vz;
        }
        else if (vz == 0) {
            tz = FLT_MAX;
        }
        return tz;
    }
}
void Box::doWallCollision(int wall, Particle &particle) {

    double t;

    Vector position = particle.Particle::getPosition();
    Vector velocity = particle.Particle::getVelocity();

    if (wall == 1) {

        t = timeToWallCollision(1, particle);
        particle.setVelocity(-velocity.getx(), velocity.gety(), velocity.getz());
    }
    else if (wall == 2) {
        t = timeToWallCollision(2, particle);
        particle.setVelocity(velocity.getx(), -velocity.gety(), velocity.getz());
    }
    else if (wall == 3) {
        t = timeToWallCollision(3, particle);
        particle.setVelocity(velocity.getx(), velocity.gety(), -velocity.getz());
    }
    particle.Particle::move(t);
    //particle.setPosition(position.getx(), position.gety(), position.getz());
}
double Box::Step() {

    double timeToNextCollision = FLT_MAX;
    int collisionType = 0;
    int collisionWall;
    int collider1 = -1;
    int collider2 = -2;
    double smallestTime;

    for (int i = 0; i < particles.size(); i++) {

        double tx = timeToWallCollision(1, particles[i]);
        double ty = timeToWallCollision(2, particles[i]);
        double tz = timeToWallCollision(3, particles[i]);

        if (tx < ty && tx < tz) {
            smallestTime = tx;
            collisionWall = 1;
        }
        else if (ty < tx && ty < tz) {
            smallestTime = ty;
            collisionWall = 2;
        }
        else if (tz < tx && tz < ty) {
            smallestTime = tz;
            collisionWall = 3;
        }
        if (smallestTime < timeToNextCollision) {
            timeToNextCollision = smallestTime;
            collider1 = i;
            collisionType = collisionWall;
        }
        // if (tx < 0 || ty < 0 || tz < 0) {
        // std::cout << i << " " << tx << " " << ty << " " << tz << " : " << particles[i].getPosition().getx() << " " << particles[i].getPosition().gety() << " " << particles[i].getPosition().getz() << std::endl;
        // }
    }
    for (int i = 0; i < (particles.size()); i++)
    {
        for (int j = i + 1; j < (particles.size()); j++)
        {
            double TimeToParticleCollision = particles[i].Particle::timeToCollision(particles[j]);
            if (TimeToParticleCollision < 0) std::cout << i << " " << j << " " << TimeToParticleCollision << std::endl;
            if (TimeToParticleCollision < timeToNextCollision)
            {
                timeToNextCollision = TimeToParticleCollision;
                collisionType = 0;
                collider1 = i;
                collider2 = j;
            }
        }
    }
    if (collisionType == 0) {
        particles[collider1].collideParticles(particles[collider2]);
    }
    else {
        doWallCollision(collisionType, particles[collider1]);
    }
    for (int i = 0; i < particles.size(); i++) {
        if (i == collider1 || i == collider2) continue;
        else move(timeToNextCollision);
    }
    return timeToNextCollision;
}
vector<int> Box::nParticlesOctant() const {

    vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < (particles.size()); i++) {

        Vector position = particles[i].getPosition();
        double x = position.getx();
        double y = position.gety();
        double z = position.getz();

        if (x > 0 && y > 0 && z > 0) { vec[0]++; }
        else if (x > 0 && y > 0 && z < 0) { vec[1]++; }
        else if (x > 0 && y < 0 && z > 0) { vec[2]++; }
        else if (x > 0 && y < 0 && z < 0) { vec[3]++; }
        else if (x < 0 && y > 0 && z > 0) { vec[4]++; }
        else if (x < 0 && y > 0 && z < 0) { vec[5]++; }
        else if (x < 0 && y < 0 && z > 0) { vec[6]++; }
        else if (x < 0 && y < 0 && z < 0) { vec[7]++; }
    }
    return vec;
}
