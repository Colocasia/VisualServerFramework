/** @file   *.h
*  @note   Hikvision System Technology Co., Ltd. All Right Reserved.
*  @brief  Colocasia
*  @author Colocasia
*  @date   2017/10/03
*/

#include "stdafx.h"

#ifndef __VISUAL_WINDOW_API_H__
#define __VISUAL_WINDOW_API_H__

#ifdef VISUAL_WINDOW_API_EXPORTS
#define VISUAL_WINDOW_API __declspec(dllexport)
#else
#define VISUAL_WINDOW_API __declspec(dllimport)
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    VISUAL_WINDOW_API int PASCAL VisualWindow_Init(IN int nType = 0);

    VISUAL_WINDOW_API int PASCAL VisualWindow_UnInit(void);

    VISUAL_WINDOW_API long PASCAL VisualWindow_CreateInstance(IN const int nFlag);

    VISUAL_WINDOW_API int PASCAL VisualWindow_DestroyInstance(IN long lInstace);

#ifdef __cplusplus
};
#endif


#endif  //__VISUAL_WINDOW_API_H__
