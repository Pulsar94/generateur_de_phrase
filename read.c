//
// Created by Tao S on 10/18/2022.
//

#include "read.h"

// p_string struct management
p_string InitString(int num){
    p_string new = (p_string) malloc(sizeof(p_string));
    return new;
}

void ChangeStringValue(p_string str, char* str_add){
    strcpy(str->values,str_add);
    str->num =(int) strlen(str_add);
}

void ShowString(p_string str){
    for(int i =0;i<(str->num);i++){
        printf("%c",str->values[i]);
    }
    printf("\n");
}

//p_dic struct management

p_dic InitDic(int num){
    p_dic new = (p_dic) malloc(sizeof(p_dic));
    return new;
}

void ChangeDicValue(p_dic str, char* str_add, int cat){
    switch (cat){
        case 0:
            strcpy(str->word,str_add);
            str->num1 =(int) strlen(str_add);
            break;
        case 1:
            strcpy(str->word2,str_add);
            str->num2 =(int) strlen(str_add);
            break;
        case 2:
            strcpy(str->type,str_add);
            str->num3 =(int) strlen(str_add);
            break;
        default:
            break;
    }
}

void ShowDic(p_dic str){
    printf("word: ");
    for(int i =0;str->word[i] != '\0';i++){
        printf("%c",str->word[i]);
    }
    printf("\nword2: ");
    for(int i =0;str->word2[i] != '\0';i++){
        printf("%c",str->word2[i]);
    }
    printf("\ntype: ");
    for(int i =0;str->type[i] != '\0';i++){
        printf("%c",str->type[i]);
    }
    printf("\n");
}

//File management
p_string readLine(int num){
    char file_read[50];
    p_string new = InitString(50);
    FILE* file = fopen(TEXT,"r");
    int count = 0;

    while(fgets(file_read, 255, file)) {
        //printf("%s\n", file_read);
        strcpy(new->values,file_read);
        if (count++ == num) {
            fclose(file);
            return new;
        }
    }

    fclose(file);
    return new;
}

p_dic GetArgFromLine(int line){
    p_dic new = InitDic(2);
    int state = 0, pos = 0;

    printf("do\n");
    p_string str = readLine(line);
    ShowString(str);
    printf("%d\n",str->num);

    for(int i=0; str->values[i] != '\0';i++){
        printf("i = %d | char = %c\n",i,str->values[i]);
        if(str->values[i] == '\n'){ // ulgy might make it better later
            break;
        }
        if(str->values[i] == '\t'){
            printf("state\n");
            state++;
            pos = i+1;
        }else {
            switch (state)
            {
                case 0:
                    new->word[i] = str->values[i];
                    //printf("%c",str->values[i]);
                    break;
                case 1:
                    new->word2[i-pos] = str->values[i];
                    //printf("%c",str->values[i]);
                    break;
                case 2:
                    new->type[i-pos] = str->values[i];
                    //printf("%c",str->values[i]);
                    break;
                default:
                    break;
            }
        }
    }

    return new;
}