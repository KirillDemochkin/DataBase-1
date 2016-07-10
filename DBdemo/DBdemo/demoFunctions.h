#pragma once
#include "stdafx.h"
void Delete(FOLDER*); //+ удаление

FOLDER * DeleteFolders(FOLDER*);

void Record(FOLDER*, FILE*); //+ сохранение

FOLDER* InputTree(FOLDER **);
void Instruction();
char* GetName(FOLDER **);

void Instruction(); //?

struct folder* scanfile(FILE*); //+ загрузка

struct folder* findfolder(char* findname, FOLDER* beginf); //тоже поиск

void way(FOLDER*); //+ поиск
