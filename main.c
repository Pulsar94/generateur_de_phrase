#include <stdio.h>
#include "read.h"

int main() {
    //char *get1,*get2,*get3;



    p_string str = InitString(50);

    str = readLine(1);
    ShowString(str);

    p_dic new = GetArgFromLine(1);
    ShowDic(new);
    //printf("Word: %s\n",*readLine(get,0));
    //GetArgFromLine(1, &get1,&get2,&get3);

    //printf("Word: %s\nWord2: %s\nType: %s\n",get1,get2,get3);
    return 0;
}
