#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "../include/dataBase.h"


int verifierLoginPwd(char * login , char * pwd){

    MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"%s%s%s%s%s","SELECT * FROM Utilisateur WHERE login='",login,"' and passw='",pwd,"';");


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
        if(strcmp(row[3],"admin")==0){
            res=1;
        }else if(strcmp(row[3],"employe")==0){
            res=2;
        }else if(strcmp(row[3],"responsable")==0){
            res=3;
        }
    }

    mysql_free_result(result);
    mysql_close(con);

    return res;

}
