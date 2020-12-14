#include<iostream>
#include<thread>
using namespace std;
typedef int n;
//sometime the optput from function 1 will get printed and sometime from function2
n function1(n x)
{
	cout<<"Value from function1: "<<x<<endl;
	return 0;
}

n function2(n x)
{
	cout<<"Value from function1: "<<x<<endl;
	return 0;
}
int main()
{
	std::thread t1(function1,10);
	std::thread t2(function2,20);
	t1.join();
	t2.join();
	return 0;
}