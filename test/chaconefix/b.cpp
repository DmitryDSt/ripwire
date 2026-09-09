// chaconefix/b.cpp — the SECOND file to ask for the Dog cone (a memo HIT must equal the first answer),
// plus a different cone on the same callee name, a receiver with no inheritance facts, and a control.
#include "zoo.h"

void g2() { Dog d; d.speak(); }        // memo hit: byte-identical to g1's answer (Animal::speak only)
void g3() { Cat c; c.speak(); }        // a DIFFERENT cone {Cat, Animal} keyed on the same callee `speak`
void g4() { Lamp l; l.speak(); }       // cone {Lamp} keeps nothing → DEGRADE: tier untouched, stays ambiguous
void g5( Dog& p ) { p.speak(); }       // control: parameter receiver → no var→type binding → cone cannot fire
