#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <bmpfile.h>
#include <math.h>
#include <time.h>
#include <semaphore.h>
#include <errno.h>
#include <bmpfile.h>

int spawn(const char * program, char * arg_list[])
{
  pid_t child_pid = fork();

  if(child_pid < 0)
  {
    perror("Error while forking...");
    return 1;
  }
  else if(child_pid != 0)
    return child_pid;
  else
  {
    if(execvp (program, arg_list) == 0);
    perror("Exec failed");
    return 1;
  }
}

int main()
{
  char *arg_list_A[] = { "/usr/bin/konsole", "-e", "./bin/processA", NULL };
  char *arg_list_B[] = { "/usr/bin/konsole", "-e", "./bin/processB", NULL };

  pid_t process_A_pid = spawn("/usr/bin/konsole", arg_list_A);
  pid_t process_B_pid = spawn("/usr/bin/konsole", arg_list_B);

  int exit_status;
  waitpid(process_A_pid, &exit_status, 0);
  waitpid(process_B_pid, &exit_status, 0);

  printf ("Main program exiting with exit_status %d\n", exit_status);

  return 0;
}

