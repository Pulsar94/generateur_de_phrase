//
// Created by Tao S on 10/18/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROJET_READ_H
#define PROJET_READ_H

#define TEXT "dictionnaire_projet_C.txt"
#define TEXT_LENGTH 287976

//String struct
struct string{
    char values[100];
    int num;
};
typedef struct string *p_string,t_string;

//Dictionary struct
struct dictionary{
    char word[100]; //ex: escroquerait
    int num1;

    char word2[100]; //ex: escroquer
    int num2;

    char type[100]; //ex: Ver:CPre+SG+P3
    int num3;
};
typedef struct dictionary *p_dic,t_dic;

//p_str struct management
p_string InitString(int);
void ChangeStringValue(p_string, char*);
void ShowString(p_string);

//p_dic struct management
p_dic InitDic();
void ChangeDicValue(p_dic, char*, int);
void ShowDic(p_dic);

//file struct management
p_dic InsertIntoDic(p_dic, p_string);
p_string readLine(FILE*);
p_dic GetArgFromLine(int,FILE*);
int GetType(p_dic);

#endif //PROJET_READ_H
