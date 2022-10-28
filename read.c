//
// Created by Tao S on 10/18/2022.
//

#include "read.h"

// p_string struct management
p_string InitString(int num){
    p_string new = (p_string) malloc(sizeof(p_string)*num);
    return new;
}

void ChangeStringValue(p_string str, char* str_add){
    str->values = str_add;
    str->num = strlen(str_add);
}

void ShowString(p_string str){
    for(int i =0;i<(str->num);i++){
        printf("%c",str->values[i]);
    }
    printf("\n");
}

//p_dic struct management

p_dic InitDic(int num){
    p_dic new = (p_dic) malloc(sizeof(p_dic)*num);
    return new;
}

void ChangeDicValue(p_dic str, char* str_add, int cat){
    switch (cat){
        case 0:
            str->word = str_add;
            str->num1 = strlen(str_add);
            break;
        case 1:
            str->word = str_add;
            str->num2 = strlen(str_add);
            break;
        case 2:
            str->type = str_add;
            str->num3 = strlen(str_add);
            break;
        default:
            break;
    }
}

void ShowDic(p_dic str){
    for(int i =0;i<(str->num1);i++){
        printf("%c",str->word[i]);
    }
    printf("\n");
    for(int i =0;i<(str->num2);i++){
        printf("%c",str->word2[i]);
    }
    printf("\n");
    for(int i =0;i<(str->num3);i++){
        printf("%c",str->type[i]);
    }
    printf("\n");
}

//File management
p_string readLine(int num){
    p_string new = InitString(50);
    FILE* file = fopen(TEXT,"r");
    int count = 0;

    while(fgets(new->values, 255, file)) {
        printf("%s\n", new->values);
        if (count++ == num) {
            fclose(file);
            return new;
        }
    }

    fclose(file);
    printf("yzvduyzq?\n");
    return new;
}

p_dic GetArgFromLine(int line){
    p_dic new = InitDic(2);
    int state = 0, pos = 0;

    printf("do\n");
    p_string str = readLine(line);
    ShowString(str);

    for(int i=0; i < str->num;i++){
        //printf("%d\n",str->values[i] != NULL);
        printf("i = %d | char = %c\n",i,str->values[i]);
        if(str->values[i] == ' '){
            printf("state\n");
            state++;
            pos = i;
        }else {
            switch (state)
            {
                case 0:
                    new->word[i] = str->values[i];
                    printf("%c",str->values[i]);
                    break;
                case 1:
                    new->word2[i] = str->values[i];
                    printf("%c",str->values[i]);
                    break;
                case 2:
                    new->type[i] = str->values[i];
                    printf("%c",str->values[i]);
                    break;
                default:
                    break;
            }
        }
    }
    printf("plp\n");

    return new;
}