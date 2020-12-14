// mutex -> Mutual Exclusion
// it is used to notify thread t2 when t2 has completed it's execution, it can notify to thread t1 or to all the threads, it depends on the implementation.
#include<iostream>
#include<thread>
#include<chrono>
#include<condition_variable>
std::condition_variable cv;
std::mutex mtx;
using namespace std;
long balance = 0;

long addMoney(long money)
{
    		std::lock_guard<mutex> lock(mtx);
    		balance = balance + money;
    		cout<<"Amount added to the account: "<<money<<endl;
    		cv.notify_one();
    		return 0; 
   
}
long withdrawMoney(long amt)
{
	std::unique_lock<mutex> lock(mtx);
	cv.wait(lock,[] {return (balance!=0)? true:false;});
	if(balance > amt)
	{
		balance = balance - amt;
		cout<<"Amount deducted from the account: "<<amt<<endl;
	}
	else
	{
		cout<<"You want to withdraw    "<<amt <<endl;
		cout<<"You do not have suifficient balance in the account"<<endl;
	}
	cout<<"Total available amount in the account: "<<balance<<endl;
	return 0;

}


//working of mutex
int main()
{
	std::thread t1(withdrawMoney,6);
	std::thread t2(addMoney,5);
	if (t2.joinable())//check if the thread is joinable.
	{
		t2.join();//we have already joined the thread we need not to again joni the thread.
	}
	if(t1.joinable())//check if thread is joinable
	{
		t1.join();
	}
	cout<<"This is how the condition variables work!!"<<endl;
	return 0;
}