//
// Created by Marc on 24/10/2022.
//
#include "tree.h"

p_conj InitConj(){
    p_conj new =(p_conj) malloc(sizeof(t_conj)*1);
    new->length = 0;
    return new;
}

void AddConj(p_conj conj,char *word_to_add, char *type_to_add){

    conj->values[conj->length] = word_to_add;
    conj->length++;
    conj->values[conj->length] = type_to_add;
    conj->length++;
    if(conj->length>1){
        //printf("%s\n",word_to_add);
        //printf("%d\n",conj->length);
    }
    //printf("%s\n",to_add);

}

pnode create_node(){ // Création d'un nœud avec allocation de la mémoire nécessaire. Nous renvoyions l'adresse du nœud.
    pnode pn=malloc(sizeof(s_pn));
    pn->left=NULL; pn->right=NULL;
    pn->value='\0';
    pn->type=0; // déclaration de la valeur à un caractère qui ne peut pas se retrouver dans un mot
    pn->conj=InitConj();
    return pn;
}

tree create_tree(){ // Création d'un arbre avec allocation de la mémoire nécessaire. Nous renvoyions l'adresse de l'arbre.
    tree tr;
    tr=malloc(sizeof(tree));
    tr->root=create_node();
    return tr;
}


int add_word(pnode pn,char* word, int num, char* type, char* flech){ // Ajout d'un mot (entièrement) à un nœud donné. La taille du mot est précisée dans les paramètres.
    char letter;
    pnode next;

    for (int i=0;i<num;i++){ // boucle en fonction de la tail du mot
        letter=word[i];
        add_letter(pn,letter);
        next=find_letter_right(pn,letter); // vérifie si la lettre n'est pas déjà implémentée pour éviter des doublons
        if (next->left==NULL){
            next->left=create_node();
        }
        if (i==num-1){
            pn->type=1; // annonce la fin du mot et change donc la variable 'type' pour faciliter ultérieurement la recherche dans l'arbre
            AddConj(pn->conj,flech,type);
            //printConj(pn->conj);
        }
        pn=next->left;
    }

    return 1;// informe que le mot est bien ajouté
}

int add_letter(pnode pn, char letter){ // Ajout d'un caractère à un nœud donné en paramètre.
    if (pn!=NULL){
        if (pn->value=='\0'){
            pn->value=letter;
            return 1; // informe que la lettre a bien été ajouté
        }
    }
    pnode find=find_letter_right(pn,letter); // utilisation de la fonction précédente
    if (find==NULL){ // on ajoute au fils droit s'il n'y est pas déjà
        pnode rg;
        rg=create_node();
        rg->value=letter;
        rg->right=pn->right;
        pn->right=rg;
        return 1; // informe que la lettre a bien été ajouté
    }
    return 0;
}

pnode find_letter_right(pnode pn, char letter){// Recherche dans les fils droits du nœud donné en paramètre si la lettre voulu s'y trouve
    if (pn==NULL){ // vérifie si le nœud demandé est défini
        return NULL;
    }
    if(pn->value==letter){ // condition pour vérifier si la valeur du caractère est le même que la lettre donnée en paramètre
        return pn;
    }
    pnode temp;
    temp=find_letter_right(pn->right,letter); // recherche récursive dans les fils droits du nœud initial
    return temp;
}
