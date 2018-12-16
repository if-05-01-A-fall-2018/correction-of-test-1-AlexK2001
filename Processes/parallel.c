#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

//Beim Test funktionierte es nur mit dem Befehl ls. Jetzt mit allen Commands


char* arguments[] = {"ls", "df", "ps", "pwd", NULL}; //arguments array erweitert. Vorher war nur ls und NULL drinnen

int main(int argc, char const *argv[])
{
  for (int i = 0; i <= 4; i++) { // Durchlauf der einzelnen Befehle mit einer For Schleife
      char* cur_arg[] = {arguments[i],arguments[4] };
      pid_t pid = fork();
      int status;
      if (pid == 0)
      {
        /* anstelle von execvp(arguments[0],arguments ); gebe ich bei jedem Durchlauf der For-Schleife einen anderen Befehl mit*/
        execvp(cur_arg[0],cur_arg);
      }
      waitpid(-1, &status, 0);

  }
  printf("Done\n");
  return 0;
}
