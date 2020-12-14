#include<iostream>
#include<thread>
#include<deque>
#include<chrono>
using namespace std;
std::mutex mtx;
std::condition_variable cond;
const unsigned int bufferSize = 5;
deque<int> buffer;

int produce (int val)
{
	while(val--)
	{   
		std::this_thread::sleep_for(chrono::seconds(1));
		std::unique_lock<mutex> lock(mtx);
		cond.wait(lock, [] () {return (buffer.size()<bufferSize);});
		buffer.push_back(val);
		cout<<"value produced: "<<val<<endl;
		cout<<"Current Buffer Size: "<<buffer.size()<<endl;
		lock.unlock();
		cond.notify_one();

	}
	return 0;

}
int consumer()
{
	while (1)
	{
		std::unique_lock<std::mutex> lock(mtx);
		cond.wait(lock,[] () {return (buffer.size()>0);});
		int val = buffer.back();
		buffer.pop_back();
		cout<<"Consumed Value: "<<val<<endl;
		cout<<"Buffer Size after Consumption"<<buffer.size()<<endl;
		lock.unlock();
		cond.notify_one();
	}
	return 0;
}

int main()
{
	int val = 5;
	std::thread t1(produce,val);
	std::thread t2(consumer);
	t1.join();
	t2.join();
	return 0;

}