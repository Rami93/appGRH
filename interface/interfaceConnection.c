#include "interfaceConnection.h"

typedef struct {
    GtkWidget * entryLogin;
    GtkWidget * entryPwd;
} entriesConnection ;
static void clicked_btn_authentification (GtkWidget *wid,gpointer p)
{
  GtkWidget *fenetre_principale = NULL;
/*
  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Hello World!");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);*/
    entriesConnection * entries = p;
    GtkWidget * el = entries->entryLogin;
    GtkWidget * ep = entries->entryPwd;


    gchar * login = gtk_entry_get_text(GTK_ENTRY(el) );
    gchar * pwd   = gtk_entry_get_text(GTK_ENTRY(ep) );
    printf("%s" ,login);
    printf("%s" ,pwd);
  /*
    if(verifierLoginPwd("Rami","Imar")==TRUE){
          creer_fenetre_principale(fenetre_principale);

    }
*/
}

void creer_fenetre_principale (GtkWidget *win ){



}
void creer_fenetre_authentification (GtkWidget *win ){


    GtkWidget *button = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;
    GtkWidget *entry_login = NULL;
    GtkWidget *entry_pwd = NULL;
    entriesConnection entries;

   // inititialisation(argc,argv,win);
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "Authentification");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);
  /* Create the main window */


  vbox = gtk_vbox_new (TRUE, 6);
  hbox = gtk_hbox_new (TRUE, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);
 /*
  button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (helloWorld), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    */
  entry_login =  gtk_entry_new ();
  gtk_entry_set_placeholder_text (entry_login,"Nom d'utilisateur");
  entry_pwd =  gtk_entry_new ();
  gtk_entry_set_visibility (entry_pwd,FALSE);
  gtk_entry_set_invisible_char(entry_pwd,'*');
  gtk_box_pack_start (GTK_BOX (vbox), entry_login, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), entry_pwd, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Connecter");

  entries.entryLogin = entry_login;
  entries.entryPwd = entry_pwd;
  g_signal_connect (button, "clicked",G_CALLBACK ( clicked_btn_authentification), &entries);

  gtk_box_pack_start (GTK_BOX (hbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label ("Fermer");
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);

  gtk_box_pack_start (GTK_BOX (hbox), button, TRUE, TRUE, 0);

  gtk_widget_show_all (win);
}
