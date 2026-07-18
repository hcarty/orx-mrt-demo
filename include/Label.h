#pragma once

#include "orx-mrt-demo.h"

MakeScrollObject(Label)
{
public:
protected:
  void OnCreate();
  void OnDelete();
  void Update(const orxCLOCK_INFO &_rstInfo);

private:
};
