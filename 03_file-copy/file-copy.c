/*
name: file_copy
version: 1.0
author: Luan Mehmeti
descritpion:
A commandshell which needs 2 inputs.
The inputs should be detected via Arguments (Command Line Arguments should be used).
The first input for the file, which should be copied (the source)
and the secound input which says where the file and with which name it should be copied (the destination).
It should work like the Linux cp command.
It uses only POSIX syscalls
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int file_copy(file_to_copy, new_file){
    char buffer[20];
    char cwd[1024];
    int fdr, fdw;
    int nBytes;
    int bytes_read, bytes_written;


    /* File Descriptior for Reading Operation */
    chdir("/home/luan/binary_search/");
    getcwd(cwd, sizeof(cw));
    printf("Test%s\n", cwd);
    
    fdr = open(file_to_copy, O_RDONLY);
    /* File Descriptior for Writing Operation, Flag O_Create describes, that a new file should be created for the writing operation */
    fdw = open(new_file, O_WRONLY | O_CREAT);

    /* Errorhandling */
    if(fdr < 0){
        printf("An Error has occurred during the reading, does the file or it's path really exist?");
        return fdr;
    }
    else if (fdw < 0){
        printf("An Error has occurred during the writing, does the target really exist?");
        return fdw;
    }

    nBytes = sizeof(buffer);


    // if the read function returns 0, it's on the end of the file and the copy operation is done
	do{
    
        bytes_read = read(fdr, buffer, nBytes);
        /* the value of bytes_read is used as nBytes,
           because if you have e.a 70 characters,
           after the third 20 byte stepping the last stepping would
           begin to write in the first 10 characters again.
           If the value of the read function is smaller than nBytes,
           it shows how near the reading process is to the end.
        */
        bytes_written = write(fdw, buffer, bytes_read);
    }while(bytes_read != 0);
    return 0;
}


int main(int args, char *argv[])
{
    file_copy("test1.txt", "test2.txt");

    return 0;
}

