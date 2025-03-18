#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF_SIZE 100
#define MAX_ARG_NUMBER 5
#define MAX_ARG_SIZE 10

int main(void) {
	
	char *buff = NULL;
	char *token = NULL;
	char *message = NULL;
	char **arguments = NULL;

	while(1) 
	{
		printf("ismail's_Pico_Shell$ ");

		buff = (char *)calloc(BUFF_SIZE, sizeof(char));
		fgets(buff, BUFF_SIZE, stdin);
		buff[strlen(buff) - 1] = 0;	//deleting \n character
		if (strlen(buff) == 0)
		continue;

		token = strtok(buff, " ");

		if (!strcmp(token, "exit"))
		{
			free(buff);
			break;
		}
		else if (!strcmp(token, "echo"))
		{
			token = strtok(NULL, " ");
			while (token != NULL)
			{
				printf ("%s ", token);
				token = strtok(NULL, " ");
			}
			printf("\n");
			free(buff);
		}
		else if (!strcmp(token, "pwd"))
		{
			printf("%s\n", getcwd(message, 100));
			free(buff);
		}
		else if (!strcmp(token, "cd"))
		{
			token = strtok(NULL, " ");
			if(chdir(token) == -1)
			{
				printf("%s: No such file or directory\n", token);
			}
			free(buff);
		}
		else
		{
			if (fork() == 0) {
				/*New child Process*/
				char *command = token;
				token = strtok(NULL, " ");

				arguments = (char **)calloc(MAX_ARG_NUMBER, MAX_ARG_SIZE);
				arguments[0] = command;
				int i = 1;
				while(token != NULL)
				{
					arguments[i] = token;
					token = strtok(NULL, " ");
					i++;
				}
				arguments[i] = NULL;

				if (execvp(command, arguments) == -1) 
				{
					printf("Terminated Incorrectly\n");
					free (arguments);
					free(buff);
					exit(3);
				}
				free(arguments);
				free(buff);
			}
			else 
			{
				/*Parent process*/
				int status = 0;

				wait(&status);
				if(WEXITSTATUS(status) == 3)
				printf("couldn't perform the command]\n");
				free(buff);
			}
		}

	}

	return 0;
}
