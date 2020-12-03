#include <sys/stat.h>
#include <fcntl.h>
#include "lib/tlpi_hdr.h"

#ifndef BUFSIZ
#define BUFSIZ 1024*1000000
#endif

int main(int argc, char const *argv[])
{
	int inputFd, outputFd, openFlags;
	ssize_t numRead;
	//mode_t filePerms;
	char *buf[BUFSIZ];

	/* opening my file:.... */

	inputFd = open(argv[1], O_RDONLY/*|O_LARGEFILE*/);
	if (inputFd ==-1){
		printf("error while opening %s file", argv[1]);
		exit(EXIT_FAILURE);
	}
	openFlags = O_CREAT|O_WRONLY|O_TRUNC/*|O_LARGEFILE*/;
	outputFd = open(argv[2],openFlags);
	if (outputFd ==-1){
		printf("error when creating a new file");
		exit(EXIT_FAILURE);
	}

	while(numRead=read(inputFd,buf,BUFSIZ) > 0){

		//printf("%d\n",numRead );
		if (write(outputFd,buf,BUFSIZ) < numRead){
			printf("error while copying!!!!");
			exit(EXIT_FAILURE);
		}

	}
	if (numRead == -1){
		printf("error while reading");
		exit(EXIT_FAILURE);
	}

	if (close(inputFd) == -1){
		printf("error while closing inputFd file");
		exit(EXIT_FAILURE);
	}
	if (close(outputFd) == -1){
		printf("error  while closing outputFd file");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}