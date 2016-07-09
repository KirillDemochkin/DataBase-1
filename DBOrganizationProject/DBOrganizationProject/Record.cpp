#include"stdafx.h"
void Record(FOLDER * CurrentFolder, FILE * file)
{
	if (CurrentFolder == NULL)
		return;
	fprintf(file, "%s\n\n%s\n\n", CurrentFolder->UpFolder->FolderName, CurrentFolder->FolderName);
	Record(CurrentFolder->NextFolder, file);
	Record(CurrentFolder->DownFolder, file);
}