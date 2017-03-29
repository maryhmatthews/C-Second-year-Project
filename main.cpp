#include "Vector.h"
#include <iostream>
#include "functions.h"
#include "Box.h"
#include <cstdlib>
#include "random.h"
#include "Particle.h"

using namespace std;

int main() {

    bool t1=test1(); //function test1() called and prints a success message if test is successful
    if(t1) cout<< "Test 1 SUCCESS"<<endl;
    else cout<< "Test 1 FAILED "<<endl;

    bool b1= testModulus();
    if (b1) cout<<"Test Modulus:SUCCESS "<<endl;
    else cout<< "Test Modulus: FAILED "<<endl;

    bool b2= testDistance();
    if(b2) cout<<"Test Distance:SUCCESS "<<endl;
    else cout<<"Test Distance:FAILED"<<endl;

    bool b3= testDot();
    if(b3) cout<<"Test Dot:SUCCESS "<<endl;
    else cout<<"Test Dot:FAILED"<<endl;

    bool b4= testscale();
    if(b4) cout<<"Test Scale:SUCCESS "<<endl;
    else cout<<"Test Scale:FAILED"<<endl;

    bool b5= testUnit();
    if(b5) cout<<"Test Unit:SUCCESS "<<endl;
    else cout<<"Test Unit:FAILED"<<endl;

    bool b6= testCross ();
    if(b6) cout<<"Test Cross:SUCCESS "<<endl;
    else cout<<"Test Cross:FAILED"<<endl;

    bool b7= testOperators();
    if (b7) cout<<"Test Operators:SUCCESS"<<endl;
    else cout<<"Test Operators:FAILED"<<endl;

    bool b8=testParticle();
    if(b8)  cout<<"Test Particle:SUCCESS"<<endl;
    else cout<<"Test Particle:FAILED"<<endl;

    bool b9=testMove();
    if(b9) cout<<"Test Move:SUCCESS"<<endl;
    else cout<<"Test move:FAILED"<<endl;

    bool b10=testcollision();
    if(b10) cout<<"Test Collision:SUCCESS" <<endl;
    else cout<<"Test Collision:FAILED"<< endl;

    bool b11 = testcollision2();
    if (b11) cout << "Test Collision 2:SUCCESS" << endl;
    else cout << "Test Collision 2:FAILED" << endl;


    Box Box;

    float time=0;
    ofstream file;
    file.open("G:/Success.dat");

    for (int i = 0; i<1000; i++){

        Particle p1;

        double pxMin= 0; double pyMin = 0; double pzMin=0;
        double pxMax= 249; double pyMax=249; double pzMax=249;
        double px = pxMin + (pxMax-pxMin)*double(rand())/RAND_MAX;
        double py = pyMin + (pyMax-pyMin)*double(rand())/RAND_MAX;
        double pz = pzMin + (pzMax-pzMin)*double(rand())/RAND_MAX;

        p1.Particle::setPosition(px, py, pz);

        double vx = Random::randomNorm(0,10);
        double vy = Random::randomNorm(0,10);
        double vz = Random::randomNorm(0,10);

        p1.Particle::setVelocity(vx, vy, vz);
        Box.Box::addParticle(p1);}
    //   for (int i = 0; i<10000; i++)
    for (int i = 0; i<=10000; i++)
    {
        double presentTime=Box.Step();
        time+=presentTime;

        if (i%100==0)
        {
            cout<<i<<" "<<time<<" ";
            file << i << " " << time << " ";

            vector <int> OctantCount=Box.Box::nParticlesOctant();

            for(int j=0;j<OctantCount.size();j++)
            {
                cout<<OctantCount.at(j)<<" ";
                file<<OctantCount.at(j)<<" " ;
            }
            cout<<endl; file << endl;
        }
    }
    file.close();

    return 0;
}