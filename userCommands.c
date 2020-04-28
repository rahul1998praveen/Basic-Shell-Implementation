//RAHUL PRAVEEN                                                                                                         //16203022                                                                                                              //rahul@ucdconnect.ie  
#include "allCommands.h"
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

// Function to parse the commands that are encounterd on the termined
void userCommands(char *command) {
	if (command[0] == '\0') {
		return;
	} else {
		//arguments
		char **UserArguments = malloc(sizeof(char *));
		char *spaces = strtok(command, " ");
		int counter1 = 0;
		int file1 = 0;
		int redirected = 0;
		for (; spaces != NULL;) {
		if (strcmp(spaces, ">") == 0) {
		redirected = 1;
		spaces = strtok(NULL, " ");
		// Open the file
		file1 = open(spaces, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		break;
		}
		UserArguments[counter1] = spaces;
		UserArguments = realloc(UserArguments, (++counter1 + 1) * sizeof(char *));
		spaces = strtok(NULL, " ");
		}
		UserArguments[counter1] = NULL;
		//When the user wants to change directory
		if (strcmp(UserArguments[0], "cd") == 0) {
			commandCD(UserArguments);
		} else {
			pid_t pid = fork();
			if (pid < 0) {
				//No processes available
				fprintf(stderr, "No processes available, Fork Unsuccessful");
				exit(EXIT_FAILURE);
			} else if (pid == 0) {
				//When the output needs to be redirected
				if (redirected) {
					dup2(file1, 1);
				}
				execvp(UserArguments[0], UserArguments);
				exit(EXIT_SUCCESS);
			} else {
				wait(NULL);
				return;
			}
		}
	}

}
