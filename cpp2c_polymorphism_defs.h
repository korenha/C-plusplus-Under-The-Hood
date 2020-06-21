#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__
#include <stdio.h>
/*typedef enum ClassName
{
    E_TextFormatter,
    E_DefaultTextFormatter,
    E_PrePostFixer,
    E_PrePostDollarFixer,
    E_PrePostHashFixer,
    E_PrePostFloatDollarFixer,
    E_PrePostChecker,
    E_Multiplier
}ClassName;*/

typedef enum FuncName
{
    E_DTOR,
    E_PRINT_CONST_CHAR,
    E_PRINT_LONG_AND_CHAR,
    E_GET_DEFAULT
}FuncName;
extern int next_id;
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



void TextFormatterD(TextFormatter* this);
void TextFormatterC(TextFormatter* this);
void printT(TextFormatter* this,const char* text);
void*(*TextFormatterVirtualTAble[2])(void*)  = {(void *(*)(void *)) TextFormatterD, (void *(*)(void *)) printT};

/*/// DefaultTextFormatter ///////////*/
typedef struct
{
    TextFormatter *parent;
    int id;
    char empty;


}DefaultTextFormatter;

void DefaultTextFormatterD(DefaultTextFormatter* this);
void DefaultTextFormatterCC(DefaultTextFormatter* this,const DefaultTextFormatter* other);
const DefaultTextFormatter* _ZNasDefaultTextFormatter(DefaultTextFormatter * this,const DefaultTextFormatter*);
void DefaultTextFormatterC(DefaultTextFormatter * this);
void printDefaultText(DefaultTextFormatter * this,const char* text);

void*(*DefaultTextFormatterVTable[2])(void*)  = {(void *(*)(void *)) DefaultTextFormatterD,
                                                 (void *(*)(void *)) printDefaultText};


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

void PrePostFixerD(PrePostFixer *this);/*virtual*/

void printPrePost(const PrePostFixer* this, const char *text);/*virtual*/

void printPrePostLong(const PrePostFixer* this,long num, char symbol);/*virtual first*/

char getDefaultSymbol(const PrePostFixer* this);/*virtual first*/

void*(*PrePostFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostFixerD, (void *(*)(void *)) printPrePost,
                                         (void *(*)(void *)) printPrePostLong, (void *(*)(void *)) getDefaultSymbol};

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
extern const char DEFAULT_SYMBOL;
typedef struct
{
    PrePostFixer par;
}PrePostDollarFixer;

void PrePostDollarFixerC(PrePostDollarFixer* this,const char* prefix, const char* postfix);
void PrePostDollarFixerCC(PrePostDollarFixer* this,const PrePostDollarFixer* const other);
void PrePostDollarFixerD(PrePostDollarFixer* this);/*virtual*/

void printPrePostDollarFixerInt(const PrePostDollarFixer* const this,int num, char symbol);
void printPrePostDollarFixerLong(const PrePostDollarFixer* const this,long num, char symbol);/*virtual*/
void printPrePostDollarFixerDouble(const PrePostDollarFixer* const this,double num, char symbol);
char getDefaultSymbolPrePostDollarFixer(const PrePostDollarFixer* const this);/*virtual*/
void*(*PrePostDollarFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostDollarFixerD, (void *(*)(void *)) printPrePost,
                                               (void *(*)(void *)) printPrePostDollarFixerLong,
                                               (void *(*)(void *)) getDefaultSymbolPrePostDollarFixer};


/*/// PrePostHashFixer ///////////*/
typedef struct
{
    PrePostDollarFixer par;
    int m_precision;
}PrePostHashFixer;
extern const char DEFAULT_SYMBOLHash;

void PrePostHashFixerC(PrePostHashFixer* this,int prc);
void PrePostHashFixerCC(PrePostHashFixer* this,int prc);
void PrePostHashFixerD(PrePostHashFixer* this);/*virtual*/

void printPrePostHashFixerInt(const PrePostHashFixer* const this,int num, char symbol);
void printPrePostHashFixerLong(const PrePostHashFixer* const this,long num, char symbol);/*virtual*/
char getDefaultSymbolPrePostHashFixer(const PrePostHashFixer* const this);/*virtual*/

void*(*PrePostHashFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostHashFixerD, (void *(*)(void *)) printPrePost,
                                             (void *(*)(void *)) printPrePostHashFixerLong,
                                             (void *(*)(void *)) getDefaultSymbolPrePostHashFixer};

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
extern const char DEFAULT_SYMBOLFloatDollar;

void PrePostFloatDollarFixerC(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix);
void PrePostFloatDollarFixerCC(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer* const other);
void PrePostFloatDollarFixerD(PrePostFloatDollarFixer* this);/*virtual*/
void printPrePostFloatDollarFixerFloat(const PrePostFloatDollarFixer* const this,float num);
void printPrePostFloatDollarFixerFloatChar(const PrePostFloatDollarFixer* const this,float num, char symbol);
char getDefaultSymbolPrePostFloatDollarFixer(const PrePostFloatDollarFixer* const this);/*virtual*/


void*(*PrePostFloatDollarFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostFloatDollarFixerD,
                                                    (void *(*)(void *)) printPrePost,
                                                    (void *(*)(void *)) printPrePostHashFixerLong,
                                                    (void *(*)(void *)) getDefaultSymbolPrePostFloatDollarFixer};


/*/// PrePostChecker ///////////*/
typedef struct
{
    PrePostFloatDollarFixer par;
}PrePostChecker;

void PrePostCheckerC(PrePostChecker* this);
void PrePostCheckerCC(PrePostChecker* this, const PrePostChecker* const other);
void PrePostCheckerD(PrePostChecker* this);/*virtual*/
    
void printThisSymbolUsingFunc(const PrePostChecker* const this);
void printThisSymbolDirectly(const PrePostChecker* const this);
void printDollarSymbolByCastUsingFunc(const PrePostChecker* const this);
void printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this);
void printDollarSymbolByCastDirectly(const PrePostChecker* const this);
void printDollarSymbolByScopeDirectly(const PrePostChecker* const this);

void*(*PrePostCheckerVTable[4])(void*)  = {(void *(*)(void *)) PrePostCheckerD, (void *(*)(void *)) printPrePost,
                                           (void *(*)(void *)) printPrePostHashFixerLong,
                                           (void *(*)(void *)) getDefaultSymbolPrePostFloatDollarFixer};

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
void printMultiplier(const Multiplier* this,const char*);


/*/// Multiplier Defs ///////////*/

/*inline Multiplier::Multiplier(int t)
:   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}

inline Multiplier::~Multiplier()
{
    printf("--- Multiplier DTOR: times = %d\n", times);
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

