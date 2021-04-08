

int menu_sort(){
	int count_num_product,number_choice = -1;
	char choice;
	read_file();
	
	for(count_num_product=0;count_num_product<num_product;count_num_product++){
		sort_goods[count_num_product]=goods[count_num_product];
	}

	while ((number_choice < 0 || number_choice > 6) && number_choice != 27){
		printf("\nМеню сортування:\n");
	    printf("0 : Повернутися на головне меню\n"
	    	   "1 : Фільтр назви товару за алфавітом\n"
	    	   "2 : Фільтр групи товарів за алфавітом\n"
	           "3 : Фільтр кількості товару по спаданю\n"
	           "4 : Фільтр за терміном придатності товару\n"
	           "5 : Фільтр ціни товару по спаданю\n"
	           "6 : Перегляд даних по вибраній групі товару\n"
	           ">");
	    choice = getch();
	    number_choice = choice - '0';
	    printf("%i\n", number_choice);
	}
  	return number_choice;
}

void sort_name(){
	int count_num_product, count_num, number_element;
  	int number_tmp;
  	float price_tmp;
	
 	for(count_num_product=0;count_num_product<num_product-1;count_num_product++){//сортування назви товару за алфавітом
    number_element=count_num_product;
    for(count_num=count_num_product+1;count_num<num_product;count_num++){
      	if(strcmp(sort_goods[number_element].name,sort_goods[count_num].name)>0){
            
        number_element=count_num; 
      
      	}  
    }
    if(number_element!=count_num_product){
    
    	sort_num=sort_goods[number_element];
	    sort_goods[number_element]=sort_goods[count_num_product];
		sort_goods[count_num_product]=sort_num;
    
    	}
  	}
  	
  	printf("\n");
	printf(" N |Назва товару |  Група |   Кількість   |    Термін  |     Ціна\n");
	printf("\n");
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	printf("%2i. %5s %15s %10i %15s %15.2f\n", count_num_product + 1,sort_goods[count_num_product].name,sort_goods[count_num_product].product_group,
		sort_goods[count_num_product].number,sort_goods[count_num_product].validity,sort_goods[count_num_product].price);

}

void sort_group(){
	int count_num_product, count_num, number_element;
  	int number_tmp=0;
	float price_tmp=0;
	
 	for(count_num_product=0;count_num_product<num_product-1;count_num_product++){//сортуванн групи товарів в алфавітному порядку
    number_element=count_num_product;
    for(count_num=count_num_product+1;count_num<num_product;count_num++){
      	if(strcmp(sort_goods[number_element].product_group,sort_goods[count_num].product_group)>0){
            
        number_element=count_num; 
      
      	}  
    }
    if(number_element!=count_num_product){
    	
    	sort_num=sort_goods[number_element];
	    sort_goods[number_element]=sort_goods[count_num_product];
		sort_goods[count_num_product]=sort_num;
		
    	}
  	}
  	
  	printf("\n");
	printf(" N |Група | Назва товару  |   Кількість   |    Термін  |     Ціна\n");
	printf("\n");
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	printf("%2i. %5s %15s %10i %15s %15.2f\n", count_num_product + 1,sort_goods[count_num_product].product_group,sort_goods[count_num_product].name,sort_goods[count_num_product].number,sort_goods[count_num_product].validity,sort_goods[count_num_product].price);

}

void sort_numb(){
	int count_num_product,count_num;
	int num_tmp=0;
	float price_tmp=0;
	
	for(int count_num=0;count_num<num_product-1;count_num++){//сотування кількості товарів по зростаню за допомгою бульбашки

	  	for(int count_num_product=0;count_num_product<num_product-1-count_num;count_num_product++){
	  
	     	if(sort_goods[count_num_product].number>sort_goods[count_num_product+1].number){
	     		
	     		sort_num=sort_goods[count_num_product];
	     		sort_goods[count_num_product]=sort_goods[count_num_product+1];
	     		sort_goods[count_num_product+1]=sort_num;
	     
	     	}	
	 	}
	}
	printf("\n");
	printf(" N |Кількість | Назва товару  |  Група    |    Термін  |     Ціна\n");
	printf("\n");
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	printf("%2i. %5i %15s %10s %15s %15.2f\n", count_num_product + 1,sort_goods[count_num_product].number,sort_goods[count_num_product].name,sort_goods[count_num_product].product_group,sort_goods[count_num_product].validity,sort_goods[count_num_product].price);

}

void sort_val(){
	
	int count_num_product,count_num,k=0,
	day1=0,month1=0,year1=0;
	
	
	int flag_data=0,length_validity=10;
	char *pgoods;
	int num_tmp=0,price_tmp=0;
	
	int *arr_day,*arr_month,*arr_year;
	
	arr_day = (int*)malloc(num_product*sizeof(int));
	arr_month = (int*)malloc(num_product*sizeof(int));
	arr_year = (int*)malloc(num_product*sizeof(int));
	
	for(int count_num_product=0;count_num_product<num_product;count_num_product++){//сотування терміну товарів по зростаню за допомгою бульбашки
		
		pgoods=sort_goods[count_num_product].validity;
		
		
		flag_data=0;
		
		for(int count_num=0;count_num<length_validity;count_num++){
			if(pgoods[count_num]=='.'){
				flag_data++;
			}else{
				if(flag_data==0){
					
					sscanf(pgoods,"%d",&arr_day[count_num_product]);
	
				}else if(flag_data==1){
					sscanf(pgoods+3,"%d",&arr_month[count_num_product]);
					
				}else if(flag_data==2){
					sscanf(pgoods+6,"%d",&arr_year[count_num_product]);
					
				}
			}
		}		
	}
	
	int flag_year,flag_day,flag_month,tmp_year,tmp_month,tmp_day;

	for(;;){
		flag_year=0;
		flag_day=0;
		flag_month=0;
		for(int count_num_product=0;count_num_product<num_product-1;count_num_product++){
		  
		    if(arr_year[count_num_product]>arr_year[count_num_product+1]){
		     	if(flag_year==0) flag_year=1;
				sort_num=sort_goods[count_num_product];
	     		sort_goods[count_num_product]=sort_goods[count_num_product+1];
	     		sort_goods[count_num_product+1]=sort_num;
	     		
	     		tmp_year=arr_year[count_num_product];
	     		arr_year[count_num_product]=arr_year[count_num_product+1];
	     		arr_year[count_num_product+1]=tmp_year;
	     		
	     		tmp_month=arr_month[count_num_product];
	     		arr_month[count_num_product]=arr_month[count_num_product+1];
	     		arr_month[count_num_product+1]=tmp_month;
	     		
	     		tmp_day=arr_day[count_num_product];
	     		arr_day[count_num_product]=arr_day[count_num_product+1];
	     		arr_day[count_num_product+1]=tmp_day;
	     		
		    }
		}
		if(flag_year==0 ) {
		
				for(int count_num_product=0;count_num_product<num_product-1;count_num_product++){
		
					if(arr_year[count_num_product]==arr_year[count_num_product+1]){
						
						if(arr_month[count_num_product]>arr_month[count_num_product+1]){
							if(flag_month==0) flag_month=1;
							
							sort_num=sort_goods[count_num_product];
			     			sort_goods[count_num_product]=sort_goods[count_num_product+1];
			     			sort_goods[count_num_product+1]=sort_num;
			     			
			     			tmp_year=arr_year[count_num_product];
				     		arr_year[count_num_product]=arr_year[count_num_product+1];
				     		arr_year[count_num_product+1]=tmp_year;
				     		
				     		tmp_month=arr_month[count_num_product];
				     		arr_month[count_num_product]=arr_month[count_num_product+1];
				     		arr_month[count_num_product+1]=tmp_month;
				     		
				     		tmp_day=arr_day[count_num_product];
				     		arr_day[count_num_product]=arr_day[count_num_product+1];
				     		arr_day[count_num_product+1]=tmp_day;
		     		
						}
					}
				}
			if(flag_month==0){
				for(int count_num_product=0;count_num_product<num_product-1;count_num_product++){
		
					if(arr_year[count_num_product]==arr_year[count_num_product+1]){
						
						if(arr_month[count_num_product]==arr_month[count_num_product+1]){
							if(arr_day[count_num_product]>arr_day[count_num_product+1]){
								if(flag_day==0) flag_day=1;
							
								sort_num=sort_goods[count_num_product];
				     			sort_goods[count_num_product]=sort_goods[count_num_product+1];
				     			sort_goods[count_num_product+1]=sort_num;
				     			
				     			tmp_year=arr_year[count_num_product];
					     		arr_year[count_num_product]=arr_year[count_num_product+1];
					     		arr_year[count_num_product+1]=tmp_year;
					     		
					     		tmp_month=arr_month[count_num_product];
					     		arr_month[count_num_product]=arr_month[count_num_product+1];
					     		arr_month[count_num_product+1]=tmp_month;
					     		
					     		tmp_day=arr_day[count_num_product];
					     		arr_day[count_num_product]=arr_day[count_num_product+1];
					     		arr_day[count_num_product+1]=tmp_day;
							}
						}
					}
				}
				if(flag_day==0)break;
			}	
		}
	}
	
	free(arr_day);
	free(arr_month);
	free(arr_year);
	
	printf("                                            Відсортована таблиця\n");
	printf("\n");
	printf("  N |  Термін  | Назва товару |   Група  | Кількість |  Ціна\n");
	printf("\n");
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	printf("%2i. %5s %15s %10s %15i %15.2f\n", count_num_product + 1,sort_goods[count_num_product].validity,sort_goods[count_num_product].name,sort_goods[count_num_product].product_group,sort_goods[count_num_product].number,sort_goods[count_num_product].price);
	
}

void sort_pra(){
	int count_num_product,count_num;
	int num_tmp=0;
	float price_tmp=0;
	
	for(int count_num=0;count_num<num_product-1;count_num++){//сотування ціни товарів по зростаню за допомгою бульбашки

	  	for(int count_num_product=0;count_num_product<num_product-1-count_num;count_num_product++){
	  
	     	if(sort_goods[count_num_product].price>sort_goods[count_num_product+1].price){
	     	
			  	sort_num=sort_goods[count_num_product];
	     		sort_goods[count_num_product]=sort_goods[count_num_product+1];
	     		sort_goods[count_num_product+1]=sort_num;
	    
	     	}	
	 	}
	}
	printf("\n");
	printf(" N |Ціна     |Назва товару | Кількість  |  Група    |    Термін  \n");
	printf("\n");
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	printf("%2i. %.2f %10s %10i %10s %15s \n", count_num_product + 1,sort_goods[count_num_product].price,sort_goods[count_num_product].name,sort_goods[count_num_product].number,sort_goods[count_num_product].product_group,sort_goods[count_num_product].validity);
}

void print_grup(){
	int id_prod,count_num_product;
	char name_grup[20],number;
	printf("________Група товарів__________\n");
	for(count_num_product=0;count_num_product<num_product;count_num_product++){
		printf("%i. %s\n",count_num_product+1,goods[count_num_product].product_group);
	}
	printf("_______________________________\n");
	printf("Для виведення даних відповідної групи товарів, оберіть НОМЕР групи :\n");
	
	do{
  		printf("\nВведіть номер товару якому відповідає група:\n");
  		id_prod=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			id_prod*=10; id_prod+= (number - '0');
		}
  		if(id_prod < 1 || id_prod > num_product){
  			printf("Товару з таким номером не існує \n");
    	
	  	}
	}while(id_prod < 1 || id_prod > num_product);
	
	strcpy(name_grup,goods[id_prod-1].product_group);
	
    printf("\n");
	printf(" N |Група | Назва товару  |   Кількість   |    Термін  |     Ціна\n");
	printf("\n");
    for( count_num_product=0;count_num_product<num_product;count_num_product++){
      	if(strcmp(name_grup,goods[count_num_product].product_group)==0){
            printf("%2i. %5s %10s %15i %18s %10.2f\n",count_num_product+1,goods[count_num_product].product_group, goods[count_num_product].name,goods[count_num_product].number,goods[count_num_product].validity,goods[count_num_product].price);
		
      	}  
    }
  
}

int sort(){
	int choice_sort;
	while ((choice_sort = menu_sort()) != 0 && choice_sort != 27){
	    switch (choice_sort)
	    {
	    case 1:
	      	sort_name();
	      	break;
	    case 2:
	      	sort_group();
	      	break;
	    case 3:
	      	sort_numb();
	      	break;
	    case 4:
	    	sort_val();
	    	break;
	    case 5:
	    	sort_pra();
	    	break;
	    case 6:
	    	print_grup();
	    	break;
	    }
	}
 	return 0;
}

