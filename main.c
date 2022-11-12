#include <stdio.h>
#include "read.h"
#include "tree.h"

int main() {

    p_dic new = GetArgFromLine(0);
    ShowDic(new);
    int type = GetType(new);
    printf("type: %d\n",type);
    printf("done\n");
    return 0;
}
