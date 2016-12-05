#include "../include/usefullFn.h"
#include "../include/Utilisateur.h"

GtkWidget *server,*dbusername,*dbpassword;
GtkWidget *cin,*nom,*prenom,*dns,*cnss,*sexe,*email,*numerotel,*ville,*adresse,*pwd_u;


void valid_adduser(GtkWidget *win,gpointer p){
    employe emp;
    emp.cinn = gtk_entry_get_text(GTK_ENTRY(cin));
    emp.nom = gtk_entry_get_text(GTK_ENTRY(nom));
    emp.prenom = gtk_entry_get_text(GTK_ENTRY(prenom));
    emp.dns = gtk_entry_get_text(GTK_ENTRY(dns));
    emp.cnss = gtk_entry_get_text(GTK_ENTRY(cnss));
    //emp.sexe = gtk_entry_get_text(GTK_ENTRY(sexe));
    emp.sexe = "Hommmmme";
    emp.email = gtk_entry_get_text(GTK_ENTRY(email));
    emp.numerotel = gtk_entry_get_text(GTK_ENTRY(numerotel));
    emp.ville = gtk_entry_get_text(GTK_ENTRY(ville));
    emp.adresse = gtk_entry_get_text(GTK_ENTRY(adresse));
    emp.pwd_u = gtk_entry_get_text(GTK_ENTRY(pwd_u));
    if((strcmp(emp.cinn,"")==0) || (strcmp(emp.nom,"")==0) || (strcmp(emp.prenom,"")==0) || (strcmp(emp.dns,"")==0) || (strcmp(emp.cnss,"")==0) || (strcmp(emp.email,"")==0) || (strcmp(emp.numerotel,"")==0) ){
        show_error_invalide(p,"\nIl' y a des champs vide !");
    }else{
        if(add_user_db(emp)==-1){
            show_error_invalide(p,"\nErreur ! verifier les données");
        }else{
            gtk_widget_hide(p);
        }
    }


}

void menu(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
    gtk_widget_hide(win);
    creer_home_admin(win);
}

void listitem_selected (GtkWidget *widget, gpointer *data)
{
    g_print ("item selected - %s\n", data);
}

/// here

void cliquer_btn_gerer_cmpts(GtkWidget *wid,gpointer p){
    GtkWidget *win = NULL;
    creer_fenetre_gerer_comptes(win);
}

void cliquer_configuration(GtkWidget *wid,gpointer p){
    config(wid,p);
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

void add_user (GtkWidget *win,gpointer *p){

    GtkWidget *info,*espace,*lcin,*lnom,*lprenom,*ldns,*lcnss,*lsexe,*lemail,*lnumerotel,*lville,*ladresse,*lpwd_u;
    GtkWidget *combo;
    GtkWidget *ok = NULL,*annuler = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Ajouter employé");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    gtk_window_set_resizable(GTK_WINDOW(win),FALSE);

    /* Create the main window */

    vbox = gtk_vbox_new (FALSE, 6);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n<b>Ajouter employé : </b>\n\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    lcin = gtk_label_new("Cin : ");
    cin =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
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
    gtk_box_pack_start (GTK_BOX (hbox), lnom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), nom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lprenom = gtk_label_new("Prenom : ");
    prenom =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lprenom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), prenom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    ldns = gtk_label_new("Date naissance : ");
    dns =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_placeholder_text (dns,"jj/mm/aaaa");
    gtk_box_pack_start (GTK_BOX (hbox), ldns, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), dns, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lcnss = gtk_label_new("CNSS : ");
    cnss =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
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
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lemail, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), email, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lnumerotel = gtk_label_new("Numéro de téléphone : ");
    numerotel =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lnumerotel, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), numerotel, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lville = gtk_label_new("Ville : ");
    ville =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lville, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), ville, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    ladresse = gtk_label_new("Adresse : ");
    adresse =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), ladresse, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), adresse, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n(*) Si les champ est vide un mot de \n passe génerer sera envoyer par mail.\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    ok = gtk_button_new_with_label ("Ajouter");
    g_signal_connect (ok, "clicked",valid_adduser, win);
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

void add_res (GtkWidget *win,gpointer *p){

    GtkWidget *espace,*info,*cin,*nom,*prenom,*email,*pwd_u;
    GtkWidget *lcin,*lnom,*lprenom,*lemail,*lpwd_u,*lres;
    GtkWidget *ok = NULL,*annuler = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;
    GtkWidget *combo;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Ajouter Responsable");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    gtk_window_set_resizable(GTK_WINDOW(win),FALSE);

    /* Create the main window */

    vbox = gtk_vbox_new (FALSE, 6);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n<b>Ajouter Responsable : </b>\n\n");

    espace = gtk_label_new("\n\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    lcin = gtk_label_new("Cin : ");
    cin =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
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
    gtk_box_pack_start (GTK_BOX (hbox), lnom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), nom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lprenom = gtk_label_new("Prenom : ");
    prenom =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lprenom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), prenom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lres = gtk_label_new("Responsabilité : ");
    combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo), "Finance");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo), "Recrutement");
    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo), "Tas7it");
    gtk_combo_box_set_active (GTK_COMBO_BOX (combo), 0);

    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lres, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lemail = gtk_label_new("Email : ");
    email =  gtk_entry_new();
    gtk_entry_set_placeholder_text (email,"mail@mail.com");
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lemail, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), email, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n(*) Si le champ est vide un mot de \n passe génerer sera envoyer par mail.\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    ok = gtk_button_new_with_label ("Ajouter");
    //g_signal_connect (ok, "clicked",NULL, win);
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

void supp(GtkWidget *win,gpointer p){
    printf("%s",p);
}

void on_changed(GtkWidget *widget, gpointer p)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    char *value;

    if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter))
    {
        gtk_tree_model_get(model, &iter, COL_ID, &value,  -1);
        printf("%s is selected\n", value);
        g_signal_connect (p, "clicked", supp,&value);
        g_free(value);
    }
}

void creer_fenetre_gerer_comptes (GtkWidget *win,gpointer *p){

    gtk_widget_hide(p);
    GtkWidget *button = NULL;
    GtkWidget *scrollbar = NULL;
    GtkWidget* text = NULL;
    GtkWidget *vbox1 ,*vbox;
    GtkWidget *hbox1 = NULL ,*hbox2;
    GtkWidget *listBox = NULL;
    GtkWidget *buttonImage;
    GtkWidget *image = NULL;
    GtkWidget *user = NULL;

    GtkCellRenderer     *renderer;
    GtkTreeModel        *model;
    GtkWidget           *view;
    GtkListStore  *store;
    GtkTreeIter iter;
    GtkTreeSelection *selection;

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


    scrollbar = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollbar),GTK_POLICY_NEVER,GTK_POLICY_ALWAYS);

    view = gtk_tree_view_new ();
    gtk_widget_set_size_request (view, 300, 600);
    store = gtk_list_store_new (NUM_COLS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"ID",renderer,"text", COL_ID,NULL);
    gtk_tree_view_column_set_resizable(view,TRUE);
    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Nom",renderer,"text", COL_NOM,NULL);
    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Prenom",renderer,"text", COL_PRENOM, NULL);
    renderer = gtk_cell_renderer_text_new ();
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Role",renderer,"text", COL_ROLE,NULL);

    show_users(store,iter);
    gtk_tree_view_set_model (GTK_TREE_VIEW (view), GTK_TREE_MODEL(store));
    g_object_unref (model);

    gtk_container_add (GTK_CONTAINER(scrollbar), view);
    gtk_container_add (GTK_CONTAINER (hbox1), scrollbar);

    //gtk_box_pack_start (GTK_BOX (hbox1), listBox, TRUE, TRUE, 10);
    gtk_box_pack_start (GTK_HBOX(hbox1), vbox1, TRUE, TRUE, 20);

    button= gtk_button_new_with_label("Modifier");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

    button= gtk_button_new_with_label("Supprimer");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

    selection = gtk_tree_view_get_selection( GTK_TREE_VIEW(view) );
    //g_signal_connect(selection, "changed", G_CALLBACK(on_changed), button);


    button = gtk_button_new_with_label("Menu");
    g_signal_connect (button, "clicked", menu, win);
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);

    user = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(user), "<b>Ajouter employé : </b>");
    button = gtk_button_new();
    image = gtk_image_new_from_file("images/add_user.png");
    gtk_button_set_image(button,image);
    gtk_box_pack_start (GTK_BOX (vbox1), user, TRUE, TRUE, 10);
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);
    g_signal_connect (button, "clicked", add_user, win);

    user = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(user), "<b>Ajouter Responsable : </b>");
    button = gtk_button_new();
    image = gtk_image_new_from_file("images/add_res.png");
    gtk_button_set_image(button,image);
    gtk_box_pack_start (GTK_BOX (vbox1), user, TRUE, TRUE, 10);
    gtk_box_pack_start (GTK_BOX (vbox1), button, TRUE, TRUE, 10);
    g_signal_connect (button, "clicked", add_res, win);

    /** remplissage VBOX 2 **/

    gtk_widget_show_all (win);
}

void sauv_conf(GtkWidget *win,gpointer p){

    char *sr,*dbu,*dbpass;
    sr=gtk_entry_get_text(GTK_ENTRY(server));
    dbu=gtk_entry_get_text(GTK_ENTRY(dbusername));
    dbpass=gtk_entry_get_text(GTK_ENTRY(dbpassword));

    if((strcmp(sr,"")==0) || (strcmp(dbu,"")==0) || (strcmp(dbpass,"")==0)){
         show_error_invalide(p,"\nIl' y a des champs vide !");
    }else{
        sauv_conf_file(sr,dbu,dbpass);
        gtk_widget_hide(p);
    }
}

void config (GtkWidget *win,gpointer *p){
    char sr[20],dbu[20],dbpass[20];
    GtkWidget *lserver,*lusername,*lpassword,*info,*espace;
    GtkWidget *ok = NULL,*annuler = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Configiration");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    gtk_window_set_resizable(GTK_WINDOW(win),FALSE);

    /* Create the main window */

    get_conf_file(sr,dbu,dbpass);
    vbox = gtk_vbox_new (FALSE, 6);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n<b>Configuration Base de Donnée</b>\n\n");

    espace = gtk_label_new("\n\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    lserver = gtk_label_new("Server : ");
    server =  gtk_entry_new();
    gtk_entry_set_placeholder_text (server,"localhost");
    gtk_entry_set_text(server,sr);
    gtk_box_pack_start (GTK_BOX (hbox), lserver, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), server, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    lusername = gtk_label_new("Username : ");
    dbusername =  gtk_entry_new();
    gtk_entry_set_placeholder_text (dbusername,"root");
    gtk_entry_set_text(dbusername,dbu);
    gtk_box_pack_start (GTK_BOX (hbox), lusername, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), dbusername, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    lpassword = gtk_label_new("Password : ");
    dbpassword =  gtk_entry_new ();
    gtk_entry_set_text(dbpassword,dbpass);
    gtk_box_pack_start (GTK_BOX (hbox), lpassword, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), dbpassword, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), espace, FALSE, FALSE, 0);
    hbox = gtk_hbox_new (TRUE, 6);
    ok = gtk_button_new_with_label ("Sauvgarder");
    g_signal_connect (ok, "clicked",G_CALLBACK (sauv_conf), win);
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

