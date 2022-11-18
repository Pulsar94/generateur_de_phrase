//
// Created by taoso on 11/18/2022.
//

#include "flech.h"


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

void printConj(p_conj conj){ //DEBUG
    printf("oui\n");
    printf("%d\n",conj->length);
    for(int i=0;i<conj->length;i++){
        printf("%s\n",conj->values[i]);
    }
}

int CountTwoTypeMatch(char* type1, char* type2){
    int count = 0;
    int chain = 0;
    for(int i=0;type1[i]!='\0';i++){
        for(int j=0;type2[j]!='\0';j++){
            if(type2[j]=='+'){
                if(chain){ //We ensure ourselves that the match continue up to the end of the word
                    count++;
                }
                break;
            }
            if(type1[i]==type2[j]){
                chain=1;
                break; //we found a match no need to pursue research
            }
        }
    }
    return count;
}

int GetHighestMatch(char* type1, p_conj packed_type2){
    int high = 0, index;
    for(int i=0;i<packed_type2->length;i++){
        int tempHigh = CountTwoTypeMatch(type1,packed_type2->values[i]);
        if (tempHigh>high){
            high = tempHigh;
            index = i;
        }
    }
    return index;
}

int ContainChar(char* type, char* type2){
    for(int i=0;type[i]!='\0';i++){
        if(type[i]==type2[i] && type[i+1]==type2[i+1]){
            return 1;
        }
    }

    return 0;
}

pnode research_flech(tree tree_word){
    int choice;
    // choice = 0 ==> go on right
    // choice = 1 ==> stop on the node because it's a word
    // choice = 2 ==> go on left
    pnode prev_temp = tree_word->root;
    pnode temp = tree_word->root;

    do {
        choice = road_determination(temp);
        if (choice == 0){ // right and conservation value in the list
            prev_temp = temp;
            temp = temp->right;
            //create_cell(word, temp->value);
        } else {
            if (choice == 2){ // left et remplacement de la valeur dans la file
                prev_temp = temp;
                temp = temp->left;
            }
        }
    } while (choice != 1); // if choice == 1 no action is require. Quit the loop and the word is already in the list
    return temp;
}

char* research_word_flech(tree tr, int plu, int fem){
    p_conj word_conj = research_flech(tr)->conj;
    char cplu[2]="SG";
    char cfem[3]="Mas";

    if(plu){
        cplu[0] = 'P';
        cplu[1] = 'L';
    }

    if(fem){
        cfem[0] = 'F';
        cfem[1] = 'e';
        cfem[2] = 'm';
    }

    for(int i=0;i < word_conj->length;i++){
        if(fem == 3 && plu == 3 && ContainChar(word_conj->values[i],"Inf")){
            return word_conj->values[i-1];
        }
        if(ContainChar(word_conj->values[i],cplu) && ContainChar(word_conj->values[i],cfem)){
            return word_conj->values[i-1];
        }

    }

    return word_conj->values[0];
}

void sentence_model_3(tree tree_name, tree tree_adjective, tree tree_verb){
    //Les socles définitifs arrachent un voilier
    //La pierre qui oublie éveilla les poignées belliqueuses
    char form[2][2][3] = {
            {
                {'L','e'},
                {'L','a'}
                },
            {
                {'L','e','s'},
                {'L','e','s'}
                }
    };

    char form2[2][3] = {
            {'u','n'},
            {'u','n','e'}
    };

    int rand1 = rand()%2; // designate if plural or not
    int rand2 = rand()%2; // designate which word gender



    char* name = research_word_flech(tree_name,rand1,rand2);
    char* adj = research_word_flech(tree_adjective,rand1,rand2);
    char* verb = research_word_flech(tree_verb,rand1,rand2);
    char* verb_inf = research_word_flech(tree_verb,3,3);


    //Le/La/Les
    printf("%s ",form[rand1][rand2]);
    //Nom
    printf("%s ",name);
    //Adjectif
    printf("%s ",adj);
    //verbe
    printf("%s ",verb);
    //un/une
    printf("%s ",form2[rand2]);
    //verbe inf
    printf("%s ",verb_inf);


    printf("\n");

}
