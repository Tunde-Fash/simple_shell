#include "shell.h"

void display_prompt(void)
{
    printf("$ ");
}

char *read_command(void)
{
    char *command = NULL;
    size_t buffer_size = 0;

    if (getline(&command, &buffer_size, stdin) == EOF)
    {
        free(command);
        return NULL;
    }

    command[strcspn(command, "\n")] = '\0';
    return command;
}

void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        handle_error();
    }
    else if (pid == 0)
    {
        if (execve(command, NULL, NULL) == -1)
        {
            handle_error();
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

void handle_error(void)
{
    perror("Error");
}
