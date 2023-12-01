#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <stdbool.h>
#include <string.h>
void create(game**arr,int*n){
	printf("Enter the number of games - ");
	scanf("%d",n);
	if(*n<=0)
		return;
	*arr=(game*)calloc(*n,sizeof(game));
	if (!arr) return;
	for(int i=0;i<*n;i++){
		printf("name -");
		scanf("%s",(*arr)[i].name);
		printf("price -");
		scanf("%f",&(*arr)[i].price);
		printf("rating -");
		scanf("%f",&(*arr)[i].rating); 
	};
}
void read(game**arr,int*n){
	FILE*f=fopen("file.txt","r");
	if(!f) return;
	if(fscanf(f,"%d",n)!=1) {
		fclose(f);
		return;
	}
	if(*n<=0) return;
	*arr=(game*)calloc(*n,sizeof(game));
	for (int i=0;i<*n;i++) {
		if(fscanf(f,"%s %f %f", (*arr)[i].name,&(*arr)[i].price,&(*arr)[i].rating)!=3) break; 
	}
	fclose(f);
}
void write (game*arr, int n){
	if(n<=0) return;
	FILE*f=fopen("file.txt","w");
	if(!f) return;
	fprintf(f,"%d\n",n);
	for(int i=0; i<n;i++) {
		fprintf(f,"%s %f %f",arr[i].name,arr[i].price,arr[i].rating);
	}
	fclose(f);
}
void search (game*arr, int * n) {
	int typeSearch;
	printf("Enter the type of search - \n1. Search by name \n2. Search by price(<=) \n3. Search by rating(>=)\n");/*пользователь, не 		надо сюда буквы вводить или числа плиз, ну ты понимаешь у тебя три варианта - 1 2 3, больше чисел и букв не существует))))*/
	scanf("%d",&typeSearch);
	switch(typeSearch) {
		case 1: {
			char word[80];
			bool flag = false;
			printf("Enter a name -");
			scanf("%s",word);
			for (int i=0; i<*n;i++) {
				if(!strcmp(word,arr[i].name)) {
					printf("Found - %s %f %f\n",arr[i].name,arr[i].price,arr[i].rating);
					flag = true;
				}
			}
			if (flag == false) printf("Nothing found \n");
			break;
		}
		case 2: {
			float price;
			bool flag = false;
			printf("Enter a price -");
			scanf("%f",&price);
			for (int i=0; i<*n; i++) {
				if (arr[i].price <= price) {
					printf("Found a game - %s %f %f \n",arr[i].name,arr[i].price,arr[i].rating);
					flag = true;
				}
			}
			if (flag == false) {
				printf("Nothing found \n");
			}
			break;
		}
		case 3: {
			double rating;
			bool flag;
			printf("Enter a rating -");
			scanf("%lf",&rating);
			for (int i = 0; i<*n;i++){
				if (rating >= arr[i].rating){
					printf("Found a game - %s %f %f",arr[i].name,arr[i].price,arr[i].rating);
					flag = true;
				}
			}
			if (flag == false) {
				printf("Nothing found");
			}
			break;
		}
		default:
			break;
	}
}
/*1. Уместным будет код из всех сase убрать в отдельную функцию, тем самым сократив код 
  2. Можно поиграться с поиском, т.к сказать сделать его более усовершенствованным, сделав поиск например: чтобы пользователь вводил цену, рейтинг как обычное число, а в цикле как то использовать приведение типов, если оно существует в C) 
  3. Ну и я не стал где то пока делать проверки на глупого пользователя, т.к вы сказали что сами скажете какую нужно сделать))*/


	
