#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define DLT " "
#define MAX_ARGS 5


char ** parse_args( char * line );

int main(void)
{
    char * s = strdup("ls -al");
    char ** args = parse_args(s);
    int i = 0;
    char * argv[MAX_ARGS + 1];

    memcpy(argv, args, sizeof(char*) * MAX_ARGS + 1);
    
    for (i = 0; argv[i] != NULL; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }


    execvp(argv[0], argv);
    
    puts("You shouldn't see this!");
    
    free(args);
    free(s);
    
}

char ** parse_args( char * line )
{
    char ** args = malloc(sizeof(char *) * (MAX_ARGS + 1));

    int i = 0;
    char * curr = line;
    char * token;
    while (curr)
    {
        args[i] = strsep(&curr, DLT);
        i++;
    }
    args[i] = NULL;
    return args;
}
