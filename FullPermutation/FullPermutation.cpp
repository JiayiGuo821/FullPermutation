#include <iostream>
#include <vector> 
#include <string.h>

using namespace std;

void main()
{
	char num;
	printf("%s","�������е�λ����2-9����");
	cin >> num;
	while (num < '2' || num > '9')
	{
		cout << "��Ч���룬���������룺";
		cin >> num;
	}
	char option;
	printf("%s","������������ݣ�1.���� 2.�������1��2����");
	cin >> option; 
	while (option != '1' && option != '2' && option != '3')
	{
		cout << "��Ч���룬���������룺";
		cin >> option;
	}	

	int sup = 1;
	for (int i = 0; i < num; i++)
	{
		sup = sup * (i + 1);
	}
	
	switch(option)
	{
	case '1':
		{
			int element;
			vector<char> permutation;
			for (int i = 0; i < int(num - '0'); i++)
			{
				cin >> element;
				permutation.push_back(element);
				cout << i;
			}
			for (int i = 0; i < permutation.size(); i++)
			{
				cout << permutation.at(i);
			}
			break;
		}
		case '2':

			cout << "zdnb";
			break;
	}

}

int Dic_Permutation(int input)
{
	return 0;
}

int Inc_Permutation(int input)
{
	return 0;
}

int Dec_Permutation(int input)
{
	return 0;
}

int CR_Permutation(int input)
{
	return 0;
}