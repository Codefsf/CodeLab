/*#include <iostream>
#include <windows.h>
using namespace std;

#define BUF_SIZE (1024 * 1024 * 10)
char szName[] = "NameOfMappingObject";    // �����ڴ������

int testFileMapping()
{
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // �����ļ����
		NULL,                    // Ĭ�ϰ�ȫ����
		PAGE_READWRITE,          // �ɶ���д
		0,                       // ��λ�ļ���С
		BUF_SIZE,                // ��λ�ļ���С
		szName                   // �����ڴ�����
	);


	char *pBuf = (char *)MapViewOfFile(
		hMapFile,            // �����ڴ�ľ��
		FILE_MAP_ALL_ACCESS, // �ɶ�д���
		0,
		0,
		BUF_SIZE
	);

	memset(pBuf, 0, BUF_SIZE);		

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	return 0;
}*/