#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>




void doPrePostFixer()
{
    PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixerC(&angleBrackets,"<<< ", " >>>");
    printPrePost(&angleBrackets,"Hello World!");
    printPrePostLong(&angleBrackets,-777,'\0');
    printPrePostLong(&angleBrackets,350, '#');

    printPrePostLong(&angleBrackets,(long)3.14, '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    PrePostFixerD(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;

    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixerC(&asterisks,"***** ", " *****");
    printPrePostDollarFixerInt(&asterisks,-777,'$');
    printPrePostDollarFixerInt(&asterisks,350, '#');
    printPrePostDollarFixerDouble((PrePostDollarFixer *) &asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    PrePostDollarFixerD(&asterisks);

}

void doPrePostChecker()
{
    PrePostChecker check;

    printf("\n--- start doPrePostChecker() ---\n\n");
    PrePostCheckerC(&check);

    printThisSymbolUsingFunc(&check);
    printThisSymbolDirectly(&check);
    printDollarSymbolByCastDirectly(&check);
    printDollarSymbolByScopeDirectly(&check);
    printDollarSymbolByCastUsingFunc(&check);
    printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    PrePostCheckerD(&check);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;


    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixerC(&hashes,"### ", " ###");
    printPrePostFloatDollarFixerFloat(&hashes, -777);
    printPrePostFloatDollarFixerFloatChar( &hashes, 350, '#');
    printPrePostFloatDollarFixerFloat( &hashes, 3.14f);

    PrePostDollarFixerCC(&hashes2, (const PrePostDollarFixer *) &hashes);
    printPrePostDollarFixerDouble(&hashes2,7.5,'$');
    printPrePostDollarFixerInt(&hashes2,100,'$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    PrePostDollarFixerD(&hashes2);
    PrePostFloatDollarFixerD(&hashes);
}

void runAsPrePostFixerRef(PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((pPrintLong)((((TextFormatter*)pp)->_vPtr)[E_PRINT_LONG_AND_CHAR]))(pp,123,'\0');
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    printPrePostDollarFixerInt(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    printPrePostDollarFixerInt(&pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    printPrePostHashFixerInt(pp,123,'#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1;
    Multiplier m2;
    Multiplier m3;
    Multiplier m4;
    printf("\n--- start doMultiplier() ---\n\n");

    DefaultTextFormatterC((DefaultTextFormatter *) &m1);
    m1.m_times = 3;
    ((TextFormatter*)&m1)->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", m1.m_times);

    DefaultTextFormatterC((DefaultTextFormatter *) &m2);
    m2.m_times = 5;
    ((TextFormatter*)&m2)->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", m2.m_times);

    MultiplierCC(&m3,&m1);
    MultiplierCC(&m4,&m2);

    printMultiplier(&m1,"abc ");
    printMultiplier(&m2,"abc ");
    printMultiplier(&m3,"abc ");
    printMultiplier(&m4,"abc ");

    printf("\n--- start doMultiplier() ---\n\n");
    MultiplierD(&m4);
    MultiplierD(&m3);
    MultiplierD(&m2);
    MultiplierD(&m1);

}

void doFormatterArray()
{

    DefaultTextFormatter formatters[3];
    int i;
    PrePostDollarFixer temp1;
    Multiplier temp2;
    PrePostChecker temp3;

    printf("\n--- start doFormatterArray() ---\n\n");

    PrePostDollarFixerC(&temp1, "!!! ", " !!!");
    DefaultTextFormatterCC(formatters, (const DefaultTextFormatter *) &temp1);
    PrePostDollarFixerD(&temp1);

    DefaultTextFormatterC((DefaultTextFormatter *) &temp2);
    ((Multiplier*)(&temp2))->m_times = 4;
    ((TextFormatter*)(&temp2))->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)(&temp2))->m_times);
    DefaultTextFormatterCC(formatters+1, (const DefaultTextFormatter *) &temp2);
    MultiplierD(&temp2);

    PrePostCheckerC(&temp3);
    DefaultTextFormatterCC(formatters+2, (const DefaultTextFormatter *) &temp1);
    PrePostCheckerD(&temp3);

    for (i = 0; i < 3; ++i)
    {
        printDefaultText(formatters+i,"Hello World");

    }
    printf("\n--- end doFormatterArray() ---\n\n");
    DefaultTextFormatterD(formatters+2);
    DefaultTextFormatterD(formatters+1);
    DefaultTextFormatterD(formatters);

}

void doFormatterPtrs()
{
    DefaultTextFormatter* pfmt[3];
    int i;
    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt[0] = malloc(sizeof(PrePostDollarFixer));
    PrePostDollarFixerC((PrePostDollarFixer*)pfmt[0],"!!! ", " !!!");

    pfmt[1] = malloc(sizeof(Multiplier));
    DefaultTextFormatterC((DefaultTextFormatter *) pfmt[1]);
    ((Multiplier*)pfmt[1])->m_times = 4;
    ((TextFormatter*)pfmt[1])->_vPtr = MultiplierVTable;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)pfmt[1])->m_times);

    pfmt[2] = malloc(sizeof(PrePostChecker));
    PrePostCheckerC((PrePostChecker*)pfmt[2]);


    for (i = 1; i < 3; ++i)
    {
        ((pPrintCHar)((((TextFormatter*)pfmt[i])->_vPtr)[E_PRINT_CONST_CHAR]))(pfmt[i],"Hello World!");
    }

    for (i = 2; i >= 0; --i)
    {
        ((pDCtor)((((TextFormatter*)pfmt[i])->_vPtr)[E_DTOR]))(pfmt[i]);
        free(pfmt[i]);
    }
    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    DefaultTextFormatter* formatters;
    int i;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");
    formatters = generateFormatterArray();

    for (i = 0; i < 3; ++i)
    {
        printDefaultText(formatters+i,"Hello World");
    }

    for (i = 2; i >= 0; --i)
    {
        DefaultTextFormatterD(formatters+i);
    }
    free(formatters);


    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    PrePostHashFixer hfix;
    PrePostDollarFixer temp1;
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();
    PrePostHashFixerC(&hfix,4);
    runAsPrePostFixerRef((PrePostFixer *) &hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer *) &hfix);
    PrePostDollarFixerCC(&temp1, (const PrePostDollarFixer *) &hfix);
    runAsPrePostDollarFixerObj(temp1);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    PrePostHashFixerD(&hfix);
    return 0;
}



