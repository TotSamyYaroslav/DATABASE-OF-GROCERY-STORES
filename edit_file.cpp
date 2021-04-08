
#define storige_file "Storige.txt"
#define storige_order "Storige_order.txt"

int menu_edit(){
	int number = -1;
	char choice = 0;
	while ((number < 0 || number > 10) && choice != 27){
		printf("\n���� ����������� �����:\n");
	    printf("0 : ����������� �� ������� ����\n"
	    	   "1 : ���������� �����\n"
	           "2 : ���������� �����\n"
	           "3 : ���������� ����� ����������\n"
	           "4 : ���������� �������\n"
	           "5 : ����������  ����\n"
	           "6 : �������� ��� �����������\n"
	           "7 : �������� ��� �� �����\n"
	           "8 : �� ���������!!!(������������ �����)\n"
	           "9 : ������������ ����\n"
	           "10 : ����������� ���\n"
	           ">");
	    choice = getch();
	    if( choice >= '0' && choice <='9'){
	    	if(choice=='1'){
	    		choice = getch();
	    		if(choice == '0') number =10;
	    		else number =1;
			}
			else number= choice -'0';
			 printf("%i\n", number);
		}
	   
	}
  	return number;
	
}

void edit_name(){
	int id_prod;
	char edit_name[20],number;
	printf("��� ����������� ����� ������, ������ ����� ������ :\n\n");
	
	print();
	do{
  		printf("\n������ ����� ������:\n");
  		id_prod=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			id_prod*=10; id_prod+= (number - '0');
		}
  		if(id_prod < 1 || id_prod > num_product){
  			printf("������ � ����� ������� �� ���� \n");
    	
	  	}
	}while(id_prod < 1 || id_prod > num_product);
	
	printf("\n������ ���� ����� ������ :\n");
	scanf("%s",&edit_name);
	fflush(stdin);
	strcpy(goods[id_prod-1].name,edit_name);
	save();
}

void edit_grup(){
	int id_prod;
	char edit_grup[20],number;
	printf("��� ����������� ����� ������, ������ ����� ������ :\n\n");
	id_prod=0;
	print();
	do{
  		printf("\n������ ����� �����:\n");
  		id_prod=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			id_prod*=10; id_prod+= (number - '0');
		}
  		if(id_prod < 1 || id_prod > num_product){
  			printf("������ � ����� ������� �� ���� \n");
    	
	  	}
	}while(id_prod < 1 || id_prod > num_product);
	
	printf("\n������ ���� ����� �����:\n");
	scanf("%s",&edit_grup);
	fflush(stdin);
	strcpy(goods[id_prod-1].product_group,edit_grup);
	save();
}

void edit_validity(){
	int id_prod;
	char edit_validity[20],number;
	printf("��� ����������� ������ ������, ������ ����� ������ :\n\n");
	id_prod=0;
	print();
	do{
  		printf("\n������ ����� �����:\n");
  		id_prod=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			id_prod*=10; id_prod+= (number - '0');
		}
  		if(id_prod < 1 || id_prod > num_product){
  			printf("������ � ����� ������� �� ���� \n");
    	
	  	}
	}while(id_prod < 1 || id_prod > num_product);
	
	printf("\n������ ����� ����� ������ � ������ day.month.year:\n");
	scanf("%s",&edit_validity);
	fflush(stdin);
	strcpy(goods[id_prod-1].validity,edit_validity);
	save();
}

void edit_num(){
	int id_prod,edit_num;
	char number;
	printf("��� ����������� ������� ������, ������ ����� ������ :\n\n");
	id_prod=0;
	print();
	do{
  		printf("\n������ ����� ������:\n");
  		id_prod=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			id_prod*=10; id_prod+= (number - '0');
		}
  		if(id_prod < 1 || id_prod > num_product){
  			printf("������ � ����� ������� �� ���� \n", id_prod);
    	
	  	}
	}while(id_prod < 1 || id_prod > num_product);
	
	printf("\n������ ���� ������� ������:\n");
	scanf("%i",&edit_num);
	fflush(stdin);
	goods[id_prod-1].number=edit_num;
	save();
}

void edit_price(){
	int id_prod;
	float edit_price;
	char number;
	printf("��� ����������� ���� ������, ������ ����� ������ :\n\n");
	id_prod=0;
	print();
	do{
  		printf("\n������ ����� ������:\n");
  		id_prod=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			id_prod*=10; id_prod+= (number - '0');
		}
  		if(id_prod < 1 || id_prod > num_product){
  			printf("������ � ����� ������� �� ���� \n");
    	
	  	}
	}while(id_prod < 1 || id_prod > num_product);
	
	printf("\n������ ���� ���� ������ ��������, � ������ 0,00:\n");
	scanf("%f",&edit_price);
	fflush(stdin);
	goods[id_prod-1].price=edit_price;
	save();
}

void edit_del(){
  	int number_element;
	char number;
  	print();
  	do{
  		printf("������ ����� ������ ��� ���������: ");
  		number_element=0;
  		while((number=getchar()) != '\n') 
		  if (number>='0' && number<='9') {
			number_element*=10; 
			number_element+= (number - '0');
		}
  		if(number_element < 1 || number_element > num_product){
  			printf("������ � ����� ������� �� ���� \n");
    	
	  	}
	}while(number_element < 1 || number_element > num_product);
	
  	for (number_element --; number_element < num_product - 1; number_element ++)
    	goods[number_element] = goods[number_element + 1];
  		num_product --;
  	save();
}

void edit_del_sort(){
	int count_num_product,count_num,k,count_element,
	day=0,month=0,year=0,day_validity=0,month_validity=0,year_validity=0;
	int flag_data=0,flag_data_goods=0,lenght_data;
	char data[12],*pdata=0,*pgoods=0;
	pdata=data;
	
	printf("������ ���� � ������ day.mont.year:");
	scanf("%s",data);
	fflush(stdin);
	
	lenght_data=strlen(pdata);

	for(int count_num_product=0;count_num_product<lenght_data;count_num_product++){//����������� ����� �� �������� ����, �����, ��, �� ������� ����������
		if(pdata[count_num_product]=='.'){
			flag_data++;
		}else{
			if(flag_data==0){
				sscanf(pdata,"%d",&day);	
			}else if(flag_data==1){
				sscanf(pdata+3,"%d",&month);
			}else if(flag_data==2){
				sscanf(pdata+6,"%d",&year);
			}
		}
	}
	puts(pdata);
	
	for( count_num_product=0;count_num_product<num_product;count_num_product++){//����������� ����� �� �������� ����, �����, ��, �� ������ � �����
		
		pgoods = goods[count_num_product].validity;
		puts(pgoods);
		
		flag_data_goods=0;
		
		for(count_num=0;count_num<lenght_data;count_num++){
			if(pgoods[count_num]=='.'){
				flag_data_goods++;
			}else{
				if(flag_data_goods==0){
					sscanf(pgoods,"%d",&day_validity);
				}else if(flag_data_goods==1){
					sscanf(pgoods+3,"%d",&month_validity);
				}else if(flag_data_goods==2){
					sscanf(pgoods+6,"%d",&year_validity);
				}	
			}	
		}
			
		if(year>year_validity){//���������� �� �����
			
			for (count_element=count_num_product ; count_element < num_product -1; count_element ++)
					    goods[count_element] = goods[count_element + 1];	
					  	num_product --;
						count_num_product--;	
		}else if(year==year_validity){
			if(month>month_validity){//���������� �� ������
				for (count_element=count_num_product ; count_element < num_product -1; count_element ++)
					    goods[count_element] = goods[count_element + 1];		
					  	num_product --;
						count_num_product--;
			}else if(month==month_validity){
				if(day>=day_validity){//���������� �� ����
					for (count_element=count_num_product ; count_element < num_product -1; count_element ++)
					    goods[count_element] = goods[count_element + 1];		
					  	num_product --;
						count_num_product--;
				}
			}
		}	
	}
	
	save();
	print();
}

void edit_formatting(){
	FILE *F;
	F = fopen(storige_file, "w");
	fclose(F);
	num_product=0;
    print();
}

void edit_formatting_order(){
	FILE *F;
	F = fopen(storige_order, "w");
	fclose(F);
}
	
int menu_edit_product(){
	int choice_edit;
	while ((choice_edit = menu_edit()) != 0 && choice_edit != 27){
	    switch (choice_edit)
	    {
	    case 1:
	      	edit_name();
	      	break;
	    case 2:
	      	edit_grup();
	      	break;
	    case 3:
	      	edit_validity();
	      	break;
	    case 4:
	      	edit_num();
	      	break;
	    case 5:
	    	edit_price();
	    	break;
	    case 6:
	    	edit_del();
	    	break;
	    case 7:
	    	edit_del_sort();
	    	break;
	    case 8:
	    	edit_formatting();
	    	break;
	    case 9:
	    	edit_formatting_order();
	    	break;
	    case 10:
	    	print();
	    	break;
	    	
	    }
	}
 	return 0;
}

void edit(){
	
	FILE *F;
  	int count_num_product;

  	if ((F = fopen(storige_file, "r")) == NULL){
    	fprintf(stderr, "��������� ������� ��� ������ ���� 'Storege.txt'\n");
    	return;
  	}

  	fscanf(F, "%i", &num_product);//������� ����� � �����
  	for (count_num_product = 0; count_num_product < num_product; count_num_product ++)
    	fscanf(F, "%s%s%i%s%f", goods[count_num_product].name, goods[count_num_product].product_group, &goods[count_num_product].number,goods[count_num_product].validity,&goods[count_num_product].price);
	
	menu_edit_product();
  	fclose(F);
}

