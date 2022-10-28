//
// Created by Tao S on 10/18/2022.
//

#include "read.h"

int readLine(char** line, int num){
    FILE* file = fopen(TEXT,"r");
    int count = 0;


    while(fgets(*line, 255, file)) {
        printf("%s\n", *line);
        if (count++ == num) {
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    printf("yzvduyzq?\n");
    return 1;
}

int GetArgFromLine(int num, char** wordM,char** word,char** def){
    char* line = (char*) malloc(sizeof (char)*50);
    int state = 0, pos;
    *wordM = (char*) malloc(sizeof (char)*50);
    *word = (char*) malloc(sizeof (char)*50);
    *def = (char*) malloc(sizeof (char)*50);
    printf("do\n");
    readLine(&line,num);
    printf("%p | %s\n",line[2],line);

    for(int i=0; i < strlen(line);i++){
        printf("%d\n",&line[i] != NULL);
        printf("i = %d | char = %c\n",i,line[i]);
        if(line[i] == ' '){
            printf("state\n");
            state++;
            pos = i;
        }else {
            switch (state)
            {
                case 0:
                    *wordM[i] = line[i];
                    break;
                case 1:
                    *word[i] = line[i];
                    break;
                case 2:
                    *def[i] = line[i];
                    break;
                default:
                    break;
            }
        }
    }
    printf("plp\n");

    return 1;
}