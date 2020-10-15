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
			deque<int> direction(permutation_deq.size() + 1, 0);//左0右1
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

int Rank2Intermediary(int rank, char method, char num)
{
	deque<int> rank_deq;
	int intermediary = 0, i, temp;

	if (method == '1' || method == '2')
	{
		i = 2;
		while(rank)
		{
			temp = rank % i;
			rank = rank / i;
			intermediary += temp * pow(10, i - 2);
			i++;
		}
	}
	else
	{
		i = int(num - '0');
		while (rank)
		{
			temp = rank % i;
			rank = rank / i;
			intermediary += temp * pow(10, int(num - '0') - i);
			i--;
		}

	}
	return intermediary;
}

int Intermediary2Permutation(int intermediary, char method, char num)
{
	deque<int> intermediary_deq;
	int permutation = 0;
	int length = int(num - '0') - 1;
	
	for (int i = 0; i < length; i++)
	{
		if (intermediary)
		{
			intermediary_deq.push_front(intermediary % 10);
			intermediary = intermediary / 10;
		}
		else
		{
			intermediary_deq.push_front(0);
		}
	}
	
	deque<int> permutation_deq(length + 1, 0);
	deque<int> count(length + 1, 0);
	switch (method)
	{
	case '1':
		{
			int temp;
			bool loop = true;
			for (int i = 0; i < intermediary_deq.size(); i++)
			{
				temp = intermediary_deq.at(i) + 1;
				for (int j = 0; j < i; j++)
				{
					if (permutation_deq.at(j) <= temp)
					{
						temp++;
						loop = true;
					}
				}
				while (loop)
				{
					loop = false;
					for (int j = 0; j < i; j++)
					{
						if (permutation_deq.at(j) == temp)
						{
							temp++;
							loop = true;
						}
					}
				}
				permutation_deq.at(i) = temp;
				permutation += temp * pow(10, length - i);
				count.at(temp - 1) = 1;
			}
			for (int t = 0; t < count.size(); t++)
			{
				if (count.at(t) == 0)
					permutation += t + 1;
			}
			break;
		}
	case '2':
		{
			for (int i = 0; i < intermediary_deq.size(); i++)
			{
				int location = 0;
				location = intermediary_deq.at(i);
				for (int j = permutation_deq.size() - 1; j > -1; j--)
				{
					if (location == 0 && permutation_deq.at(j) == 0)
					{
						permutation_deq.at(j) = length + 1 - i;
						break;
					}
					if (location != 0 && permutation_deq.at(j) == 0)
						location--;
				}
			}
			for (int j = 0; j < permutation_deq.size(); j++)
			{
				if (permutation_deq.at(j) == 0)
					permutation += pow(10, length - j);
				else
					permutation += permutation_deq.at(j) * pow(10, length - j);
			}
			break;
		}
	case '3':
		{
			for (int i = 0; i < intermediary_deq.size(); i++)
			{
				int location = 0;
				location = intermediary_deq.at(intermediary_deq.size() - 1 - i);
				for (int j = permutation_deq.size() - 1; j > -1; j--)
				{
					if (location == 0 && permutation_deq.at(j) == 0)
					{
						permutation_deq.at(j) = length + 1 - i;
						break;
					}
					if (location != 0 && permutation_deq.at(j) == 0)
						location--;
				}
			}
			for (int j = 0; j < permutation_deq.size(); j++)
			{
				if (permutation_deq.at(j) == 0)
					permutation += pow(10, length - j);
				else
					permutation += permutation_deq.at(j) * pow(10, length - j);
			}
			break;
		}
	case '4':
		{
			deque<int> direction(permutation_deq.size() + 1, 0);//左0右1
			for (int i = permutation_deq.size(); i > 2; i--)
			{
				if (i%2 == 1)
				{
					if (intermediary_deq.at(i - 3)%2 == 1)
						direction.at(i) = 1;
				}
				else
				{
					if ((intermediary_deq.at(i - 3) + intermediary_deq.at(i - 4))%2 == 1)
						direction.at(i) = 1;
				}
			}
			int b = 0;
			for (int i = permutation_deq.size(); i > 1; i--)
			{
				b = intermediary_deq.at(i - 2);
				if (direction.at(i) == 1)
				{
					for (int j = 0; j < permutation_deq.size(); j++)
					{
						if (b == 0 && permutation_deq.at(j) == 0)
						{
							permutation_deq.at(j) = i;
							break;
						}
						else
						{
							if (permutation_deq.at(j) == 0)
								b--;
						}
					}
				}
				else
				{
					for (int j = permutation_deq.size() - 1; j > -1; j--)
					{
						if (b == 0 && permutation_deq.at(j) == 0)
						{
							permutation_deq.at(j) = i;
							break;
						}
						else
						{
							if (permutation_deq.at(j) == 0)
								b--;
						}
					}
				}
			}
			for (int j = 0; j < permutation_deq.size(); j++)
			{
				if (permutation_deq.at(j) == 0)
					permutation += pow(10, length - j);
				else
					permutation += permutation_deq.at(j) * pow(10, length - j);
			}
			break;
		}
	default:
		break;
	}
	
	return permutation;
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

bool check_rank(int rank, char num)
{
	int count = 1;
	for (int i = 2; i <= int(num - '0'); i++)
	{
		count *= i;
	}
	if (rank < count)
		return 1;
	return 0;
}

bool check_intermediary(int intermediary, char num, char method)
{
	int rank = Intermediary2Rank(intermediary, method, num);
	return check_rank(rank, num);
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
			while (check_permutation(permutation, num) == false)
			{
				cout << "无效输入，请重新输入：";
				cin >> permutation;
			}

			int rank, intermediary;
			intermediary = Permutation2Intermediary(permutation, method);
			cout << "对应的中介数为：" << intermediary << endl;
			rank = Intermediary2Rank(intermediary, method, num);
			cout << "对应的序号数为：" << rank << endl;

			break;
		}
	case '2':
		{
			int rank;
			cout << "输入一个序号:";
			cin >> rank;
			while (check_rank(rank, num) == false)
			{
				cout << "无效输入，请重新输入：";
				cin >> rank;
			}

			int permutation, intermediary;
			intermediary = Rank2Intermediary(rank, method, num);
			cout << "对应的中介数为：" << intermediary << endl;
			permutation = Intermediary2Permutation(intermediary, method, num);
			cout << "对应的排列为：" << permutation << endl;

			break;
		}
	case '3':
		{
			int intermediary;
			cout << "输入一个中介数:";
			cin >> intermediary;
			while (check_intermediary(intermediary, num, method) == false)
			{
				cout << "无效输入，请重新输入：";
				cin >> intermediary;
			}

			int permutation, rank;
			rank = Intermediary2Rank(intermediary, method, num);
			cout << "对应的序号数为：" << rank << endl;
			permutation = Intermediary2Permutation(intermediary, method, num);
			cout << "对应的排列数为：" << permutation << endl;

			break;
		}
	default:
		break;
	}

}
