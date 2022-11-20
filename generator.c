//
// Projet Générateur de Phrase
// EFREI S3-L2 | 2022-2023
// Created by SOLAN Tao | ROUGAGNOU Marc | MENIN Thibaut
//

#include "generator.h"

//Generate three binary trees (name,verb,adjective) from specified file dictionary
void generate_three_type_tree(tree nam_tree,tree adj_tree,tree ver_tree){
    char *prev_word;
    FILE* file = fopen(TEXT,"r");
    prev_word = GetArgFromLine(2,file)->word2;
    printf("Generating trees...\n");
    for(int i=0;i<TEXT_LENGTH;i++){ //Row size of the dictionary file
        p_dic new = GetArgFromLine(i,file);

        if (GetType(new) == 1) { //Testing what is the type of the word extracted to assign him the corresponding tree
            add_word(nam_tree->root, new->word2, new->num2, new->type, new->word);
        }
        if (GetType(new) == 2) {
            add_word(adj_tree->root, new->word2, new->num2, new->type, new->word);
        }
        if (GetType(new) == 3) {
            add_word(ver_tree->root, new->word2, new->num2, new->type, new->word);
        }
    }
    fclose(file);
    printf("Trees Generated\n");
}
