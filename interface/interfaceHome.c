#include <gtk/gtk.h>
#include "../include/interfaceConnection.h"
#include "../include/interfaceAdmin.h"

void creer_home(int x){
    GtkWidget *win = NULL;
    if(x==1){
        creer_home_admin(win);
    }else if(x==2){
        creer_home_employe(win);
    }else if(x==3){
        creer_home_responsable(win);
    }
}


void creer_home_employe(GtkWidget *win){
    GtkWidget *text = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Espace Employé GRH");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create the main window */

    vbox = gtk_vbox_new (TRUE, 6);
    hbox = gtk_hbox_new (TRUE, 6);

    gtk_container_add (GTK_CONTAINER (win), vbox);


    text = gtk_label_new("Hello Employé");

    gtk_box_pack_start (GTK_BOX (vbox), text, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

    gtk_widget_show_all (win);

}

void creer_home_responsable(GtkWidget *win){
    GtkWidget *text = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Espace Responsable GRH");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create the main window */

    vbox = gtk_vbox_new (TRUE, 6);
    hbox = gtk_hbox_new (TRUE, 6);

    gtk_container_add (GTK_CONTAINER (win), vbox);


    text = gtk_label_new("Hello Responsable");

    gtk_box_pack_start (GTK_BOX (vbox), text, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

    gtk_widget_show_all (win);

}
