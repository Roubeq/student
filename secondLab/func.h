typedef struct game{
	char name[70];
	float price;
	float rating;
}game;
void create(game**arr,int*n);
void read(game**arr,int*n);
void write(game*arr,int n);
void search(game*arr,int *n);
