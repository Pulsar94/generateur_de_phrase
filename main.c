#include <stdio.h>
#include "read.h"
#include "tree.h"
#include "generator.h"
#include "tree_research.h"
#include "flech.h"

//Here we create our three dictionary trees as global
tree tree_name;
tree tree_adjective;
tree tree_verb;
//

void menu(){
    int choice=2;
    printf("\n#########################################################\n");
    printf("############                                 ############\n");
    printf("############        PROJET LANGUAGE C        ############\n");
    printf("############      GENERATEUR DE PHRASES      ############\n");
    printf("############                                 ############\n");
    printf("#########################################################\n");
    printf("############    SELECTIONNER UNE ACTION :    ############\n");
    printf("############   RENTRER LE CHIFFRE ASSOCIE    ############\n");
    printf("############                                 ############\n");
    printf("############       0 | FORME DE BASE |       ############\n");
    printf("############       1 | FORME DE FLECHIE |    ############\n");
    printf("############                                 ############\n");
    printf("############       5 | QUITTER |             ############\n");
    printf("############                                 ############\n");
    printf("#########################################################\n");
    printf("CHOIX : ");
    scanf("%d",&choice);
    switch (choice) {
        case 0:
            printf("\n#########################################################\n");
            printf("########           FORME DE BASE                 ########\n");
            printf("########     SELECTIONNER UNE ACTION :           ########\n");
            printf("########    RENTRER LE CHIFFRE ASSOCIE           ########\n");
            printf("########                                         ########\n");
            printf("########  0 | NOM ADJECTIF VERBE NOM |           ########\n");
            printf("########  1 | NOM QUI VERBE VERBE NOM ADJECTIF | ########\n");
            printf("########                                         ########\n");
            printf("########  5 | RETOURNER A L'ACCUEIL |            ########\n");
            printf("########                                         ########\n");
            printf("#########################################################\n");
            printf("CHOIX : ");
            int choice2=2;
            scanf("%d",&choice2);
            switch (choice2) {
                case 0:
                    sentence_model_1(tree_name,tree_adjective,tree_verb);
                    break;
                case 1:
                    sentence_model_2(tree_name,tree_adjective,tree_verb);
                    break;
                case 5:
                    break;
                default:
                    break;
            }
            break;
        case 1:
            printf("\n##########################################################################\n");
            printf("#########                    FORME DE FLECHIE                    #########\n");
            printf("#########                SELECTIONNER UNE ACTION :               #########\n");
            printf("#########                                                        #########\n");
            printf("#########   0 | PRONOM NOM ADJECTIF VERBE NOM |                  #########\n");
            printf("#########   1 | PRONOM NOM QUI VERBE VERBE PRONOM NOM ADJECTIF | #########\n");
            printf("#########   2 | PRONOM NOM VERBE PRONOM NOM ? |                  #########\n");
            printf("#########                                                        #########\n");
            printf("#########   5 | RETOURNER A L'ACCUEIL |                          #########\n");
            printf("#########                                                        #########\n");
            printf("##########################################################################\n");
            printf("CHOIX : ");
            int choice3=2;
            scanf("%d",&choice3);
            switch (choice3) {
                case 0:
                    sentence_fleched_model_1(tree_name,tree_adjective,tree_verb);
                    break;
                case 1:
                    sentence_fleched_model_2(tree_name,tree_adjective,tree_verb);
                    break;
                case 2:
                    sentence_fleched_model_3(tree_name,tree_adjective,tree_verb);
                    break;
                case 5:
                    break;
                default:
                    break;
            }
            break;
        case 5:
            return;
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

    printf("\nMERCI DE VOTRE VISITE\n");
    return 0;
}


