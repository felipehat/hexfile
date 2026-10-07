#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
    int main(int argc, char *argv[]){
		FILE *fileOpen, *fileClose;
		int byte = 0;
		// uso ./hexfile -a (abrir)
		// ou ./hexfile -f (fechar)
		if(strcmp(argv[1], "-a") == 0){
		    fileOpen = fopen(argv[2], "r");
			if(fileOpen == NULL){
				perror("Erro de leitura");
				return 1;
			}
		    char name[256];
		    strcpy(name, argv[2]);
		    strcat(name, ".hex");
		    fileClose = fopen(name, "w");
			if(fileClose == NULL){
				perror("Erro de escrita");
				return 1;
			}
		    while((byte = fgetc(fileOpen)) != EOF){
			    fprintf(fileClose, "%X ", byte);	
			}
			fclose(fileOpen);
			fclose(fileClose);	
		} else if(strcmp(argv[1], "-f") == 0){
            char name[256];
			strcpy(name, argv[2]);
			name[strlen(name)-4]='\0';
			fileOpen = fopen(argv[2], "r");
			if(fileOpen == NULL){
				perror("Erro de leitura");
				return 1;
			}
			fileClose = fopen(name, "wb");
			if(fileClose == NULL){
				perror("Erro de escrita");
			}
			while(fscanf(fileOpen, "%X", &byte) == 1){
				fputc((unsigned char)byte, fileClose);				
			}
			fclose(fileOpen);
			fclose(fileClose);
		}
		else{
		    printf("???\n");	
		}
		
	    return 0;	
	}
