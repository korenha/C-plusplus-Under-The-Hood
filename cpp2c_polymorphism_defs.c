#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>
void*(*TextFormatterVirtualTAble[2])(void*)  = {(void *(*)(void *)) TextFormatterD,NULL};
void*(*DefaultTextFormatterVTable[2])(void*)  = {(void *(*)(void *)) DefaultTextFormatterD,
                                                 (void *(*)(void *)) printDefaultText};
void*(*PrePostFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostFixerD, (void *(*)(void *)) printPrePost,
                                         (void *(*)(void *)) printPrePostLong, (void *(*)(void *)) getDefaultSymbol};
void*(*PrePostDollarFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostDollarFixerD, (void *(*)(void *)) printPrePost,
                                               (void *(*)(void *)) printPrePostDollarFixerLong,
                                               (void *(*)(void *)) getDefaultSymbolPrePostDollarFixer};
void*(*PrePostHashFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostHashFixerD, (void *(*)(void *)) printPrePost,
                                             (void *(*)(void *)) printPrePostHashFixerLong,
                                             (void *(*)(void *)) getDefaultSymbolPrePostHashFixer};
void*(*PrePostFloatDollarFixerVTable[4])(void*)  = {(void *(*)(void *)) PrePostFloatDollarFixerD,
                                                    (void *(*)(void *)) printPrePost,
                                                    (void *(*)(void *)) printPrePostHashFixerLong,
                                                    (void *(*)(void *)) getDefaultSymbolPrePostFloatDollarFixer};
void*(*PrePostCheckerVTable[4])(void*)  = {(void *(*)(void *)) PrePostCheckerD, (void *(*)(void *)) printPrePost,
                                           (void *(*)(void *)) printPrePostHashFixerLong,
                                           (void *(*)(void *)) getDefaultSymbolPrePostFloatDollarFixer};

void*(*MultiplierVTable[2])(void*)  = {(void *(*)(void *)) MultiplierD, (void *(*)(void *)) printMultiplier};

void TextFormatterC(TextFormatter* this)
{
    this->_vPtr = TextFormatterVirtualTAble;
}
void TextFormatterD(void *pThis) { }
int next_id=0;




/*/// DefaultTextFormatter Defs ///////////*/


void DefaultTextFormatterC(DefaultTextFormatter* this)
{
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    TextFormatterC((TextFormatter *) this);
    this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void DefaultTextFormatterD(void *pThis)
{
    DefaultTextFormatter* this = pThis;
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
    ((TextFormatter*)this)->_vPtr = TextFormatterVirtualTAble;
    TextFormatterD((TextFormatter *) pThis);
}

void DefaultTextFormatterCC(DefaultTextFormatter* this,const DefaultTextFormatter* const other)
{
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    TextFormatterC((TextFormatter *) this);
    this->id = next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

const DefaultTextFormatter* _ZNasDefaultTextFormatter(DefaultTextFormatter * this,const DefaultTextFormatter* const other)
{
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}

void printDefaultText(void *pThis, const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    int i;
    DefaultTextFormatter *generatArrey = (DefaultTextFormatter*)malloc(sizeof(DefaultTextFormatter)*3);
    for (i = 0; i < 3; ++i)
    {
        DefaultTextFormatterC(generatArrey+i);
    }
    return  generatArrey;
}


/*/// PrePostFixer Defs ///////////*/


void PrePostFixerC(PrePostFixer *this,const char* prefix, const char* postfix)
{
    DefaultTextFormatterC((DefaultTextFormatter *) this);
    ((TextFormatter*)this)->_vPtr =PrePostFixerVTable;
    this->m_pre = prefix;
    this->m_post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
}

void PrePostFixerCC(PrePostFixer *this, const PrePostFixer* const other)
{
    DefaultTextFormatterCC((DefaultTextFormatter *) this, (const DefaultTextFormatter *) other);
    this->m_pre = other->m_pre;
    this->m_post = other->m_post;
    ((TextFormatter*)this)->_vPtr =PrePostFixerVTable;
}

void PrePostFixerD(void *pThis)/*virtual*/
{
    PrePostFixer* this = pThis;
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    DefaultTextFormatterD((DefaultTextFormatter *) this);
}

void printPrePost(void *pThis, const char *text)/*virtual*/
{
    PrePostFixer* this = pThis;
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");printf("%s%s%s\n", this->m_pre, text, this->m_post);
}

char getDefaultSymbol(void *pThis)/*virtual first*/
{
    return '\0';
}

void printPrePostLong(void *pThis, long num, char symbol)/*virtual first*/
{
    PrePostFixer* this = pThis;
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->m_pre, symbol, num, this->m_post);
    }
    else
    {
        printf("%-60s | ","[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->m_pre, num, this->m_post);}
    }

/*/// PrePostDollarFixer Defs ///////////*/
char getDefaultSymbolPrePostDollarFixer(void *pThis)/*virtual*/
{
    return '$';
}

void PrePostDollarFixerC(PrePostDollarFixer* this,const char* prefix, const char* postfix)
{
    PrePostFixerC((PrePostFixer*)this,prefix,postfix);
    ((TextFormatter*)this)->_vPtr = PrePostDollarFixerVTable;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void PrePostDollarFixerCC(PrePostDollarFixer* this,const PrePostDollarFixer* const other)
{
    PrePostFixerCC((PrePostFixer *) this, (const PrePostFixer *) other);
    ((TextFormatter*)this)->_vPtr =PrePostDollarFixerVTable;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void PrePostDollarFixerD(void *pThis)/*virtual*/
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)pThis)->m_pre, ((PrePostFixer*)pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostFixerVTable;
    PrePostFixerD((PrePostFixer *) pThis);
}

void printPrePostDollarFixerInt(PrePostDollarFixer *this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    ((pPrintLong)((((TextFormatter*)this)->_vPtr)[E_PRINT_LONG_AND_CHAR]))(this,num,symbol);

}

void printPrePostDollarFixerLong(void *pThis, long num, char symbol)/*virtual*/
{

    printf("%-60s | ","[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    printPrePostLong((PrePostFixer *) pThis, num, symbol);
}

void printPrePostDollarFixerDouble(PrePostDollarFixer *this, double num, char symbol)
{
    printf("%-60s | ","[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)this)->m_pre,  symbol, num, ((PrePostFixer*)this)->m_post);
}


/*/// PrePostHashFixer Defs ///////////*/
void PrePostHashFixerC(PrePostHashFixer* this,int prc)
{
    PrePostDollarFixerC((PrePostDollarFixer *) this, "===> ", " <===");
    this->m_precision = prc;
    ((TextFormatter*)this)->_vPtr = PrePostHashFixerVTable;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post, this->m_precision);

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, '#', this->m_precision, 9999.9999, ((PrePostFixer*)this)->m_post);
}

void PrePostHashFixerCC(PrePostHashFixer* this,const PrePostHashFixer* other)
{
    PrePostDollarFixerCC((PrePostDollarFixer *) this, (const PrePostDollarFixer *) other);
    this->m_precision = other->m_precision;
    ((TextFormatter*)this)->_vPtr = PrePostHashFixerVTable;
}

void PrePostHashFixerD(void *pThis)/*virtual*/
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)pThis)->m_pre, ((PrePostFixer*)pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostDollarFixerVTable;
    PrePostDollarFixerD((PrePostDollarFixer *) pThis);
}

void printPrePostHashFixerInt(PrePostHashFixer *this, int num, char symbol)
{
    printf("%-60s | ","[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, symbol, this->m_precision, (double)num, ((PrePostFixer*)this)->m_post);
}

void printPrePostHashFixerLong(void *pThis, long num, char symbol)/*virtual*/
{
    PrePostHashFixer* this = pThis;
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer *) this)->m_pre, symbol, this->m_precision, (double)num, ((PrePostFixer *) this)->m_post);
}

char getDefaultSymbolPrePostHashFixer(void *pThis)/*virtual*/
{
    return '#';
}

/*/// PrePostFloatDollarFixer Defs ///////////*/

void PrePostFloatDollarFixerC(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix)
{
    PrePostDollarFixerC((PrePostDollarFixer *) this, prefix, postfix);
    ((TextFormatter*)this)->_vPtr = PrePostFloatDollarFixerVTable;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
}

void PrePostFloatDollarFixerCC(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer* const other)
{
    PrePostDollarFixerCC((PrePostDollarFixer *) this, (PrePostDollarFixer *) other);
    ((TextFormatter*)this)->_vPtr = PrePostFloatDollarFixerVTable;
}

void PrePostFloatDollarFixerD(void *pThis)/*virtual*/
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) pThis)->m_pre, ((PrePostFixer *) pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostDollarFixerVTable;
    PrePostDollarFixerD((PrePostDollarFixer *) pThis);
}

void printPrePostFloatDollarFixerFloat(PrePostFloatDollarFixer *this, float num)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    printPrePostFloatDollarFixerFloatChar(this,num, '@');
}

void printPrePostFloatDollarFixerFloatChar(PrePostFloatDollarFixer *this, float num, char symbol)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", ((PrePostFixer *) this)->m_pre, symbol, num, ((PrePostFixer *) this)->m_post);
}

char getDefaultSymbolPrePostFloatDollarFixer(void *pThis)/*virtual*/
{
    return '@';
}
/*/// PrePostChecker Defs ///////////*/

void PrePostCheckerC(PrePostChecker* this)
{
    PrePostFloatDollarFixerC((PrePostFloatDollarFixer *) this, "[[[[ ", " ]]]]");
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
    ((TextFormatter*)this)->_vPtr = PrePostCheckerVTable;
}

void PrePostCheckerCC(PrePostChecker* this, const PrePostChecker* const other)
{
    PrePostFloatDollarFixerCC((PrePostFloatDollarFixer *) this, (const PrePostFloatDollarFixer *) other);
    ((TextFormatter*)this)->_vPtr = PrePostCheckerVTable;
}

void PrePostCheckerD(void *pThis)/*virtual*/
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) pThis)->m_pre, ((PrePostFixer *) pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostFloatDollarFixerVTable;
    PrePostFloatDollarFixerD((PrePostFloatDollarFixer *) pThis);
}

void printThisSymbolUsingFunc(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n",((pGetDefault)(((TextFormatter*)this)->_vPtr[E_GET_DEFAULT]))(this));
}

void printThisSymbolDirectly(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", '@');
}

void printDollarSymbolByCastUsingFunc(PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", ((pGetDefault) ((TextFormatter *) (this))->_vPtr[E_GET_DEFAULT])(this));
}

void printDollarSymbolByScopeUsingFunc(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbolPrePostDollarFixer((PrePostDollarFixer *) this));
}

void printDollarSymbolByCastDirectly(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", '$');/*?*/
}

void printDollarSymbolByScopeDirectly(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", '$');
}


/*/// Multiplier Defs ///////////*/

void printMultiplier(void *pThis, const char *text)
{
    Multiplier* this = pThis;
    int i;
    printf("%-60s | ","[Multiplier::print(const char*)]");
    
    for (i = 0; i < this->m_times; ++i)
        printf("%s", text);
    printf("\n");
}

void MultiplierCC(Multiplier* this,const Multiplier* other)
{
    DefaultTextFormatterCC((DefaultTextFormatter *) this, (const DefaultTextFormatter *) other);
    this->m_times = other->m_times;
    ((TextFormatter*)this)->_vPtr = MultiplierVTable;

}

void MultiplierD(void* pThis)
{
    Multiplier* this = pThis;
    printf("--- Multiplier DTOR: times = %d\n", this->m_times);
    ((TextFormatter*)pThis)->_vPtr = DefaultTextFormatterVTable;
    DefaultTextFormatterD(this);
}