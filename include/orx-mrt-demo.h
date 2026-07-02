/**
 * @file orx-mrt-demo.h
 * @date 1-Jul-2026
 */

#ifndef __orx_mrt_demo_H__
#define __orx_mrt_demo_H__

#include "Scroll/Scroll.h"

/** Game Class
 */
class orx_mrt_demo : public Scroll<orx_mrt_demo>
{
public:


private:

                orxSTATUS       Bootstrap() const;

                void            Update(const orxCLOCK_INFO &_rstInfo);
                void            CameraUpdate(const orxCLOCK_INFO &_rstInfo);

                orxSTATUS       Init();
                orxSTATUS       Run();
                void            Exit();


private:
};

#endif // __orx_mrt_demo_H__
