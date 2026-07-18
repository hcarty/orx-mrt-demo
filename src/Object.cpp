/**
 * @file Object.cpp
 * @date 1-Jul-2026
 */

#include "Object.h"

void Object::OnCreate()
{
  PushConfigSection();
  orxConfig_GetVector("ID", &mIDColor);
  PopConfigSection();
}

void Object::OnDelete()
{
}

void Object::Update(const orxCLOCK_INFO &_rstInfo)
{
}

orxBOOL Object::OnShader(orxSHADER_EVENT_PAYLOAD &_rstPayload)
{
  if (_rstPayload.eParamType == orxSHADER_PARAM_TYPE_VECTOR && orxString_Compare(_rstPayload.zParamName, "id") == 0)
  {
    orxVector_Copy(&_rstPayload.vValue, &mIDColor);
  }
  return orxTRUE;
}
