
#define storige_file "Storige.txt"
#define storige_order "Storige_order.txt"
#define num_product_file "Number_product.txt"

typedef struct products{
  char name[50],product_group[50],validity[50];
  int number;
  float price;
  
} pro;
pro goods[50],sort_goods[50],sort_num;

typedef struct orders{
	char name_product[20],product_group_order[20];
	int number_product,number_order,kilk_order;
	float sum_price;
} ord;
ord products[100];

typedef struct clients{
	char surname[50],phone[15];
} cli;
cli client[50];

int num_client=0;
int num_order=0;
int num_product=0;
int count_printf;

void read_file(){
	FILE *F,*fproduct;
  	int count_num_product;

  	if ((F = fopen(storige_file, "r")) == NULL){
    	fprintf(stderr, "Невдається відкрити для читання файл 'Storege.txt'\n");
    	return;
  	}
  	if ((fproduct = fopen(num_product_file, "r")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'Number_product.txt'\n");
    	return;
  	}
  	fscanf(fproduct, "%i", &num_product);
  	fclose(fproduct);
  	
  	char names[100];
  	int lenth;
  	
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++){
  		
		fgets(names,sizeof(names),F);
		lenth= strlen(names);
		names[lenth-1]=0;
		strcpy(goods[count_num_product].name,names);
		
		fscanf(F, "%s", goods[count_num_product].product_group);
		fscanf(F, "%i", &goods[count_num_product].number);
		fscanf(F, "%s", goods[count_num_product].validity);
		fscanf(F, "%f", &goods[count_num_product].price);
	    fgets(names,sizeof(names),F);
	  }
    
	fclose(F);
}

void print(){	
	int count_num_product,count_prod;
	read_file();
	
	for(count_num_product=0; count_num_product < num_product; count_num_product++){//видалення елемента з файлу,якщо його кількість менша 1
		if(goods[count_num_product].number<1){
			for (count_prod=count_num_product ; count_prod < num_product -1; count_prod ++)
    			goods[count_prod] = goods[count_prod + 1];
  			num_product --;
			count_num_product--;
			
		}
	}
	
	printf(" N |Назва товару |  Група  | Кількість | Термін  |  Ціна\n");
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	printf("%2i. %10s %15s %5i %15s %15.2f\n", count_num_product + 1,goods[count_num_product].name,goods[count_num_product].product_group,goods[count_num_product].number,goods[count_num_product].validity,goods[count_num_product].price);
}
int menu(){
  	int number_choice =-1;
  	char choice=0;
  	if(count_printf==0)print();
  	count_printf++;

	while ((number_choice < 0 || number_choice > 5) && number_choice != 27){
  		printf("\nГоловне меню:\n");
    	printf("0 : Вихід\n"
           "1 : Додати дані \n"
           "2 : Редагувати дані\n"
           "3 : Переглянути дані\n"
           "4 : Зробити замовлення\n"
           "5 : Сортування даних\n"
           ">");
          
    	choice = getch();
    	number_choice = choice -'0';
    	printf("%i\n", number_choice);
  	}
  	return number_choice;
}
void save(){
  	FILE *F,*fproduct;
  	int count_num_product;
	
  	if ((F = fopen(storige_file, "w")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'Storege.txt'\n");
    	return;
  	}
  	if ((fproduct = fopen(num_product_file, "w")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'Number_product.txt'\n");
    	return;
  	}
	fprintf(fproduct, "%i\n", num_product);
	fclose(fproduct);
	
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	fprintf(F, "%s\n %s\n %i\n %s\n %f\n ",goods[count_num_product].name,goods[count_num_product].product_group,goods[count_num_product].number,goods[count_num_product].validity,goods[count_num_product].price);

  	fclose(F);
}
void add(){
	
  	if (num_product == 50){
    	fprintf(stderr, "ПОМИЛКА! Недостатньо памяті\n");
    	//return;
  	}
	
  	printf("Введіть назву товару:");
  	gets(goods[num_product].name);
  	fflush(stdin);
  	printf("Введіть групу товару:");
  	gets(goods[num_product].product_group);
  	fflush(stdin);
  	printf("Введіть кількість товару:");
  	scanf("%i", &goods[num_product].number);
  	fflush(stdin);
  	printf("Введіть термін товару, у форматі day.month.year:");
	gets(goods[num_product].validity);
	fflush(stdin);
	printf("Введіть ціну товару гривнями, у форматі 0,00  :");
	scanf("%f", &goods[num_product].price);
	fflush(stdin);
	num_product ++;
	
	save();
  	
}





