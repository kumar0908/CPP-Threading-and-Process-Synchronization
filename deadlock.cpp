#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
using namespace std;
std::mutex m1;
std::mutex m2;


int fun1()
{
	m1.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));//we are waiting for thread2 to aquire the m2, so that we can create the deadlock.
	m2.lock();
	cout<<"This is function1!!"<<endl;
	m1.unlock();
	m2.unlock();
	return 0;

}
int fun2()
{
	m2.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m1.lock();
	cout<<"This is function2!!"<<endl;
	m2.unlock();
	m1.unlock();
	return 0;

}
int main()
{
	std::thread t1(fun1);
	std::thread t2(fun2);

	if(t1.joinable())
	{
		t1.join();
	}
	if (t2.joinable())
	{
		t2.join();
	}
	return 0;
}