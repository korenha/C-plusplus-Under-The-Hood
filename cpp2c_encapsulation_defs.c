#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
const char* _ZN5Shelf7messageE = DEF_MSG;


void _ZN3BoxC1Ev(Box* this)
{
    this->_width = 1;
    this->_length = 1;
    this->_height = 1;
    _ZNK3Box5printEv(this);
}

void _ZN3BoxC1Ed(Box* this, double dim)
{
    this->_width = dim;
    this->_length = dim;
    this->_height = dim;
    _ZNK3Box5printEv(this);
}

void _ZN3BoxC1Eddd(Box* this, double l, double w, double h)
{
    this->_width = w;
    this->_length = l;
    this->_height = h;
    _ZNK3Box5printEv(this);
}

void _ZN3BoxD1Ev(const Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this->_width, this->_height, this->_length);
}

Box _ZN3BoxmLEd(Box* this, double multi)
{
    this->_width*=multi;
    this->_height*=multi;
    this->_length*=multi;
    return *this;
}

void _ZNK3Box5printEv(const Box *this)
{
    printf("Box: %f x %f x %f\n", this->_length, this->_width, this->_height);
}


/*/// Shelf ///////////*/


void _ZN5Shelf6setBoxEiRK3Box(Shelf* this, int index, const Box *dims)
{
    this->boxes[index] = *dims;
}

double _ZNK5Shelf9getVolumeEv(const Shelf *this)
{
    size_t i;
    double vol = 0;
    for (i = 0; i < NUM_BOXES; ++i) {
        vol += this->boxes[i]._width * this->boxes[i]._length * this->boxes[i]._height;
    }

    return vol;
}

void _ZNK5Shelf5printEv(const Shelf *this)
{
    printf("%s %f\n", _ZN5Shelf7messageE, _ZNK5Shelf9getVolumeEv(this));
}


void _ZN5ShelfD1Ev(Shelf* this)
{
    _ZN3BoxD1Ev(&this->boxes[2]);
    _ZN3BoxD1Ev(&this->boxes[1]);
    _ZN3BoxD1Ev(&this->boxes[0]);
}
