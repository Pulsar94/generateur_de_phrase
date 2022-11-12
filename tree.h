//
// Created by Marc on 24/10/2022.
//

#ifndef READ_C_TREE_H
#define READ_C_TREE_H

#include <stdio.h>
#include <stdlib.h>

/* Structures */

struct pn{ // noeud
    struct pn* left;
    struct pn* right;
    char value;
    int type;
};

typedef struct pn s_pn, *pnode;

struct tr{ // arbre
    pnode root;
};

typedef struct tr s_tr, *tree;

/* Fonctions */

pnode create_node();
tree create_tree();
int add_word(pnode,char*,int);
int add_letter(pnode, char);
pnode find_letter_right(pnode,char);

#endif //READ_C_TREE_H
