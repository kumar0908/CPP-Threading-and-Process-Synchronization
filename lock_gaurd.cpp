// mutex -> Mutual Exclusion
//no need to unlock the lock gaurd explicitly
//you can not copy the lock gaurd
#include<iostream>
#include<thread>
#include<chrono>
std::mutex mtx;
using namespace std;
typedef int n;

n function1(n x)
{
    std::lock_guard<mutex> lock(mtx);//it's very light weight and work on scope basis
    	
    	while (x--)
    	{
    		cout<<"Value from function1: "<<x<<endl; //let suppose this section of code is the critical section so at a time only one process can access this part of the code
    	}
	
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
	cout<<"In lock_guard, we need not to unlock the lock, as it works on scope basis!!"<<endl;
	return 0;
}