#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "header_file.h"

#include "menu_file.cpp"
#include "edit_file.cpp"
#include "sorting_file.cpp"
#include "add_order_file.cpp"

int menu();//головне меню
void add();//додавання товару до бази
void save();//запис даних про товари у файл
void print();//виведення даних про товари на екран
void read_file();//читання даних про товари з файлу

int make_order();//логіка меню "зробити замовлення"
int menu_order();//відображення меню "зробити замовлення"
void add_order();//додавання товару у кошик
void save_order();//збрігання замовлення
void print_order();//виведення замовлення на екран
void del_order();//видалення замовлення
void check();//виведення чеку на екран

void edit();//виклик меню "редагування"
int menu_edit_product();//логіка меню "редагування"
int menu_edit();//відображення меню "редагування" 
void edit_name();//редагування назви продуктів
void edit_grup();//редагування групи продуктів
void edit_validity();//редагування терміну придатності продуктів
void edit_num();//редагування кількості продуктів
void edit_price();//редагування ціни продуктів
void edit_del();//видалення поелементно даних з файлу
void edit_del_sort();//видалення відсортованих елементів з файлу по терміну придатності 
void edit_formatting();//форматування даних у файлі про товари
void edit_formatting_order();//форматування даних у файлі про чеки

int sort();//виклик меню "сортування"
int menu_sort();//логіка меню "сортування"
void sort_name();//сортування в алфавітному порядку назви товарів
void sort_group();//сортування в алфавітному порядку групи товарів
void sort_numb();//сортування по зростаню кількості товарів
void sort_val();//сортування по зростаню терміну тридатності товарів
void sort_pra();//сортування по зростаню ціни товарів
void print_grup();//відображення даних про товари відповідної групи

int main(){
	setlocale (LC_ALL,"");
	SetConsoleOutputCP(1251);
   	SetConsoleCP(1251);
 	int choice;
 
 	while ((choice = menu()) != 0 && choice != 27){
	 	
	    switch (choice)
	    {
	    case 1:
	    	add();
	      	break;
	    case 2:
	    	if(num_product>0){
	    		edit();
			}else{
				printf("Товару немає :(\nДодайте товар\n");
				add();
			}
	      	break;
	    case 3:
	    	if(num_product>0){
	    		print();
			}else{
				printf("Товару немає :(\nДодайте товар\n");
				add();
			}
	      	break;
	    case 4:
	    	if(num_product>0){
	    		make_order();
			}else{
				printf("Товару немає :(\nДодайте товар\n");
				add();
			}
	      	break;
	    case 5:
	    	if(num_product>0){
	    		sort();
			}else{
				printf("Товару немає :(\nДодайте товар\n");
				add();
			}
	    	break;
	    
	    }
	}
 	
 	return 0;
}

