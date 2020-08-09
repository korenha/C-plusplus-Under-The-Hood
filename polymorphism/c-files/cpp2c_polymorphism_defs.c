#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>
generateFunc TextFormatterVirtualTAble[] = {(generateFunc) TextFormatterD,NULL};
generateFunc DefaultTextFormatterVTable[]  = {(generateFunc) _ZN20DefaultTextFormatterD0Ev,
                                                 (generateFunc) _ZNK20DefaultTextFormatter5printEPKc};
generateFunc PrePostFixerVTable[]  = {(generateFunc) _ZN12PrePostFixerD0Ev, (generateFunc) _ZNK12PrePostFixer5printEPKc,
                                      (generateFunc) _ZNK12PrePostFixer5printElc, (generateFunc) _ZNK12PrePostFixer16getDefaultSymbolEv};
generateFunc PrePostDollarFixerVTable[]  = {(generateFunc) _ZN18PrePostDollarFixerD0Ev, (generateFunc) _ZNK12PrePostFixer5printEPKc,
                                            (generateFunc) _ZNK18PrePostDollarFixer5printElc,
                                            (generateFunc) _ZNK18PrePostDollarFixer16getDefaultSymbolEv};
generateFunc PrePostHashFixerVTable[]  = {(generateFunc) _ZN16PrePostHashFixerD0Ev, (generateFunc) _ZNK12PrePostFixer5printEPKc,
                                          (generateFunc) _ZNK16PrePostHashFixer5printElc,
                                          (generateFunc) _ZNK16PrePostHashFixer16getDefaultSymbolEv};
generateFunc PrePostFloatDollarFixerVTable[] = {(generateFunc) _ZN23PrePostFloatDollarFixerD0Ev,
                                                   (generateFunc) _ZNK12PrePostFixer5printEPKc,
                                                   (generateFunc)_ZNK16PrePostHashFixer5printElc,
                                                   (generateFunc) _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv};
generateFunc PrePostCheckerVTable[]  = {(generateFunc) _ZN14PrePostCheckerD0Ev, (generateFunc) _ZNK12PrePostFixer5printEPKc,
                                        (generateFunc) _ZNK16PrePostHashFixer5printElc,
                                        (generateFunc) _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv};

generateFunc MultiplierVTable[] = {(generateFunc) _ZN10MultiplierD0Ev, (generateFunc) _ZNK10Multiplier5printEPKc};

void TextFormatterC(TextFormatter* this)
{
    this->_vPtr = TextFormatterVirtualTAble;
}
void TextFormatterD(void *pThis) { }
int _ZN20DefaultTextFormatter4Ider7next_idE=0;




/*/// DefaultTextFormatter Defs ///////////*/


void _ZN20DefaultTextFormatterC1Ev(DefaultTextFormatter* this)
{
    TextFormatterC((TextFormatter *) this);
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    this->m_id = _ZN20DefaultTextFormatter4Ider7next_idE++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->m_id);
}

void _ZN20DefaultTextFormatterD0Ev(void *pThis)
{
    DefaultTextFormatter* this = pThis;
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->m_id);
    ((TextFormatter*)this)->_vPtr = TextFormatterVirtualTAble;
    TextFormatterD((TextFormatter *) pThis);
}

void _ZN20DefaultTextFormatterC1ERKS_(DefaultTextFormatter* this, const DefaultTextFormatter *other)
{
    TextFormatterC((TextFormatter *) this);
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    this->m_id = _ZN20DefaultTextFormatter4Ider7next_idE++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->m_id, this->m_id);
}

const DefaultTextFormatter* _ZNasDefaultTextFormatter(DefaultTextFormatter * this,const DefaultTextFormatter* const other)
{
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->m_id, this->m_id);
    return this;
}

void _ZNK20DefaultTextFormatter5printEPKc(void *pThis, const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* _Z22generateFormatterArrayv()
{
    int i;
    DefaultTextFormatter *generatArrey = (DefaultTextFormatter*)malloc(sizeof(DefaultTextFormatter)*3);
    for (i = 0; i < 3; ++i)
    {
        _ZN20DefaultTextFormatterC1Ev(generatArrey + i);
    }
    return  generatArrey;
}


/*/// PrePostFixer Defs ///////////*/


void _ZN12PrePostFixerC2EPKcS1_(PrePostFixer *this, const char* prefix, const char* postfix)
{
    _ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter *) this);
    ((TextFormatter*)this)->_vPtr =PrePostFixerVTable;
    this->m_pre = prefix;
    this->m_post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
}

void _ZN12PrePostFixerC2EPKS_(PrePostFixer *this, const PrePostFixer *other)
{
    _ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter *) this, (const DefaultTextFormatter *) other);
    this->m_pre = other->m_pre;
    this->m_post = other->m_post;
    ((TextFormatter*)this)->_vPtr =PrePostFixerVTable;
}

void _ZN12PrePostFixerD0Ev(void *pThis)/*virtual*/
{
    PrePostFixer* this = pThis;
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev((DefaultTextFormatter *) this);
}

void _ZNK12PrePostFixer5printEPKc(void *pThis, const char *text)/*virtual*/
{
    PrePostFixer* this = pThis;
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");printf("%s%s%s\n", this->m_pre, text, this->m_post);
}

char _ZNK12PrePostFixer16getDefaultSymbolEv(void *pThis)/*virtual first*/
{
    return '\0';
}

void _ZNK12PrePostFixer5printElc(void *pThis, long num, char symbol)/*virtual first*/
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
char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(void *pThis)/*virtual*/
{
    return '$';
}

void _ZN18PrePostDollarFixerC2EPKcS1_(PrePostDollarFixer* this, const char* prefix, const char* postfix)
{
    _ZN12PrePostFixerC2EPKcS1_((PrePostFixer *) this, prefix, postfix);
    ((TextFormatter*)this)->_vPtr = PrePostDollarFixerVTable;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN18PrePostDollarFixerC2ERKS_(PrePostDollarFixer* this, const PrePostDollarFixer* const other)
{
    _ZN12PrePostFixerC2EPKS_((PrePostFixer *) this, (const PrePostFixer *) other);
    ((TextFormatter*)this)->_vPtr =PrePostDollarFixerVTable;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN18PrePostDollarFixerD0Ev(void *pThis)/*virtual*/
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)pThis)->m_pre, ((PrePostFixer*)pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostFixerVTable;
    _ZN12PrePostFixerD0Ev((PrePostFixer *) pThis);
}

void _ZNK18PrePostDollarFixer5printEic(PrePostDollarFixer *this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    ((pPrintLong)((((TextFormatter*)this)->_vPtr)[E_PRINT_LONG_AND_CHAR]))(this,num,symbol);

}

void _ZNK18PrePostDollarFixer5printElc(void *pThis, long num, char symbol)/*virtual*/
{

    PrePostDollarFixer *this = pThis;
    printf("%-60s | ","[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    {
        printf("%-60s | ", "[PrePostFixer::print(long, char)]");
        printf("-->\n");

        if (symbol)
        {
            printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
            printf("%s%c%ld%s\n", ((PrePostFixer *)this)->m_pre, symbol, num, ((PrePostFixer *)this)->m_post);
        }

        else
        {
            printf("%-60s | ","[PrePostFixer::print_num(long)]");
            printf("%s%ld%s\n", ((PrePostFixer *)this)->m_pre, num, ((PrePostFixer *)this)->m_post);}
    }

}

void _ZNK18PrePostDollarFixer5printEdc(PrePostDollarFixer *this, double num, char symbol)
{
    printf("%-60s | ","[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)this)->m_pre,  symbol, num, ((PrePostFixer*)this)->m_post);
}


/*/// PrePostHashFixer Defs ///////////*/
void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer* this, int prc)
{
    _ZN18PrePostDollarFixerC2EPKcS1_((PrePostDollarFixer *) this, "===> ", " <===");
    this->m_precision = prc;
    ((TextFormatter*)this)->_vPtr = PrePostHashFixerVTable;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post, this->m_precision);

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, '#', this->m_precision, 9999.9999, ((PrePostFixer*)this)->m_post);
}

void PrePostHashFixerCC(PrePostHashFixer* this,const PrePostHashFixer* other)
{
    _ZN18PrePostDollarFixerC2ERKS_((PrePostDollarFixer *) this, (const PrePostDollarFixer *) other);
    this->m_precision = other->m_precision;
    ((TextFormatter*)this)->_vPtr = PrePostHashFixerVTable;
}

void _ZN16PrePostHashFixerD0Ev(void *pThis)/*virtual*/
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)pThis)->m_pre, ((PrePostFixer*)pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostDollarFixerVTable;
    _ZN18PrePostDollarFixerD0Ev((PrePostDollarFixer *) pThis);
}

void _ZNK16PrePostHashFixer5printEic(PrePostHashFixer *this, int num, char symbol)
{
    printf("%-60s | ","[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, symbol, this->m_precision, (double)num, ((PrePostFixer*)this)->m_post);
}

void _ZNK16PrePostHashFixer5printElc(void *pThis, long num, char symbol)/*virtual*/
{
    PrePostHashFixer* this = pThis;
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer *) this)->m_pre, symbol, this->m_precision, (double)num, ((PrePostFixer *) this)->m_post);
}

char _ZNK16PrePostHashFixer16getDefaultSymbolEv(void *pThis)/*virtual*/
{
    return '#';
}

/*/// PrePostFloatDollarFixer Defs ///////////*/

void _ZN23PrePostFloatDollarFixerC1EPKcS1_(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix)
{
    _ZN18PrePostDollarFixerC2EPKcS1_((PrePostDollarFixer *) this, prefix, postfix);
    ((TextFormatter*)this)->_vPtr = PrePostFloatDollarFixerVTable;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
}

void _ZN23PrePostFloatDollarFixerC1EPKS_(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer* const other)
{
    _ZN18PrePostDollarFixerC2ERKS_((PrePostDollarFixer *) this, (PrePostDollarFixer *) other);
    ((TextFormatter*)this)->_vPtr = PrePostFloatDollarFixerVTable;
}

void _ZN23PrePostFloatDollarFixerD0Ev(void *pThis)/*virtual*/
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) pThis)->m_pre, ((PrePostFixer *) pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostDollarFixerVTable;
    _ZN18PrePostDollarFixerD0Ev((PrePostDollarFixer *) pThis);
}

void _ZNK23PrePostFloatDollarFixer5printEf(PrePostFloatDollarFixer *this, float num)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    _ZNK23PrePostFloatDollarFixer5printEfc(this, num, '@');
}

void _ZNK23PrePostFloatDollarFixer5printEfc(PrePostFloatDollarFixer *this, float num, char symbol)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", ((PrePostFixer *) this)->m_pre, symbol, num, ((PrePostFixer *) this)->m_post);
}

char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(void *pThis)/*virtual*/
{
    return '@';
}
/*/// PrePostChecker Defs ///////////*/

void _ZN14PrePostCheckerC1Ev(PrePostChecker* this)
{
    _ZN23PrePostFloatDollarFixerC1EPKcS1_((PrePostFloatDollarFixer *) this, "[[[[ ", " ]]]]");
    ((TextFormatter*)this)->_vPtr = PrePostCheckerVTable;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
}

/*void PrePostCheckerCC(PrePostChecker* this, const PrePostChecker* const other)
{
    _ZN23PrePostFloatDollarFixerC1EPKS_((PrePostFloatDollarFixer *) this, (const PrePostFloatDollarFixer *) other);
    ((TextFormatter*)this)->_vPtr = PrePostCheckerVTable;
}*/

void _ZN14PrePostCheckerD0Ev(void *pThis)/*virtual*/
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) pThis)->m_pre, ((PrePostFixer *) pThis)->m_post);
    ((TextFormatter*)pThis)->_vPtr = PrePostFloatDollarFixerVTable;
    _ZN23PrePostFloatDollarFixerD0Ev((PrePostFloatDollarFixer *) pThis);
}

void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n",((pGetDefault)(((TextFormatter*)this)->_vPtr[E_GET_DEFAULT]))(this));
}

void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", '@');
}

void _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", ((pGetDefault) ((TextFormatter *) (this))->_vPtr[E_GET_DEFAULT])(this));
}

void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", '$'
    );
}

void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", '$');/*?*/
}

void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", '$');
}


/*/// Multiplier Defs ///////////*/

void _ZNK10Multiplier5printEPKc(void *pThis, const char *text)
{
    Multiplier* this = pThis;
    int i;
    printf("%-60s | ","[Multiplier::print(const char*)]");
    
    for (i = 0; i < this->m_times; ++i)
        printf("%s", text);
    printf("\n");
}

void _ZN12PrePostFixerC1EPKcS1_(Multiplier* this, const Multiplier* other)
{
    _ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter *) this, (const DefaultTextFormatter *) other);
    this->m_times = other->m_times;
    ((TextFormatter*)this)->_vPtr = MultiplierVTable;

}

void _ZN10MultiplierD0Ev(void* pThis)
{
    Multiplier* this = pThis;
    printf("--- Multiplier DTOR: times = %d\n", this->m_times);
    ((TextFormatter*)pThis)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev(this);
}