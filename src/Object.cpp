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

void Label::OnCreate()
{
}

void Label::OnDelete()
{
}

void Label::Update(const orxCLOCK_INFO &_rstInfo)
{
  orxTEXTURE *pstIDTexture = orxTexture_Get("IDTexture");
  orxASSERT(pstIDTexture != orxNULL);

  orxBITMAP *pstIDBitmap = orxTexture_GetBitmap(pstIDTexture);
  orxASSERT(pstIDBitmap != orxNULL);

  orxFLOAT fWidth, fHeight;
  orxASSERT(orxDisplay_GetBitmapSize(pstIDBitmap, &fWidth, &fHeight) == orxSTATUS_SUCCESS);

  orxU32 u32Bytes = static_cast<orxU32>(fWidth) * static_cast<orxU32>(fHeight) * 4;
  orxU8 *au8Buf = (orxU8 *)orxMemory_Allocate(u32Bytes, orxMEMORY_TYPE_TEMP);
  orxASSERT(au8Buf != orxNULL);

  orxASSERT(orxDisplay_GetBitmapData(pstIDBitmap, au8Buf, u32Bytes) == orxSTATUS_SUCCESS);

  orxVECTOR vMousePosition = orxVECTOR_0;
  orxVECTOR vWorldPosition = orxVECTOR_0;
  orxVIEWPORT *pstViewport = orxViewport_Get("MainViewport");
  if (orxRender_GetWorldPosition(orxMouse_GetPosition(&vMousePosition), pstViewport, &vWorldPosition) == orxNULL)
  {
    // Mouse is outside of the viewport so there isn't anything to update
    return;
  }

  orxU32 u32Offset = static_cast<orxU32>(vMousePosition.fX) * 4 + static_cast<orxU32>(vMousePosition.fY) * 4 * static_cast<orxU32>(fWidth);

  if (u32Offset >= u32Bytes)
  {
    // Don't query outside of the texture/bitmap bounds
    return;
  }

  orxCHAR acLabel[1024];
  orxString_NPrint(acLabel, sizeof(acLabel), "MOUSE: (%d, %d) LABEL: (%d, %d, %d)", (int)vMousePosition.fX, (int)vMousePosition.fY, au8Buf[u32Offset], au8Buf[u32Offset + 1], au8Buf[u32Offset + 2]);
  SetText(acLabel);

  orxMemory_Free((void *)au8Buf);
}
