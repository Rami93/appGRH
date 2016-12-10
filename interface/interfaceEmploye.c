#include <gtk/gtk.h>
#include "../include/TypeDef.h"

GtkWidget *cin,*nom,*prenom,*dns,*cnss,*sexe,*email,*numerotel,*ville,*adresse,*pwd_u,*un;
GtkWidget *view1,*view2;
GtkListStore  *store;

void logout_u(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
    gtk_widget_hide(win);
    authentification(win);
}

void close_window_mod(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
}

void modifier_info_per(GtkWidget *win)
{
    GtkWidget *info,*espace,*lcin,*lun,*lnom,*lprenom,*ldns,*lcnss,*lsexe,*lemail,*lnumerotel,*lville,*ladresse,*lpwd_u;
    GtkWidget *combo;
    GtkWidget *ok = NULL,*annuler = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;
    employe emp;
    int id = Getsession();
    get_user(&emp,id);
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Modifier Information employé");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    gtk_window_set_resizable(GTK_WINDOW(win),FALSE);

    vbox = gtk_vbox_new (FALSE, 6);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n<b>Modifier Information: </b>\n\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    lcin = gtk_label_new("Cin : ");
    cin =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(cin,emp.cinn);
    gtk_box_pack_start (GTK_BOX (hbox), lcin, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), cin, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    lpwd_u = gtk_label_new("Mot de Passe (*) : ");
    pwd_u =  gtk_entry_new ();
    gtk_box_pack_start (GTK_BOX (hbox), lpwd_u, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), pwd_u, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);


    lnom = gtk_label_new("Nom : ");
    nom =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(nom,emp.nom);
    gtk_box_pack_start (GTK_BOX (hbox), lnom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), nom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lprenom = gtk_label_new("Prenom : ");
    prenom =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(prenom,emp.prenom);
    gtk_box_pack_start (GTK_BOX (hbox), lprenom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), prenom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    ldns = gtk_label_new("Date naissance : ");
    dns =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_placeholder_text (dns,"jj/mm/aaaa");
    gtk_entry_set_text(dns,emp.dns);
    gtk_box_pack_start (GTK_BOX (hbox), ldns, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), dns, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lcnss = gtk_label_new("CNSS : ");
    cnss =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(cnss,emp.cnss);
    gtk_box_pack_start (GTK_BOX (hbox), lcnss, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), cnss, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lsexe = gtk_label_new("Sexe : ");
    combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo), "Homme");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo), "Femme");
    gtk_combo_box_set_active (GTK_COMBO_BOX (combo), 0);

    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lsexe, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lemail = gtk_label_new("Email : ");
    email =  gtk_entry_new();
    gtk_entry_set_placeholder_text (email,"mail@mail.com");
    gtk_entry_set_text(email,emp.email);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lemail, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), email, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lnumerotel = gtk_label_new("Numéro de téléphone : ");
    numerotel =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(numerotel,emp.numerotel);
    gtk_box_pack_start (GTK_BOX (hbox), lnumerotel, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), numerotel, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lville = gtk_label_new("Ville : ");
    ville =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(ville,emp.ville);
    gtk_box_pack_start (GTK_BOX (hbox), lville, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), ville, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    ladresse = gtk_label_new("Adresse : ");
    adresse =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(adresse,emp.adresse);
    gtk_box_pack_start (GTK_BOX (hbox), ladresse, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), adresse, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    ok = gtk_button_new_with_label ("Modifier");
    g_signal_connect (ok, "clicked",NULL, win);
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window_mod, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

void ajouterItem (GtkWidget *listbox, char *sText)
{
    GtkWidget     *item;
    item = gtk_list_box_row_new();
    gtk_container_add(GTK_CONTAINER(item),gtk_label_new(sText));
    gtk_widget_set_size_request(listbox,150,200);
    gtk_list_box_prepend(listbox,item);
    gtk_widget_show (item);
}

void gerer_compitance(GtkWidget *win,gpointer *p)
{

    close_window(win,p);
    GtkWidget *button = NULL;
    GtkWidget *scrollbar = NULL,*scrollbar2 = NULL;
    GtkWidget* text = NULL;
    GtkWidget *vbox1,*vbox;
    GtkWidget *hbox1 = NULL,*hbox2;
    GtkWidget *listBox = NULL;
    GtkWidget *buttonImage;
    GtkWidget *image = NULL;
    GtkWidget *user = NULL;
    GtkCellRenderer     *renderer;
    GtkTreeModel        *model;
    GtkTreeIter iter;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Gérer les comptes");
    gtk_window_set_default_size(GTK_WINDOW(win), 600, 300);
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    hbox1 = gtk_hbox_new (FALSE, 6);
    vbox1 = gtk_vbox_new (FALSE, 10);
    vbox = gtk_vbox_new (FALSE, 1);
    hbox2 = gtk_hbox_new(FALSE, 0);

    gtk_container_add (GTK_CONTAINER (win), vbox);

    gtk_box_pack_start (GTK_HBOX(vbox), hbox1, TRUE, TRUE, 20);
    gtk_box_pack_start (GTK_HBOX (vbox), hbox2, TRUE, TRUE, 20);


    scrollbar = gtk_scrolled_window_new (NULL, NULL);
    scrollbar2 = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollbar),GTK_POLICY_NEVER,GTK_POLICY_ALWAYS);

    view1 = gtk_tree_view_new ();
    view2 = gtk_tree_view_new ();

    gtk_widget_set_size_request (view1, 250, 600);
    gtk_tree_view_column_set_resizable(view1,TRUE);
    store = gtk_list_store_new (NUM_COLSC,G_TYPE_STRING, G_TYPE_STRING);

    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view1),-1,"ID",renderer,"text", COL_IDC,NULL);

    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view1),-1,"Competence",renderer,"text", COL_NOMC,NULL);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,COL_IDC, "1",COL_NOMC, "Nom",-1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,COL_IDC, "2",COL_NOMC, "Nom 2",-1);

    gtk_tree_view_set_model (GTK_TREE_VIEW (view1), GTK_TREE_MODEL(store));
    gtk_container_add (GTK_CONTAINER(scrollbar), view1);
    gtk_container_add (GTK_CONTAINER (hbox1), scrollbar);
    gtk_box_pack_start (GTK_HBOX(hbox1), vbox1, TRUE, TRUE, 20);

    user = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(user), "<b>Ajouter Cpmétance : </b>");

    listBox = gtk_list_box_new() ;
    ajouterItem(listBox,"item 1");
    ajouterItem(listBox,"item 2");
    ajouterItem(listBox,"item 1");
    ajouterItem(listBox,"item 2");
    ajouterItem(listBox,"item 1");
    ajouterItem(listBox,"item 2");

    gtk_container_add (GTK_CONTAINER(scrollbar2), listBox);
    gtk_container_add (GTK_CONTAINER (vbox1), scrollbar2);

    button= gtk_button_new_with_label("Ajouter");
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);

    button= gtk_button_new_with_label("Ajouter Autr com");
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);

    button= gtk_button_new_with_label("Modifier");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);
    //g_signal_connect (button, "clicked", modifier, win);
    button= gtk_button_new_with_label("Supprimer");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);
    //g_signal_connect (button, "clicked", supp, win);

    button = gtk_button_new_with_label("Menu");
    //g_signal_connect (button, "clicked", menu, win);
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

  /*  user = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(user), "<b>Ajouter Responsable : </b>");
    button = gtk_button_new();
    image = gtk_image_new_from_file("images/add_res.png");
    gtk_button_set_image(button,image);
    gtk_box_pack_start (GTK_BOX (vbox1), user, TRUE, TRUE, 10);
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);*/
    //g_signal_connect (button, "clicked", add_res, win);

    /** remplissage VBOX 2 **/

    gtk_widget_show_all (win);
}

void inerface_conge(GtkWidget *win,gpointer *p)
{

    close_window(win,p);
    GtkWidget *button = NULL;
    GtkWidget *scrollbar = NULL,*scrollbar2 = NULL;
    GtkWidget *champ,*label;
    GtkWidget *vbox1,*vbox;
    GtkWidget *hbox1 = NULL,*hbox2,*hbox3;
    GtkWidget *listBox = NULL;
    GtkWidget *buttonImage;
    GtkWidget *image = NULL;
    GtkWidget *user = NULL;
    GtkCellRenderer     *renderer;
    GtkTreeModel        *model;
    GtkTreeIter iter;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Demande de congé");
    gtk_window_set_default_size(GTK_WINDOW(win), 600, 300);
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    hbox1 = gtk_hbox_new (FALSE, 6);
    vbox1 = gtk_vbox_new (FALSE, 10);
    vbox = gtk_vbox_new (FALSE, 1);
    hbox2 = gtk_hbox_new(FALSE, 0);

    gtk_container_add (GTK_CONTAINER (win), vbox);

    gtk_box_pack_start (GTK_HBOX(vbox), hbox1, TRUE, TRUE, 20);
    gtk_box_pack_start (GTK_HBOX (vbox), hbox2, TRUE, TRUE, 20);


    scrollbar = gtk_scrolled_window_new (NULL, NULL);
    scrollbar2 = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollbar),GTK_POLICY_NEVER,GTK_POLICY_ALWAYS);

    view1 = gtk_tree_view_new ();
    gtk_widget_set_size_request (view1, 250, 600);
    gtk_tree_view_column_set_resizable(view1,TRUE);
    store = gtk_list_store_new (NUM_COLSC,G_TYPE_STRING, G_TYPE_STRING);

    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view1),-1,"ID",renderer,"text", COL_IDC,NULL);

    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view1),-1,"Competence",renderer,"text", COL_NOMC,NULL);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,COL_IDC, "1",COL_NOMC, "Nom",-1);

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,COL_IDC, "2",COL_NOMC, "Nom 2",-1);

    gtk_tree_view_set_model (GTK_TREE_VIEW (view1), GTK_TREE_MODEL(store));
    gtk_container_add (GTK_CONTAINER(scrollbar), view1);
    gtk_container_add (GTK_CONTAINER (hbox1), scrollbar);
    gtk_box_pack_start (GTK_HBOX(hbox1), vbox1, TRUE, TRUE, 20);


    user = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(user), "<b>Demande congé : </b>");
    gtk_box_pack_start (GTK_HBOX(vbox1), user, TRUE, TRUE, 20);

    label = gtk_label_new("Duré : ");
    champ =  gtk_entry_new();
    hbox3 = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox3), label, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox3), champ, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox1), hbox3, FALSE, FALSE, 0);


    button= gtk_button_new_with_label("Demande Congé");
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);

    button = gtk_button_new_with_label("Menu");
    //g_signal_connect (button, "clicked", menu, win);
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

    gtk_widget_show_all (win);
}


void creer_home_emp(GtkWidget *win){
    GtkWidget *button = NULL;
    GtkWidget* text = NULL;
    GtkWidget *vbox,*vbox1 ,*vbox2 , *vbox3,*vbox4 ,*vbox5 , *vbox6;
    GtkWidget *hbox1 = NULL,*hbox2 = NULL;
    GtkWidget *entry_login = NULL;
    GtkWidget *entry_pwd = NULL;
    GtkWidget *image = NULL;
    GtkWidget *frame1,*frame2,*frame3,*frame4,*frame5,*frame6;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Espace Employé");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    hbox1 = gtk_hbox_new (FALSE, 6);
    hbox2 = gtk_hbox_new (FALSE, 6);
    vbox = gtk_vbox_new (FALSE, 2);
    vbox1 = gtk_vbox_new (FALSE, 2);
    vbox2 = gtk_vbox_new (FALSE, 2);
    vbox3 = gtk_vbox_new (FALSE, 2);
    vbox4 = gtk_vbox_new (FALSE, 2);
    vbox5 = gtk_vbox_new (FALSE, 2);
    vbox6 = gtk_vbox_new (FALSE, 2);

    gtk_container_add(vbox, hbox1);
    gtk_container_add(vbox, hbox2);

    gtk_container_add (GTK_CONTAINER (win), vbox);

    frame1 = gtk_frame_new("Gérer information\n");
    gtk_frame_set_label_align(GTK_FRAME(frame1), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox1), frame1, TRUE, TRUE, 5);

    frame2 = gtk_frame_new("Gérer Compétance...\n");
    gtk_frame_set_label_align(GTK_FRAME(frame2), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox1), frame2, TRUE, TRUE, 5);

    frame3 = gtk_frame_new("Génerer CV\n");
    gtk_frame_set_label_align(GTK_FRAME(frame3), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame3), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox1), frame3, TRUE, TRUE, 5);

    gtk_container_add(GTK_CONTAINER(hbox1), vbox);

    frame4 = gtk_frame_new("Demande Congé\n");
    gtk_frame_set_label_align(GTK_FRAME(frame4), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame4), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox2), frame4, TRUE, TRUE, 5);

    frame5 = gtk_frame_new("Fiche de pais\n");
    gtk_frame_set_label_align(GTK_FRAME(frame5), 0, 0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame5), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox2), frame5, TRUE, TRUE, 5);

    frame6 = gtk_frame_new("Se déconnecter\n");
    gtk_frame_set_label_align(GTK_FRAME(frame6), 0, 0.0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame6), GTK_SHADOW_OUT);
    gtk_box_pack_start (GTK_HBOX(hbox2), frame6, TRUE, TRUE, 5);
    gtk_container_add(GTK_CONTAINER(hbox2), vbox);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/user.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", modifier_info_per, NULL);
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame1), vbox1);


    button = gtk_button_new();
    image = gtk_image_new_from_file("images/skills.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", gerer_compitance, win);
    gtk_box_pack_start (GTK_BOX (vbox2), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame2), vbox2);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/pdf.png");
    gtk_button_set_image(button,image);
    //g_signal_connect (button, "clicked", logout, win);
    gtk_box_pack_start (GTK_BOX (vbox3), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame3), vbox3);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/vec.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", inerface_conge, win);
    gtk_box_pack_start (GTK_BOX (vbox4), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame4), vbox4);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/fiche.png");
    gtk_button_set_image(button,image);
    //g_signal_connect (button, "clicked", logout, win);
    gtk_box_pack_start (GTK_BOX (vbox5), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame5), vbox5);

    button = gtk_button_new();
    image = gtk_image_new_from_file("images/logout_u.png");
    gtk_button_set_image(button,image);
    g_signal_connect (button, "clicked", logout_u, win);
    gtk_box_pack_start (GTK_BOX (vbox6), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame6), vbox6);

    gtk_widget_show_all (win);
}
