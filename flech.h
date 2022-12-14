//
// Projet Générateur de Phrase
// EFREI S3-L2 | 2022-2023
// Created by SOLAN Tao | ROUGAGNOU Marc | MENIN Thibaut
//

#ifndef MAIN_C_FLECH_H
#define MAIN_C_FLECH_H
#include "stdlib.h"
#include "stdio.h"
#include "tree_research.h"

//Prototyping

int CountTwoTypeMatch(char*, char*);
int GetHighestMatch(char*, p_conj);
void printConj(p_conj);
int ContainChar(char*,char*);
pnode research_flech(tree);
char* research_word_flech(tree,int,int);

void sentence_fleched_model_1(tree, tree, tree);
void sentence_fleched_model_2(tree, tree, tree);
void sentence_fleched_model_3(tree, tree, tree);

#endif //MAIN_C_FLECH_H
