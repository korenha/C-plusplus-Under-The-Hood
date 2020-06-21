#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>
void TextFormatterC(TextFormatter* this)
{
    this->_vPtr = TextFormatterVirtualTAble;
}
void TextFormatterD(TextFormatter* this) { }
int next_id=0;
const char DEFAULT_SYMBOL = '$';
const char DEFAULT_SYMBOLHash = '#';
const char DEFAULT_SYMBOLFloatDollar = '@';




/*/// DefaultTextFormatter Defs ///////////*/


void DefaultTextFormatterC(DefaultTextFormatter* this)
{
    ((TextFormatter*)this)->_vPtr = DefaultTextFormatterVTable;
    TextFormatterC((TextFormatter *) this);
    this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void DefaultTextFormatterD(DefaultTextFormatter* this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
    TextFormatterD((TextFormatter *) this);
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

void printDefaultText(DefaultTextFormatter * this,const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    int i;
    DefaultTextFormatter *generatArrey = malloc(sizeof(DefaultTextFormatterVTable)*3);
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
    this->m_pre = prefix;
    this->m_post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
    ((TextFormatter*)this)->_vPtr =PrePostFixerVTable;
}

void PrePostFixerCC(PrePostFixer *this, const PrePostFixer* const other)
{
    DefaultTextFormatterCC((DefaultTextFormatter *) this, (const DefaultTextFormatter *) other);
    ((TextFormatter*)this)->_vPtr =PrePostFixerVTable;
}

void PrePostFixerD(PrePostFixer *this)/*virtual*/
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
    DefaultTextFormatterD((DefaultTextFormatter *) this);
}

void printPrePost(const PrePostFixer* const this, const char *text)/*virtual*/
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->m_pre, text, this->m_post);
}

char getDefaultSymbol(const PrePostFixer* const this)/*virtual first*/
{
    return '\0';
}

void printPrePostLong(const PrePostFixer* const this,long num, char symbol)/*virtual first*/
{
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
char getDefaultSymbolPrePostDollarFixer(const PrePostDollarFixer* const this)/*virtual*/
{
    return DEFAULT_SYMBOL;
}

void PrePostDollarFixerC(PrePostDollarFixer* this,const char* prefix, const char* postfix)
{
    PrePostFixerC((PrePostFixer*)this,prefix,postfix);
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)this)->_vPtr = PrePostDollarFixerVTable;
}

void PrePostDollarFixerCC(PrePostDollarFixer* this,const PrePostDollarFixer* const other)
{
    PrePostFixerCC((PrePostFixer *) this, (const PrePostFixer *) other);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)this)->_vPtr =PrePostDollarFixerVTable;
}

void PrePostDollarFixerD(PrePostDollarFixer* this)/*virtual*/
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    PrePostFixerD((PrePostFixer *) this);
}

void printPrePostDollarFixerInt(const PrePostDollarFixer* const this,int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    printPrePostDollarFixerLong(this,(long)(num), symbol);
}

void printPrePostDollarFixerLong(const PrePostDollarFixer* const this,long num, char symbol)/*virtual*/
{
    printf("%-60s | ","[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    printPrePostLong((const PrePostFixer *) this, num, symbol);
}

void printPrePostDollarFixerDouble(const PrePostDollarFixer* const this,double num, char symbol)
{
    printf("%-60s | ","[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)this)->m_pre,  symbol, num, ((PrePostFixer*)this)->m_post);
}


/*/// PrePostHashFixer Defs ///////////*/
void PrePostHashFixerC(PrePostHashFixer* this,int prc)
{
    PrePostDollarFixerC((PrePostDollarFixer *) this, "===> ", " <===");
    this->m_precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post, this->m_precision);

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, DEFAULT_SYMBOLHash, this->m_precision, 9999.9999, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)this)->_vPtr = PrePostHashFixerVTable;
}

void PrePostHashFixerD(PrePostHashFixer* this)/*virtual*/
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    PrePostDollarFixerD((PrePostDollarFixer *) this);
}

void printPrePostHashFixerInt(const PrePostHashFixer* const this,int num, char symbol)
{
    printf("%-60s | ","[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*d]%s\n", ((PrePostFixer*)this)->m_pre, symbol, this->m_precision, num, ((PrePostFixer*)this)->m_post);
}

void printPrePostHashFixerLong(const PrePostHashFixer* const this,long num, char symbol)/*virtual*/
{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*ld]%s\n", ((PrePostFixer *) this)->m_pre, symbol, this->m_precision, num,((PrePostFixer *) this)->m_post);
}

char getDefaultSymbolPrePostHashFixer(const PrePostHashFixer* const this)/*virtual*/
{
    return DEFAULT_SYMBOLHash;
}

/*/// PrePostFloatDollarFixer Defs ///////////*/

void PrePostFloatDollarFixerC(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix)
{
    PrePostDollarFixerC((PrePostDollarFixer *) this, prefix, postfix);
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
    ((TextFormatter*)this)->_vPtr = PrePostFloatDollarFixerVTable;
}

void PrePostFloatDollarFixerCC(PrePostFloatDollarFixer* this, const PrePostFloatDollarFixer* const other)
{
    PrePostDollarFixerCC((PrePostDollarFixer *) this, (const PrePostDollarFixer *) other);
    ((TextFormatter*)this)->_vPtr = PrePostFloatDollarFixerVTable;
}

void PrePostFloatDollarFixerD(PrePostFloatDollarFixer* this)/*virtual*/
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
    PrePostDollarFixerD((PrePostDollarFixer *) this);
}

void printPrePostFloatDollarFixerFloat(const PrePostFloatDollarFixer* const this,float num)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    printPrePostFloatDollarFixerFloatChar(this,num, DEFAULT_SYMBOL);
}

void printPrePostFloatDollarFixerFloatChar(const PrePostFloatDollarFixer* const this,float num, char symbol)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", ((PrePostFixer *) this)->m_pre, symbol, num, ((PrePostFixer *) this)->m_post);
}

char getDefaultSymbolPrePostFloatDollarFixer(const PrePostFloatDollarFixer* const this)/*virtual*/
{
    return DEFAULT_SYMBOLFloatDollar;
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

void PrePostCheckerD(PrePostChecker* this)/*virtual*/
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->m_pre, ((PrePostFixer *) this)->m_post);
    PrePostFloatDollarFixerD((PrePostFloatDollarFixer *) this);
}

void printThisSymbolUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n",getDefaultSymbolPrePostFloatDollarFixer((const PrePostFloatDollarFixer *) this));
}

void printThisSymbolDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOLFloatDollar);
}

void printDollarSymbolByCastUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", ((char(*)(const PrePostFloatDollarFixer*))((TextFormatter*)(this))->_vPtr[3])(
            (const PrePostFloatDollarFixer *) this));
}

void printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbolPrePostDollarFixer((const PrePostDollarFixer *) this));
}

void printDollarSymbolByCastDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOLFloatDollar);/*?*/
}

void printDollarSymbolByScopeDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOL);
}


/*/// Multiplier Defs ///////////*/

void printMultiplier(const Multiplier* const this,const char* text)
{
    int i;
    printf("%-60s | ","[Multiplier::print(const char*)]");
    
    for (i = 0; i < this->m_times; ++i)
        printf("%s", text);
    printf("\n");
}


