#include <stdio.h>
#include <tchar.h>
#include <afx.h>
#include <afxwin.h>    
#include <afxext.h>    
#include <afxcmn.h>
#include <afxdtctl.h>
#include <iostream>

//timeGetTime: Header file mmsystem.h, lib file: winmm.lib
#include <mmsystem.h>

using namespace std;

void GetCurrentDateTimeDemo()
{
	//COleDateTime Class
	COleDateTime dtCurrent = COleDateTime::GetCurrentTime();
	cout << "COleDateTime Current DateTime: " << dtCurrent.Format("%Y/%m/%d %H:%M:%S") << endl;

	//GetLocalTime
	SYSTEMTIME tmCurrent;
	::GetLocalTime(&tmCurrent);
	CString strCurrentTime = "";
	strCurrentTime.Format("%4d/%2d/%2d %2d:%2d:%2d.%3d",tmCurrent.wYear, tmCurrent.wMonth, tmCurrent.wDay, tmCurrent.wHour, tmCurrent.wMinute, tmCurrent.wSecond, tmCurrent.wMilliseconds);
	cout << "GetLocalTime Current DateTime: " << strCurrentTime << endl;

	//timeGetTime
	//Set time unit to 1ms
	timeBeginPeriod(1);
	DWORD dwCurrentTime = timeGetTime();
	timeEndPeriod(1);
	cout << "timeGetTime Current Time: " << dwCurrentTime << endl;

	//QueryPerformanceCounter
	LARGE_INTEGER li;
	if (FALSE == QueryPerformanceFrequency(&li))
	{
		cout << "CPU does not support PerformanceCounter" << endl;
		return;
	}

	double PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	__int64 CounterStart = li.QuadPart;

	Sleep(100);

	QueryPerformanceCounter(&li);
	double timeCount = double(li.QuadPart - CounterStart) / PCFreq;

	cout << "QueryPerformanceCounter Time Count: " << timeCount << endl;
}
