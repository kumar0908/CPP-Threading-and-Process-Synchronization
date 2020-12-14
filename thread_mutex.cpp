// mutex -> Mutual Exclusion
#include<iostream>
#include<thread>
#include<chrono>
std::mutex m;
using namespace std;
typedef int n;
//sometime the optput from function 1 will get printed and sometime from function2
n function1(n x)
{
    m.lock(); //either t1 or t2 will access this part of the code at a time.
    while (x--)
    {
    	cout<<"Value from function1: "<<x<<endl; //let suppose this section of code is the critical section so at a time only one process can access this part of the code
    }
	
	m.unlock();
	return 0;
}

//working of mutex
int main()
{
	std::thread t2(function1,5);
	std::thread t1(function1,6);
	if (t2.joinable())//check if the thread is joinable.
	{
		t2.join();//we have already joined the thread we need not to again joni the thread.
	}
	if(t1.joinable())//check if thread is joinable
	{
		t1.join();
	}
	cout<<"Main After Running the Function"<<endl;
	return 0;
}