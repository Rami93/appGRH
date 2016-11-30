#include "../include/usefullFn.h"

void menu(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
    gtk_widget_hide(win);
    creer_home_admin(win);
}

void listitem_selected (GtkWidget *widget, gpointer *data)
{
    g_print ("item selected - %s\n", data);
}

void ajouterItemUtilisateur (GtkWidget *listbox, char *sText)
{
    GtkWidget     *item;

    /* --- Create a list item from the data element --- */

//    item = gtk_label_new(sText);
    item = gtk_list_box_row_new();
  //  gtk_box_pack_start(item,);
  //  gtk_box_pack_start (GTK_BOX (hbox_btn), button, TRUE, TRUE, 10);
    gtk_container_add(GTK_CONTAINER(item),gtk_label_new(sText));
 //   g_signal_connect ( item, "select", listitem_selected, sText);

    /* --- Conigure for the "select" event --- */
    gtk_widget_set_size_request(listbox,300,300);;

    /* --- Add item to the listbox --- */
    gtk_list_box_prepend(listbox,item);
 //   gtk_container_add (GTK_CONTAINER (listbox), item);

    /* --- Make it visible --- */
    gtk_widget_show (item);
}

void cliquer_btn_gerer_cmpts(GtkWidget *wid,gpointer p){
    GtkWidget *win = NULL;
    creer_fenetre_gerer_comptes(win);
}

void cliquer_configuration(GtkWidget *wid,gpointer p){

}

void creer_home_admin(GtkWidget *win){
    GtkWidget *button = NULL;
    GtkWidget* text = NULL;
    GtkWidget *vbox1 ,*vbox2 , *vbox3 = NULL;
    GtkWidget *hbox = NULL;
    GtkWidget *entry_login = NULL;
    GtkWidget *entry_pwd = NULL;
    GtkWidget *image = NULL;
    GtkWidget *frame1,*frame2,*frame3;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Espace Administrateur");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create the main window */

    hbox = gtk_hbox_new (FALSE, 6);
    vbox1 = gtk_vbox_new (FALSE, 2);
    vbox2 = gtk_vbox_new (FALSE, 2);
    vbox3 = gtk_vbox_new (FALSE, 2);
    gtk_container_add (GTK_CONTAINER (win), hbox);

    frame1 = gtk_frame_new("Gérer les comptes\n");
    gtk_frame_set_label_align(GTK_FRAME(frame1), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox), frame1, TRUE, TRUE, 5);

    frame2 = gtk_frame_new("Configuration\n");
    gtk_frame_set_label_align(GTK_FRAME(frame2), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox), frame2, TRUE, TRUE, 5);

    frame3 = gtk_frame_new("Se déconnecter\n");
    gtk_frame_set_label_align(GTK_FRAME(frame3), 0, 0.0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame3), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox), frame3, TRUE, TRUE, 5);


    button = gtk_button_new();
    image = gtk_image_new_from_file("images/icon_users.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", cliquer_btn_gerer_cmpts, win);
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame1), vbox1);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/conf.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", cliquer_configuration, NULL);
    gtk_box_pack_start (GTK_BOX (vbox2), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame2), vbox2);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/logout.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", logout, win);
    gtk_box_pack_start (GTK_BOX (vbox3), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame3), vbox3);

    gtk_widget_show_all (win);

}

void creer_fenetre_gerer_comptes (GtkWidget *win,gpointer *p){
    gtk_widget_hide(p);
    GtkWidget *button = NULL;
    GtkWidget* text = NULL;
    GtkWidget *vbox1 ,*vbox;
    GtkWidget *hbox1 = NULL ,*hbox2;
    GtkWidget *listBox = NULL;
    GtkWidget *buttonImage;
    GtkWidget *image = NULL;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Gérer les comptes");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);


    /* Create the main window */

    hbox1 = gtk_hbox_new (FALSE, 6);
    vbox1 = gtk_vbox_new (FALSE, 10);
    vbox = gtk_vbox_new (FALSE, 1);
    hbox2 = gtk_hbox_new(FALSE, 0);

    gtk_container_add (GTK_CONTAINER (win), vbox);

    /* remplissage VBOX 1 */

    gtk_box_pack_start (GTK_HBOX(vbox), hbox1, TRUE, TRUE, 20);
    gtk_box_pack_start (GTK_HBOX (vbox), hbox2, TRUE, TRUE, 20);


    //VBOX1
    listBox = gtk_list_box_new() ;
    ajouterItemUtilisateur(listBox,"Utilisateur 1");
    ajouterItemUtilisateur(listBox,"Utilisateur 2");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");
    ajouterItemUtilisateur(listBox,"Utilisateur 3");


    gtk_box_pack_start (GTK_BOX (hbox1), listBox, TRUE, TRUE, 10);
    gtk_box_pack_start (GTK_HBOX(hbox1), vbox1, TRUE, TRUE, 20);

    button= gtk_button_new_with_label("Modifier");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

    button= gtk_button_new_with_label("Supprimer");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);
    button = gtk_button_new_with_label("Menu");
    g_signal_connect (button, "clicked", menu, win);
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/conf.png");
    gtk_button_set_image(button,image);
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);

    image = gtk_image_new_from_file("images/conf.png");
    gtk_button_set_image(button,image);

    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);


    /** remplissage VBOX 2 **/

    gtk_widget_show_all (win);
}
