#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__
extern const char* _ZN5Shelf7messageE;
typedef enum {
    false,
    true
}bool;

typedef struct {
    double _length;
    double _width;
    double _height;
}Box;


void _ZN3BoxC1Esv(Box* this);
void _ZN3BoxC1Esd(Box* this, double dim);
void _ZN3BoxC1Esddd(Box* this, double l, double w, double h);
void _ZNK3Box5printEsv(const Box* const this);
Box _ZN3BoxmLEsd(Box* this, double multi);
const Box* const _ZN3BoxC1EsRKS(Box* this, const Box* const other);
const Box* const _ZN3BoxaSEsRKS3Box(Box* this, const Box* const other);

void _ZN3BoxD1Esv(const Box* this);

typedef struct
{
    Box boxes[3];
}Shelf;

void _ZN5Shelf6setBoxEiRK3Box(Shelf* this, int index, const Box* const dims);
double _ZNK5Shelf9getVolumeEv(const Shelf* this);
void _ZNK5Shelf5printEv(const Shelf* this);
void _ZN5ShelfD1Ev(Shelf* this);

#endif

