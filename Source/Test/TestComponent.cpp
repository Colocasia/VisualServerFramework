// TestComponent.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <Windows.h>

#include "Api\WindowComponentAPI.h"
#pragma comment(lib, "../../../../Debug/WindowComponent.lib")

HANDLE g_hThread = NULL;
HANDLE g_hEvnet = NULL;
int    g_nFlag = 0;
long   g_lInstance = 0;

unsigned __stdcall ThreadFunction(void *pThread)
{
    while (true)
    {
        bool bIsbreak = false;
        long lInstance = 0;
        ::WaitForSingleObject(g_hEvnet, 10);//等待线程同步事件，10毫秒超时，不使用INFINITE
        switch (g_nFlag)
        {
        case 1:
            g_lInstance = WindowComponent_CreateInstance(0);//创建窗口
            printf("czj --- create instance=%d \n", g_lInstance);
            g_nFlag = 0;
            break;
        case 2:
            WindowComponent_DestroyInstance(g_lInstance);//销毁窗口
            printf("czj --- destroy instance=%d \n", g_lInstance);
            g_nFlag = 0;
            break;
        case 3:
            bIsbreak = true;
            g_nFlag = 0;
            break;
        default:
            {//在线程中创建消息循环，每10毫秒从消息队列中获取windows消息并分发
                MSG msg;	
                while(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    // 转化键盘消息
                    ::TranslateMessage(&msg);
                    // 将消息发送到相应的窗口函数
                    ::DispatchMessage(&msg);
                }
            }
            g_nFlag = 0;
            break;
        }
        if (bIsbreak)
        {
            break;
        }
    }
    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int nRet = 0;
    
    nRet = WindowComponent_Init();

    printf("yaanipclic init ret=%d", nRet);

    unsigned int unThreadID = 0;
    //创建线程，处理命令及消息循环
    HANDLE g_hThread = (HANDLE)::_beginthreadex(NULL, 
        1024, ThreadFunction, NULL, CREATE_SUSPENDED, &unThreadID);
    if (g_hThread == NULL)
    {
        ::CloseHandle(g_hThread);
        g_hThread = NULL;
        return -1;
    }
    else
    {
        g_hEvnet = ::CreateEvent(NULL, FALSE, FALSE, NULL);
        ::ResumeThread(g_hThread);
    }

    printf("开始!\n");

    printf("按[q-退出,c-创建窗口,d-销毁窗口]!\n");

    while (true)
    {
        bool bIsbreak = false;
        char ckey = getchar();
        switch (ckey)
        {
        case 'c':
            g_nFlag = 1;
            ::SetEvent(g_hEvnet);
        	break;
        case 'd':
            g_nFlag = 2;
            ::SetEvent(g_hEvnet);
            break;
        case 'q':
            bIsbreak = true;
            g_nFlag = 3;
            ::SetEvent(g_hEvnet);
            break;
        default:
            break;
        }

        if (bIsbreak)
        {
            break;
        }
    }

    ::WaitForSingleObject(g_hThread, INFINITE);
    ::CloseHandle(g_hThread);
    g_hThread = NULL;
    
    nRet = WindowComponent_UnInit();
    return 0;
}

