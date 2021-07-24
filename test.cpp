#include<iostream>
#include<vector>
using namespace std;
int main()
{
	// int p[]={4,2,6,5};
	// vector<int> my_vector(p,p+4);
	// vector<int>::iterator it;
	// it=my_vector.begin();
	// while(it!=my_vector.end())
	// {
	// 	cout<<*it<<" ";
	// 	it++;
	// }
	// cout<<endl;
	char arr[8]={'D','E','V','Z','O','N','E'};
	char *p;
	p=(char *)(arr+2)[3];
	cout<<*p;
	system("pause");
	 return 0;
	}

