// CheckPIDDll.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "pch.h"
#include <msi.h>
#include <msiquery.h>
#include <tchar.h>

#pragma comment(lib, "msi")

UINT __stdcall VerifyPID(MSIHANDLE hInstall)
{
	// Local variables
	TCHAR szPidKey[MAX_PATH] = { 0, };
	DWORD dwBuffer = sizeof(szPidKey) / sizeof(TCHAR);

	// Get the PIDKEY property
	if (ERROR_SUCCESS != MsiGetProperty(hInstall, TEXT("PIDKEY"), szPidKey, &dwBuffer))
	{
		MessageBox(NULL, _T("PIDKEY"), _T("Not able to retrieve PIDKEY property"),
			MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	// do something ...
	// pid key check alghrithm ...
	// .......

	//If PIDKEY passes check (simple example)
	if (lstrcmp(szPidKey, _T("123-4567890")) == 0)
	{
		MsiSetProperty(hInstall, _T("PIDCHECK"), _T("TRUE"));//PIDKEY passes check
	}
	else
	{
		//PIDKEY doesn't pass check
		MsiSetProperty(hInstall, _T("PIDCHECK"), _T("FALSE"));
		MessageBox(NULL, _T("serial number is not valid."), _T("Installer"),
			MB_OK | MB_ICONINFORMATION);
	}

	return 0;
}