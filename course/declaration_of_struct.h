#ifndef STRUCTDECLARATION
#define STRUCTDECLARATION
#include<wchar.h>

struct Sentence{
	wchar_t *sent;
	unsigned int size;
	unsigned long int multi;
	int digit;
	int symb;
	int replays;
};

struct Text{
	struct Sentence **array_of_sent;
	unsigned int size;
};

#endif
