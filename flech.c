//
// Created by taoso on 11/18/2022.
//

#include "flech.h"
#include "stdlib.h"
#include "stdio.h"

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
