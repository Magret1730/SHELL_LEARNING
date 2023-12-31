#include "main.h"

char *get_location(char *command)
{
    struct stat buffer;
    char *path, *path_copy, *path_token, *file_path;
    size_t file_path_len;

    /* Check if the command is already an absolute path */
    if (stat(command, &buffer) == 0)
    {
        /* Return the command as it is */
        return command;
    }

    path = getenv("PATH");

    if (path != NULL)
    {
        path_copy = strdup(path);
        path_token = strtok(path_copy, ":");

        while (path_token != NULL)
        {
            file_path_len = strlen(path_token) + 1 + strlen(command) + 1; /* path + "/" + command + '\0' */
            file_path = malloc(file_path_len);
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);

            if (access(file_path, X_OK) == 0)
            {
                free(path_copy);
                return file_path;
            }

            free(file_path);
            path_token = strtok(NULL, ":");
        }

        free(path_copy);
    }

    return NULL;
}

