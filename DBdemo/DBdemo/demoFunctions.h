#pragma once
#include "stdafx.h"
void Delete(FOLDER*); //+ удаление

FOLDER * DeleteFolders(FOLDER*);

void Record(FOLDER*, FILE*); //+ сохранение

void Instruction();
char* GetName(FOLDER **);
FOLDER* InputTree(FOLDER**, char*); //+ создание

struct folder* scanfile(FILE*); //+ загрузка

struct folder* findfolder(char* findname, FOLDER* beginf); //тоже поиск

void way(FOLDER*); //+ поиск
