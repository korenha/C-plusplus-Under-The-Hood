#include <stdio.h>
#include "cpp2c_inheritance_defs.h"




void _Z11doMaterialsv()
{
    /*Materials mat;*/
    typedef struct { Materials mat; Material_t mat_t; }MatTest;
    Material_t mat1;
    Material_t mat2;

    /*struct ?*/
    /*רשימת איתחול?
     * operator=?*/
    /* sizeof?*/


    mat1.material = OTHER;
    mat2.material = OTHER;


    printf("\n--- Start doMaterials() ---\n\n");
    

    printf("Size of Materials: %d\n", 1/*sizeof(Materials)*/);
    printf("Size of mat: %d\n", 1/*sizeof(mat)*/);
    printf("Size of Materials::Types: %lu\n", sizeof(enum Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));
    mat1.material = OTHER;
    mat2.material = METAL;
    printf("Material created, set to %s\n", "other");
    printf("Material created, set to %s\n", "Metal");

    printf("\n--- End doMaterials() ---\n\n");
    _ZN10Material_tDEv(&mat2);
    _ZN10Material_tDEv(&mat1);


}

void _Z13doPhysicalBoxv()
{

    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    _ZN11PhysicalBoxC1EdddN9Materials5TypesE(&pb1, 8, 6, 4, PLASTIC);
    _ZN11PhysicalBoxC1EN9Materials5TypesE(&pb2,WOOD);
    pb3.material.material = OTHER;
    _ZN3BoxC1Esddd(((Box *) &pb3), 7,7,7);
    printf("Material created, set to %s\n", "other");
    _ZN11PhysicalBoxC1Eddd(&pb3,7,7,7);


    printf("\npb4 is copy-constructed from pb1\n");
    _ZN11PhysicalBoxC1EKN9Materials(&pb4,&pb1);
    _ZNK11PhysicalBox6printpEv(&pb4);
    _ZNK11PhysicalBox6printpEv(&pb1);
    printf("pb4 %s pb1\n", ((((const Box*)&pb1)->_width == ((const Box*)&pb4)->_width && ((const Box*)&pb1)->_height == ((const Box*)&pb4)->_height && ((const Box*)&pb1)->_length == ((const Box*)&pb4)->_length) && pb1.material.material == pb4.material.material) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    _ZN11PhysicalBoxaSEsRK11PhysicalBox(&pb4,&pb3);
    _ZNK11PhysicalBox6printpEv(&pb4);
    _ZNK11PhysicalBox6printpEv(&pb3);

    printf("pb4 %s pb3\n", ((((const Box*)&pb4)->_width == ((const Box*)&pb3)->_width && ((const Box*)&pb4)->_height == ((const Box*)&pb3)->_height && ((const Box*)&pb4)->_length == ((const Box*)&pb3)->_length) && pb4.material.material == pb3.material.material) ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    _ZN11PhysicalBoxD1Ev(&pb4);
    _ZN11PhysicalBoxD1Ev(&pb3);
    _ZN11PhysicalBoxD1Ev(&pb2);
    _ZN11PhysicalBoxD1Ev(&pb1);

}

void _Z11doWeightBoxv()
{
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");


    _ZN9WeightBoxC1ESdddd(&pw1,8,6,4,25);
    _ZN9WeightBoxC1ESdddd(&pw2,1,2,3,0.0);
    _ZN9WeightBoxC1ESdddd(&pw3,10,20,30,15);

    printf("\npw4 is copy-constructed from pw1\n");
    _ZN3BoxC1Esd((Box *) &pw4, 1);
    _ZN9WeightBoxCESRKS_(&pw4,&pw1);
    _ZNK9WeightBox6printwESv(&pw4);
    _ZNK9WeightBox6printwESv(&pw1);

    printf("pw4 %s pw1\n", ((((const Box*)&pw4)->_width == ((const Box*)&pw1)->_width && ((const Box*)&pw4)->_height == ((const Box*)&pw1)->_height && ((const Box*)&pw4)->_length == ((const Box*)&pw1)->_length) && pw4.weight == pw1.weight) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    _ZN9WeightBoxaSESRKS_(&pw4,&pw3);
    _ZNK9WeightBox6printwESv(&pw4);
    _ZNK9WeightBox6printwESv(&pw3);
    printf("pw4 %s pw3\n", ((((const Box*)&pw4)->_width == ((const Box*)&pw3)->_width && ((const Box*)&pw4)->_height == ((const Box*)&pw3)->_height && ((const Box*)&pw4)->_length == ((const Box*)&pw3)->_length) && pw4.weight == pw3.weight) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    _ZN9WeightBoxD1ESv(&pw4);
    _ZN9WeightBoxD1ESv(&pw3);
    _ZN9WeightBoxD1ESv(&pw2);
    _ZN9WeightBoxD1ESv(&pw1);
}





int main()
{
    printf("\n--- Start main() ---\n\n");

    _Z11doMaterialsv();

    _Z13doPhysicalBoxv();

    _Z11doWeightBoxv();

    printf("\n--- End main() ---\n\n");
    return 0;
}
