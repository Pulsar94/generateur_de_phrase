//
// Created by taoso on 11/12/2022.
//

#include "generator.h"

void generate_three_type_tree(tree nam_tree,tree adj_tree,tree ver_tree){
    char *prev_word;
    FILE* file = fopen(TEXT,"r");
    prev_word = GetArgFromLine(2,file)->word2;
    printf("Generating trees...\n");
    for(int i=0;i<287976;i++){ //Might change this in the near future
        p_dic new = GetArgFromLine(i,file);
        //ShowDic(new);
        if(strcmp(prev_word,new->word2) != 0) {
            //printf("i:%d\n", i);
            strcpy(prev_word,new->word2);
            if (GetType(new) == 1) {
                add_word(nam_tree->root, new->word2, new->num2);
            }
            if (GetType(new) == 2) {
                add_word(adj_tree->root, new->word2, new->num2);
            }
            if (GetType(new) == 3) {
                add_word(ver_tree->root, new->word2, new->num2);
            }
        }
    }
    fclose(file);
    printf("Trees Generated\n");
}
