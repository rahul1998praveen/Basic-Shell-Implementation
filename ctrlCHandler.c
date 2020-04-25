//RAHUL PRAVEEN                                                                                                         //16203022                                                                                                              //rahul@ucdconnect.ie  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>
#include "allCommands.h"

void ctrlCHandler(int sig) {
	// if CTRL C is encountered
	if (sig == SIGINT) {	 
     		printf("\n");
		prompt();	
		fflush(stdout);
	}
}
