// chaconefix/a.cpp — the FIRST call whose receiver static type is Dog: the Dog cone is computed here.
#include "zoo.h"

void g1() { Dog d; d.speak(); }   // cone {Dog, Animal} → Animal::speak only; Robot::speak dropped
