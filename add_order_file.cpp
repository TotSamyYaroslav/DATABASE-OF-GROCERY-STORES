
int menu_order(){
 	int number_choice = -1;
	char choice=0;
	while ((number_choice < 0 || number_choice > 5) && number_choice != 27){
		printf("\nМеню замовлень:\n");
	    printf("0 : Повернутися на головне меню     \n"
	           "1 : Розпочати замовлення            \n"
	           "2 : Переглянути КОШИК      \n"
	           "3 : Зберегти замовлення             \n"
	           "4 : Відмінити замовлення            \n"
	           "5 : Роздрукувати чек               \n"
	           ">");
	    choice = getch();
	    number_choice=choice-'0';
	    printf("%c\n", number_choice);
	}
  	return number_choice;
 	
}

void add_order(){
	int count_prod,count_num_product,id_prod,num_prod;
	char key_exit,number;
	
	if (num_order == 20){
    	fprintf(stderr, "ПОМИЛКА! Недостатньо памяті\n");
    	return;
  	}
  	
  	for(count_num_product=0; count_num_product < num_product; count_num_product++){//видалення елемента з файлу,якщо його кількість менша 1
		if(goods[count_num_product].number<1){
			for (count_prod=count_num_product ; count_prod < num_product -1; count_prod ++)
    			goods[count_prod] = goods[count_prod + 1];
  			num_product --;
			count_num_product--;
			
		}
	}
	
	save();
	print();
	do{	
		printf("Для додавання товару у кошик оберіть номер товару :\n");
		id_prod=0;
		num_prod=0;
		do{
	  		printf("\nВведіть номер товар:\n");
	  		id_prod=0;
	  		while((number=getchar()) != '\n') 
			  	if (number>='0' && number<='9') {
					id_prod*=10; 
					id_prod+= (number - '0');
			}
	  		if(id_prod < 1 || id_prod > num_product){
	  			printf("Товару з таким номером не існує \n");
	    	
		  	}
		}while(id_prod < 1 || id_prod > num_product);
		
	  	if(num_product==1){//перевірка на кілкість відповідного товару більша ніж 0, при умові якщо кількість товарів = 1(щоб припинити замовлення)
	  		if(goods[id_prod-1].number == 0){
	  			printf("Товар закінчився :(  \nЗбережіть замовлення :)\n");
	  			return;
			  }
		  }
		  
		do{
	  		printf("Введіть кількість товару:");
			num_prod=0;
			while((number=getchar()) != '\n') 
			  	if (number>='0' && number<='9') {
					num_prod*=10; 	
					num_prod+= (number - '0');
			}
			if(num_prod < 1 || num_prod > goods[id_prod-1].number){
	  			printf("Товару бракує %i  \n", num_prod);
	    	
		  	}
		  	
		}while(num_prod < 1 || num_prod > goods[id_prod-1].number);
		
		
		for(count_num_product=0;count_num_product<num_product;count_num_product++){//копіювання даних у масив структури замолення з масиву структури продукту
			if(id_prod-1 == count_num_product){
				goods[id_prod-1].number=goods[id_prod-1].number-num_prod;
				strcpy(products[num_order].name_product,goods[id_prod-1].name);
				strcpy(products[num_order].product_group_order,goods[id_prod-1].product_group);
				products[num_order].number_product=num_prod;
				///
				products[num_order].sum_price=num_prod*goods[id_prod-1].price;
				products[num_order].kilk_order=num_order+1;
				products[num_order].number_order=id_prod;
			}
		}
			num_order++;
	
		fflush(stdin);
		save();
		
		printf("Продовжити - Еnter, ESC - завершити\n");
		key_exit=getch();
		
	}while(key_exit!=27);
	
}

void save_order(){
	
	fflush(stdin);
	printf("Введіть П.І.Б.:");
  	gets(client[num_client].surname);
  	printf("Введіть тел.:");
  	gets(client[num_client].phone);
  	num_client++;
  	
  		FILE *F2;
  	int count_num_order,count_num_client;

  	if ((F2 = fopen(storige_order, "a")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'Storege.txt'\n");
    	return;
  	}

  	fprintf(F2, "%i\n", num_order);//збереження чеку про замовлення
  	for(count_num_order=0;count_num_order<num_order;count_num_order++){
	    fprintf(F2, "N:%i\n Name:     %s\n Numder:   %i\n Price:    %.2f\n",products[count_num_order].kilk_order, products[count_num_order].name_product,
		products[count_num_order].number_product,products[count_num_order].sum_price);
	}
	for(count_num_client=0;count_num_client<num_client;count_num_client++){
		fprintf(F2, "Name Client:%s  Tel:%s\n  ",client[count_num_client].surname,client[count_num_client].phone);
	}
  	fclose(F2);
}

void print_order(){
	int count_num_order;
	float total=0;
	
  	printf(" N |Назва товару |  Група  | Кількість|  Ціна|   \n");
  	for (count_num_order = 0; count_num_order <num_order; count_num_order ++){
	  
  		total+=products[count_num_order].sum_price;
    	printf("%i. %5s %10s %10i  %15.2f\n", count_num_order + 1,products[count_num_order].name_product,products[count_num_order].product_group_order,
		products[count_num_order].number_product,products[count_num_order].sum_price);
	}
	
	printf("\n                                   Сума:%.2f\n",total);
}

void del_order(){
	num_order=0;
}

void check(){
	
	int count_num_order,count_num_client;
	float total=0;
	for(count_num_order=0; count_num_order < num_order;count_num_order++){
		total+=products[count_num_order].sum_price;
	}
	printf("sum=%.2f\n",total);
	printf("______________________________________________\n");
  	printf(" N |   Назва товару |Кількість|  Ціна|   \n");
  	
	for (count_num_order = 0; count_num_order <num_order; count_num_order ++)
    	printf("%i. %5s %10i  %15.2f\n", count_num_order + 1,products[count_num_order].name_product,products[count_num_order].number_product,products[count_num_order].sum_price);
    	
    printf("______________________________________________\n");
    printf("                            Сума: %.2f\n",total);
    printf("______________________________________________\n");
	printf(" П.І.Б.               |Телефон           \n");
	for (count_num_client = 0; count_num_client < num_client; count_num_client ++)
		printf("  %s               %20s\n",client[count_num_client].surname,client[count_num_client].phone);
	num_client=0;
	num_order=0;
	
	FILE *F2;
	if ((F2 = fopen(storige_order, "a")) == NULL){
    	fprintf(stderr, "Невдається відкрити для запису файл 'Storege_order.txt'\n");
    	return;
  	}
  	fprintf(F2,"SumPraice:%f\n=====================================================================================\n", total);
  	
  	fclose(F2);
  	
}

int make_order(){
	int choice_order;
	while ((choice_order = menu_order()) != 0 && choice_order != 27){
	 
	    switch (choice_order)
	    {
	    case 1:
	    	if(num_product>0){
	    		add_order();
			}else{
				printf("Товару немає :( \n");
			}
	      	break;
	    case 2:
	      	print_order();
	      	break;
	    case 3:
	      	save_order();
	      	break;
	    case 4:
	    	del_order();
	    	break;
	    case 5:
	      	check();
	      	break;
	    }
	}
 	return 0;
}
