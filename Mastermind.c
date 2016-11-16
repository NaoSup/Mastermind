
#include "graphics.h"
#include<stdio.h>

int compteur;
int ordi[4];
int joueur[4];
POINT dep;
int i;

void ecran_debut ()
{
    POINT P1, P2, P3;
    P1.x=100;
    P1.y=750;
    P2.x=500;
    P2.y=250;
    draw_rectangle(P1,P2,blanc);
    P1.x=130;
    P1.y=720;
    P2.x=480;
    P2.y=470;
    draw_rectangle(P1,P2,blanc);
    P1.x=150;
    P1.y=250;
    P2.x=450;
    P2.y=200;
    draw_rectangle(P1,P2,blanc);
    P1.x=130;
    P1.y=410;
    P2.x=190;
    P2.y=390;
    draw_fill_rectangle(P1,P2,blanc);
    P1.x=340;
    P1.y=410;
    P2.x=480;
    P2.y=390;
    draw_fill_rectangle(P1,P2,blanc);
    P1.x=160;
    P1.y=540;
    P2.x=440;
    P2.y=490;
    draw_fill_rectangle(P1,P2,blanc);
    P1.x=160;
    P1.y=530;
    P2.x=300;
    P2.y=490;
    draw_fill_rectangle(P1,P2,black);
    P1.x=150;
    P1.y=700;
    P2.x=230;
    P2.y=640;
    draw_line(P1,P2,blanc);
    P1.x=150;
    P1.y=640;
    P2.x=230;
    P2.y=700;
    draw_line(P1,P2,blanc);
    P1.x=370;
    P1.y=700;
    P2.x=450;
    P2.y=640;
    draw_line(P1,P2,blanc);
    P1.x=450;
    P1.y=700;
    P2.x=370;
    P2.y=640;
    draw_line(P1,P2,blanc);
    P1.x=300;
    P1.y=620;
    draw_circle_BD(P1,70,blanc);
    draw_circle_BG(P1,70,blanc);
    P1.x=90;
    P1.y=835;
    aff_pol("#MASTERMIND#",50,P1,vert);

}

void regles_du_jeu()
{
    POINT P1,P2,P3;
    P1.x=90;P1.y=835;
aff_pol("#MASTERMIND#",50,P1,vert);


P1.x=10; P1.y=650;
aff_pol("Un bug informatique a provoqué le déclenchement d'une bombe atomique",15,P1,vert);
P1.x=10; P1.y=630;
aff_pol("en direction de la tour Eiffel. Vous avez le pouvoir de désactiver cette bombe",15,P1,vert);
P1.x=10;P1.y=610;
aff_pol("car nous sommes très peu à savoir que le code de désactivation se compose ",15,P1,vert);
P1.x=10; P1.y=590;
aff_pol("de quatre couleurs différentes. Donc ne risquez la vie de nos citoyens en ",15,P1,vert);
P1.x=10;P1.y=570;
aff_pol("essayant de mettre deux pions de même couleur! La lutte sera acharnée, vous ",15,P1,vert);
P1.x=10;P1.y=550;
aff_pol("devez à TOUT prix déjouer le piège de NAO6MI, le célèbre cheval de Troie ... ",15,P1,vert);
P1.x=10;P1.y=530;
aff_pol(" ... le plus dangereux que les autorités mondiales n'aient jamais rencontré!",15,P1,vert);

P1.x=300;P1.y=450;
P2.x=200;P2.y=300;
P3.x=400;P3.y=300;
draw_triangle(P1,P2,P3,rouge);
P1.x=295;P1.y=410;
P2.x=305;P2.y=340;
draw_fill_rectangle(P1,P2,rouge);
P1.x=300;P1.y=320;
draw_fill_circle(P1,5,rouge);

P1.x=10;P1.y=220;
aff_pol("Mais attention, vous n'avez que 10 essais, bien que NAO6MI soit redoutable,",15,P1,vert);
P1.x=10;P1.y=200;
aff_pol("ce n'est pas un mauvais perdant.C'est pourquoi il vous communiquera au fil",15,P1,vert);
P1.x=10;P1.y=180;
aff_pol("de vos essais les pions bien placés et ceux de bonnes couleurs mais mal placés.",15,P1,vert);
P1.x=100;P1.y=100;
aff_pol("ON COMPTE SUR VOUS !",30,P1,vert);


}


void combinaison_ordi()
{
    do
    {
        ordi[0]=alea_int(6);
        ordi[1]=alea_int(6);
        ordi[2]=alea_int(6);
        ordi[3]=alea_int(6);
    }
    while(ordi[0]==ordi[1] || ordi[0]==ordi[2] || ordi[0]==ordi[3] || ordi[1]==ordi[2] || ordi[1]==ordi[3] || ordi[2]==ordi[3]);

}

COULEUR nombre_couleur(int nombre)
{
    /*conversion couleur*/
    COULEUR couleur;

    if(nombre==0)
    {
        couleur=couleur_RGB(241,12,12);
    }
    else if(nombre==1)
    {
        couleur=gris;
    }
    else if(nombre==2)
    {
        couleur=couleur_RGB(35,152,14);
    }
    else if(nombre==3)
    {
        couleur=couleur_RGB(230,197,6);
    }
    else if(nombre==4)
    {
        couleur=bleu;
    }
    else if(nombre==5)
    {
        couleur=blanc;
    }
    return couleur;

}
void affiche_combi_ordi()
{
    int i, nombre;
    COULEUR couleur_ordi;
    POINT P1;
    P1.x=150;
    P1.y=725;

    for (i=0; i<4; i++)
    {
        P1.x=150+i*100;
        nombre=ordi[i];
        couleur_ordi=nombre_couleur(nombre);
        draw_fill_circle(P1,20,couleur_ordi);

    }



}
void choix_couleur()
{
    POINT P1,P2;
    int nombre,i;
    COULEUR couleur_pion;
    /*i=cercle*/
    i=0;
    while(i<4)
    {
        P1=wait_clic();
        P2.x=dep.x+100*i;
        P2.y=dep.y;
        if (P1.y<=199 && P1.y>=100)
        {
            nombre=P1.x/100;
            joueur[i]=nombre;
            couleur_pion=nombre_couleur(nombre);
            draw_fill_circle(P2,20,couleur_pion);
            i=i+1;
        }
        else
        {
            P1.x=50;
            P1.y=80;
            aff_pol("recommencez",55,P1,rouge);
        }

    }
}

void affichage()
{
    int n;
    COULEUR macouleur;

    POINT P1, P2;

    P1.x=100;
    P1.y=750;
    P2.x=500;
    P2.y=200;
    draw_rectangle(P1,P2,thistle);

    P1.x=100;
    P1.y=200;
    P2.x=500;
    P2.y=200;

    while(P1.y<=650 && P2.y<=650)
    {
        P1.y = P1.y+50;
        P2.y = P2.y+50;
        draw_line(P1,P2,thistle);

    }

    P1.x=0;
    P1.y=199;
    P2.x=99;
    P2.y=100;

    while(P1.x<=600 && P2.x<=600)
    {

        n=P1.x/100;
        macouleur = nombre_couleur(n);
        draw_fill_rectangle(P1,P2,macouleur);
        P1.x = P1.x+100;
        P2.x = P2.x+100;
    }

    P1.x=100;
    P1.y=200;
    P2.x=100;
    P2.y=750;

    P1.x=90;
    P1.y=835;
    aff_pol("#MASTERMIND#",50,P1,vert);
    P1.x=10;P1.y=70;
    aff_pol("un chiffre blanc indique un pion de la bonne couleur mais MAL placé",15,P1,blanc);
    P1.x=10;P1.y=50;
    aff_pol("un chiffre rouge indique un pion de la bonne couleur et BIEN placé",15,P1,rouge);
}
void pions()
{
    POINT P1,P2, P3;
    P1.x = dep.x+375;
    P1.y = dep.y;
    P2.x=P1.x+25;
    P2.y=P1.y;
    P3.x=180;
    P3.y=500;



    int i, j, mauvais, bon;

    bon=0;

    for (i=0; i<4; i++)
    {
        if(ordi[i]==joueur[i])
            bon=bon+1;
    }
    aff_int(bon,20,P1,rouge);


    mauvais=0;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            if(ordi[j]==joueur[i])

                mauvais=mauvais+1;
        }

    }
    mauvais=mauvais-bon;
    aff_int(mauvais,20,P2,blanc);


    if(bon==4)
    {
        aff_pol("WIN",100,P3,vert);
        affiche_combi_ordi();
        wait_escape();
    }

}
int main (int argc, char *argv[])
{
    dep.x=150;
    dep.y=225;


    init_graphics (600,850);
    fill_screen(black);


    ecran_debut();
    wait_clic();
    fill_screen(black);
    regles_du_jeu();
    wait_clic();
    fill_screen(black);
    affichage();
    combinaison_ordi();
    /*affiche_combi_ordi();*/
    compteur=0;
    POINT P1;
    P1.x=150;
    P1.y=500;
    while(compteur<10)
    {

        choix_couleur();
        pions();
        compteur=compteur+1;
        dep.y=dep.y+50;

        if(compteur==10)
        {
            aff_pol("LOSE",100,P1,vert);
            affiche_combi_ordi();
            wait_clic();
            fill_screen(bleu);
            P1.x=20;P1.y=550;
            aff_pol("ERROR.404",100,P1,blanc);
            wait_escape();
        }

    }

    wait_escape ();
    exit(0);
}
