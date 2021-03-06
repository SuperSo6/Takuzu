//Takuzu Projet C 
//  Ce fichier est utilisé lorsque l'utilisateur choisit l'option auto(); L'ordinateur résout tout seul
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "auto.h"
#include "fonctions_resoudres.h"
#include "fonctions_main.h"
#include "fonction_generer_solution.h"
#include "fonctions_generer_masque.h"

void auto_(int taille){
    // Fonction qui génère les 3 matrices et permets à l'ordinateur de jouer tout seul
    int **m_solution = generer_matrice(taille, m_solution), ligne_1[8], ligne_2[8], ligne_3[8], ligne_4[8],ligne_5[8],ligne_6[8],ligne_7[8],ligne_8[8];
    int **m_masque = generer_matrice(taille, m_masque);
    int **jouer = generer_matrice(taille, jouer);
    int verif_colon;

    if(taille==4){

        printf("\n");
        printf("Chargement de la Matrice ...");


        do {
            nbr_ale_4x(ligne_1, ligne_2, ligne_3, ligne_4);  // La fonction nbr_ale_4x permets de récupérer 4 valeurs binaires dans 4 tableaux
            verif_colon = verif_colonne4(ligne_1, ligne_2, ligne_3, ligne_4,4);     // Verification des colonnes avec leurs sommes qui ne doivent pas dépasser 2
        } while (verif_colon == 1);


        printf("\n");




        m_solution = solution4(m_solution, ligne_1, ligne_2, ligne_3, ligne_4, 4);   // Rassemble les 4 tableaux dans une seule matrice

        m_masque = generer_masque(m_masque,4);


        afficher_grille(m_masque,m_solution,4);

        jouer = fill_matrice_joueur(jouer, m_masque, m_solution,4);         // Rempli la matrice jouer de -1 pour les valeurs non affiche par le masque

        Jouer(jouer,m_masque,m_solution,4);  // La fonction appeler résout la matrice tout seul



    } else if(taille==8){

        printf("\n");
        printf("Chargement de la Matrice ...");

        do {
            nbr_ale_8x(ligne_1, ligne_2, ligne_3, ligne_4,ligne_5,ligne_6,ligne_7,ligne_8);  //   La fonction nbr_ale_8x permets de récupérer 8 valeurs binaires dans 8 tableaux
            verif_colon = verif_colonne8(ligne_1, ligne_2, ligne_3, ligne_4,ligne_5,ligne_6,ligne_7,ligne_8,8); // Verification des colonnes avec leurs sommes qui ne doivent pas dépasser 4
        } while (verif_colon == 1);


        printf("\n");




        m_solution = solution8(m_solution, ligne_1, ligne_2, ligne_3, ligne_4,ligne_5,ligne_6,ligne_7,ligne_8, 8); // Rassemble les 8 tableaux dans une seule matrice

        m_masque = generer_masque(m_masque,8);


        afficher_grille(m_masque,m_solution,8);

        jouer = fill_matrice_joueur(jouer, m_masque, m_solution,8);     // Rempli la matrice jouer de -1 pour les valeurs non affiche par le masque

        Jouer(jouer,m_masque,m_solution,8);
    }
}


void Jouer(int **joueur,int**masque,int**solution,int taille){
    int ligne;
    char colonnee;


        printf("\n");
        printf("Debut du jeu \n");

        for (int i=0;i<taille;i++){
            for(int j=0;j<taille;j++) {
                ligne = i;
                switch (j) {            // Permets d'associer pour l'affichage valeur de la colonne et le nom A=0 ; B=1  etc..
                    case 0: {
                        colonnee = 'A';
                        break;
                    }
                    case 1: {
                        colonnee = 'B';
                        break;
                    }
                    case 2: {
                        colonnee = 'C';
                        break;
                    }
                    case 3: {
                        colonnee = 'D';
                        break;
                    }
                    case 4: {
                        colonnee = 'E';
                        break;
                    }
                    case 5: {
                        colonnee = 'F';
                        break;
                    }
                    case 6: {
                        colonnee = 'G';
                        break;
                    }
                    case 7: {
                        colonnee = 'H';
                        break;
                    }


                }
                printf("\n");

                if (joueur[i][j] == -1) {
                    if (solution[i][j] == 1) {
                        printf("Remplissage de la case [%d][%c]  avec la valeur 1 \n", ligne+1, colonnee);
                        joueur[i][j] = 1;
                        masque[i][j] = 1;
                        sleep(1);
                    } else if (solution[i][j] == 0) {

                        printf("Remplissage de la case [%d][%c]  avec la valeur 0 \n", ligne+1, colonnee);
                        joueur[i][j] = 0;
                        masque[i][j] = 0;
                        sleep(1);
                    }

                    afficher_grille(masque, solution, taille);
                    sleep(1);

                }
            }


    }
    printf("\n");
    printf("Grille rempli !");
}
