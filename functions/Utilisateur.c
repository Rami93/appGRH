#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "../include/TypeDef.h"
#include "../include/dataBase.h"


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
        }else if(strcmp(row[13],"Employe")==0){
            res=2;
        }else if(strcmp(row[13],"Responsable")==0){
            res=3;
        }
    }
    mysql_free_result(result);
    mysql_close(con);
    return res;
}

int getiduser(char * login , char * pwd){

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
    int res = atoi(row[0]);
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
}

int add_res_db(employe emp){
    int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"insert into Utilisateur(id,cin,username,password,nom,prenom,dns,cnss,sexe,email,num_tel,ville,adresse,role) Values(NULL,'%s','%s','%s','%s','%s',NULL,NULL,NULL,'%s',NULL,NULL,NULL,'%s');",
    emp.cinn,emp.username,emp.pwd_u,emp.nom,emp.prenom,emp.email,emp.role);
    if (mysql_query(con, querry)) {
      finish_with_error(con);
      res = -1;
    }else{
        res = 1;
    }
    mysql_close(con);
}

int update_emp(employe emp,int id){
    int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"update Utilisateur set cin='%s',username='%s',password='%s',nom='%s',prenom='%s',dns='%s',cnss='%s',sexe='%s',email='%s',num_tel='%s',ville='%s',adresse='%s') where id = %d ;",
    emp.cinn,emp.username,emp.pwd_u,emp.nom,emp.prenom,emp.email,id);
    if (mysql_query(con, querry)) {
      finish_with_error(con);
      res = -1;
    }else{
        res = 1;
    }
    mysql_close(con);
}

void delete_user(int id){
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
    sprintf(querry,"delete from Utilisateur where id=%d;",id);
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
}

void get_user(employe *e,int id){
    employe emp;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
    sprintf(querry,"select * from Utilisateur where id=%d;",id);
    if (mysql_query(con, querry)) {
      finish_with_error(con);
    }else{
        MYSQL_RES *result = mysql_store_result(con);
        if (result == NULL)
        {
          finish_with_error(con);
        }
        int num_fields = mysql_num_fields(result);
        MYSQL_ROW row = mysql_fetch_row(result);
        emp.id = row[0];
        emp.cinn = row[1];
        emp.username = row[2];
        emp.pwd_u = row[3];
        emp.nom = row[4];
        emp.prenom = row[5];
        emp.dns = row[6];
        emp.cnss = row[7];
        emp.sexe = row[8];
        emp.email = row[9];
        emp.numerotel = row[10];
        emp.ville = row[11];
        emp.adresse = row[12];
        emp.role = row[13];
        mysql_free_result(result);
    }
    mysql_close(con);
    *e=emp;
}
