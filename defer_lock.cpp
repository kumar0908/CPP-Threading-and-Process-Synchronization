// mutex -> Mutual Exclusion
#include<iostream>
#include<thread>
#include<chrono>
std::mutex mtx;
using namespace std;
typedef int n;

n function1(n x)
{
    std::unique_lock<mutex> lock(mtx,std::defer_lock);//defined the lock with lock strategy
    //we can write any number of lines of code in this section.
    lock.lock();
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
	cout<<"We first define and then lock the lock in case of defer lock!!"<<endl;
	return 0;
}