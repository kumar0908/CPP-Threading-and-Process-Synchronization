// mutex -> Mutual Exclusion
//rapper over mutex
#include<iostream>
#include<thread>
#include<chrono>
std::mutex mtx;
using namespace std;
typedef int n;

n function1(const char* T, n x)
{
    std::unique_lock<mutex> lock(mtx);//it's very light weight and work on scope basis and automatically lock the critical section
    	
    	while (x--)
    	{
    		cout<<"Value from  " <<T<< ": "<<x<<endl; //let suppose this section of code is the critical section so at a time only one process can access this part of the code
    	}
	
	return 0;
}

//working of mutex
int main()
{
	std::thread t1(function1,"T1",5);
	std::thread t2(function1,"T2",6);
	if (t1.joinable())//check if the thread is joinable.
	{
		t1.join();//we have already joined the thread we need not to again joni the thread.
	}
	if(t2.joinable())//check if thread is joinable
	{
		t2.join();
	}
	cout<<"In lock_guard, we need not to unlock the lock, as it works on scope basis!!"<<endl;
	return 0;
}