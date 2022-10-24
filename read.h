//
// Created by Tao S on 10/18/2022.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef PROJET_READ_H
#define PROJET_READ_H

#define TEXT "test.txt"
#define MAX_LENGTH 290000

char** readLine(char**, int);

int GetArgFromLine(int, char**,char**,char**);

char* getWord(char*);

char* getType(char*);

#endif //PROJET_READ_H
