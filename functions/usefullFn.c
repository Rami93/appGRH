
void get_conf_file(char sr[],char dbu[],char dbpass[]){
    FILE *fichier;
    fichier = fopen("data/db.txt", "r");
    fscanf(fichier, "%s %s %s", sr, dbu, dbpass);
    fclose(fichier);
}

void sendmail(char to[],char body[]) {
    char cmd[100];
    char tempFile[100];
    strcpy(tempFile,tempnam("/tmp","sendmail"));
    FILE *fp = fopen(tempFile,"w");
    fprintf(fp,"%s\n",body);
    fclose(fp);
    sprintf(cmd,"mail -s 'Mot de passe Employé' %s < %s",to,tempFile);
    system(cmd);
}


void logout(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
    gtk_widget_hide(win);
    authentification(win);
}

void close_window(GtkWidget *win,gpointer p){
    gtk_widget_hide(p);
}

void sauv_conf_file(char *sr,char *dbu,char *dbpass){
    FILE *fichier;
    fichier = fopen("data/db.txt", "w");
    fprintf(fichier, "%s %s %s", sr,dbu,dbpass);
    fclose(fichier);
}

void addsession(int id){
    FILE *fichier;
    fichier = fopen("data/session.txt", "w");
    fprintf(fichier, "%d", id);
    fclose(fichier);
}

int Getsession(){
    int id;
    FILE *fichier;
    fichier = fopen("data/session.txt", "r");
    fscanf(fichier, "%d", id);
    fclose(fichier);
    return id;
}
