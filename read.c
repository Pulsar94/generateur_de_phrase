//
// Created by Tao S on 10/18/2022.
//

#include "read.h"

// p_string struct management
p_string InitString(int num){
    p_string new = (p_string) malloc(sizeof(t_string));
    return new;
}

//DEBUG: Change a value in a string
void ChangeStringValue(p_string str, char* str_add){
    strcpy(str->values,str_add);
    str->num =(int) strlen(str_add);
}

//DEBUG: Show a string
void ShowString(p_string str){
    for(int i =0;str->values[i] != '\0';i++){
        printf("%c",str->values[i]);
    }
    printf("\n");
}



//p_dic struct management, Initialize the right size for our p_dic struct
p_dic InitDic(){
    p_dic new = (p_dic) malloc(sizeof(t_dic));
    return new;
}

//DEBUG: Arbitrary change values in a p_dic
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

//DEBUG: Show a p_dic struct
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




//File management, extract one line from the dictionary file
p_string readLine(FILE* file){
    char file_read[100];
    p_string new = InitString(50);

    while(fgets(file_read, 255, file)) {
        strcpy(new->values,file_read);
        return new;
    }
    return new;
}

//'Explode' a string into p_dic specified string
p_dic InsertIntoDic(p_dic dic, p_string str){
    int state = 0, pos = 0;

    for(int i =0;str->values[i] != '\0';i++){
        if(str->values[i] == '\n'){
            break;
        }
        if(str->values[i] == '\t' || str->values[i] == ' '){ //Each time we hit a tabulation or space this is a new word
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
    return dic;
}

//Collect a line from a text file to insert it into our p_dic struct
p_dic GetArgFromLine(int line, FILE* file){
    p_dic new = InitDic();
    p_string str = readLine(file);
    new->num1 = 0; new->num2 = 0; new->num3 = 0; //For some reason doing it inside the InitDic() does not work, set the length of our three string at 0

    InsertIntoDic(new, str);

    return new;
}

//Get type(in int) of the word stored in a p_dic
//Type 1: Name
//Type 2: Adjective
//Type 3: Verb
int GetType(p_dic dic){
    char type[9] = "NomAdjVer";
    int count = 0,success = 0;
    for(int i=0;i<9&&count==0;i++){ //No need to pursue operation if a match (count) is already found
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