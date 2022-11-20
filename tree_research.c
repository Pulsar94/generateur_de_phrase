//
// Projet Générateur de Phrase
// EFREI S3-L2 | 2022-2023
// Created by SOLAN Tao | ROUGAGNOU Marc | MENIN Thibaut
//

#include "tree_research.h"

void sentence_model_1(tree tree_name, tree tree_adjective, tree tree_verb){ //formation de la phrase suivant le modèle 1 avec les formes de base
    p_t_std_list name = research_word(tree_name);
    p_t_std_list name2 = research_word(tree_name);
    p_t_std_list adjective = research_word(tree_adjective);
    p_t_std_list verb = research_word(tree_verb);

    display_chaine(*name);
    display_chaine(*adjective);
    display_chaine(*verb);
    display_chaine(*name2);
    printf("\n");

    deleteList(name);
    deleteList(adjective);
    deleteList(verb);
    deleteList(name2);
}

void sentence_model_2(tree tree_name, tree tree_adjective, tree tree_verb){ //formation de la phrase suivant le modèle 2 avec les formes de base
    p_t_std_list name = research_word(tree_name);
    p_t_std_list name2 = research_word(tree_name);
    p_t_std_list adjective = research_word(tree_adjective);
    p_t_std_list verb = research_word(tree_verb);
    p_t_std_list verb2 = research_word(tree_verb);

    display_chaine(*name);
    printf("qui ");
    display_chaine(*verb);
    display_chaine(*verb2);
    display_chaine(*name2);
    display_chaine(*adjective);
    printf("\n");

    deleteList(name);
    deleteList(name2);
    deleteList(adjective);
    deleteList(verb);
    deleteList(verb2);
}

p_t_std_list research_word(tree tree_word){ //fonction principale qui appel toutes les autres fonctions pour rechercher un mot dans l'arbre
    int choice;
    // choice = 0 ==> go on right
    // choice = 1 ==> stop on the node because it's a word
    // choice = 2 ==> go on left
    pnode temp = tree_word->root;
    p_t_std_list word = create_empty_std_list();
    create_cell(word, temp->value);
    do {
        choice = road_determination(temp);
        if (choice == 0){ // right and conservation value in the list
            temp = temp->right;
            letter_replacement(word, temp->value);
            //create_cell(word, temp->value);
        } else {
            if (choice == 2){ // left et remplacement de la valeur dans la file
                temp = temp->left;
                create_cell(word, temp->value);
            }
        }
    } while (choice != 1); // if choice == 1 no action is require. Quit the loop and the word is already in the list
    return word;
}

int road_determination (pnode temp){ //permet de décider grâce au hasard si on va dans le fils droit, gauche ou si on s'arrête sur le mot s'il en existe un
    int choice = -1;
    // choice = 0 ==> go on right
    // choice = 1 ==> stop on the node because it's a word
    // choice = 2 ==> go on left
    do{
        int randed = rand()%((rand()%50)+20); //the best randomisation is when you randomise the randomisation

        if(temp->right==NULL && temp->left != NULL){ choice = 2; }
        if(randed==1 && temp->left != NULL){ choice = 2; }
        if(randed>1 && temp->right != NULL){ choice = 0; }
        if(randed==0 && temp->type){ choice = 1; }
        if(temp->right==NULL && temp->left == NULL){ choice = 1;}
    }while(choice==-1);
    return choice;
}

void letter_replacement(p_t_std_list word, char letter){ //si on va dans le fils droit dans l'arbre, alors la lettre précédemment stockée dans la file de recherche est supprimée
    p_cell temp = word->head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->value = letter;
}

p_t_std_list create_empty_std_list(){ //création de la liste vide pour recueillir le mot en cours de recherche
    p_t_std_list new = (p_t_std_list) malloc(sizeof (t_std_list));
    new->head = NULL;
    return new;
}

void create_cell (p_t_std_list mylist, char val){ //création d'une cellule dans la liste chainée pour ajouter une lettre afin de composer le mot
    p_cell maillon = (p_cell) malloc(sizeof (t_cell));
    p_cell temp = mylist->head;
    maillon->value = val;
    maillon->next = NULL;
    if (mylist->head == NULL){
        mylist->head = maillon;
    } else {
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = maillon;
    }
}

void display_chaine(t_std_list word){ //affichage de la liste chainée contenant le mot
    p_cell temp = word.head;
    if (temp == NULL){
        printf("NULL\n");
    } else {
        while (temp != NULL){
            printf("%c", temp->value);
            temp = temp->next;
        }
        printf(" ");
    }
}

void deleteList(p_t_std_list p_list){ //suppression sécurisée de la list chainée contenant le mot
    p_cell prev ,temp;
    temp = p_list->head ;
    prev = temp;
    while (temp  != NULL ){
        temp = temp->next ;
        free(prev) ;
        prev = temp;
    }
    p_list->head  = NULL ;
}
