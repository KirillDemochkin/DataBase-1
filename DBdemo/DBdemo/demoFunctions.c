#include "demoFunctions.h"
void Delete(FOLDER * CurrentFolder)
{
	if (CurrentFolder->DownFolder)
		CurrentFolder->DownFolder = DeleteFolders(CurrentFolder->DownFolder);
	printf("%s deleted\n", CurrentFolder->FolderName);
	if (CurrentFolder->PreviousFolder && CurrentFolder->NextFolder)
	{
		CurrentFolder->PreviousFolder->NextFolder = CurrentFolder->NextFolder;
		CurrentFolder->NextFolder->PreviousFolder = CurrentFolder->PreviousFolder;
		free(CurrentFolder);
	}
	else if (CurrentFolder->PreviousFolder)
	{
		CurrentFolder->PreviousFolder->NextFolder = NULL;
		free(CurrentFolder);
	}
	else if (CurrentFolder->NextFolder)
	{
		CurrentFolder->UpFolder->DownFolder = CurrentFolder->NextFolder;
		free(CurrentFolder);
	}
	else if (CurrentFolder->UpFolder)
	{
		CurrentFolder->UpFolder->DownFolder = NULL;
		free(CurrentFolder);
	}
	else
	{
		free(CurrentFolder);
		MainFolder = NULL;
	}
}

FOLDER * DeleteFolders(FOLDER * CurrentFolder)
{
	if (CurrentFolder == NULL)
		return NULL;
	CurrentFolder->NextFolder = DeleteFolders(CurrentFolder->NextFolder);
	CurrentFolder->DownFolder = DeleteFolders(CurrentFolder->DownFolder);
	free(CurrentFolder);
	return NULL;
}

void Record(FOLDER * CurrentFolder, FILE * file)
{
	if (CurrentFolder == NULL)
		return;
	fprintf(file, "%s\n\n%s\n\n", CurrentFolder->UpFolder->FolderName, CurrentFolder->FolderName);
	Record(CurrentFolder->NextFolder, file);
	Record(CurrentFolder->DownFolder, file);
}
char* GetName(FOLDER **currPtr){
	bool flag = 0;
	char buf[256], p = '/';
	char *newname;
	int c;

	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	do
	{
		Instruction();
		flag = 0;
		c = 0;
		puts("Please enter a filename for the new folder:");
		fgets(buf, 256, stdin);
		if (buf[254] == '\n')
			c = strlen(buf) - 1;
		else
			c = strlen(buf);
		while (temp != NULL)
		{
			if (strcmp(buf, temp->FolderName) == 0)
			{
				puts("Error! Folder with this name already exists");
				flag = 1;
			}
			temp = temp->NextFolder;
		}
		if (c == 255) 
		{
			puts("Error! File names seem to be limited to less than 254 characters");
			flag = 1;
			while (buf[254] != NULL)
			{
				buf[254] = NULL;
				fgets(buf, 256, stdin);
			}
		}
		else
		{
			if (strchr(buf, p) != 0) 
			{
				puts("Error! The folder name specified contains character that is not permitted: '/'");
				flag = 1;
			}
			else
			{
				if (c == 1) 
				{
					puts("Error! The folder name cannot be empty");
					flag = 1;
				}
			}
		}
	} while (flag != 0); 
	newname = (char*)malloc(sizeof(char)*(c + 1));
	strcpy(newname, buf);
	return(newname);
}

void Instruction()
{
	puts("Warning!");
	puts("1. The folder name cannot be empty");
	puts("2. The folder name cannot be less than 1 character or more than 255 characters");
	puts("3. The folder name cannot coitain '/' character");
}
void Delete(FOLDER * CurrentFolder)
{
	if (CurrentFolder->DownFolder)
		CurrentFolder->DownFolder = DeleteFolders(CurrentFolder->DownFolder);
	printf("%s deleted\n", CurrentFolder->FolderName);
	if (CurrentFolder->PreviousFolder && CurrentFolder->NextFolder)
	{
		CurrentFolder->PreviousFolder->NextFolder = CurrentFolder->NextFolder;
		CurrentFolder->NextFolder->PreviousFolder = CurrentFolder->PreviousFolder;
		free(CurrentFolder);
	}
	else if (CurrentFolder->PreviousFolder)
	{
		CurrentFolder->PreviousFolder->NextFolder = NULL;
		free(CurrentFolder);
	}
	else if (CurrentFolder->NextFolder)
	{
		CurrentFolder->UpFolder->DownFolder = CurrentFolder->NextFolder;
		free(CurrentFolder);
	}
	else if (CurrentFolder->UpFolder)
	{
		CurrentFolder->UpFolder->DownFolder = NULL;
		free(CurrentFolder);
	}
	else
	{
		free(CurrentFolder);
		MainFolder = NULL;
	}
}

FOLDER * DeleteFolders(FOLDER * CurrentFolder)
{
	if (CurrentFolder == NULL)
		return NULL;
	CurrentFolder->NextFolder = DeleteFolders(CurrentFolder->NextFolder);
	CurrentFolder->DownFolder = DeleteFolders(CurrentFolder->DownFolder);
	free(CurrentFolder);
	return NULL;
}

void Record(FOLDER * CurrentFolder, FILE * file)
{
	if (CurrentFolder == NULL)
		return;
	fprintf(file, "%s\n\n%s\n\n", CurrentFolder->UpFolder->FolderName, CurrentFolder->FolderName);
	Record(CurrentFolder->NextFolder, file);
	Record(CurrentFolder->DownFolder, file);
}

char* GetName(FOLDER **currPtr){
	bool flag = 0;
	char buf[256], p = '/';
	char *newname;
	int c;

	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	do
	{
		Instruction();
		flag = 0;
		c = 0;
		puts("Please enter a filename for the new folder:");
		fgets(buf, 256, stdin);
		if (buf[254] == '\n')
			c = strlen(buf) - 1;
		else
			c = strlen(buf);
		while (temp != NULL)
		{
			if (strcmp(buf, temp->FolderName) == 0)
			{
				puts("Error! Folder with this name already exists");
				flag = 1;
			}
			temp = temp->NextFolder;
		}
		if (c == 255)
		{
			puts("Error! File names seem to be limited to less than 254 characters");
			flag = 1;
			while (buf[254] != NULL)
			{
				buf[254] = NULL;
				fgets(buf, 256, stdin);
			}
		}
		else
		{
			if (strchr(buf, p) != 0)
			{
				puts("Error! The folder name specified contains character that is not permitted: '/'");
				flag = 1;
			}
			else
			{
				if (c == 1)
				{
					puts("Error! The folder name cannot be empty");
					flag = 1;
				}
			}
		}
	} while (flag != 0);
	newname = (char*)malloc(sizeof(char)*(c + 1));
	strcpy(newname, buf);
	return(newname);
}
void Instruction()
{
	puts("Warning!");
	puts("1. The folder name cannot be empty");
	puts("2. The folder name cannot be less than 1 character or more than 255 characters");
	puts("3. The folder name cannot coitain '/' character");
}
FOLDER* InputTree(FOLDER **currPtr, char *newname)
{
	FOLDER *childPtr = NULL;
	childPtr = (*currPtr)->DownFolder;
	FOLDER *temp = NULL;
	if ((*currPtr)->DownFolder != NULL) temp = childPtr;
	FOLDER *newPtr = NULL;
	newPtr = (FOLDER*)malloc(sizeof(FOLDER));
	if (newPtr == NULL){
		printf("No memory available \n");
		return(NULL);
	}
	strcpy(newPtr->FolderName, newname);
	newPtr->UpFolder = *currPtr;
	newPtr->DownFolder = NULL;
	newPtr->Values = NULL;
	if (childPtr != NULL)
	{
		newPtr->NextFolder = childPtr;
		(childPtr)->PreviousFolder = newPtr;
	}
	else
	{
		newPtr->NextFolder = NULL;
	}
	newPtr->PreviousFolder = NULL;
	(*currPtr)->DownFolder = newPtr;
	return(newPtr);
}

struct folder* scanfile(FILE* dat)
{
	FOLDER * root = (FOLDER*)malloc(sizeof(FOLDER));
	root->UpFolder = NULL;
	root->NextFolder = NULL;
	root->PreviousFolder = NULL;
	root->DownFolder = NULL;
	//memset(root->FolderName, 0, 20);
	if (dat == NULL)
		return root;

	root->DownFolder = (FOLDER*)malloc(sizeof(FOLDER));
	root->DownFolder->UpFolder = root;
	root->DownFolder->NextFolder = NULL;
	root->DownFolder->PreviousFolder = NULL;
	root->DownFolder->DownFolder = NULL;
	//memset(root->DownFolder->FolderName, 0, 20);

	fscanf(dat, "%s\n\n%s\n\n", root->FolderName, root->DownFolder->FolderName);
	printf("%s=>%s  Begin\n", root->FolderName, root->DownFolder->FolderName);
	if (strcmp(root->FolderName, "") == 0) {
		printf("\nRead error or file is empty\nCreated new data base...\n");
		return root;
	}

	char Father[20];
	char Child[20];
	FOLDER * buf = root;
	FOLDER * children;
	FOLDER * ggwp;
	int check = 0;
	//!!!BEGIN!!!
	while (!feof(dat)) {
		//memset(Father, 0, 20);
		//memset(Child, 0, 20);
		fscanf(dat, "%s\n\n%s\n\n", Father, Child);
		printf("%s=>%s  ", Father, Child);
		if (strcmp(Father, "") == 0)
			return root;
		children = buf->DownFolder;

		if (strcmp(buf->FolderName, Father) == 0) {//Ищем по отцу
			printf("Father\n");
			while (children != NULL) {
				++check;
				ggwp = children;
				children = children->NextFolder;
			}
			if (children == NULL) {
				children = (FOLDER*)malloc(sizeof(FOLDER));
				children->UpFolder = buf;
				children->NextFolder = NULL;
				children->DownFolder = NULL;
				//memset(children->FolderName, 0, 20);
				strcpy(children->FolderName, Child);
				if (check == 0) {
					buf->DownFolder = children;
					children->PreviousFolder = NULL;
				}
				else {
					ggwp->NextFolder = children;
					children->PreviousFolder = ggwp;
				}
				continue;
			}
		}

		check = 1;
		while (1) {//ищем по детям
			if (children == NULL) {
				break;
			}
			if (strcmp(children->FolderName, Father) == 0) {
				printf("Children\n");
				children->DownFolder = (FOLDER*)malloc(sizeof(FOLDER));
				children->DownFolder->UpFolder = children;
				children->DownFolder->NextFolder = NULL;
				children->DownFolder->PreviousFolder = NULL;
				children->DownFolder->DownFolder = NULL;
				//memset(children->DownFolder->FolderName, 0, 20);
				strcpy(children->DownFolder->FolderName, Child);

				buf = children;
				check = 0;
			}
			children = children->NextFolder;
		}

		if (check == 1) {
			//Поиск по всему дереву
			check = 0;
			printf("Find\n");
			ggwp = findfolder(Father, root);
			buf = ggwp;
			children = buf->DownFolder;

			children = (FOLDER*)malloc(sizeof(FOLDER));
			children->UpFolder = buf;
			children->NextFolder = NULL;
			children->PreviousFolder = NULL;
			children->DownFolder = NULL;
			//memset(children->FolderName, 0, 20);
			strcpy(children->FolderName, Child);
			buf->DownFolder = children;

		}
	}
	return root;
}

struct folder* findfolder(char* findname, struct folder* beginf)//Поиск файлов с помощью рекурсии
{
	struct folder* buf = NULL;
	char YN[2];
	strcat(YN, "Y");
	if (strcmp(beginf->FolderName, findname) == 0)//Идёт сравнение
	{
		//way(beginf);
		//printf("    Continue searching? Y/N: ");
		//scanf("%s", YN);
		//if (strcmp(YN, "N") == 0)
		//{
		//	memset(YN, 0, 2);
		//	return(beginf);
		//}
		return(beginf);
	}
	beginf = beginf->DownFolder;
	if (beginf != NULL)
		while (beginf != NULL)//Проходимся по каждому брату(NextFolder)
		{
			buf = findfolder(findname, beginf);
			if (buf != NULL)//Требуется, для возварата значения при отказе дальнейшего поиска
				return(buf);
			beginf = beginf->NextFolder;
		}

	return(NULL);
}
