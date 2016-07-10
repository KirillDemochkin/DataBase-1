// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

FOLDER *MainFolder = NULL;
typedef enum TYPE
{
	None,
	Int,
	Float,
	Double,
	Bool,
	Character
}TYPE;

typedef struct keys
{
	// TYPE type = None;
	union
	{
		int Integer;
		float Float;
		double Double;
		bool Bool;
		char Character;
	}Value;
	struct keys* NextKey;
}KEYS;

typedef struct folder
{
	char FolderName[255];
	int level;
	struct folder* UpFolder;
	struct folder* PreviousFolder;
	struct folder* NextFolder;
	struct folder* DownFolder;
	struct keys * Values;
}FOLDER;


