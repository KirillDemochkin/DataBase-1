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
	FOLDER *pointer, *SearchFolder;
	char str[20];
	printf("'scanfile'...\n");
	pointer = scanfile(fp);
	printf("%s\n", pointer->FolderName);
	printf("'search & delete'...\nEnter the name to delete:\n");
	scanf("%s", str);
	SearchFolder = findfolder(str, pointer);
	Delete(SearchFolder);
	printf("'record'...\n");
	fp = fopen("check_delete.txt", "w");
	Record(pointer->DownFolder, fp);
	printf("'search & delete'...\nEnter the name to insert:\n");
	scanf("%s", str);
	SearchFolder = findfolder(str, pointer);

	getch();
}

