#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
	game *arr = NULL;
	int n = 0;
	int stop= 1;
	int keyC = 0;
	while(stop){
		int key = 0;
		key += keyC;
		keyC = 0;
		if (!key){
			printf("1. Create a database \n2. Print the database \n3. Search in the database\n");
			scanf("%i", &key);
		}
		switch (key)
		{
			case 1:{
				int key2;
				printf("1. Write new\n2. Load from a file\n");
				scanf("%i", &key2);
				if (key2==1) {	
					create(&arr, &n);
					if(!arr) {
						printf("Error create a database\n");
						stop = 0;
						break;
					}
					else {
						printf("Created %d entries\n", n);
					}
					write(arr,n);
					}
				else if(key2==2){
					read(&arr, &n);
					if(!arr) 
					{
						printf("Error reading a database\n");
						stop = 0;
						break;
					}
					else {
						printf("Loaded %d entries\n", n);
					}
				}
				break;
			}
			case 2:
				if(!arr) 
					{
						int key3;
						printf("Couldn't find the database. Would you like to create one?\n1 - Yes\n2 - No\n");
						scanf("%i", &key3);
						if(key3==1) keyC=1;
						else stop = 0;
						break;
					}
					else
					{
						for(int i = 0; i<n; i++) {
							printf("Name: %s; Price: %f; Rating: %f;\n",
							 arr[i].name, arr[i].price, arr[i].rating); 
							}
					}
				break;
			case 3:
				if(!arr) 
					{
						int key3;
						printf("Couldn't find the database. Would you like to create one?\n1 - Yes\n2 - No\n");
						scanf("%i", &key3);
						if(key3==1) keyC=1;
						else stop = 0;
						break;
					}
					else
					{
						search(arr,&n);
					}
				break;
			default:
				stop = 0;
				break;
		}
	}
	if (arr) free(arr);
	return 0;
}
