#include <stdio.h>
#include "read.h"
#include "tree.h"
#include "generator.h"
#include "tree_research.h"

//Here we create our three dictionary trees as global
tree tree_name;
tree tree_adjective;
tree tree_verb;
//

void menu(){
    int choice=0;
    printf("\nSelectionner une action: (0 : arreter | 1 : phrase type 1 | 2 : phrase type 2)\n");
    scanf("%d",&choice);

    switch (choice) {
        case 0:
            return;
            break;
        case 1:
            sentence_model_1(tree_name,tree_adjective,tree_verb);
            break;
        case 2:
            sentence_model_2(tree_name,tree_adjective,tree_verb);
            break;
        default:
            break;
    }
    menu();
}

int main() {

    //Here we initialize our three dictionary trees
    tree_name = create_tree();
    tree_adjective = create_tree();
    tree_verb = create_tree();
    //

    //Seeding the randomness
    srand(time(0));
    //

    //We convert our dictionary into our trees
    generate_three_type_tree(tree_name, tree_adjective, tree_verb);
    //

    //calling the menu
    menu();
    //

    printf("done\n");
    return 0;
}


