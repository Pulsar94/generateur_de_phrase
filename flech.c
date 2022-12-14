//
// Projet Générateur de Phrase
// EFREI S3-L2 | 2022-2023
// Created by SOLAN Tao | ROUGAGNOU Marc | MENIN Thibaut
//

#include "flech.h"

void printConj(p_conj conj){ //DEBUG
    printf("oui\n");
    printf("%d\n",conj->length);
    for(int i=0;i<conj->length;i++){
        printf("%s\n",conj->values[i]);
    }
}

int CountTwoTypeMatch(char* type1, char* type2){ //UNUSED
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

int GetHighestMatch(char* type1, p_conj packed_type2){// UNUSED
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

int ContainChar(char* type, char* type2){ //Check if the two type correspond
    for(int i=0;type[i]!='\0';i++){
        for(int j=0;type2[j]!='\0';j++) {
            if (type[i] == type2[j] && type[i + 1] == type2[j + 1]) {
                return 1;
            }
        }
    }

    return 0;
}

pnode research_flech(tree tree_word){ //Similar to resarch_word, only that it returns the p_node associated to it, instead of the word
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
    return prev_temp;
}

char* research_word_flech(tree tr, int plu, int fem){ //Research a single fleched word in the tree according to the gender/plural of the world
    p_conj word_conj;

    char cplu[3]="SG\0";
    char cfem[4]="Mas\0";

    if(plu){ //If plural switch our variable to search for plural word
        cplu[0] = 'P';
        cplu[1] = 'L';
    }

    if(fem){ //Idem but for the gender of the word
        cfem[0] = 'F';
        cfem[1] = 'e';
        cfem[2] = 'm';
    }

    do {
        do {
            word_conj = research_flech(tr)->conj;
        } while (word_conj->length < 1); //Some words do not contain fleched form, so we prefer to avoid them for a better structure

        //printConj(word_conj);
        //printf("cplu: %s| cfem: %s",cplu,cfem);

        for (int i = 1; i < word_conj->length; i = i + 2) { // We are only looking for the grammatical structure, so we take the odd index number containing them

            if (fem == 3 && plu == 3) { //Check if we are not looking for infinitive
                if (ContainChar(word_conj->values[i], "Inf")) {
                    return word_conj->values[i - 1];
                }
            } else {
                if (ContainChar(word_conj->values[i], cplu) && ContainChar(word_conj->values[i], cfem)) {
                    return word_conj->values[i - 1];
                }
            }

        }
    } while (1); //Continue until we find corresponding word
    //return word_conj->values[0];
}

void sentence_fleched_model_1(tree tree_name, tree tree_adjective, tree tree_verb){ //Create one the asked form

    char form[3][2][4] = {
            {
                    {'L','e','\0'},
                    {'L','a','\0'}
            },
            {
                    {'L','e','s','\0'},
                    {'L','e','s','\0'}
            },
            {
                    {'\0'}
            }
    };

    char form2[3][4] = {
            {'u','n','\0'},
            {'u','n','e','\0'},
            {'\0'}
    };

    int rand1 = rand()%2; // designate if plural or not
    int rand2 = rand()%2; // designate which word gender

    char* name = research_word_flech(tree_name,rand1,rand2);
    char* adj = research_word_flech(tree_adjective,rand1,rand2);
    char* verb = research_word_flech(tree_verb,rand1,rand2);
    char* name2 = research_word_flech(tree_name,rand1,rand2);

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
    //Nom
    printf("%s ",name2);

    printf("\n");
}

void sentence_fleched_model_2(tree tree_name, tree tree_adjective, tree tree_verb){ //Create one the asked form

    char form[3][2][4] = {
            {
                    {'L','e','\0'},
                    {'L','a','\0'}
            },
            {
                    {'L','e','s','\0'},
                    {'L','e','s','\0'}
            },
            {
                    {'\0'}
            }
    };

    char form2[3][4] = {
            {'u','n','\0'},
            {'u','n','e','\0'},
            {'\0'}
    };

    int rand1 = rand()%2; // designate if plural or not
    int rand2 = rand()%2; // designate which word gender

    char* name = research_word_flech(tree_name,rand1,rand2);
    char* adj = research_word_flech(tree_adjective,rand1,rand2);
    char* verb = research_word_flech(tree_verb,rand1,rand2);
    char* verb2 = research_word_flech(tree_verb,rand1,rand2);
    char* name2 = research_word_flech(tree_name,rand1,rand2);


    //Le/La/Les
    printf("%s ",form[rand1][rand2]);
    //Nom
    printf("%s ",name);
    //Qui
    printf("qui ");
    //verbe
    printf("%s ",verb);
    //verbe
    printf("%s ",verb2);
    //un/une
    printf("%s ",form2[rand2]);
    //Nom
    printf("%s ",name2);
    //Adjectif
    printf("%s ",adj);

    printf("\n");
}

void sentence_fleched_model_3(tree tree_name, tree tree_adjective, tree tree_verb){ //Create one the asked form

    char form[3][2][8] = {
            {
                    {'Q','u', 'e', 'l', '\0'},
                    {'Q','u','e', 'l', 'l', 'e', '\0'}
            },
            {
                    {'Q','u', 'e', 'l', 's', '\0'},
                    {'Q','u','e', 'l', 'l', 'e', 's', '\0'}
            },
            {
                    {'\0'}
            }
    };

    char form2[3][4] = {
            {'u','n','\0'},
            {'u','n','e','\0'},
            {'\0'}
    };

    int rand1 = rand()%2; // designate if plural or not
    int rand2 = rand()%2; // designate which word gender

    char* name = research_word_flech(tree_name,rand1,rand2);
    char* verb = research_word_flech(tree_verb,rand1,rand2);
    char* name2 = research_word_flech(tree_name,rand1,rand2);

    //Quel,Quelle, Quels,Quelles
    printf("%s ",form[rand1][rand2]);
    //Nom
    printf("%s ",name);
    //verbe
    printf("%s ",verb);
    //un/une
    printf("%s ",form2[rand2]);
    //Nom
    printf("%s ",name2);
    printf("?");
    printf("\n");
}