//
// Projet Générateur de Phrase
// EFREI S3-L2 | 2022-2023
// Created by SOLAN Tao | ROUGAGNOU Marc | MENIN Thibaut
//

#ifndef READ_C_TREE_H
#define READ_C_TREE_H

#include <stdio.h>
#include <stdlib.h>

/* Structures */

typedef struct s_conj{ //conj
    char* values[200];
    int length;
}t_conj,*p_conj;

struct pn{ // noeud
    struct pn* left;
    struct pn* right;
    char value;
    int type;
    p_conj conj;
};
typedef struct pn s_pn, *pnode;

struct tr{ // arbre
    pnode root;
};
typedef struct tr s_tr, *tree;

/* Fonctions */

p_conj InitConj();
void AddConj(p_conj, char *, char*);
pnode create_node();
tree create_tree();
int add_word(pnode,char*,int,char*,char*);
int add_letter(pnode, char);
pnode find_letter_right(pnode,char);

#endif //READ_C_TREE_H
