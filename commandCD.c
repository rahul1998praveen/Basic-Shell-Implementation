// Rahul Praveen
// 16203022
// rahul@ucdconnect.ie
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "allCommands.h"

void commandCD(char** arguments) {
	//Home directory 
	if (arguments[1] == NULL) {
		chdir(getenv("HOME"));
	} else{
		if (chdir(arguments[1]) != 0) {
			//invalid argument
			perror("cd: Invalid argument, no such file or directory");
		}
	}
}
