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
    int state = 0, pos;
    readLine(line,num);

    for(int i=0;line[i];i++){
        if(*line[i] == ' '){
            state++;
            pos = i;
        }else {
            switch (1)
            {
                case (0):
                    *wordM[i] = *line[i];
                    break;
                case (1):
                    *word[i-pos] = *line[i];
                    break;
                case (2):
                    *def[i-pos] = *line[i];
                    break;

            }
        }
    }

    return 1;
}