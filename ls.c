#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
          DIR * dir = opendir(".");
          struct dirent* ent = NULL;
          while((ent = readdir(dir)))
          {
              if((ent->d_type == 4 || ent->d_type == 8)
                   && ent->d_name[0] != ".")            
                 {   
                     if((ent->d_type == 4))
                     {
                      printf("\e[1;34;49m %s \033[0m",ent->d_name);
                     }
                     if((ent->d_type == 8))
                     {
                         printf("\e[1;30;47m %s \033[0m",ent->d_name);
                     }
                 }
          }     
          closedir(dir);
          puts("");
}
