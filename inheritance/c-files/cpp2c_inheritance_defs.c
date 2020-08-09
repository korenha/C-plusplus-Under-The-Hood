#include <stdio.h>
#include "cpp2c_inheritance_defs.h"
#include <string.h>

void _ZN9MaterialsCEv(Materials* this)
{}
void _ZN9MaterialsDEv(Materials* this)
{}
void _ZN9MaterialsCERC9Materials(Materials* this,const Materials* other)
{}

const Materials *const _ZN9MaterialsaSEsRC9Materials(Materials* this, const Materials* other)
{
    return this;
}

void _ZN10Material_tCEv(Material_t* this){}
void _ZN10Material_tCERC10Material_t(Material_t* this,const Material_t* other)
{
    _ZN9MaterialsCERC9Materials((Materials *) this, (const Materials *) other);
    memcpy(this,other, sizeof(enum Types));
}
void _ZN10Material_tDEv(Material_t* this)
{
    _ZN9MaterialsDEv((Materials *) this);
}

const Material_t *const _ZN10Material_taSEsRC10Material_t(Material_t* this, const Material_t* other)
{
    _ZN9MaterialsaSEsRC9Materials((Materials *) this, (const Materials *) other);
    this->material = other->material;
    return this;
}

/*/// PhysicalBox Defs ///////////*/

void _ZN11PhysicalBoxC1Eddd(PhysicalBox* this,double l, double w, double h)
{
    _ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* this,double l, double w, double h, enum Types t)
{
    _ZN3BoxC1Esddd((Box *) this, l, w, h);
    this->material.material = t;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this->material.material]);
    }
    _ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox* this,enum Types t)
{
    _ZN3BoxC1Esd((Box *) this, 1);
    this->material.material = t;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this->material.material]);
    }
    _ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1EKN9Materials(PhysicalBox* this,const PhysicalBox* other)
{
    _ZN3BoxC1EsRKS((Box *) this, (const Box *) other);
    _ZN10Material_tCERC10Material_t((Material_t *) ((char *) this + sizeof(Box)),(const Material_t *) ((char *) other + sizeof(Box)));
}

void _ZN11PhysicalBoxD1Ev(PhysicalBox* this)
{
   {
       const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
       printf("PhysicalBox dtor, %f x %f x %f, %s; ", ((Box*)this)->_length, ((Box*)this)->_width, ((Box*)this)->_height ,names[this->material.material]);
    }
    _ZN10Material_tDEv((Material_t *) ((char*)this + sizeof(Box)));
    _ZN3BoxD1Esv((const Box *) this);
}

void _ZNK11PhysicalBox6printpEv(const PhysicalBox* const this)
{
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox, made of %s; ",names[this->material.material]);
    }
    _ZNK3Box5printEsv((const Box *) this);
}

const PhysicalBox *const _ZN11PhysicalBoxaSEsRK11PhysicalBox(PhysicalBox* this, const PhysicalBox* other)
{
    _ZN3BoxaSEsRKS3Box((Box *) this, (const Box *) other);
    _ZN10Material_taSEsRC10Material_t((Material_t *) ((char *) this + sizeof(Box)),(const Material_t *) ((char *) other + sizeof(Box)));
    return this;
}

/*// WeightBox Defs ///////////*/

void _ZN9WeightBoxC1ESdddd(WeightBox* this,double l, double w, double h, double wgt)
{
    _ZN3BoxC1Esddd((Box *) this, l, w, h);
    this->weight = wgt;
    _ZNK9WeightBox6printwESv(this);
}

void _ZN9WeightBoxCESRKS_(WeightBox* this, const WeightBox *other)
{
    this->weight = other->weight;
    _ZNK9WeightBox6printwESv(this);
}

void _ZN9WeightBoxD1ESv(WeightBox* this)
{
    printf("Destructing WeightBox; ");
    _ZNK9WeightBox6printwESv(this);
    _ZN3BoxD1Esv((const Box *) this);
}

const WeightBox *const _ZN9WeightBoxaSESRKS_(WeightBox* this, const WeightBox *other)
{
    this->weight = other->weight;
    return this;
}


void _ZNK9WeightBox6printwESv(const WeightBox* const this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    _ZNK3Box5printEsv((const Box *) this);
}


