/*
wycat.c
Author: Jared Sleep
Date: 2/22/2022

COSC 3750, HW4

This is a simple version of the cat utility.
Without any arguments, will take standard input,
and go straight to standard output. If a filename
is given as an argument, it is outputted to stdout.
If a dash is used as an argument, process it as stdin to stdout.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

	if(argc == 1)
	{
		char str[4096];
		printf("Please enter standard input: ");
		fgets(str, 4096, stdin);
		printf("\nStandard output: %s", str);


	}
	if (argc>1)
	{
		int counter = 1;
		FILE *fp;
		char str[4096];
		while(counter < argc)
		{
			fp = fopen(argv[counter], "r");
			if(*argv[counter] == '-')
			{
				printf("Please enter a standard input: ");
				fgets(str, 4096, stdin);
				printf("\nStandard output: %s", str);
			}
			else if (fp == NULL)
			{
				perror("Error opening file.");
			}
			else if (fp != NULL)
			{
			
			
				
				
				printf("\nFile: ");
				printf(argv[counter]);
				printf("\n");
			
				while (fread(str,1,1,fp) == 1)
				{
					fwrite(str,1,1,stdout);
				}
			
				fclose(fp);
			}
			
			counter++;
		}
		
		return(0);
	
}
}
