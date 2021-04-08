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

int menu();//������� ����
void add();//��������� ������ �� ����
void save();//����� ����� ��� ������ � ����
void print();//��������� ����� ��� ������ �� �����
void read_file();//������� ����� ��� ������ � �����

int make_order();//����� ���� "������� ����������"
int menu_order();//����������� ���� "������� ����������"
void add_order();//��������� ������ � �����
void save_order();//�������� ����������
void print_order();//��������� ���������� �� �����
void del_order();//��������� ����������
void check();//��������� ���� �� �����

void edit();//������ ���� "�����������"
int menu_edit_product();//����� ���� "�����������"
int menu_edit();//����������� ���� "�����������" 
void edit_name();//����������� ����� ��������
void edit_grup();//����������� ����� ��������
void edit_validity();//����������� ������ ���������� ��������
void edit_num();//����������� ������� ��������
void edit_price();//����������� ���� ��������
void edit_del();//��������� ����������� ����� � �����
void edit_del_sort();//��������� ������������ �������� � ����� �� ������ ���������� 
void edit_formatting();//������������ ����� � ���� ��� ������
void edit_formatting_order();//������������ ����� � ���� ��� ����

int sort();//������ ���� "����������"
int menu_sort();//����� ���� "����������"
void sort_name();//���������� � ���������� ������� ����� ������
void sort_group();//���������� � ���������� ������� ����� ������
void sort_numb();//���������� �� �������� ������� ������
void sort_val();//���������� �� �������� ������ ���������� ������
void sort_pra();//���������� �� �������� ���� ������
void print_grup();//����������� ����� ��� ������ �������� �����

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
				printf("������ ���� :(\n������� �����\n");
				add();
			}
	      	break;
	    case 3:
	    	if(num_product>0){
	    		print();
			}else{
				printf("������ ���� :(\n������� �����\n");
				add();
			}
	      	break;
	    case 4:
	    	if(num_product>0){
	    		make_order();
			}else{
				printf("������ ���� :(\n������� �����\n");
				add();
			}
	      	break;
	    case 5:
	    	if(num_product>0){
	    		sort();
			}else{
				printf("������ ���� :(\n������� �����\n");
				add();
			}
	    	break;
	    
	    }
	}
 	
 	return 0;
}

