// chaconefix/zoo.h — gate fixture for the CHA-lite cone memo (test/chaconecheck.sh).
//
// The same hierarchy shape as chafix/cha.cpp, kept in ONE header so every candidate for `speak` sits in
// the SAME directory as every caller (tier 2 of the ladder) and the tier reaches CHA-lite still ambiguous:
//   Animal — a base with a bodied speak(); Dog and Cat implement it WITHOUT overriding speak();
//   Robot  — UNRELATED, its own speak();  Lamp — a class with NO inheritance facts and NO speak().
struct Animal
{
    void         speak();        // declared here, defined out-of-line below (a real, bodied def)
    virtual void move();         // an unrelated virtual so Animal is a genuine polymorphic base
    int          tag = 0;
};

struct Dog : Animal              // implementor 1 — does NOT define speak (inherits Animal::speak)
{
    void move() override { tag = 1; }
};

struct Cat : Animal              // implementor 2 — a DIFFERENT cone on the same callee name
{
    void move() override { tag = 2; }
};

struct Robot                     // UNRELATED — outside every Animal cone
{
    void speak() { power = 1; }
    int  power = 0;
};

struct Lamp                      // no bases, no derived classes, no speak(): its cone is {Lamp} alone
{
    int watts = 0;
};

inline void Animal::speak() { tag = 3; }
inline void Animal::move()  { tag = 4; }
