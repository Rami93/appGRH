#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <gtk/gtk.h>

enum
{
  COL_ID=0,
  COL_NOM=1,
  COL_PRENOM=2,
  COL_ROLE=3,
  NUM_COLS
} ;

struct struct_employe{
    char *cinn,*username,*nom,*prenom,*dns,*cnss,*sexe,*email,*numerotel,*ville,*adresse,*pwd_u;
};

typedef struct struct_employe employe;

int verifierLoginPwd(char *, char *);
int add_user_db(employe emp);
void ajouterItemUtilisateur (GtkWidget *listbox, char *sText);
void show_users(GtkListStore  *store,GtkTreeIter iter);

#endif // UTILISATEUR_H_INCLUDED
