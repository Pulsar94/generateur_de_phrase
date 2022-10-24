//
// Created by Tao S on 10/18/2022.
//

#include "read.h"

char** readLine(char** line, int num){
    FILE* file = fopen(TEXT,"r");
    int count = 0;


    while(fgets(*line, 255, file)) {
        printf("%s", *line);
        if (count++ == num) {
            fclose(file);
            return line;
        }
    }
    printf("oui");

    fclose(file);
    return line;
}

int GetArgFromLine(int num, char** wordM,char** word,char** def){
    char* line[50];
    readLine(line,num);

    for(int i=0;line[i];i++){

    }

    return 1;
}