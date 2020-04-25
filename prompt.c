//RAHUL PRAVEEN                                                                                                         //16203022                                                                                                              //rahul@ucdconnect.ie  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "allCommands.h"

void prompt() {
	// Copied from the sample code given to us on Moodle
	char buff[100];
	time_t now = time(0);
	strftime(buff, 32, "%d/%m %H:%M", localtime(&now));
	printf("[%s]# ", buff);
}
