#include <stdio.h>
#include "read.h"

int main() {

    p_dic new = GetArgFromLine(0);
    ShowDic(new);

    printf("done\n");
    return 0;
}
