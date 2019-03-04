#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 10
#define PATH "/home/zp/Desktop/5.31/mybin/"

void printf_sys_info()
{
    char buff[128]={0};
    strcpy(buff,"[my@localhost ");
    
    char route[128]={0};
    getcwd(route,128);
     char * myargv[MAX]={0};
     char* s = strtok(route,"/");
     myargv[0]=s;
     int i = 1;
    while( (s = strtok(NULL,"/")) != NULL )
  {
     myargv[i++] = s;
  }
    strcat(buff,myargv[i]);
    strcat(buff,"]$ ");
    printf("%s",buff);
    fflush(stdout);
 }
}

int main()
{
    while(1)
    {
        char buff[128]={0};

        printf_sys_info();
        
        fgets(buff,128,stdin);
        buff[strlen(buff)-1]=0;

        char * myargv[MAX]={0};

        char* s = strtok(buff," ");

        if(s == NULL)
        {
            continue;
        }
        myargv[0]=s;

        int i = 1;
        while( (s = strtok(NULL," ")) != NULL )
        {
            myargv[i++] = s;
        }
        if( strcmp(myargv[0],"exit") ==0 )
        {
            break;
        }
        pid_t pid = fork();
        if(pid == 0)
        {
            char path[256]={0};
            assert( pid != -1);

         if( strncmp(myargv[0],"./",2) != 0 && strncmp(myargv[0],"/",1)!=0)
          {
            strcpy(path,PATH);
          }
            strcat(path,myargv[0]);
            execv(path,myargv);
            perror("error");
            exit(0);
        }
        wait(NULL);
    }
}
