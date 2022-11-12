//
// Created by Tao S on 10/18/2022.
//

#include "read.h"

// p_string struct management
p_string InitString(int num){
    p_string new = (p_string) malloc(sizeof(t_string));
    return new;
}

void ChangeStringValue(p_string str, char* str_add){
    strcpy(str->values,str_add);
    str->num =(int) strlen(str_add);
}

void ShowString(p_string str){
    for(int i =0;str->values[i] != '\0';i++){
        //printf("i = %d | char = %c\n",i,str->values[i]);
        printf("%c",str->values[i]);
    }
    printf("\n");
}



//p_dic struct management
p_dic InitDic(){
    p_dic new = (p_dic) malloc(sizeof(t_dic));
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
    printf("%d | %d | %d |\n",str->num1,str->num2,str->num3);
    printf("word: ");
    for(int i =0; i < str->num1;i++){
        printf("%c",str->word[i]);
    }
    printf("\nword2: ");
    for(int i =0; i < str->num2;i++){
        printf("%c",str->word2[i]);
    }
    printf("\ntype: ");
    for(int i =0; i < str->num3;i++){
        printf("%c",str->type[i]);
    }
    printf("\n");
}




//File management
p_string readLine(int num){
    char file_read[100];
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

p_dic InsertIntoDic(p_dic dic, p_string str){
    int state = 0, pos = 0;

    for(int i =0;str->values[i] != '\0';i++){
        //printf("i = %d | char = %c\n",i,str->values[i]);
        if(str->values[i] == '\n'){ // ulgy might make it better later
            break;
        }
        if(str->values[i] == '\t' || str->values[i] == ' '){
            //printf("state\n");
            state++;
            pos = i+1;
        }else {
            switch (state)
            {
                case 0:
                    dic->word[i-pos] = str->values[i];
                    dic->num1++;
                    break;
                case 1:
                    dic->word2[i-pos] = str->values[i];
                    dic->num2++;
                    break;
                case 2:
                    dic->type[i-pos] = str->values[i];
                    dic->num3++;
                    break;
                default:
                    break;
            }
        }
    }
    //ShowString(str);
    return dic;
}

//Separate line argument into the p_dic struct
p_dic GetArgFromLine(int line){
    p_dic new = InitDic();
    p_string str = readLine(line);
    new->num1 = 0; new->num2 = 0; new->num3 = 0;
    //printf("%d | %d | %d |\n",new->num1,new->num2,new->num3);
    //ShowString(str);

    InsertIntoDic(new, str);

    return new;
}

//Get int type of the word stored in a p_dic
int GetType(p_dic dic){
    char type[9] = "NomAdjVer";
    int count = 0,success = 0;
    for(int i=0;i<9&&count==0;i++){
        //printf("compare: %d|succ: %d|char: %c\n",i,success,dic->type[i%3]);
        if(dic->type[i%3]==type[i]){
            success++;
        }else{
            success=0;
        }
        if(success == 3){
            if(i>0){
                count = 1;
            }
            if(i>3){
                count = 2;
            }
            if(i>6){
                count = 3;
            }
        }
    }
    return count;
}