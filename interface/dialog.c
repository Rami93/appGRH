void show_error_invalide(gpointer window) {

  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "\nNom d'utilisateur ou mot de passe incorrect !\nveuillez réessayer.");
  gtk_window_set_title(GTK_WINDOW(dialog), "Erreur");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}
