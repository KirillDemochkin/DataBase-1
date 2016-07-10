// DBdemo.cpp : Defines the entry point for the console application.
//

#include "demoFunctions.h"

int main()
{
	FILE *fp;
	if ((fp = fopen("example.txt", "r")) == NULL) {
		printf("Can't open your file.\n");
		getch();
		exit(1);
	}
	FOLDER *pointer, *SearchFolder, *NewPointer;
	char str[20];
	printf("'scanfile'...\n");
	pointer = scanfile(fp);
	//printf("%s\n", pointer->FolderName);

	printf("\n'search' & 'delete'...");
	do{
		printf("\nEnter the name to delete:\n");
		scanf("%s", str);
		SearchFolder = findfolder(str, pointer);
		if (SearchFolder == NULL) printf("\nNot found.\n");
	} while (SearchFolder == NULL);
	Delete(SearchFolder);

	printf("\n'record'...\n");
	fp = fopen("check_delete.txt", "w");
	Record(pointer->DownFolder, fp);

	printf("\n'search' & 'insert'...");
	do{
		printf("\nEnter the name to insert : \n");
		scanf("%s", str);
		SearchFolder = findfolder(str, pointer);
		if (SearchFolder == NULL) printf("\nNot found.\n");
	} while (SearchFolder == NULL);
	printf("\nEnter the new name:\n");
	scanf("%s", str);
	NewPointer = InputTree(&SearchFolder, str);

	printf("\n'record'...\n");
	fp = fopen("check_insert.txt", "w");
	Record(pointer->DownFolder, fp);
	getch();
}

