#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>

int main()
{
	openlog("LeoLog1", LOG_PID | LOG_CONS, LOG_USER);
	syslog(LOG_DEBUG, "Program Started!"); 

	FILE *fptr;
	//File Path including Filename
	char writefile[] = "LeoAssignment2.txt";
	//Data to be inserted
	char writestr[] = "Hello World!";

	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

	//Open File in Write Mode
	fptr = fopen(writefile, "w");

	if(fptr==NULL)
	{
		syslog(LOG_ERR, "Error: Failed to create file: %s \n", strerror(errno));
		return 1;
	}

	//Write to the File
	fprintf(fptr, writestr);
	//Close the File
	fclose(fptr);

	closelog();
	return 0;
}
