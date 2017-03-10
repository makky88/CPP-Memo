# CPP-Memo
Memo lại những thông tin đã tra cứu về CPP/VCPP/MFC

## Các phương pháp lấy current time trong C++
### MFC COleDateTime Class
```cpp
COleDateTime COleDateTime::GetCurrentTime()
```

### Win API GetLocalTime
```cpp
VOID GetLocalTime(LPSYSTEMTIME lpSystemTime   // System Time);
```

### timeGetTime,timeBeginPeriod,time
```cpp
DWORD timeGetTime(VOID);
MMRESULT timeBeginPeriod(UINT uPeriod );
MMRESULT timeEndPeriod(UINT uPeriod );
```
### QueryPerformanceCounter
```cpp
BOOL QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount   // Count Number);
```

