#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void core_change() {
    static int first_time = 1;
    if (first_time) {
        const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
        first_time = 0;
    }

    printf("Core Change >>");
}

void bolt_out(char command[], char *params[]) {
    char line[1024];
    int count = 0, i = 0, j = 0;
    char *array[100], *pch;

    for(;;){
        int c = fgetc(stdin);
        line[count++] = (char)c;
        if (c == '\n') {
             break;
        }
    }
    if (count == 1) return;
    pch = strtok(line, "\n");

    while(pch != NULL) {
        array[i++] =  strdup(pch);
        pch= strtok(NULL, "\n");
        for (int c = 0; pch[c] != '\0'; c++)
            printf("%c", pch[c]);
    }

    strcpy(command, array[0]);

    for (int j = 0; j < i; j++) {
        params[j] = array[j];
    }

    params[i] = NULL;
    
}

int main() {
    char command[100], *params[100];


    while (1) {
        core_change();
        bolt_out(command, params);
    }
    

    return 0;
}