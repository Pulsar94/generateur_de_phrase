#include <stdio.h>
#include "read.h"
#include "tree.h"
#include "generator.h"

//Here we create our three dictionary trees as global
tree tree_name;
tree tree_adjective;
tree tree_verb;
//

int main() {

    //Here we initialize our three dictionary trees
    tree_name = create_tree();
    tree_adjective = create_tree();
    tree_verb = create_tree();
    //

    //We convert our dictionary into our trees
    generate_three_type_tree(tree_name, tree_adjective, tree_verb);
    //



//    p_dic new = GetArgFromLine(26);
//    p_dic new = GetArgFromLine(5);
//    ShowDic(new);
//    int type = GetType(new);
//    printf("type: %d\n",type);

    printf("done\n");
    return 0;
}
