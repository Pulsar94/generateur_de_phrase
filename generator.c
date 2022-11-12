//
// Created by taoso on 11/12/2022.
//

#include "generator.h"

tree generate_type_tree(int type){
    tree new_tree = create_tree();
    for(int i=0;i<287976;i++){ //Might change this in the near future
        p_dic new = GetArgFromLine(i);
        printf("i:%d\n",i);
        if(GetType(new) == type){
            add_word(new_tree->root,new->word2,new->num2);
        }
    }
    printf("Tree Generated\n");
    return new_tree;
}

//int isidenticalword(char word1,p_dic dic){
//    printf("%s\n",word1);
//    for(int i=0;i<dic->num2;i++){
//        if(word1[i]!=dic->word2[i]){
//            return 0;
//        }
//    }
//    return 1;
//}

void generate_three_type_tree(tree nam_tree,tree adj_tree,tree ver_tree){
    char *prev_word;
    prev_word = GetArgFromLine(2)->word2;
    printf("Generating trees...\n");
    FILE* file = fopen(TEXT,"r");
    for(int i=0;i<287976;i++){ //Might change this in the near future
        p_dic new = GetArgFromLine(i);
        if(strcmp(prev_word,new->word2) != 0) {
            printf("i:%d\n", i);
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
