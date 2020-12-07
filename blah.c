#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
void parse_command(char command[], char* arguments[]) {
  const char s[2] = " ";
			char *k = strtok(command, s);
            int n =0;
            
			arguments[n]=k;
           //first
		
            while (k != NULL) {
				n++;
                k=strtok(NULL,s);
				arguments[n]=k;
            }
}
// void test(){
    
//     char *s= malloc(5*sizeof(char));
//     s[0]='0';
//     s[1]='1';
//     printf("%s\n",(s[0]));
// }
void test(){
    int val =5;
    int pid;
    pid=fork();
    // printf("%d\n", pid);
    if(pid== -1 )
    { //fork unsuccessful 
        printf("%s\n","fail");
        
    }
    else if ( pid> 0)
    { //This is parent
        printf("%s\n","parent");
       // val+=2;
        //printf("%d\n",val);
         printf("%d\n",pid);
    }
    else
    {//This is child
        fork();
        val-=2;
        //printf("%s\n","child");
        // printf("%d\n",val);
         printf("%d\n",pid);
    }
}
int main() {
     printf("%s\n","here we go main");
    test();
//     pid_t p = fork();
//     if(p==0){
//         printf("%s\n","child process");
//     }else{
//         p>0?printf("%s\n","parent"):printf("%s\n","fail");
//         //  printf("%s\n","parent process");
//     }

    return 0;
}