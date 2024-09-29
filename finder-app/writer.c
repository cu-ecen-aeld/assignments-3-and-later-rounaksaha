#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	//LeoDebug
	//printf("writer.c has been called \n");

	openlog("LeoLog1", LOG_PID | LOG_CONS, LOG_USER);
	syslog(LOG_DEBUG, "Program Started!"); 

	FILE *fptr;

	//Accessing Arguments 
	//printf("number of arguments %d\n", argc);
	//for(int i=0; i<argc; i++)
	//{
	//	printf("argument %d: %s\n", i, argv[i]); 
	//}

	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

	//Open File in Write Mode
	fptr = fopen(argv[1], "w");

	if(fptr==NULL)
	{
		syslog(LOG_ERR, "Error: Failed to create file! \n");
		//printf("file could not be created \n");
		return 1;
	}

	//Write to the File
	fprintf(fptr, "%s\n", argv[2]);
	//printf("string written to file \n");
	//Close the File
	fclose(fptr);
	//printf("file close \n");
	closelog();
	return 0;
}
