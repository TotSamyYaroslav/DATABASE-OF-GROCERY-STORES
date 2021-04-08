
int menu_order(){
 	int number_choice = -1;
	char choice=0;
	while ((number_choice < 0 || number_choice > 5) && number_choice != 27){
		printf("\n���� ���������:\n");
	    printf("0 : ����������� �� ������� ����     \n"
	           "1 : ��������� ����������            \n"
	           "2 : ����������� �����      \n"
	           "3 : �������� ����������             \n"
	           "4 : ³������ ����������            \n"
	           "5 : ������������ ���               \n"
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
    	fprintf(stderr, "�������! ����������� �����\n");
    	return;
  	}
  	
  	for(count_num_product=0; count_num_product < num_product; count_num_product++){//��������� �������� � �����,���� ���� ������� ����� 1
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
		printf("��� ��������� ������ � ����� ������ ����� ������ :\n");
		id_prod=0;
		num_prod=0;
		do{
	  		printf("\n������ ����� �����:\n");
	  		id_prod=0;
	  		while((number=getchar()) != '\n') 
			  	if (number>='0' && number<='9') {
					id_prod*=10; 
					id_prod+= (number - '0');
			}
	  		if(id_prod < 1 || id_prod > num_product){
	  			printf("������ � ����� ������� �� ���� \n");
	    	
		  	}
		}while(id_prod < 1 || id_prod > num_product);
		
	  	if(num_product==1){//�������� �� ������ ���������� ������ ����� �� 0, ��� ���� ���� ������� ������ = 1(��� ��������� ����������)
	  		if(goods[id_prod-1].number == 0){
	  			printf("����� ��������� :(  \n�������� ���������� :)\n");
	  			return;
			  }
		  }
		  
		do{
	  		printf("������ ������� ������:");
			num_prod=0;
			while((number=getchar()) != '\n') 
			  	if (number>='0' && number<='9') {
					num_prod*=10; 	
					num_prod+= (number - '0');
			}
			if(num_prod < 1 || num_prod > goods[id_prod-1].number){
	  			printf("������ ����� %i  \n", num_prod);
	    	
		  	}
		  	
		}while(num_prod < 1 || num_prod > goods[id_prod-1].number);
		
		
		for(count_num_product=0;count_num_product<num_product;count_num_product++){//��������� ����� � ����� ��������� ��������� � ������ ��������� ��������
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
		
		printf("���������� - �nter, ESC - ���������\n");
		key_exit=getch();
		
	}while(key_exit!=27);
	
}

void save_order(){
	
	fflush(stdin);
	printf("������ �.�.�.:");
  	gets(client[num_client].surname);
  	printf("������ ���.:");
  	gets(client[num_client].phone);
  	num_client++;
  	
  		FILE *F2;
  	int count_num_order,count_num_client;

  	if ((F2 = fopen(storige_order, "a")) == NULL){
    	fprintf(stderr, "��������� ������� ��� ������ ���� 'Storege.txt'\n");
    	return;
  	}

  	fprintf(F2, "%i\n", num_order);//���������� ���� ��� ����������
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
	
  	printf(" N |����� ������ |  �����  | ʳ������|  ֳ��|   \n");
  	for (count_num_order = 0; count_num_order <num_order; count_num_order ++){
	  
  		total+=products[count_num_order].sum_price;
    	printf("%i. %5s %10s %10i  %15.2f\n", count_num_order + 1,products[count_num_order].name_product,products[count_num_order].product_group_order,
		products[count_num_order].number_product,products[count_num_order].sum_price);
	}
	
	printf("\n                                   ����:%.2f\n",total);
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
  	printf(" N |   ����� ������ |ʳ������|  ֳ��|   \n");
  	
	for (count_num_order = 0; count_num_order <num_order; count_num_order ++)
    	printf("%i. %5s %10i  %15.2f\n", count_num_order + 1,products[count_num_order].name_product,products[count_num_order].number_product,products[count_num_order].sum_price);
    	
    printf("______________________________________________\n");
    printf("                            ����: %.2f\n",total);
    printf("______________________________________________\n");
	printf(" �.�.�.               |�������           \n");
	for (count_num_client = 0; count_num_client < num_client; count_num_client ++)
		printf("  %s               %20s\n",client[count_num_client].surname,client[count_num_client].phone);
	num_client=0;
	num_order=0;
	
	FILE *F2;
	if ((F2 = fopen(storige_order, "a")) == NULL){
    	fprintf(stderr, "��������� ������� ��� ������ ���� 'Storege_order.txt'\n");
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
				printf("������ ���� :( \n");
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
