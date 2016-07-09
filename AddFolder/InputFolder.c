#include "stdafx.h"

void InputTree(FOLDER **currPtr, char *newname)
{
	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	FOLDER *newPtr = NULL;
	newPtr = (FOLDER*)malloc(sizeof(FOLDER));//������� ����� ���������(�����)
	if (newPtr == NULL){
		printf("No memory available \n");
		return;
	}
	newPtr->FolderName = newname; //����� �������� �������� ������(���, ��������� �� ������, ��������� �� �������, �� ��������� NULL)
	newPtr->UpFolder = *currPtr;
	newPtr->DownFolder = NULL;
	newPtr->Values = NULL;
	if (childPtr != NULL)
	{
		newPtr->NextFolder = childPtr;//���������� ����� ���� � ������
		(childPtr)->PreviousFolder = newPtr;//� ������ � ����� ����
	}
	else
	{
		newPtr->NextFolder = NULL;
	}
	newPtr->PreviousFolder = NULL;
	(*currPtr)->DownFolder = newPtr;//���������� ����� ���� � ������
}//����� ����������� ���������� ����� ���������
