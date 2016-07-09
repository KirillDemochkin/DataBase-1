#include "stdafx.h"

FOLDER *MySearch(char *str, FOLDER *pointer)
{
	if (strcmp(pointer->FolderName, str) == 0) return pointer;
	else
	{
		FOLDER *ptr = NULL;
		if (pointer->NextFolder != NULL)
		{
			ptr = MySearch(str, pointer->NextFolder);
			if (ptr != pointer) return ptr;
		}
		if (pointer->DownFolder != NULL)
		{
			ptr = MySearch(str, pointer->DownFolder);
			if (ptr != pointer) return ptr;
			else if (pointer->PreviousFolder != NULL)return pointer->PreviousFolder;
			else if (pointer->UpFolder != NULL)return pointer->UpFolder;
			else return NULL;
		}
		else if (pointer->PreviousFolder != NULL)return pointer->PreviousFolder;
		else if (pointer->UpFolder != NULL)return pointer->UpFolder;
		else return NULL;
	}
}