#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main() {
    int f = open("./p5_3.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IWUSR);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr,"fork failed [%d]\n", getpid());
    }
    else if (rc == 0) {
        const char buf[20] = "child process";
        write(f,buf,20);
    }
    else {
        for (int i = 0; i < 10000; i++){printf("hi\n");}
        //wait(NULL);
        const char buf[20] = "parent process";
        write(f,buf,20);
    }
    return 0;
}