//RAHUL PRAVEEN                                                                                                         //16203022                                                                                                              //rahul@ucdconnect.ie  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include "allCommands.h"
// the command line that appaears after every execution
void commandLoop() {
	//If signal isnt caught
	if (signal(SIGINT, ctrlCHandler) == SIG_ERR) {
		printf("\nSIGINT cant be caught\n");	  
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	prompt();
	// getting the user line from terminal
	fflush(stdout);
	while ((read = getline(&line, &len, stdin)) != EOF){ 
		if (line[read - 1] == '\n'){
			line[read - 1] = '\0';
		}
		userCommands(line);
		prompt();
								        }
}

int main() {
	commandLoop();
        return 0;
}
