#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 100000
#define NR_WORDS 10

/*

buffer = [
	'a', 'b', 'c', 0, 'a', 'a', 'b',0
]

char *buffer;

char *erstes_wort = buffer + 0;
char *zweites_wort = buffer + 4;
char * drittes_wort = buffer + 8;

for(int i=0; i < number_of_bytes_in_buffer; ++i){
	if(*buffer+i) == 0){
	

	}

}
*/


int bin_search(char *w[], char* key, int us, int os){
    int delta = (os-us)/2;
    int m = us+delta;
    int cmp_res;

    cmp_res = strcmp(w[m], key);
    if(cmp_res == 0) return m;

    if(delta == 0) return -1;

    if(strcmp(w[m], key) == 0){
       return m;
    }

    if(cmp_res > 0){
        return bin_search(w, key, us, m);
    } else if(cmp_res < 0){
        return bin_search(w, key, m, os);
    } else if(cmp_res == 0){
        return m;
    }
}

char read_wordbuffer(char* file_path){
	char buffer[100];
	char *wordlist[100000];
    FILE *file = fopen(file_path, "r");
    
    if (file == NULL)
    {
        fputs("Failed to open the file\n", stderr);
        return;
    }
	int i = 0;
	
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
    	strcat(wordlist[i], buffer);
    	
        printf("Line read = %s\n", wordlist[i++]);
    }
	
	return wordlist;
}
int main(int argc, char **argv)
{

    
    for (;;) {
                char input[100];

                fgets(input, sizeof(input), stdin);
                input[strlen(input)-1] = 0;

                if (!strlen(input)) break;

                struct timeval tv_begin, tv_end, tv_diff;

                gettimeofday(&tv_begin, NULL);
                
                char *wl[100000];
    			wl = read_wordbuffer("wordbuffer"); 
                int res = bin_search(wl,input,0,NR_WORDS)
                
                gettimeofday(&tv_end, NULL);

                timersub(&tv_end, &tv_begin, &tv_diff);

                if (res != NULL) {
                        printf("found");
                } else {
                        printf("not found");
                }
                printf(" in (%ld seconds %ld microseconds)\n", tv_diff.tv_sec, tv_diff.tv_usec);
        }
    return 0;
}
