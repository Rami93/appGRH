#include <stdio.h>
#include <string.h>
#include "Utilisateur.h"

int verifierLoginPwd(char * login , char * pwd){
    return (0==strcmp(login,pwd));

}
