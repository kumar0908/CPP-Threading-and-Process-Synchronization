#include<iostream>
#include<thread>
#include<chrono>
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
	while (x--)
	{
		cout<<"X : "<<x<<endl;
	}
	cout<<"Thread Completed"<<endl;
	return 0;
}
//working of join
/*
int main()
{
	std::thread t2(function2,20);
	t2.join();
	if (t2.joinable())//check if the thread is joinable.
	{
		t2.join();//we have already joined the thread we need not to again joni the thread.
	}
	cout<<"Main After Running the Function"<<endl;
	return 0;
}*/
//working of detach
int main()
{
	std::thread t2(function2,20);
	t2.detach();
	std::this_thread::sleep_for(chrono::seconds(5));//now the program execution will take as expected bcs now we are waiting for 5 seconds

	cout<<"Main After Running the Function"<<endl; 
	return 0;
}