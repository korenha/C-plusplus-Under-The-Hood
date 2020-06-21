#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__
#include <stdio.h>
typedef void(*pDCtor)(void*);
typedef void(*pPrintCHar)(void*,const char*);
typedef void(*pPrintLong)(void*,long,char);
typedef char(*pGetDefault)(void*);
extern void*(*TextFormatterVirtualTAble[2])(void*);
extern void*(*DefaultTextFormatterVTable[2])(void*);
extern void*(*PrePostFixerVTable[4])(void*);
extern void*(*PrePostDollarFixerVTable[4])(void*);
extern void*(*PrePostHashFixerVTable[4])(void*);
extern void*(*PrePostFloatDollarFixerVTable[4])(void*);
extern void*(*PrePostCheckerVTable[4])(void*);
extern void*(*MultiplierVTable[2])(void*);
extern int next_id;


        typedef enum FuncName
{
    E_DTOR,
    E_PRINT_CONST_CHAR,
    E_PRINT_LONG_AND_CHAR,
    E_GET_DEFAULT
}FuncName;
/*
inline void printFunc(const char* fname)
{
    printf("%-60s | ", fname); 
}
*/
/*/// TextFormatter ///////////*/
typedef struct
{
    void* (** _vPtr)(void *);
}TextFormatter;



void TextFormatterD(void *pThis);
void TextFormatterC(TextFormatter* this);
/*void printT(void *pThis, const char* text);*/
/*/// DefaultTextFormatter ///////////*/
typedef struct
{
    TextFormatter *parent;
    int id;
    char empty;


}DefaultTextFormatter;

void DefaultTextFormatterD(void *pThis);
void DefaultTextFormatterCC(DefaultTextFormatter* this,const DefaultTextFormatter* other);
const DefaultTextFormatter* _ZNasDefaultTextFormatter(DefaultTextFormatter * this,const DefaultTextFormatter*);
void DefaultTextFormatterC(DefaultTextFormatter * this);
void printDefaultText(void *pThis, const char* text);



 /*       static int getId() {obj.next_id++; }*/


DefaultTextFormatter* generateFormatterArray();


/*/// PrePostFixer ///////////*/
typedef struct
{
    DefaultTextFormatter par;
    const char* m_pre;
    const char* m_post;
}PrePostFixer;


void PrePostFixerC(PrePostFixer *this, const char* prefix, const char* postfix);
void PrePostFixerCC(PrePostFixer *this, const PrePostFixer* other);

void PrePostFixerD(void *pThis);/*virtual*/

void printPrePost(void *pThis, const char *text);/*virtual*/

void printPrePostLong(void *pThis, long num, char symbol);/*virtual first*/

char getDefaultSymbol(void *pThis);/*virtual first*/


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

void PrePostDollarFixerC(PrePostDollarFixer* this,const char* prefix, const char* postfix);
void PrePostDollarFixerCC(PrePostDollarFixer* this,const PrePostDollarFixer* const other);
void PrePostDollarFixerD(void *pThis);/*virtual*/

void printPrePostDollarFixerInt(PrePostDollarFixer *this, int num, char symbol);
void printPrePostDollarFixerLong(void *pThis, long num, char symbol);/*virtual*/
void printPrePostDollarFixerDouble(PrePostDollarFixer *this, double num, char symbol);
char getDefaultSymbolPrePostDollarFixer(void *pThis);/*virtual*/


/*/// PrePostHashFixer ///////////*/
typedef struct
{
    PrePostDollarFixer par;
    int m_precision;
}PrePostHashFixer;

void PrePostHashFixerC(PrePostHashFixer* this,int prc);
void PrePostHashFixerCC(PrePostHashFixer* this,const PrePostHashFixer* other);
void PrePostHashFixerD(void *pThis);/*virtual*/

void printPrePostHashFixerInt(PrePostHashFixer *this, int num, char symbol);
void printPrePostHashFixerLong(void *pThis, long num, char symbol);/*virtual*/
char getDefaultSymbolPrePostHashFixer(void *pThis);/*virtual*/


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

void PrePostFloatDollarFixerC(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix);
void PrePostFloatDollarFixerCC(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer* const other);
void PrePostFloatDollarFixerD(void *pThis);/*virtual*/
void printPrePostFloatDollarFixerFloat(PrePostFloatDollarFixer *this, float num);
void printPrePostFloatDollarFixerFloatChar(PrePostFloatDollarFixer *this, float num, char symbol);
char getDefaultSymbolPrePostFloatDollarFixer(void *pThis);/*virtual*/




/*/// PrePostChecker ///////////*/
typedef struct
{
    PrePostFloatDollarFixer par;
}PrePostChecker;

void PrePostCheckerC(PrePostChecker* this);
void PrePostCheckerCC(PrePostChecker* this, const PrePostChecker* const other);
void PrePostCheckerD(void *pThis);/*virtual*/
    
void printThisSymbolUsingFunc(PrePostChecker *this);
void printThisSymbolDirectly(PrePostChecker *this);
void printDollarSymbolByCastUsingFunc(PrePostChecker *this);
void printDollarSymbolByScopeUsingFunc(PrePostChecker *this);
void printDollarSymbolByCastDirectly(PrePostChecker *this);
void printDollarSymbolByScopeDirectly(PrePostChecker *this);


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
void MultiplierD(void* pThis);
void MultiplierCC(Multiplier* this,const Multiplier* other);
void printMultiplier(void *pThis, const char *text);/*virtual*/



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

