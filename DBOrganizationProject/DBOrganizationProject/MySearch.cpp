#include <string.h>

typedef enum TYPE{ None, Int, Float, Double, Bool, Character }TYPE;

typedef struct Sweets
{
	//TYPE type = None;
	union
	{
		int Integer;
		float Float;
		double Double;
		bool Bool;
		char Character;
	}Candy;
	Sweets * NextCandy;
}Sweets;

typedef struct Box
{
	char BoxName[20];
	int level;
	Box * FatherBox;
	Box * NextBox;
	Box * PreviousBox;
	Box * BoxIn;
	Sweets * Candies;
}Box;

Box *MySearch(char *str, Box *pointer)
{
	if (strcmp(pointer->BoxName, str) == 0) return pointer;
	else
	{
		Box *ptr = NULL;
		if (pointer->NextBox != NULL)
		{
			ptr = MySearch(str, pointer->NextBox);
			if (ptr != pointer) return ptr;
		}
		if (pointer->BoxIn != NULL)
		{
			ptr = MySearch(str, pointer->BoxIn);
			if (ptr != pointer) return ptr;
			else if (pointer->PreviousBox != NULL)return pointer->PreviousBox;
			else if (pointer->FatherBox != NULL)return pointer->FatherBox;
			else return NULL;
		}
		else if (pointer->PreviousBox != NULL)return pointer->PreviousBox;
		else if (pointer->FatherBox != NULL)return pointer->FatherBox;
		else return NULL;
	}
}