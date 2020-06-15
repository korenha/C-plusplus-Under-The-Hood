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
        _ZN3BoxC1Eddd(&_ZZ8thisFuncVE5box99, 99, 99, 99);
        isFirstTimeStaticBoxThisFunc = false;
    }
    _ZZ8thisFuncVE5box99.height*=10;
    _ZZ8thisFuncVE5box99.width*=10;
    _ZZ8thisFuncVE5box99.length*=10;

}

void _Z8thatFuncv()
{
    printf("\n--- thatFunc() ---\n\n");
    if(isFirstTimeStaticBoxThatFunc)
    {
        _ZN3BoxC1Eddd(&_ZZ8thatFuncVE5box88, 88, 88, 88);
        isFirstTimeStaticBoxThatFunc = false;
    }
    _ZZ8thatFuncVE5box88.height*=10;
    _ZZ8thatFuncVE5box88.width*=10;
    _ZZ8thatFuncVE5box88.length*=10;}

void _Z7doBoxesv()
{
    Box b1,b2,b3,b4;
    printf("\n--- Start doBoxes() ---\n\n");

    _ZN3BoxC1Ed(&b1, 3);
    _ZN3BoxC1Eddd(&b2, 4, 5, 6);
    
    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    _ZN3BoxmLEd(&b1, 1.5);
    _ZN3BoxmLEd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    b3 = b2;
    b4 = b2;
    _ZN3BoxmLEd(&b4, 3);
    printf("b3 %s b4\n", (b3.width == b4.width && b3.length == b4.length && b3.height == b4.height ) ? "equals" : "does not equal");

    _ZN3BoxmLEd(&b3, 1.5);
    _ZN3BoxmLEd(&b4, 0.5);

    printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.length == b4.length && b3.height == b4.height ) ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _ZN3BoxD1Ev(&b4);
    _ZN3BoxD1Ev(&b3);
    _ZN3BoxD1Ev(&b2);
    _ZN3BoxD1Ev(&b1);
}


void _Z9doShelvesv()
{
    Shelf aShelf;
    Box temp,temp2,aBox;
    printf("\n--- start doShelves() ---\n\n");

    _ZN3BoxC1Ed(&aBox, 5);
    _ZN3BoxC1Ev(&aShelf.boxes[0]);
    _ZN3BoxC1Ev(&aShelf.boxes[1]);
    _ZN3BoxC1Ev(&aShelf.boxes[2]);

    printShelf(&aShelf);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &_ZL8largeBox);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    printShelf(&aShelf);
    _ZN5Shelf7messageE = "This is the total volume on the shelf:";
    printShelf(&aShelf);
    _ZN5Shelf7messageE =  "Shelf's volume:";
    printShelf(&aShelf);

    _ZN3BoxC1Eddd(&temp, 2, 4, 6);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &temp);
    _ZN3BoxD1Ev(&temp);

    _ZN3BoxC1Ed(&temp2, 2);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &temp2);
    _ZN3BoxD1Ev(&temp2);

    printShelf(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    _ZN3BoxD1Ev(&aShelf.boxes[2]);
    _ZN3BoxD1Ev(&aShelf.boxes[1]);
    _ZN3BoxD1Ev(&aShelf.boxes[0]);

    _ZN3BoxD1Ev(&aBox);
}

int main()
{
    _ZN3BoxC1Eddd(&_ZL8largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    _Z7doBoxesv();
    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thatFuncv();
    _Z8thatFuncv();

    _Z9doShelvesv();

    printf("\n--- End main() ---\n\n");

    _ZN3BoxD1Ev(&_ZZ8thatFuncVE5box88);
    _ZN3BoxD1Ev(&_ZZ8thisFuncVE5box99);
    _ZN3BoxD1Ev(&_ZL8largeBox);

    return 0;
}

