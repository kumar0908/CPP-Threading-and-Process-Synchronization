// mutex -> Mutual Exclusion
//using recursive lock we can lock the critical section any number of times, this number depends on the size of the stack.
//it creates the overhead to the system so we should try to avoid it.
#include<iostream>
#include<thread>
#include<chrono>
std::recursive_mutex mtx;
using namespace std;
typedef int n;

n function1(n x)
{
    mtx.lock(); //thread will try to recursively try to get the lock
    	
    	while (x--)
    	{
    		cout<<"Value from function1: "<<x<<endl; //let suppose this section of code is the critical section so at a time only one process can access this part of the code
    	}
	
		mtx.unlock();
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
	cout<<"In recursive lock all the processes will get execute!!"<<endl;
	return 0;
}