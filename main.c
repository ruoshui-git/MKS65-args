#include <stdio.h>
#include <string.h>

#include <unistd.h>
#define DLT ' '
#define MAX_ARGS 5


char ** parse_args( char * line );

int main(void)
{

}

char ** parse_args( char * line )
{
    char ** args = malloc(sizeof(char *) * MAX_ARGS);

    int i = 0;
    char * curr = line;
    char * token;
    token = strsep(line, DLT);
}
