#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>

#define MAX_LEN_LINE    100
#define LEN_HOSTNAME    30

int main(void)
{
    char command[MAX_LEN_LINE];
    char workingDir[MAX_LEN_LINE];
    char *idx1;
    char *idx2;
    char *idx3;
    char *args[] = {command, idx1, idx2, idx3, NULL};
    int ret, status;
    pid_t pid, cpid;

    char *path = "/bin/";
    char *home = "~";
    char *slash = "/";
    char fullPath[30];

    char *parsed;
    int lines = 0;
    
    while(true) {
        char *s;
        int len;
        char *dirToken;


        if (lines == 0){
            printf("Hello.\nFor more information, enter <info>\n");
        }

        char *username = getpwuid(getuid())->pw_name; // get user name and host name
        char hostname[LEN_HOSTNAME + 1];
        memset(hostname, 0x00, sizeof(hostname));
        gethostname(hostname, LEN_HOSTNAME);
        getcwd(workingDir, sizeof(workingDir));

        int slashCount = 0;
        for(int i = 0; i < sizeof(workingDir); i++){
            if(workingDir[i] == '/') slashCount++;
        }

        char *dir[slashCount];

        dirToken = strtok(workingDir,"/");
        int count = 0;
        while(dirToken!=NULL){
            dir[count] = dirToken;      
            dirToken = strtok(NULL,"/");
            count++;
        }
        if((strcmp(dir[0], "home") == 0) && (strcmp(dir[1], username) == 0)) {
            strcpy(workingDir, home);
            for(int i = 2; i<slashCount; i++){
                strcat(workingDir, slash);
                strcat(workingDir, dir[i]);
            }
        }
        else if((strcmp(dir[0], "home") == 0) && (strcmp(dir[1], username) != 0)) {
            strcpy(workingDir, slash);
            strcat(workingDir, home);
            for(int i = 1; i<slashCount; i++){
                strcat(workingDir, slash);
                strcat(workingDir, dir[i]);
            }
        }
        else {
            for(int i = 0; i<slashCount; i++){
                strcat(workingDir, slash);
                strcat(workingDir, dir[i]);
            }
        }
        printf("%s@%s:%s $ ", username, hostname, workingDir);

        s = fgets(command, MAX_LEN_LINE, stdin);

        if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        
        len = strlen(command);
        //printf("%d\n", len);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        }
        

        int i = 0;
        parsed = strtok(command," ");
        while(parsed != NULL)
        {
            args[i] = parsed;
            //printf("args[%d] = %s\n", i, args[i]);
            parsed = strtok(NULL, " ");
            i++;
        }
        idx1 = args[1];
        args[i]=NULL;

        if((strcmp(command, "red") != 0) && (strcmp(command, "undocolor") != 0) && (strcmp(command, "info") != 0))
        {
            strcpy(fullPath, path);
            strcat(fullPath, args[0]);
            args[0] = fullPath;
        }

        //printf("[%s]\n", command);
        if(strcmp(command, "clear") == 0) system("clear");  
        if(strcmp(command, "exit") == 0) break;

        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        if (pid != 0) {  /* parent */
            cpid = waitpid(pid, &status, 0);
            if (cpid != pid) {
                fprintf(stderr, "waitpid failed\n");        
            }
            printf("Child process terminated\n");
            if (WIFEXITED(status)) {
                printf("Exit status is %d\n", WEXITSTATUS(status)); 
            }
        }
        else {  /* child */
            printf("[%s] command executed\n", command);

            ret = execve(args[0], args, NULL);
            if (ret < 0) {
                fprintf(stderr, "execve failed\n");   
                return 1;
            }
        }
        lines++;
    }
    return 0;
} 