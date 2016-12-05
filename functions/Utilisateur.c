#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "../include/dataBase.h"
#include "../include/Utilisateur.h"

/*void ajouterItemUtilisateur(GtkWidget *listbox, char *sText){
    GtkWidget *item;
    item = gtk_list_box_row_new();
    gtk_container_add(GTK_CONTAINER(item),gtk_label_new(sText));
    gtk_widget_set_size_request(listbox,300,300);;
    gtk_list_box_prepend(listbox,item);
    gtk_widget_show (item);
}*/


int verifierLoginPwd(char * login , char * pwd){

    MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"%s%s%s%s%s","SELECT * FROM Utilisateur WHERE username='",login,"' and password='",pwd,"';");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }
    MYSQL_ROW row=mysql_fetch_row(result);
    int res=(row==NULL)?-1:0;

    if(res==0){
        if(strcmp(row[13],"role_admin")==0){
            res=1;
        }else if(strcmp(row[13],"role_employe")==0){
            res=2;
        }else if(strcmp(row[13],"role_responsable")==0){
            res=3;
        }
    }

    mysql_free_result(result);
    mysql_close(con);

    return res;

}

int add_user_db(employe emp){
    int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"insert into Utilisateur Values(NULL,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','Employe');",
    emp.cinn,emp.username,emp.pwd_u,emp.nom,emp.prenom,emp.dns,emp.cnss,emp.sexe,emp.email,emp.numerotel,emp.ville,emp.adresse);
    if (mysql_query(con, querry)) {
      finish_with_error(con);
      res = -1;
    }else{
        res = 1;
    }

    mysql_close(con);
};

void delete_user(int id){

    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
    sprintf(querry,"deletre from Utilisateur where id=%d;",id);
    if (mysql_query(con, querry)) {
      finish_with_error(con);
     }
    mysql_close(con);
}

void show_users(GtkListStore  *store,GtkTreeIter iter){

    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
    if (mysql_query(con, "select * from Utilisateur;")) {
      finish_with_error(con);
    }else{
        MYSQL_RES *result = mysql_store_result(con);
        if (result == NULL)
        {
          finish_with_error(con);
        }
        int num_fields = mysql_num_fields(result);

        MYSQL_ROW row;
        char user_info[100];

        while ((row = mysql_fetch_row(result)))
        {
            gtk_list_store_append (store, &iter);
            gtk_list_store_set(store, &iter,COL_ID, row[0],COL_NOM, row[4],COL_PRENOM, row[5],COL_ROLE, row[13],-1);
        }
        mysql_free_result(result);
    }
    mysql_close(con);
    return GTK_TREE_MODEL (store);
};
