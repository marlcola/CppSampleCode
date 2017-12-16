// CppSampleCode.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>

int main()
{

	HANDLE hFind;

	WIN32_FIND_DATA fd;


	hFind = FindFirstFile(_T("C:\\Data\\Download\\Image\\*.*"), &fd);

	do {

		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("%s (DIR)\n", fd.cFileName);
		}
		else {
			printf("%s\n", fd.cFileName);
		}


	} while (FindNextFile(hFind, &fd));

	return 0;
}


