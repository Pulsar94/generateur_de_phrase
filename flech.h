//
// Created by taoso on 11/18/2022.
//

#ifndef MAIN_C_FLECH_H
#define MAIN_C_FLECH_H

typedef struct s_conj{
    char* values[50];
    int length;
}t_conj,*p_conj;

//Prototyping
p_conj InitConj();
void AddConj(p_conj, char *);
int CountTwoTypeMatch(char*, char*);
int GetHighestMatch(char*, p_conj);

#endif //MAIN_C_FLECH_H
