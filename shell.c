/**********************************************************************************************************************************************************
 * Simple UNIX Shell
 * @author: 
 * 
 **/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LENGTH 80 // The maximum length of the commands

#define OUTPUT 1
#define INPUT 2
#define PIPE 3
#define EXECUTE 4


void parent(){
	printf("%s\n","parent");
}
void child(){
	printf("%s\n","child");
}
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


void output_redirect(char* arguments[]) {
	pid_t p;
    p = fork();
    if(p==-1)
    {
        printf("There is an error while calling fork()");
    }
    if(p==0)
    {
       child();
    }
    else
    {
       parent();
    }
	return;
	// fork();
	// open(); O_WRONLY
	// copy_to_file_descriptor(STDOUT_FILENO);
	// 	dup2();
	// close();
	// execvp();
	// if (arguments != "&") {
	// 	wait();
	// }

	
}

// void input_redirect() {
// 	if (command == INPUT) {
// 		fork();
// 		open();
// 		copy_to_file_descriptor(STDIN_FILENO);
// 		dup2();
// 		close();
// 		execvp();
// 		if (arguments != "&") {
// 			wait();
// 		}

// 	}
// }

// void pipe_redirect() {
// 	if (command == PIPE) {
// 		fork();
// 			pipe();
// 			fork();	
// 				close();
// 				copy_to_file_descriptor(STDIN_FILENO);
// 				dup2();
	// 				execvp(); //watch for (|) symbol
// 			close();
// 			copy_to_file_descriptor(STDOUT_FILENO);
// 			execvp(); //watch for (|) symbol
// 		if (arguments != "&") {
// 			wait();
// 		}

// 	}
// }

// void execute() {
// 	if (command == EXECUTE) {
// 		fork();
// 			execvp();
// 		if (command != "&") {
// 			wait();
// 		}
// 	}
// }



int main(void) {

	char command[MAX_LENGTH];

	//arg[0]=command
	char* arguments[MAX_LENGTH/2 + 1]; // MAximum 40 argments



	while (1) {
		printf("%s\n","ssh>>");
		fflush(stdout);
		fgets(command, MAX_LENGTH, stdin);
		


		//Parse command and arguments.
		parse_command(command,arguments);
	  printf("%s\n",*arguments);
	  printf("%s\n",arguments[1]);

		//If command contains output redirection argument
		//	fork a child process invoking fork() system call and perform the followings in the child process:
		//		open the redirected file in write only mode invoking open() system call
		//		copy the opened file descriptor to standard output file descriptor (STDOUT_FILENO) invoking dup2() system call
		//		close the opened file descriptor invoking close() system call
		//		change the process image with the new process image according to the UNIX command using execvp() system call
		//	If command does not conatain & (ampersand) at the end
		//		invoke wait() system call in parent process.
		//
		//		
		if(arguments[0]=="cd"){
		output_redirect(arguments);
		}
			
		//If command contains input redirection argument
		//	fork a child process invoking fork() system call and perform the followings in the child process:
		//		open the redirected file in read  only mode invoking open() system call
		//		copy the opened file descriptor to standard input file descriptor (STDIN_FILENO) invoking dup2() system call
		//		close the opened file descriptor invoking close() system call
		//		change the process image with the new process image according to the UNIX command using execvp() system call
		//	If command does not conatain & (ampersand) at the end
		//		invoke wait() system call in parent process.
		//
		//	
		// if(arguments[0]==INPUT){

		// }
		//If command contains pipe argument
		//	fork a child process invoking fork() system call and perform the followings in the child process:
		//		create a pipe invoking pipe() system call
		//		fork another child process invoking fork() system call and perform the followings in this child process:
		//			close the write end descriptor of the pipe invoking close() system call
		//			copy the read end  descriptor of the pipe to standard input file descriptor (STDIN_FILENO) invoking dup2() system call
		//			change the process image of the this child with the new image according to the second UNIX command after the pipe symbol (|) using execvp() system call
		//		close the read end descriptor of the pipe invoking close() system call
		//		copy the write end descriptor of the pipe to standard output file descriptor (STDOUT_FILENO) invoking dup2() system call
		//		change the process image with the new process image according to the first UNIX command before the pipe symbol (|) using execvp() system call
		//	If command does not conatain & (ampersand) at the end
		//		invoke wait() system call in parent process.
		//
		//
		// if(arguments[0]==PIPE){}
		//If command does not contain any of the above
		//	fork a child process using fork() system call and perform the followings in the child process.
		//		change the process image with the new process image according to the UNIX command using execvp() system call
		//	If command does not conatain & (ampersand) at the end
		//		invoke wait() system call in parent process.

		// if(arguments[0]==EXECUTE){}

				break;
	}

	return 0;
}
