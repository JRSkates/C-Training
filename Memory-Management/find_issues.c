#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void  get_sky_team_name(char* name)
{
   char* ptr = (char*) malloc(10);
   
   //copy team name to pointer
   strcpy(ptr, "Home Comms SW Team");
   
   //return team name
   name = ptr;

   free(ptr);
}
  
int main(void)
{
   char name[10];
   char* pTeamName = NULL;    
   
   strcpy(name, "Sky UK");     
   
   while(1)
   {
       get_sky_team_name(pTeamName);        
       
       //print team name
       // skyName variable does not exist
       //printf("%s: %s\n", skyName, pTeamName); 
       
       sleep(1);
   }
   
  return 0;
}