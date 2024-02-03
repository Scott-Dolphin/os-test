#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid;
  /* fork a child process */
  pid = fork();
  
  if (pid < 0) { /* error */
    fprintf(stderr, "Fork Failed");
    return 1;
  }
  else if (pid == 0) { /* child process */
    execlp("/bin/ls", "ls", NULL);
  }
  else { /* parent process */
    /* parent will wait for the child to complete */
    wait(null);          // If this line is ommitted, child process is a zombie
    printf("child complete");
  }
  return 0;
}