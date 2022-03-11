/*

*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include<sys/stat.h>
int main(int argc, char* argv[])
{
	
	DIR* dObj;
	FILE* fp;
	struct dirent* dir;
	char *filename;
	char *file_two;
	char *user;
	struct stat fs;
	int r;
	int tes = 0;
	int boo = 0;
	//time_t rawtime;
	//struct tm * timeInfo;
	//char buffer[80];
	
	//time ( &rawtime );
	
	//char *permissions = "----------";
	//permissions[0] = 'r';
	char perm[12] = "----------";
	perm[0] = 'r';
	printf(perm);
	struct passwd *pw;
	struct group *gr;
	if(argc == 1)
	{
			
		dObj = opendir(".");
		int counter = 0;
		while((dir=readdir(dObj)) != NULL)
		{
			
			if(counter > 1)
			{
			
				printf("%s  ", dir->d_name);
				/*
				r = stat(dir->d_name, &fs);
				printf("Owner permissions: ");
				if( fs.st_mode & S_IRUSR )
				{
					printf("read ");
				}
				*/
			}
			counter++;
		}
		printf("\n");
	}
	
	
	if (argc>1)
	{
		int ctr = 1;
		char options[100];
		char options_cmp[100] = "-lhn";
		char human_readable[100] = "h";
		char long_list[100] = "l";
		char n_symbol[100] = "n";
		int h_option = 0;
		int l_option = 0;
		int n_option = 0;
		int option_it = 0;
		int cab = 1;
		int args = argc;
		int number_of_option_arguments = 0;
		while(ctr<argc)
		{
			
			
				
			
	
			strcpy(options,argv[ctr]);
			
			if(option_it == 1)
			{
				printf("\nOption_IT =1");
			}
			if(options[0] == '-' && option_it == 0)
			{

				for(int j=0; j<=97; j++)
				{
					if((options[j] == human_readable[0]))
					{
						//printf("OPTIONS WAS");
						//printf(options[j]);
						h_option = 1;
						printf("\nHUMAN READABLE ON\n");
					}
					if((options[j] == long_list[0]))
					{
						l_option = 1;
						printf("\nLONG LIST ON\n");
					}
					if((options[j] == n_symbol[0]))
					{
						n_option = 1;
						printf("\nN OPTION ON\n");
					}
				}
				number_of_option_arguments++;
			}
			if((options[0] != '-') && option_it == 0)
			{
				option_it = 1;
			}
			if(option_it == 1)
			{	
				
				
				strcpy(filename, argv[ctr]);
				strcat(filename, "/");
				
				dObj = opendir(argv[ctr]);
				int coun = 0;
				if(dObj == NULL)
				{
					closedir(dObj);
					printf("%s ", argv[ctr]);
				}
				if(dObj != NULL)
				{
						
					
					
						if((number_of_option_arguments+2)<= argc)
						{
							printf(" ");
							printf("\n");
							printf(argv[ctr]);
							printf(": \n");
						}
						if(l_option == 0)
						{
							while((dir=readdir(dObj)) != NULL)
							{
								if(coun>1)
								{
									printf("%s ", dir->d_name);
								}
								coun++;
							}
						}
						if(l_option == 1)
						{
							
							int cou = 0;
							
							while((dir=readdir(dObj)) != NULL)
							{

								if(cou > 1)
								{
								
									strcat(filename, dir->d_name);
									printf("\nConcatenated: ");
									printf(filename);
									r = stat(filename, &fs);
									if( S_ISDIR(fs.st_mode))
									{
										perm[0] = 'd';
										
									}
									if( S_ISLNK(fs.st_mode))
									{
										perm[0] = 'l';
									}
									if( S_ISREG(fs.st_mode))
									{
										perm[0] = '-';
										
										
									}
									if ( fs.st_mode & S_IRUSR )
									{
										perm[1] = 'r';
									}
									if ( fs.st_mode & S_IWUSR )
									{
										perm[2] = 'w';
									}
									if ( fs.st_mode & S_IXUSR )
									{
										perm[3] = 'x';
									}
									if (fs.st_mode & S_IRGRP)
									{
										perm[4] = 'r';
									}
									if (fs.st_mode & S_IWGRP)
									{
										perm[5] = 'w';
									}
									if (fs.st_mode & S_IXGRP )
									{
										perm[6] = 'x';
									}
									if (fs.st_mode & S_IROTH)
									{
										perm[7] = 'r';
									}
									if(fs.st_mode & S_IWOTH)
									{
										perm[8] = 'w';
									}
									if(fs.st_mode & S_IXOTH)
									{
										perm[9] = 'x';
									}
									printf("\nPermissions are: ");
									printf(perm);
									//user = argv[ctr];
									//strcpy(user,fs.st_uid);
									
									pw = getpwuid(fs.st_uid);
									printf("\nTest: ");
									if(pw!=0)
									{
										
										printf(pw->pw_name);
										//strcpy(user, pw->pw_name);
									}
									gr = getgrgid(fs.st_gid);
									if(gr!=0)
									{
										printf(gr->gr_name);
									}
									if ( S_ISREG(fs.st_mode)) 
									{
										printf("\nTrying size: ");
										printf("Total file size: %lu bytes\n", fs.st_size);
										//time_t rawtime;
										//struct tm * timeinfo;
										//char buffer[80];
										
										if(fs.st_mtime !=0)
										{
											char *time = ctime(&fs.st_mtime);
											char the_time[100];
											char buffer[80];
											strcpy(the_time, ctime(&fs.st_mtime));
											//printf(the_time);
											struct tm *mytm = localtime(&fs.st_mtime);
											strftime(buffer,80,"%I:%M:%S-%m/%d/%y", mytm);
											puts(buffer);
											//struct tm *mytm = localtime(&fs.st_mtime);
											//strftime(buffer,80,"%I:%M:%S-%m/%d/%y", mytm);
											//puts(buffer)
											
											
											
											//printf("Last modification time: %s", &fs.st_mtime);
										}
										
									}	
									
									
								}
								
								
								
								cou++;
								strcpy(filename,argv[ctr]);
								strcat(filename,"/");
							}
					
						}
						if((number_of_option_arguments+2)<=argc)
						{
							printf("\n");
						}
						coun=0;
					
				}
			
			}
				
				
			
			
			
			ctr++;
		}
               
	//	strcpy(options, argv[1]);
		
	//	while(counter<argc)
	//	{
	//		strcpy(options,argv[counter]);
			
			/////////////////////////////////////////////////////////
//			if((options[0] == options_cmp[0]))
//			{
		//	if(n_option == 0)
		//	{
			//	strcpy(options,argv[counter]);
			//	printf("\nOPTION OCCURED");
				
			//	for(long unsigned int c = 0; c <= 900; c++)
			//	{
				/*
				int fa = 0;
				while(fa<900)
				{
					fa++;
				}
				*/
				  	/*
					if(options[c] == human_readable[0])
					{	
						h_option = 1;	
					}
					if(options[c] == long_list[0])
					{	
						l_option = 1;
					}				
					if(options[c] == n_symbol[0])
					{
										
						n_option = 1;
					}
				*/
			//	}	
				
			
		//	}
			//////////////////////////////////////////////////////////
		//	if ((options[0] != options_cmp[0]))
		//	{
		//		option_it = 1;
		//	}
			
			/*
		
		
		
			if(option_it == 1)
			{
			
				dObj = opendir(argv[counter]);
				
				if(l_option == 1)
				{
					if(dObj!=NULL)
					{
						r = stat(argv[counter], &fs);
						printf("\nPermission bits: %X\n",fs.st_mode);
						printf("\nTime to build permissions\n");
						if( S_ISDIR(fs.st_mode) )
						{
							//permissions[0] = 'd';
						}
					}
				}
				
				
				if(l_option==0)
				{
					
					if(dObj==NULL)
					{
						fp = fopen(argv[counter], "r");
						if(fp!=NULL)
						{
							printf(argv[counter]);
							printf("\n");
						}
						if(fp==NULL)
						{
							perror(argv[counter]);
							
						}
					}
					
					
					if(dObj!=NULL)
					{
						int counter = 0;
						if(counter<argc)
						{
							printf("\n");
							printf(argv[counter]);
							printf(":  \n");
						}
						while((dir=readdir(dObj)) != NULL)
						{
							if(counter > 1)
							{
								printf("%s  ", dir->d_name);
								r= stat(dir->d_name, &fs);
						
							}
							counter++;

						}
					}
					
					printf("\n");
					closedir(dObj);
			
				}
				
			
				
				
			}
			*/
		
		
		//counter++;
	
		//}
	
	}
	
	
		return(0);


}
tm formatTime(struct tm* var)
{
	return var;
}


