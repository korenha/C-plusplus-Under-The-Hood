#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
const char* _ZN5Shelf7messageE = DEF_MSG;


void _ZN3BoxC1Ev(Box* this)
{
    this->width = 1;
    this->length = 1;
    this->height = 1;
    _ZNK3Box5printEv(this);
}

void _ZN3BoxC1Ed(Box* this, double dim)
{
    this->width = dim;
    this->length = dim;
    this->height = dim;
    _ZNK3Box5printEv(this);
}

void _ZN3BoxC1Eddd(Box* this, double l, double w, double h)
{
    this->width = w;
    this->length = l;
    this->height = h;
    _ZNK3Box5printEv(this);
}

void _ZN3BoxD1Ev(const Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

Box _ZN3BoxmLEd(Box* this, double multi)
{
    this->width*=multi;
    this->height*=multi;
    this->length*=multi;
    return *this;
}

void _ZNK3Box5printEv(const Box *this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}


/*/// Shelf ///////////*/


void _ZN5Shelf6setBoxEiRK3Box(Shelf* this, int index, const Box *dims)
{
    this->boxes[index] = *dims;
}

double getVolume(const Shelf* const this)
{
    size_t i;
    double vol = 0;
    for (i = 0; i < NUM_BOXES; ++i) {
        vol += this->boxes[i].width * this->boxes[i].length * this->boxes[i].height;
    }

    return vol;
}

void printShelf(const Shelf* const this)
{
    printf("%s %f\n", _ZN5Shelf7messageE, getVolume(this));
}



