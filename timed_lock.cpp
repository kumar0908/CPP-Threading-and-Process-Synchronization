// mutex -> Mutual Exclusion
//try_lock -> it try to lock the mutex, if the lock could not get successfully, it will return to it's intial state.
#include<iostream>
#include<thread>
#include<chrono>
std::timed_mutex mtx;
using namespace std;
typedef int n;
//sometime the optput from function 1 will get printed and sometime from function2
n function1(n x)
{
    if (mtx.try_lock_for(std::chrono::seconds(2))) //once some thread return comes and return false, it will come again after 2 seconds of waiting and try to ge tthe lock for execution.
    {	
    	while (x--)
    	{
    		cout<<"Value from function1: "<<x<<endl; //let suppose this section of code is the critical section so at a time only one process can access this part of the code
    	}
	
		mtx.unlock();
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
	cout<<"Main After Running both the thread"<<endl;
	return 0;
}