#include<thread>
#include<chrono>
#include<iostream>
using namespace std;
std::mutex mtx;
int balance = 0;
int addMoney(int amt)
{
	mtx.lock();
	balance = balance+amt;
	mtx.unlock();
	cout<<"Current Balance After Adding Some Amount in Your Account is :  " <<balance<<endl;
	return 0;
}
int checkBalance()
{
	cout<<"Total Amount in Your Account: "<<balance<<endl;
	return 0;
}
int main()
{
int amt = 100;
std::thread t1(addMoney,100);
std::thread t2(checkBalance);
t1.join();
t2.join();
return 0;
}


