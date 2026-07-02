/**
 * @file Object.h
 * @date 1-Jul-2026
 */

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "orx-mrt-demo.h"

/** Object Class
 */
MakeScrollObject(Object)
{
public:


protected:

                void            OnCreate();
                void            OnDelete();
                void            Update(const orxCLOCK_INFO &_rstInfo);
                orxBOOL         OnShader(orxSHADER_EVENT_PAYLOAD &_rstPayload);


private:
    orxVECTOR mIDColor;
};

MakeScrollObject(Label)
{
public:
protected:
    void            OnCreate();
    void            OnDelete();
    void            Update(const orxCLOCK_INFO &_rstInfo);
private:
};

#endif // __OBJECT_H__
