#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>


int main(int argc, char* argv[],char* envp[])
{
    printf("main pid =%d\n",getpid());
    pid_t pid =fork();
    if(pid == 0)
    {
   char *myargv[] ={"asd","ksp","asd",(char*)0};
   char *myenvp[] ={"asd","ksp","asd",(char*)0};
   execve("./b",myargv,myenvp);
   perror("err ");
    }
   printf("main pid =%d\n",getpid());
   pid_t pid= fork();
   assert(pid != -1);
    if(pid == 0)
    {
        execlp("ps","ps","-f",(char*)0);
        exit(0);
    }
    
    wait(NULL);
    printf("over\n");
    exit(0);
}
