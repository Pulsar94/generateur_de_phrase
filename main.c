#include <stdio.h>
#include "read.h"

int main() {
    char* get1[50],*get2[50],*get3[50];

    //printf("Word: %s\n",*readLine(get,0));
    GetArgFromLine(1, get1,get2,get3);

    printf("Word: %s\nWord2: %s\nType: %s\n",*get1,*get2,*get3);
    return 0;
}
