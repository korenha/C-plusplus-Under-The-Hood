#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__
#include <stdio.h>
typedef void(*pDCtor)(void*);
typedef void(*pPrintKChar)(void*, const char*);
typedef void(*pPrintLong)(void*,long,char);
typedef char(*pGetDefault)(void*);
typedef void*(*generateFunc)(void*);

extern void*(*TextFormatterVirtualTAble[])(void*);
extern void*(*DefaultTextFormatterVTable[])(void*);
extern void*(*PrePostFixerVTable[])(void*);
extern void*(*PrePostDollarFixerVTable[])(void*);
extern void*(*PrePostHashFixerVTable[])(void*);
extern void*(*PrePostFloatDollarFixerVTable[4])(void*);
extern void*(*PrePostCheckerVTable[])(void*);
extern void*(*MultiplierVTable[])(void*);
extern int _ZN20DefaultTextFormatter4Ider7next_idE;


typedef enum TextFormatterV
{
    E_DTOR,
    E_PRINT_CONST_CHAR,
    E_Last_FUNC
}TextFormatterV;

typedef enum PrePostV
{
    E_PRINT_LONG_AND_CHAR=E_Last_FUNC,
    E_GET_DEFAULT
}PrePostV;
/*
inline void printFunc(const char* fname)
{
    printf("%-60s | ", fname); 
}
*/
/*/// TextFormatter ///////////*/
typedef struct
{
    /*void* (** _vPtr)(void *)*/
    generateFunc *_vPtr;
}TextFormatter;



void TextFormatterD(void *pThis);
void TextFormatterC(TextFormatter* this);
/*void printT(void *pThis, const char* text);*/
/*/// DefaultTextFormatter ///////////*/
typedef struct
{
    TextFormatter *parent;
    int m_id;
}DefaultTextFormatter;

void _ZN20DefaultTextFormatterD0Ev(void *pThis);
void _ZN20DefaultTextFormatterC1ERKS_(DefaultTextFormatter* this, const DefaultTextFormatter* other);
const DefaultTextFormatter* _ZNasDefaultTextFormatter(DefaultTextFormatter * this,const DefaultTextFormatter*);
void _ZN20DefaultTextFormatterC1Ev(DefaultTextFormatter * this);
void _ZNK20DefaultTextFormatter5printEPKc(void *pThis, const char* text);



 /*       static int getId() {obj.next_id++; }*/


DefaultTextFormatter* _Z22generateFormatterArrayv();


/*/// PrePostFixer ///////////*/
typedef struct
{
    DefaultTextFormatter par;
    const char* m_pre;
    const char* m_post;
}PrePostFixer;


void _ZN12PrePostFixerC2EPKcS1_(PrePostFixer *this, const char* prefix, const char* postfix);
void _ZN12PrePostFixerC2EPKS_(PrePostFixer *this, const PrePostFixer* other);

void _ZN12PrePostFixerD0Ev(void *pThis);/*virtual*/

void _ZNK12PrePostFixer5printEPKc(void *pThis, const char *text);/*virtual*/

void _ZNK12PrePostFixer5printElc(void *pThis, long num, char symbol);/*virtual first*/

char _ZNK12PrePostFixer16getDefaultSymbolEv(void *pThis);/*virtual first*/


/*/// PrePostFixer Defs ///////////*/

/*inline const char* PrePostFixer::getPrefix() const
{
    return pre;
}

inline const char* PrePostFixer::getPostfix() const
{
    return post;
}
*/

/*inline void PrePostFixer::print_num(long num) const
{
    printFunc("[PrePostFixer::print_num(long)]");
    printf("%s%ld%s\n", pre, num, post);
}

inline void PrePostFixer::print_num(long num, char symbol) const
{
    printFunc("[PrePostFixer::print_num(long, char)]");
    printf("%s%c%ld%s\n", pre, symbol, num, post);
}

*/
/*/// PrePostDollarFixer ///////////*/
typedef struct
{
    PrePostFixer par;
}PrePostDollarFixer;

void _ZN18PrePostDollarFixerC2EPKcS1_(PrePostDollarFixer* this, const char* prefix, const char* postfix);
void _ZN18PrePostDollarFixerC2ERKS_(PrePostDollarFixer* this, const PrePostDollarFixer* const other);
void _ZN18PrePostDollarFixerD0Ev(void *pThis);/*virtual*/

void _ZNK18PrePostDollarFixer5printEic(PrePostDollarFixer *this, int num, char symbol);
void _ZNK18PrePostDollarFixer5printElc(void *pThis, long num, char symbol);/*virtual*/
void _ZNK18PrePostDollarFixer5printEdc(PrePostDollarFixer *this, double num, char symbol);
char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(void *pThis);/*virtual*/


/*/// PrePostHashFixer ///////////*/
typedef struct
{
    PrePostDollarFixer par;
    int m_precision;
}PrePostHashFixer;

void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer* this, int prc);
/*void PrePostHashFixerCC(PrePostHashFixer* this,const PrePostHashFixer* other);*/
void _ZN16PrePostHashFixerD0Ev(void *pThis);/*virtual*/

void _ZNK16PrePostHashFixer5printEic(PrePostHashFixer *this, int num, char symbol);
void _ZNK16PrePostHashFixer5printElc(void *pThis, long num, char symbol);/*virtual*/
char _ZNK16PrePostHashFixer16getDefaultSymbolEv(void *pThis);/*virtual*/


/*/// PrePostHashFixer Defs ///////////*/

/*inline void PrePostHashFixer::print(double num, char symbol) const
{
    printFunc("[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", getPrefix(), symbol, precision, num, getPostfix());
}*/


/*/// PrePostFloatDollarFixer ///////////*/
typedef struct
{
    PrePostDollarFixer par;
}PrePostFloatDollarFixer;

void _ZN23PrePostFloatDollarFixerC1EPKcS1_(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix);
void _ZN23PrePostFloatDollarFixerC1EPKS_(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer* const other);
void _ZN23PrePostFloatDollarFixerD0Ev(void *pThis);/*virtual*/
void _ZNK23PrePostFloatDollarFixer5printEf(PrePostFloatDollarFixer *this, float num);
void _ZNK23PrePostFloatDollarFixer5printEfc(PrePostFloatDollarFixer *this, float num, char symbol);
char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(void *pThis);/*virtual*/




/*/// PrePostChecker ///////////*/
typedef struct
{
    PrePostFloatDollarFixer par;
}PrePostChecker;

void _ZN14PrePostCheckerC1Ev(PrePostChecker* this);
void PrePostCheckerCC(PrePostChecker* this, const PrePostChecker* const other);
void _ZN14PrePostCheckerD0Ev(void *pThis);/*virtual*/
    
void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(PrePostChecker *this);
void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(PrePostChecker *this);
void _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(PrePostChecker *this);
void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(PrePostChecker *this);
void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(PrePostChecker *this);
void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(PrePostChecker *this);


/*/// Multiplier ///////////*/
typedef struct
{
    DefaultTextFormatter par;
    int m_times;
}Multiplier;

/*void MultiplierC(Multiplier* this, int t = 2);
void MultiplierD(Multiplier* this);
int getTimes(const Multiplier* const this);
void setTimes(Multiplier* this,int);*/
void _ZN10MultiplierD0Ev(void* pThis);
void _ZN12PrePostFixerC1EPKcS1_(Multiplier* this, const Multiplier* other);
void _ZNK10Multiplier5printEPKc(void *pThis, const char *text);/*virtual*/



/*/// Multiplier Defs ///////////*/
/*inline Multiplier::Multiplier(int t)
:   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}


    
inline int Multiplier::getTimes() const
{
    return times;
}

inline void Multiplier::setTimes(int t)
{
    times = t;
}


*/
#endif /*/ __CPP2C_POLYMORPHISM_H__*/

