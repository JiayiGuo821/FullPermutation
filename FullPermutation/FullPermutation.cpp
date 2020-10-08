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
	printf("%s","键入排列的位数（2-9）：");
	cin >> num;
	while (num < '2' || num > '9')
	{
		cout << "无效输入，请重新输入：";
		cin >> num;
	}

	char method;
	printf("%s","键入全排列方法：1.字典序法 2.递增进位制法 3.递减进位制法 4.邻域对换法：");
	cin >> method;
	while (method < '1' || method > '4')
	{
		cout << "无效输入，请重新输入：";
		cin >> method;
	}

	char option;
	printf("%s","键入输入的内容：1.排列 2.序号数 3.中介数（1或2或3）：");
	cin >> option; 
	while (option != '1' && option != '2' && option != '3')
	{
		cout << "无效输入，请重新输入：";
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
			cout << "输入一个排列:";
			cin >> permutation;
			
			int rank, intermediary;
			intermediary = Permutation2Intermediary(permutation, method);
			cout << "对应的中介数为：" << intermediary << endl;
			rank = Intermediary2Rank(intermediary, method);
			cout << "对应的序号数为：" << rank << endl;

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