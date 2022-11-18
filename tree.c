//
// Created by Marc on 24/10/2022.
//
#include "tree.h"
pnode create_node(){
    pnode pn=malloc(sizeof(s_pn));
    pn->left=NULL; pn->right=NULL;
    pn->value='\0';
    pn->type=0;
    pn->conj=InitConj();
    return pn;
}

tree create_tree(){
    tree tr;
    tr= malloc(sizeof(tree));
    tr->root=create_node();
    return tr;
}


int add_word(pnode pn,char* word, int num, char* type, char* flech){ // num taille logique char
    char letter;
    pnode next;
    for (int i=0;i<num;i++){ // boucle en fonction de la tail du mot
        letter=word[i];
        add_letter(pn,letter);
        next=find_letter_right(pn,letter);
        if (next->left==NULL){
            next->left=create_node();
        }
        if (i==num-1){
            pn->type=1;
            AddConj(pn->conj,flech,type);
        }
        pn=next->left;
    }
    return 1;
}

// on ne peut pas ajouter direct fils gauche il faut créer et relier
int add_letter(pnode pn, char letter){ // normalement fonctionne
    if (pn!=NULL){
        if (pn->value=='\0'){
            pn->value=letter;
            return 1;
        }
    }
    pnode find=find_letter_right(pn,letter);
    if (find==NULL){
        pnode rg;
        rg=create_node();
        rg->value=letter;
        rg->right=pn->right;
        pn->right=rg;
        return 1;
    }
    return 0;
}

pnode find_letter_right(pnode pn, char letter){// normalement fonctionne
    if (pn==NULL){//ne regarde pas si la lettre existe déjà
        return NULL;
    }
    if(pn->value==letter){
        return pn;
    }
    pnode temp;
    temp=find_letter_right(pn->right,letter);
    return temp;
}
