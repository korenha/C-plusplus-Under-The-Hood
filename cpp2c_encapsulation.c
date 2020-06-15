#include<stdio.h>
#include "cpp2c_encapsulation_defs.h"
static Box _ZZ8thisFuncVE5box99;
static Box _ZZ8thatFuncVE5box88;
static bool isFirstTimeStaticBoxThatFunc = true;
static bool isFirstTimeStaticBoxThisFunc = true;

static Box _ZL8largeBox;

void _Z8thisFuncv()
{
    printf("\n--- thisFunc() ---\n\n");
    if(isFirstTimeStaticBoxThisFunc)
    {
        _ZN3BoxC1Esddd(&_ZZ8thisFuncVE5box99, 99, 99, 99);
        isFirstTimeStaticBoxThisFunc = false;
    }
    _ZN3BoxmLEsd(&_ZZ8thisFuncVE5box99, 10);

}

void _Z8thatFuncv()
{
    printf("\n--- thatFunc() ---\n\n");
    if(isFirstTimeStaticBoxThatFunc)
    {
        _ZN3BoxC1Esddd(&_ZZ8thatFuncVE5box88, 88, 88, 88);
        isFirstTimeStaticBoxThatFunc = false;
    }
    _ZN3BoxmLEsd(&_ZZ8thatFuncVE5box88, 10);
}

void _Z7doBoxesv()
{
    Box b1,b2,b3,b4;
    printf("\n--- Start doBoxes() ---\n\n");

    _ZN3BoxC1Esd(&b1, 3);
    _ZN3BoxC1Esddd(&b2, 4, 5, 6);
    
    printf("b1 volume: %f\n", b1._width * b1._length * b1._height);
    printf("b2 volume: %f\n", b2._width * b2._length * b2._height);

    _ZN3BoxmLEsd(&b1, 1.5);
    _ZN3BoxmLEsd(&b2, 0.5);

    printf("b1 volume: %f\n", b1._width * b1._length * b1._height);
    printf("b2 volume: %f\n", b2._width * b2._length * b2._height);

    _ZN3BoxC1EsRKS(&b3,&b2);
    _ZN3BoxC1EsRKS(&b4,&b2);
    _ZN3BoxmLEsd(&b4, 3);
    printf("b3 %s b4\n", (b3._width == b4._width && b3._length == b4._length && b3._height == b4._height ) ? "equals" : "does not equal");

    _ZN3BoxmLEsd(&b3, 1.5);
    _ZN3BoxmLEsd(&b4, 0.5);

    printf("Now, b3 %s b4\n", (b3._width == b4._width && b3._length == b4._length && b3._height == b4._height ) ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _ZN3BoxD1Esv(&b4);
    _ZN3BoxD1Esv(&b3);
    _ZN3BoxD1Esv(&b2);
    _ZN3BoxD1Esv(&b1);
}


void _Z9doShelvesv()
{
    Shelf aShelf;
    Box temp,temp2,aBox;
    printf("\n--- start doShelves() ---\n\n");

    _ZN3BoxC1Esd(&aBox, 5);
    _ZN3BoxC1Esv(&aShelf.boxes[0]);
    _ZN3BoxC1Esv(&aShelf.boxes[1]);
    _ZN3BoxC1Esv(&aShelf.boxes[2]);

    _ZNK5Shelf5printEv(&aShelf);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &_ZL8largeBox);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    _ZNK5Shelf5printEv(&aShelf);
    _ZN5Shelf7messageE = "This is the total volume on the shelf:";
    _ZNK5Shelf5printEv(&aShelf);
    _ZN5Shelf7messageE =  "Shelf's volume:";
    _ZNK5Shelf5printEv(&aShelf);

    _ZN3BoxC1Esddd(&temp, 2, 4, 6);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &temp);
    _ZN3BoxD1Esv(&temp);

    _ZN3BoxC1Esd(&temp2, 2);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &temp2);
    _ZN3BoxD1Esv(&temp2);

    _ZNK5Shelf5printEv(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    _ZN5ShelfD1Ev(&aShelf);
    _ZN3BoxD1Esv(&aBox);
}

int main()
{
    _ZN3BoxC1Esddd(&_ZL8largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    _Z7doBoxesv();
    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thatFuncv();
    _Z8thatFuncv();

    _Z9doShelvesv();

    printf("\n--- End main() ---\n\n");

    _ZN3BoxD1Esv(&_ZZ8thatFuncVE5box88);
    _ZN3BoxD1Esv(&_ZZ8thisFuncVE5box99);
    _ZN3BoxD1Esv(&_ZL8largeBox);

    return 0;
}

