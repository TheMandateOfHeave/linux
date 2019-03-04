#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
   if(argc != 3)
   {
       printf("argc error\n");
   }
   int pid =0;
   int sig =0;
   sscanf(argv[1],"%d",&pid);
   sscanf(argv[2],"%d",&sig);

   if(kill(pid,sig) == -1)
   {
       printf("error\n");
   }
   
   exit(0);
}
