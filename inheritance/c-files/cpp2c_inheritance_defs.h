#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/*/// Materials ///////////*/
typedef struct
{
    enum Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    }Types;

/*    static const char* getName(Types type)
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        return names[type];
    }*/
}Materials;

void _ZN9MaterialsCEv(Materials* this);
void _ZN9MaterialsCERC9Materials(Materials* this,const Materials* other);
void _ZN9MaterialsDEv(Materials* this);
const Materials *const _ZN9MaterialsaSEsRC9Materials(Materials* this, const Materials* other);

typedef struct
{
 /*   Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }*/
 /*   const char* name() const { return getName(material); }*/

    enum Types material;
}Material_t;

void _ZN10Material_tCERC10Material_t(Material_t* this,const Material_t* other);
void _ZN10Material_tDEv(Material_t* this);
const Material_t *const _ZN10Material_taSEsRC10Material_t(Material_t* this, const Material_t* other);


/*/// PhysicalBox ///////////*/
typedef struct
{
    Box box;
    Material_t material;
}PhysicalBox;
void _ZN11PhysicalBoxC1Eddd(PhysicalBox* this,double l, double w, double h);
void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* this,double l, double w, double h, enum Types t);
void _ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox* this,enum Types t);
void _ZN11PhysicalBoxC1EKN9Materials(PhysicalBox* this,const PhysicalBox* other);
void _ZN11PhysicalBoxD1Ev(PhysicalBox* this);
void _ZNK11PhysicalBox6printpEv(const PhysicalBox* this);
const PhysicalBox *const _ZN11PhysicalBoxaSEsRK11PhysicalBox(PhysicalBox* this, const PhysicalBox* other);

/*bool operator==(const PhysicalBox&, const PhysicalBox&);
bool operator!=(const PhysicalBox&, const PhysicalBox&);*/

/*/// PhysicalBox Defs ///////////*/

/*inline Materials::Types PhysicalBox::getMaterial() const
{
    return material.material;
}*/

/*inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
}

inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
{
    return !(lhs == rhs);
}
*/
/*/// WeightBox ///////////*/
typedef struct
{
    Box box;
    double weight;

}WeightBox;

void _ZN9WeightBoxC1ESdddd(WeightBox* this,double l, double w, double h, double wgt);
void _ZN9WeightBoxCESRKS_(WeightBox* this, const WeightBox* other);
void _ZN9WeightBoxD1ESv(WeightBox* this);
const WeightBox *const _ZN9WeightBoxaSESRKS_(WeightBox* this, const WeightBox* other);
void _ZNK9WeightBox6printwESv(const WeightBox* this);

 /*   double getWeight() const;*/

/*bool operator==(const WeightBox&, const WeightBox&);
bool operator!=(const WeightBox&, const WeightBox&);

//// WeightBox Defs ////////////

inline double WeightBox::getWeight() const
{
    return weight;
}

inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
{
    return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
}

inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
{
    return !(lhs == rhs);
}

*/







#endif /*/ __CPP2C_INHERITANCE_DEFS_H__*/


