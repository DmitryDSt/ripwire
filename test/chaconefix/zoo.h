// chaconefix/zoo.h — gate fixture for the CHA-lite cone memo (test/chaconecheck.sh).
//
// The same hierarchy shape as chafix/cha.cpp under UNIQUE names (recallevalcheck pins --for=Robot to chafix), in ONE header so every candidate for `vocalize` sits in
// the SAME directory as every caller (tier 2 of the ladder) and the tier reaches CHA-lite still ambiguous:
//   Creature — a base with a bodied vocalize(); Hound and Lynx implement it WITHOUT overriding vocalize();
//   Automaton  — UNRELATED, its own vocalize();  Lamp — a class with NO inheritance facts and NO vocalize().
struct Creature
{
    void         vocalize();        // declared here, defined out-of-line below (a real, bodied def)
    virtual void move();         // an unrelated virtual so Creature is a genuine polymorphic base
    int          tag = 0;
};

struct Hound : Creature              // implementor 1 — does NOT define vocalize (inherits Creature::vocalize)
{
    void move() override { tag = 1; }
};

struct Lynx : Creature              // implementor 2 — a DIFFERENT cone on the same callee name
{
    void move() override { tag = 2; }
};

struct Automaton                     // UNRELATED — outside every Creature cone
{
    void vocalize() { power = 1; }
    int  power = 0;
};

struct Lamp                      // no bases, no derived classes, no vocalize(): its cone is {Lamp} alone
{
    int watts = 0;
};

inline void Creature::vocalize() { tag = 3; }
inline void Creature::move()  { tag = 4; }
