#include "../include/interfaceConnection.h"
#include "../include/interfaceHome.h"
#include "../include/Utilisateur.h"



    GtkWidget *entry_login;
    GtkWidget *entry_pwd;


static void clicked_btn_authentification (GtkWidget *wid,gpointer p)
{
    gchar *login = gtk_entry_get_text(GTK_ENTRY(entry_login) );
    gchar *pwd   = gtk_entry_get_text(GTK_ENTRY(entry_pwd) );
    int res=verifierLoginPwd(login,pwd);
    if(res!=0){
        gtk_widget_hide (p);
        creer_home(res);
        //printf("\nCorrect open %d ^^",res);

    }else{
        printf("\n not correct :/");
    }

}


void creer_fenetre_authentification (GtkWidget *win ){
    GtkWidget *username,*password,*tab;
    GtkWidget *button = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL,*usernamebox=NULL,*passwordbox=NULL;;
    GtkWidget *image = NULL;

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
    entry_login =  gtk_entry_new ();
    password = gtk_label_new("Mot de Passe : ");
    gtk_entry_set_placeholder_text (entry_login,"");
    entry_pwd =  gtk_entry_new ();
    gtk_entry_set_visibility (entry_pwd,FALSE);
    gtk_entry_set_invisible_char(entry_pwd,'*');

    gtk_box_pack_start (GTK_BOX (vbox), image, TRUE, TRUE, 1);

    gtk_box_pack_start (GTK_BOX (usernamebox), username, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (usernamebox), entry_login, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwordbox), password, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (passwordbox), entry_pwd, TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), usernamebox, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), passwordbox, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

    button = gtk_button_new_with_label ("Connecter");

    g_signal_connect (button, "clicked",G_CALLBACK (clicked_btn_authentification), win);

    gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 0);

    button = gtk_button_new_with_label ("Fermer");
    g_signal_connect (button, "clicked", gtk_main_quit, NULL);

    gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 0);

    gtk_widget_show_all (win);
}
