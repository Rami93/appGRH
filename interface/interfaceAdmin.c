#include "../include/usefullFn.h"


GtkWidget *server,*dbusername,*dbpassword;
GtkWidget *cin,*nom,*prenom,*dns,*cnss,*sexe,*email,*numerotel,*ville,*adresse,*pwd_u,*un;
GtkWidget *view;
GtkListStore  *store;
int id;

void menu(GtkWidget *win,gpointer p)
{
    close_window(win,p);
    creer_home_admin(win);
}

void cliquer_btn_gerer_cmpts(GtkWidget *wid,gpointer p)
{
    GtkWidget *win = NULL;
    creer_fenetre_gerer_comptes(win);
}

void cliquer_configuration(GtkWidget *wid,gpointer p)
{
    config(wid,p);
}

void logout_ad(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
    gtk_widget_hide(win);
    authentification(win);
}

void creer_home_admin(GtkWidget *win)
{
    GtkWidget *menubar;
    GtkWidget *fileMenu;
    GtkWidget *fileMi;
    GtkWidget *quitMi;
    GtkWidget *button = NULL;
    GtkWidget* text = NULL;
    GtkWidget *vbox1,*vbox2, *vbox3 = NULL;
    GtkWidget *vbox;
    GtkWidget *hbox = NULL;
    GtkWidget *entry_login = NULL;
    GtkWidget *entry_pwd = NULL;
    GtkWidget *image = NULL;
    GtkWidget *frame1,*frame2,*frame3;
    GtkWidget *toolbar;
    GtkToolItem *newTb;
    GtkToolItem *openTb;
    GtkToolItem *saveTb;
    GtkToolItem *sep;
    GtkToolItem *exitTb;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 0);
    gtk_window_set_title (GTK_WINDOW (win), "Espace Administrateur");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    vbox = gtk_vbox_new(FALSE, 0);
    menubar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();

    fileMi = gtk_menu_item_new_with_label("File");
    quitMi = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    /* Create the main window */

    hbox = gtk_hbox_new (FALSE, 6);
    vbox1 = gtk_vbox_new (FALSE, 2);
    vbox2 = gtk_vbox_new (FALSE, 2);
    vbox3 = gtk_vbox_new (FALSE, 2);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

  newTb = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

  openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

  sep = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);

  exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

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
    g_signal_connect (button, "clicked", logout_ad, win);
    gtk_box_pack_start (GTK_BOX (vbox3), button, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(frame3), vbox3);

    gtk_widget_show_all (win);

}

void valid_adduser(GtkWidget *win,gpointer p)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    employe emp;
    emp.cinn = gtk_entry_get_text(GTK_ENTRY(cin));
    emp.nom = gtk_entry_get_text(GTK_ENTRY(nom));
    emp.username = gtk_entry_get_text(GTK_ENTRY(un));
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
    if((strcmp(emp.cinn,"")==0) || (strcmp(emp.nom,"")==0) || (strcmp(emp.prenom,"")==0) || (strcmp(emp.dns,"")==0) || (strcmp(emp.cnss,"")==0) || (strcmp(emp.email,"")==0) || (strcmp(emp.numerotel,"")==0) )
    {
        show_error_invalide(p,"\nIl' y a des champs vide !");
    }
    else
    {
        if(add_user_db(emp)==-1)
        {
            show_error_invalide(p,"\nErreur ! verifier les données");
        }
        else
        {
            close_window(win,p);
            store = gtk_list_store_new (NUM_COLS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
            show_users(store,iter);
            gtk_tree_view_set_model (GTK_TREE_VIEW(view), GTK_TREE_MODEL(store));
        }
    }

}

void add_user (GtkWidget *win,gpointer *p)
{

    GtkWidget *info,*espace,*lcin,*lun,*lnom,*lprenom,*ldns,*lcnss,*lsexe,*lemail,*lnumerotel,*lville,*ladresse,*lpwd_u;
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

    lun = gtk_label_new("Nom d'utilisateur : ");
    un =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lun, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), un, TRUE, TRUE, 0);
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

void valid_addres(GtkWidget *win,gpointer p)
{
    GtkTreeIter iter;
    GtkTreeModel *model;

    employe emp;
    emp.cinn = gtk_entry_get_text(GTK_ENTRY(cin));
    emp.nom = gtk_entry_get_text(GTK_ENTRY(nom));
    emp.username = gtk_entry_get_text(GTK_ENTRY(un));
    emp.prenom = gtk_entry_get_text(GTK_ENTRY(prenom));
    emp.email = gtk_entry_get_text(GTK_ENTRY(email));
    emp.role = "responsable";
    emp.pwd_u = gtk_entry_get_text(GTK_ENTRY(pwd_u));
    if((strcmp(emp.cinn,"")==0) || (strcmp(emp.nom,"")==0) || (strcmp(emp.prenom,"")==0) || (strcmp(emp.email,"")==0) )
    {
        show_error_invalide(p,"\nIl' y a des champs vide !");
    }
    else
    {
        if(add_res_db(emp)==-1)
        {
            show_error_invalide(p,"\nErreur ! verifier les données");
        }
        else
        {
            close_window(win,p);
            store = gtk_list_store_new (NUM_COLS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
            show_users(store,iter);
            gtk_tree_view_set_model (GTK_TREE_VIEW(view), GTK_TREE_MODEL(store));
        }
    }

}

void add_res(GtkWidget *win,gpointer *p)
{

    GtkWidget *espace,*info;
    GtkWidget *lcin,*lnom,*lprenom,*lemail,*lpwd_u,*lres,*lun;
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

    lun = gtk_label_new("Nom d'utilisateur : ");
    un =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lun, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), un, TRUE, TRUE, 0);
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
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    g_signal_connect (ok, "clicked",valid_addres, win);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

void valid_modres(GtkWidget *win,gpointer *p)
{

}

void modifier_res(GtkWidget *win,employe emp)
{

    GtkWidget *espace,*info;
    GtkWidget *lcin,*lnom,*lprenom,*lemail,*lpwd_u,*lres,*lun;
    GtkWidget *ok = NULL,*annuler = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;
    GtkWidget *combo;

    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Modifier Information Responsable");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);
    gtk_window_set_resizable(GTK_WINDOW(win),FALSE);

    /* Create the main window */

    vbox = gtk_vbox_new (FALSE, 6);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    info = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(info), "\n<b>Modifier Responsable : </b>\n\n");

    espace = gtk_label_new("\n\n");
    gtk_box_pack_start (GTK_BOX (vbox), info, FALSE, FALSE, 0);

    lcin = gtk_label_new("Cin : ");
    cin =  gtk_entry_new();
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_entry_set_text(cin,emp.cinn);
    gtk_box_pack_start (GTK_BOX (hbox), lcin, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), cin, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lun = gtk_label_new("Nom d'utilisateur : ");
    un =  gtk_entry_new();
    gtk_entry_set_text(un,emp.username);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lun, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), un, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);


    hbox = gtk_hbox_new (TRUE, 6);
    lpwd_u = gtk_label_new("Mot de Passe (*) : ");
    pwd_u =  gtk_entry_new ();
    gtk_entry_set_text(pwd_u,emp.pwd_u);
    gtk_box_pack_start (GTK_BOX (hbox), lpwd_u, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), pwd_u, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);


    lnom = gtk_label_new("Nom : ");
    nom =  gtk_entry_new();
    gtk_entry_set_text(nom,emp.nom);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lnom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), nom, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    lprenom = gtk_label_new("Prenom : ");
    prenom =  gtk_entry_new();
    gtk_entry_set_text(prenom,emp.prenom);
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
    gtk_entry_set_text(email,emp.email);
    gtk_entry_set_placeholder_text (email,"mail@mail.com");
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lemail, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), email, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    ok = gtk_button_new_with_label ("Modifier");
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    g_signal_connect (ok, "clicked",valid_modres, win);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

void valid_modemp(GtkWidget *win,gpointer *p)
{

    GtkTreeIter iter;
    GtkTreeModel *model;
    employe emp;
    emp.cinn = gtk_entry_get_text(GTK_ENTRY(cin));
    emp.nom = gtk_entry_get_text(GTK_ENTRY(nom));
    emp.username = gtk_entry_get_text(GTK_ENTRY(un));
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
    if((strcmp(emp.cinn,"")==0) || (strcmp(emp.nom,"")==0) || (strcmp(emp.prenom,"")==0) || (strcmp(emp.dns,"")==0) || (strcmp(emp.cnss,"")==0) || (strcmp(emp.email,"")==0) || (strcmp(emp.numerotel,"")==0) )
    {
        show_error_invalide(p,"\nIl' y a des champs vide !");
    }
    else
    {
        if(update_emp(emp,id)==-1)
        {
            show_error_invalide(p,"\nErreur ! verifier les données");
        }
        else
        {
            close_window(win,p);
            store = gtk_list_store_new (NUM_COLS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
            show_users(store,iter);
            gtk_tree_view_set_model (GTK_TREE_VIEW(view), GTK_TREE_MODEL(store));
        }
    }

}


void modifier_emp(GtkWidget *win,employe emp)
{
    GtkWidget *info,*espace,*lcin,*lun,*lnom,*lprenom,*ldns,*lcnss,*lsexe,*lemail,*lnumerotel,*lville,*ladresse,*lpwd_u;
    GtkWidget *combo;
    GtkWidget *ok = NULL,*annuler = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox = NULL;

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

    lun = gtk_label_new("Nom d'utilisateur : ");
    un =  gtk_entry_new();
    gtk_entry_set_text(un,emp.username);
    hbox = gtk_hbox_new (TRUE, 6);
    gtk_box_pack_start (GTK_BOX (hbox), lun, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), un, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (TRUE, 6);
    lpwd_u = gtk_label_new("Mot de Passe (*) : ");
    pwd_u =  gtk_entry_new ();
    gtk_entry_set_text(pwd_u,emp.pwd_u);
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
    g_signal_connect (ok, "clicked",valid_modemp, win);
    gtk_box_pack_start (GTK_BOX (hbox), ok, FALSE, TRUE, 0);
    annuler = gtk_button_new_with_label ("Annuler");
    g_signal_connect (annuler, "clicked", close_window, win);
    gtk_box_pack_start (GTK_BOX (hbox), annuler, FALSE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

    gtk_widget_show_all (win);
}

void modifier (GtkWidget *win,gpointer *p)
{
    employe emp;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkTreeSelection *selection;
    char *value;
    selection = gtk_tree_view_get_selection( GTK_TREE_VIEW(view) );
    gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model, &iter);
    gtk_tree_model_get(model, &iter, COL_ID, &value,  -1);
    id = atoi(value);
    get_user(&emp,id);
    if(strcmp(emp.role,"responsable")==0)
    {
        modifier_res(win,emp);
    }
    else if(strcmp(emp.role,"role_admin")==0)
    {
        show_error_invalide(p,"\nContacter Responsable Informatique\npour modifier information admin.");
    }
    else if(strcmp(emp.role,"Employe")==0)
    {
        modifier_emp(win,emp);
    }


}

void supp(GtkWidget *win,gpointer p)
{
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkTreeSelection *selection;
    char *value;

    selection = gtk_tree_view_get_selection( GTK_TREE_VIEW(view) );
    gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model, &iter);
    gtk_tree_model_get(model, &iter, COL_ROLE, &value,  -1);
    if(strcmp(value,"role_admin")==0)
    {
        show_error_invalide(p,"\nVous ne pouver pas supprimer un admin ! ");
    }
    else
    {
        gtk_tree_model_get(model, &iter, COL_ID, &value,  -1);
        delete_user(atoi(value));
    }
    g_free(value);
    store = gtk_list_store_new (NUM_COLS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    show_users(store,iter);
    gtk_tree_view_set_model (GTK_TREE_VIEW (view), GTK_TREE_MODEL(store));
}

void creer_fenetre_gerer_comptes (GtkWidget *win,gpointer *p)
{

    close_window(win,p);
    GtkWidget *button = NULL;
    GtkWidget *scrollbar = NULL;
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
    gtk_container_add (GTK_CONTAINER(scrollbar), view);
    gtk_container_add (GTK_CONTAINER (hbox1), scrollbar);
    gtk_box_pack_start (GTK_HBOX(hbox1), vbox1, TRUE, TRUE, 20);

    button= gtk_button_new_with_label("Modifier");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);
    g_signal_connect (button, "clicked", modifier, win);
    button= gtk_button_new_with_label("Supprimer");
    gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 10);
    g_signal_connect (button, "clicked", supp, win);

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
    g_signal_connect (button, "clicked", add_user, view);

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

void sauv_conf(GtkWidget *win,gpointer p)
{

    char *sr,*dbu,*dbpass;
    sr=gtk_entry_get_text(GTK_ENTRY(server));
    dbu=gtk_entry_get_text(GTK_ENTRY(dbusername));
    dbpass=gtk_entry_get_text(GTK_ENTRY(dbpassword));

    if((strcmp(sr,"")==0) || (strcmp(dbu,"")==0) || (strcmp(dbpass,"")==0))
    {
        show_error_invalide(p,"\nIl' y a des champs vide !");
    }
    else
    {
        sauv_conf_file(sr,dbu,dbpass);
        close_window(win,p);
    }
}

void config (GtkWidget *win,gpointer *p)
{
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

