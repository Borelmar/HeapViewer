#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include"hexdump.h"
	
#define Person struct { char name[10]; char city[10]; char gender[10];}

void length(Person *array[])
{
    return( (int)( sizeof(array) / sizeof(array[0]) ) );
}


int main(){
	Person *array[10];
	for(int i = 0; i < 10; ++i){
		array[i] = 0; 
	}
	while(1){
		char choice;
		puts("#####################################");	
		puts("#[1] - allocate new Person          #");	
		puts("#[2] - list of Person's             #");	
		puts("#[3] - edit params of choice Person #");
		puts("#[4] - hexdump all                  #");	
		puts("#[5] - show source struct           #");
		puts("#####################################");	
		choice = getchar();
		getchar();
		if(choice == '1'){
			int freep = -1;
			for( int i = 0 ; i < 10; ++i){
				if(array[i] == 0){
					freep = i;
					break;
				}	
			}
			if(freep == -1){
				printf("list non free\n");
				continue;
			}
			array[freep] = malloc(30);
			printf("Name: ");
			gets( array[freep]->name);
			printf("City: ");
			gets( array[freep]->city);
			printf("Gender: ");
			gets( array[freep]->gender);
		}
		else if(choice == '2'){
		    for( int i = 0; i < 10 ; ++i){
		        if(array[i] != 0){
		            printf("[%d] addr: %p , Name: %s , City: %s, Gender: %s\n", (i) , array[i] , array[i]->name , array[i]->city , array[i]->gender);
		            continue;
		        }
		        printf("[%d] ...\n" , (i));
		    }
			
		}
		else if(choice == '3'){
			printf("choice the index of the person: ");
			char ind = getchar(); getchar();	
			int index = atoi(&ind);
			printf("Name: ");
			gets( array[index]->name);
			printf("City: ");
			gets( array[index]->city);
			printf("Gender: ");
			gets( array[index]->gender);
					
		}
		else if(choice == '4'){
			int *lowborder = array[0];
			hexdump("dump" , lowborder-0x8 , 500);
			continue;
 	
		}
		else if(choice == '5'){
			puts("struct Person {");	
			puts("	char name[10];");	
			puts("	char city[10];");	
			puts("	char gender[10];");	
			puts("}");	
		}
		
	}

	return 0;
}
