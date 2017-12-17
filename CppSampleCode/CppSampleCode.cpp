// CppSampleCode.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

// ファイルリストクラス
// 
class FileList {
public:
	// ファイルリストを出力する
	void outputFileList();

	void outputFileList(LPCTSTR basePath);
};

void FileList::outputFileList() {
	// 検索ベースパス
	LPCTSTR basePath = _T("C:\\Data\\Download\\Image\\*.*");
	
	FileList fileList;

	fileList.outputFileList(basePath);
}

void FileList::outputFileList(LPCTSTR basePath) {
	// 検索ハンドラ
	HANDLE hFind;
	// データバッファ
	WIN32_FIND_DATA fd;

	// ベースパスの出力
	_tprintf(_T("%s\n"), basePath);

	// 検索実行
	hFind = FindFirstFile(basePath, &fd);
	do {

		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("%s (DIR)\n", fd.cFileName);
		}
		else {
			printf("%s\n", fd.cFileName);
		}

	} while (FindNextFile(hFind, &fd));
}


int main()
{
	// ファイルリストオブジェクト作成
	FileList fileList;
	// ファイルリスト出力
	fileList.outputFileList();
	fileList.outputFileList(_T("C:\\*.*"));
	//入力待ち
	getchar();

	return 0;
}