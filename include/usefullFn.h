#ifndef USEFULLFN_H_INCLUDED
#define USEFULLFN_H_INCLUDED
#include <string.h>
#include <gtk/gtk.h>
#include "../functions/usefullFn.c"

void logout(GtkWidget *win,gpointer p);
void close_window(GtkWidget *win,gpointer p);
void sendmail(char to[],char body[]);
void sauv_conf_file(char *sr,char *dbu,char *dbpass);
void get_conf_file(char *sr,char *dbu,char *dbpass);

#endif // USEFULLFN_H_INCLUDED
