#include <iostream>
#include <vector> 
#include <deque>
#include <cmath>
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

	switch (method)
	{
	case '1':
		{
			for (int i = 0; i < permutation_deq.size() - 1; i++)
			{
				intermediary *= 10;
				int count = 0;
				for (int j = i + 1; j < permutation_deq.size(); j++)
				{
					if (permutation_deq.at(j) < permutation_deq.at(i))
						count++;
				}
				intermediary += count;
			}
			break;
		}
	case '2':
		{
			for (int i = 0; i < permutation_deq.size() - 1; i++)
			{
				int count = 0;
				for (int j = i + 1; j < permutation_deq.size(); j++)
				{
					if (permutation_deq.at(j) < permutation_deq.at(i))
						count++;
				}
				intermediary += count * pow(10, permutation_deq.at(i) - 2);
			}
			break;
		}
	case '3':
		{
			for (int i = 0; i < permutation_deq.size() - 1; i++)
			{
				int count = 0;
				for (int j = i + 1; j < permutation_deq.size(); j++)
				{
					if (permutation_deq.at(j) < permutation_deq.at(i))
						count++;
				}
				intermediary += count * pow(10, permutation_deq.size()- 2 -(permutation_deq.at(i) - 2));
			}
			break;
		}
	case '4':
		{
			deque<int> direction(permutation_deq.size() + 1, 0);//��0��1
			deque<int> b(permutation_deq.size() + 1, 0);
			for (int i = 2; i < permutation_deq.size() + 1; i++)
			{
				int mark = 0;
				for (int k = 0; k < permutation_deq.size(); k++)
				{
					if (permutation_deq.at(k) == i)
						mark = k;
				}

				if (i == 2)
					direction.at(i) = 0;
				else if (i%2 == 0)
				{
					if ((b.at(i - 1) + b.at(i - 2)) % 2 == 0)
						direction.at(i) = 0;
					else
						direction.at(i) = 1;
				}
				else
				{
					if (b.at(i - 1) % 2 == 0)
						direction.at(i) = 0;
					else
						direction.at(i) = 1;
				}

				if (direction.at(i) == 0)
				{
					for (int t = mark + 1; t < permutation_deq.size(); t++)
					{
						if (permutation_deq.at(t) < i)
							b.at(i)++;
					}
				}
				else
				{
					for (int t = mark - 1; t > -1; t--)
					{
						if (permutation_deq.at(t) < i)
							b.at(i)++;
					}
				}

				intermediary += b.at(i) * pow(10, permutation_deq.size() - i);
			}
			break;
		}
	default:
		break;
	}
	
	return intermediary;
}


int Intermediary2Rank(int intermediary, char method, char num)
{
	deque<int> intermediary_deq;
	int rank = 0;

	while (intermediary)
	{
		intermediary_deq.push_front(intermediary % 10);
		intermediary = intermediary / 10;
	}

	deque<int> rank_deq;
	if (method == '1' || method == '2')
	{
		int max_num = intermediary_deq.size() + 1;
		for (int i = 0; i < intermediary_deq.size(); i++)
		{
			rank *= max_num;
			rank += intermediary_deq.at(i);
			max_num--;
		}
	}
	else //'3'or'4'
	{
		int min_num  = int(num - '0') - intermediary_deq.size() + 1;
		for (int i = 0; i < intermediary_deq.size(); i++)
		{
			rank *= min_num;
			rank += intermediary_deq.at(i);
			min_num++;
		}
	}
	return rank;
}

bool check_permutation(int permutation, char num)
{
	int temp = int(num - '0');
	deque<int> check(temp, 0);

	while (permutation)
	{
		if (permutation % 10 > temp)
			return false;
		check.at((permutation % 10) - 1) = 1;
		permutation = int(permutation / 10);
	}
	int count = 0;
	for (int i = 0; i < check.size(); i++)
	{
		count += check.at(i);
	}
	return count == temp;
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
			while (check_permutation(permutation, num) == false)
			{
				cout << "��Ч���룬���������룺";
				cin >> permutation;
			}

			int rank, intermediary;
			intermediary = Permutation2Intermediary(permutation, method);
			cout << "��Ӧ���н���Ϊ��" << intermediary << endl;
			rank = Intermediary2Rank(intermediary, method, num);
			cout << "��Ӧ�������Ϊ��" << rank << endl;

			break;
		}
	case '2':
		{
			/*int rank;
			cout << "����һ�����:";
			cin >> rank;
			while (check_permutation(rank, num) == false)
			{
				cout << "��Ч���룬���������룺";
				cin >> rank;
			}

			int rank, intermediary;
			intermediary = Rank2Intermediary(Rank, method);
			cout << "��Ӧ���н���Ϊ��" << intermediary << endl;
			rank = Intermediary2Permutation(intermediary, method, num);
			cout << "��Ӧ�������Ϊ��" << permutation << endl;*/

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