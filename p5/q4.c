#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main() {
    int rc = fork();
    if (rc == 0) {
        printf("child process\n");
        char *myargv[3];
        myargv[0] = strdup("ls");
        myargv[1] = strdup("./");
        myargv[2] = NULL;
        execvp(myargv[0],myargv);
    }
    else {
        printf("parent process\n");
    }
    return 0;
}