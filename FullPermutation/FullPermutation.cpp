#include <iostream>
#include <vector> 
#include <deque>
#include <string.h>

using namespace std;

int Permutation2Intermediary(int permutation, char method)
{
	deque<int> permutation_deq;
	int intermediary = 0;

	while (permutation)
	{
		permutation_deq.push_front(permutation % 10);
		permutation = permutation / 10;
	}

	deque<int> intermediary_deq;
	switch (method)
	{
	case '1':
		{
			for (int i = 0; i < permutation_deq.size(); i++)
			{
				int count = 0;
				for (int j = i + 1; j < permutation_deq.size(); j++)
				{
					if (permutation_deq.at(j) < permutation_deq.at(i))
						count++;
				}
				intermediary_deq.push_back(count);
			}
			break;
		}
	case '2':
		{
			break;
		}
	case '3':
		{
			break;
		}
	case '4':
		{
			break;
		}
	default:
		break;
	}
	
	for (int i = 0; i < intermediary_deq.size() - 1; i++)
	{
		intermediary = intermediary * 10;
		intermediary += intermediary_deq.at(i);
	}
	
	return intermediary;
}


int Intermediary2Rank(int intermediary, char method)
{
	deque<int> intermediary_deq;
	int rank;

	while (intermediary)
	{
		intermediary_deq.push_front(intermediary % 10);
		intermediary = intermediary / 10;
	}

	deque<int> rank_deq;
	switch (method)
	{
	case '1':
		{
			for (int i = 0; i < permutation_deq.size(); i++)
			{
				int count = 0;
				for (int j = i + 1; j < permutation_deq.size(); j++)
				{
					if (permutation_deq.at(j) < permutation_deq.at(i))
						count++;
				}
				intermediary_deq.push_back(count);
			}
			break;
		}
	case '2':
		{
			break;
		}
	case '3':
		{
			break;
		}
	case '4':
		{
			break;
		}
	default:
		break;
	}
	return 0;
}


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

	char method;
	printf("%s","����ȫ���з�����1.�ֵ��� 2.������λ�Ʒ� 3.�ݼ���λ�Ʒ� 4.����Ի�����");
	cin >> method;
	while (method < '1' || method > '4')
	{
		cout << "��Ч���룬���������룺";
		cin >> method;
	}

	char option;
	printf("%s","������������ݣ�1.���� 2.����� 3.�н�����1��2��3����");
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
			int permutation;
			cout << "����һ������:";
			cin >> permutation;
			
			int rank, intermediary;
			intermediary = Permutation2Intermediary(permutation, method);
			cout << "��Ӧ���н���Ϊ��" << intermediary << endl;
			rank = Intermediary2Rank(intermediary, method);
			cout << "��Ӧ�������Ϊ��" << rank << endl;

			break;
		}
	case '2':
		{
			int rank;
			deque<int> rank_deq;
			cin >> rank;
			while (rank)
			{
				rank_deq.push_front(rank % 10);
				rank = rank / 10;
			}
			switch (method)
			{
			case '1':
				{

				}
			case '2':
				{

				}
			case '3':
				{

				}
			case '4':
				{

				}
			default:
				break;
			}
			break;
		}
	case '3':
		{
			int intermediary;
			deque<int> intermediary_deq;
			cin >> intermediary;
			while (intermediary)
			{
				intermediary_deq.push_front(intermediary % 10);
				intermediary = intermediary / 10;
			}
			switch (method)
			{
			case '1':
				{

				}
			case '2':
				{

				}
			case '3':
				{

				}
			case '4':
				{

				}
			default:
				break;
			}
			break;
		}
	default:
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