#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 10

void printf_sys_info()
{
    printf("[stu@localhost~]$");
    fflush(stdout);
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
        assert( pid != -1);
      
        if( pid == 0)
        {
            execvp(myargv[0],myargv);
            printf("error");
            exit(0);
        }

        wait(NULL);
    }
}
