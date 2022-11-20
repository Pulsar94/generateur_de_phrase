//
// Projet Générateur de Phrase
// EFREI S3-L2 | 2022-2023
// Created by SOLAN Tao | ROUGAGNOU Marc | MENIN Thibaut
//

#ifndef TEST_TREE_RESEARCH_H
#define TEST_TREE_RESEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <time.h>

struct s_cell
{
    char value;
    struct s_cell *next;
};
typedef struct s_cell t_cell, *p_cell;

typedef struct s_std_list
{
    p_cell head;
} t_std_list, *p_t_std_list;

void sentence_model_1(tree, tree, tree);
void sentence_model_2(tree, tree, tree);
p_t_std_list research_word(tree);
int road_determination (pnode);
void letter_replacement(p_t_std_list, char);
p_t_std_list create_empty_std_list();
void create_cell(p_t_std_list, char);
void display_chaine(t_std_list);
void deleteList(p_t_std_list);

#endif //TEST_TREE_RESEARCH_H
