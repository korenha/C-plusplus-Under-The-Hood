#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>




void _Z14doPrePostFixerv()
{
    PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");

    _ZN12PrePostFixerC2EPKcS1_(&angleBrackets, "<<< ", " >>>");
    _ZNK12PrePostFixer5printEPKc(&angleBrackets, "Hello World!");

    {
        printf("%-60s | ", "[PrePostFixer::print(long, char)]");
        printf("-->\n");

        /*if ('\0')
        {
            printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
            printf("%s%c%ld%s\n", angleBrackets.m_pre, '\0', (long)-777, angleBrackets.m_post);
        }
        else*/
        {
            printf("%-60s | ","[PrePostFixer::print_num(long)]");
            printf("%s%ld%s\n", angleBrackets.m_pre, (long)-777, angleBrackets.m_post);}

    }
    /*_ZNK12PrePostFixer5printElc(&angleBrackets, -777, '\0');*/

    {
        printf("%-60s | ", "[PrePostFixer::print(long, char)]");
        printf("-->\n");

       /* if ('#')
        {
            printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
            printf("%s%c%ld%s\n", angleBrackets.m_pre, '#',  (long)350, angleBrackets.m_post);
        }
        else*/
        {
            printf("%-60s | ","[PrePostFixer::print_num(long)]");
            printf("%s%ld%s\n", angleBrackets.m_pre,  (long)350, angleBrackets.m_post);
        }
    }

    /*_ZNK12PrePostFixer5printElc(&angleBrackets, 350, '#');*/

    {
        printf("%-60s | ", "[PrePostFixer::print(long, char)]");
        printf("-->\n");

        /*if ('\0')
        {
            printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
            printf("%s%c%ld%s\n", angleBrackets.m_pre, '\0', (long) 3.14, angleBrackets.m_post);
        }
        else*/
        {
            printf("%-60s | ","[PrePostFixer::print_num(long)]");
            printf("%s%ld%s\n", angleBrackets.m_pre, (long) 3.14, angleBrackets.m_post);
        }
    }

    /*_ZNK12PrePostFixer5printElc(&angleBrackets, (long) 3.14, '\0');*/

    printf("\n--- end doPrePostFixer() ---\n\n");
    _ZN12PrePostFixerD0Ev(&angleBrackets);
}

void _Z20doPrePostDollarFixerv()
{
    PrePostDollarFixer asterisks;

    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    _ZN18PrePostDollarFixerC2EPKcS1_(&asterisks, "***** ", " *****");
    _ZNK18PrePostDollarFixer5printEic(&asterisks, -777, '$');
    _ZNK18PrePostDollarFixer5printEic(&asterisks, 350, '#');
    _ZNK18PrePostDollarFixer5printEdc((PrePostDollarFixer *) &asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _ZN18PrePostDollarFixerD0Ev(&asterisks);

}

void _Z16doPrePostCheckerv()
{
    PrePostChecker check;

    printf("\n--- start doPrePostChecker() ---\n\n");
    _ZN14PrePostCheckerC1Ev(&check);

    _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(&check);
    _ZNK14PrePostChecker23printThisSymbolDirectlyEv(&check);
    _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(&check);
    _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(&check);
    _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(&check);
    _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    _ZN14PrePostCheckerD0Ev(&check);
}

void _Z25doPrePostFloatDollarFixerv()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;


    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    _ZN23PrePostFloatDollarFixerC1EPKcS1_(&hashes, "### ", " ###");
    _ZNK23PrePostFloatDollarFixer5printEf(&hashes, -777);
    _ZNK23PrePostFloatDollarFixer5printEfc(&hashes, 350, '#');
    _ZNK23PrePostFloatDollarFixer5printEf(&hashes, 3.14f);

    _ZN18PrePostDollarFixerC2ERKS_(&hashes2, (const PrePostDollarFixer *) &hashes);
    _ZNK18PrePostDollarFixer5printEdc(&hashes2, 7.5, '$');
    _ZNK18PrePostDollarFixer5printEic(&hashes2, 100, '$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    _ZN18PrePostDollarFixerD0Ev(&hashes2);
    _ZN23PrePostFloatDollarFixerD0Ev(&hashes);
}

void _Z20runAsPrePostFixerRefRK12PrePostFixer(PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((pPrintLong)((((TextFormatter*)pp)->_vPtr)[E_PRINT_LONG_AND_CHAR]))(pp,123,'\0');
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void _Z26runAsPrePostDollarFixerRefRK18PrePostDollarFixer(PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    _ZNK18PrePostDollarFixer5printEic(pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void _Z26runAsPrePostDollarFixerObj18PrePostDollarFixer(PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    _ZNK18PrePostDollarFixer5printEic(&pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void _Z24runAsPrePostHashFixerRefRK16PrePostHashFixer(PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    _ZNK16PrePostHashFixer5printEic(pp, 123, '#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void _Z12doMultiplierv()
{
    Multiplier m1;
    Multiplier m2;
    Multiplier m3;
    Multiplier m4;
    printf("\n--- start _Z12doMultiplierv() ---\n\n");

    _ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter *) &m1);
    m1.m_times = 3;
    ((TextFormatter*)&m1)->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", m1.m_times);

    _ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter *) &m2);
    m2.m_times = 5;
    ((TextFormatter*)&m2)->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", m2.m_times);

    _ZN12PrePostFixerC1EPKcS1_(&m3, &m1);
    _ZN12PrePostFixerC1EPKcS1_(&m4, &m2);

    _ZNK10Multiplier5printEPKc(&m1, "abc ");
    _ZNK10Multiplier5printEPKc(&m2, "abc ");
    _ZNK10Multiplier5printEPKc(&m3, "abc ");
    _ZNK10Multiplier5printEPKc(&m4, "abc ");

    printf("\n--- start _Z12doMultiplierv() ---\n\n");

    printf("--- Multiplier DTOR: times = %d\n", m4.m_times);
    ((TextFormatter*)&m4)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev(&m4);

    printf("--- Multiplier DTOR: times = %d\n", m3.m_times);
    ((TextFormatter*)&m3)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev(&m3);

    printf("--- Multiplier DTOR: times = %d\n", m2.m_times);
    ((TextFormatter*)&m2)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev(&m2);

    printf("--- Multiplier DTOR: times = %d\n", m1.m_times);
    ((TextFormatter*)&m1)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev(&m1);

    /*_ZN10MultiplierD0Ev(&m4);
    _ZN10MultiplierD0Ev(&m3);
    _ZN10MultiplierD0Ev(&m2);
    _ZN10MultiplierD0Ev(&m1);*/

}

void _Z16doFormatterArrayv()
{

    DefaultTextFormatter formatters[3];
    int i;
    PrePostDollarFixer temp1;
    Multiplier temp2;
    PrePostChecker temp3;

    printf("\n--- start doFormatterArray() ---\n\n");

    _ZN18PrePostDollarFixerC2EPKcS1_(&temp1, "!!! ", " !!!");
    _ZN20DefaultTextFormatterC1ERKS_(formatters, (const DefaultTextFormatter *) &temp1);
    _ZN18PrePostDollarFixerD0Ev(&temp1);

    _ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter *) &temp2);
    ((Multiplier*)(&temp2))->m_times = 4;
    ((TextFormatter*)(&temp2))->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)(&temp2))->m_times);
    _ZN20DefaultTextFormatterC1ERKS_(formatters + 1, (const DefaultTextFormatter *) &temp2);

    printf("--- Multiplier DTOR: times = %d\n", temp2.m_times);
    ((TextFormatter*)&temp2)->_vPtr = DefaultTextFormatterVTable;
    _ZN20DefaultTextFormatterD0Ev(&temp2);

    /*_ZN10MultiplierD0Ev(&temp2);*/

    _ZN14PrePostCheckerC1Ev(&temp3);
    _ZN20DefaultTextFormatterC1ERKS_(formatters + 2, (const DefaultTextFormatter *) &temp1);
    _ZN14PrePostCheckerD0Ev(&temp3);

    for (i = 0; i < 3; ++i)
    {
        _ZNK20DefaultTextFormatter5printEPKc(formatters + i, "Hello World");
    }
    printf("\n--- end doFormatterArray() ---\n\n");
    _ZN20DefaultTextFormatterD0Ev(formatters + 2);
    _ZN20DefaultTextFormatterD0Ev(formatters + 1);
    _ZN20DefaultTextFormatterD0Ev(formatters);

}

void _Z15doFormatterPtrsv()
{
    DefaultTextFormatter* pfmt[3];
    int i;
    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt[0] = malloc(sizeof(PrePostDollarFixer));
    _ZN18PrePostDollarFixerC2EPKcS1_((PrePostDollarFixer *) pfmt[0], "!!! ", " !!!");

    pfmt[1] = malloc(sizeof(Multiplier));
    _ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter *) pfmt[1]);
    ((Multiplier*)pfmt[1])->m_times = 4;
    ((TextFormatter*)pfmt[1])->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)pfmt[1])->m_times);

    pfmt[2] = malloc(sizeof(PrePostChecker));
    _ZN14PrePostCheckerC1Ev((PrePostChecker *) pfmt[2]);


    for (i = 0; i < 3; ++i)
    {
        ((pPrintKChar)((((TextFormatter*)pfmt[i])->_vPtr)[E_PRINT_CONST_CHAR]))(pfmt[i], "Hello World!");
    }

    for (i = 2; i >= 0; --i)
    {
        ((pDCtor)((((TextFormatter*)pfmt[i])->_vPtr)[E_DTOR]))(pfmt[i]);
        free(pfmt[i]);
    }
    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void _Z23doFormatterDynamicArrayv()
{
    DefaultTextFormatter* formatters;
    int i;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");
    formatters = _Z22generateFormatterArrayv();

    for (i = 0; i < 3; ++i)
    {
        _ZNK20DefaultTextFormatter5printEPKc(formatters + i, "Hello World");
    }

    for (i = 2; i >= 0; --i)
    {
        _ZN20DefaultTextFormatterD0Ev(formatters + i);
    }
    free(formatters);


    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    PrePostHashFixer hfix;
    PrePostDollarFixer temp1,temp2;
    printf("\n--- Start main() ---\n\n");

    _Z14doPrePostFixerv();
    _Z20doPrePostDollarFixerv();
    _Z25doPrePostFloatDollarFixerv();
    _Z16doPrePostCheckerv();
    _ZN16PrePostHashFixerC1Ei(&hfix, 4);
    _Z20runAsPrePostFixerRefRK12PrePostFixer((PrePostFixer *) &hfix);
    _Z26runAsPrePostDollarFixerRefRK18PrePostDollarFixer((PrePostDollarFixer *) &hfix);
    _ZN18PrePostDollarFixerC2ERKS_(&temp1, (const PrePostDollarFixer *) &hfix);
    _ZN18PrePostDollarFixerC2ERKS_(&temp2, &temp1);
    _Z26runAsPrePostDollarFixerObj18PrePostDollarFixer(temp1);
    _Z24runAsPrePostHashFixerRefRK16PrePostHashFixer(&hfix);

    _Z12doMultiplierv();

    _Z16doFormatterArrayv();
    _Z15doFormatterPtrsv();
    _Z23doFormatterDynamicArrayv();/**/

    printf("\n--- End main() ---\n\n");

    _ZN16PrePostHashFixerD0Ev(&hfix);
    return 0;
}



