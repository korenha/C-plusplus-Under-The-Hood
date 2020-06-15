#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__
#define NUM_BOXES 3
#define DEF_MSG "The total volume held on the shelf is"
extern const char* _ZN5Shelf7messageE;
typedef enum {
    false,
    true
}bool;

typedef struct {
    double length;
    double width;
    double height;
}Box;


void _ZN3BoxC1Ev(Box* this);
void _ZN3BoxC1Ed(Box* this, double dim);
void _ZN3BoxC1Eddd(Box* this, double l, double w, double h);
void _ZNK3Box5printEv(const Box* this);
Box _ZN3BoxmLEd(Box* this, double multi);
void _ZN3BoxD1Ev(const Box* this);

typedef struct
{
    Box boxes[NUM_BOXES];
}Shelf;

void _ZN5Shelf6setBoxEiRK3Box(Shelf* this, int index, const Box* const dims);
double getVolume(const Shelf* this);
void printShelf(const Shelf* this);

#endif

