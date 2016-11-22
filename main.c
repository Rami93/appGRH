#include <stdlib.h>
#include <gtk/gtk.h>
#include "Utilisateur.h"
#include "interfaceConnection.h";
int main (int argc, char *argv[])
{

    GtkWidget *win = NULL;
      gtk_init (&argc, &argv);
    creer_fenetre_authentification(win);
  gtk_main ();
  // Modification
  return 0;
}
