#include "../include/interfaceConnection.h"


typedef struct {
    GtkWidget *username;
    GtkWidget *password;
} entriesConnection ;


static void clicked_btn_authentification (GtkWidget *wid,gpointer p)
{
    entriesConnection* entries = (entriesConnection*) p;
    gchar *login = gtk_entry_get_text(GTK_ENTRY(entries->username) );
    gchar *pwd   = gtk_entry_get_text(GTK_ENTRY(entries->password) );
    printf("%s" ,login);
    printf("%s" ,pwd);

    /*
    if(verifierLoginPwd("Rami","Imar")==TRUE){
          creer_fenetre_principale(fenetre_principale);

    }
    */
}


void creer_fenetre_authentification (GtkWidget *win ){
    GtkWidget *username,*password,*entry_login,*entry_pwd,*tab;
    GtkWidget *button = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL,*usernamebox=NULL,*passwordbox=NULL;;
    entriesConnection entries;
    GtkWidget *image = NULL;
    entriesConnection st;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Authentification");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create the main window */

    vbox = gtk_vbox_new (TRUE, 6);
    hbox = gtk_hbox_new (TRUE, 6);
    usernamebox = gtk_hbox_new (TRUE, 6);
    passwordbox = gtk_hbox_new (TRUE, 6);

    gtk_container_add (GTK_CONTAINER (win), vbox);

    image = gtk_image_new_from_file("img/users_lock.png");

    username = gtk_label_new("Nom d'utilisateur : ");
    st.username =  gtk_entry_new ();
    password = gtk_label_new("Mot de Passe : ");
    gtk_entry_set_placeholder_text (st.username,"");
    st.password =  gtk_entry_new ();
    gtk_entry_set_visibility (st.password,FALSE);
    gtk_entry_set_invisible_char(st.password,'*');

    gtk_box_pack_start (GTK_BOX (vbox), image, TRUE, TRUE, 1);

    gtk_box_pack_start (GTK_BOX (usernamebox), username, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (usernamebox), st.username, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwordbox), password, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwordbox), st.password, TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), usernamebox, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), passwordbox, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

    button = gtk_button_new_with_label ("Connecter");

    g_signal_connect (button, "clicked",G_CALLBACK (clicked_btn_authentification), (gpointer) &st);

    gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 0);

    button = gtk_button_new_with_label ("Fermer");
    g_signal_connect (button, "clicked", gtk_main_quit, NULL);

    gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 0);

    gtk_widget_show_all (win);
}
