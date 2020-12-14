#include<iostream>
#include<thread>
#include <pthread.h>
#include<algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
ull s1=0,s2=0;
void oddSum(ull x)
	{   s1  = 0;
		ull i;
		for (i= 0 ; i<=x; i++)
		{
			if ((i&1) ==0)
			{
				//cout<<"Odd Number: "<<i<<endl;
				s1 = s1+i;
			}
		}
	}
void evenSum(ull x)
	{
		s2 = 0;
		ull j;
		for (j = 0;j<=x;j++)
		{
			if ((j&1)==1)
			{
				//cout<<"Even Number: "<<j<<endl;
				s2 = s2+j;
			}
		}
	}

int main()
{
	ull num=100;
	oddSum(num);
	evenSum(num);
    auto starttime = std::chrono::system_clock::now();
	cout<<"Even Sum : "<<s1<<endl;
	cout<<"Odd Sum : "<<s2<<endl;
	auto endtime = std::chrono::system_clock::now();
	auto duration = duration_cast<microseconds>(endtime-starttime);
	cout<<"Time(in micro sec) Taken without multithreading: "<<duration.count()<<endl;

	//using multithreading
	auto starttime1 = std::chrono::system_clock::now();
	ull num1 = 10000000;
	std::thread t1 (oddSum, num1);
	std::thread t2 (evenSum, num1);
    
    t1.join();
    t2.join();
    auto endtime1 = std::chrono::system_clock::now();
    auto duration1 = duration_cast<microseconds>(endtime1-starttime1);
    //cout<<t1.
    cout<<"Even Sum : "<<s1<<endl;
	cout<<"Odd Sum : "<<s2<<endl;
    cout<<"Time(in micro sec) Taken with multithreading: "<<duration1.count()<<endl;
    


    return 0;
}
	
