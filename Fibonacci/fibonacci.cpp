#include <iostream>
#include <ctime>
using namespace std;


// 递归的方式求解fibonacci的解，时间复杂度为O(2^n)
uint64_t fibonacci1(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return fibonacci1(n - 1) + fibonacci1(n - 2);
}

// 使用递推的方式求解fibonacci的解，时间复杂度为O(n), 空间复杂度为O(1)
uint64_t fibonacci2(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	uint64_t first = 0;
	uint64_t second = 1;
	int index = 1;
	uint64_t fibo = 0;
	while (index++ < n)
	{
		fibo = first + second;
		first = second;
		second = fibo;
	}
	return fibo;
}


// 使用动态规划算法求解fibonacci的解，时间复杂度为O(n), 空间复杂度为O(n)
long cacheLength = 100000000L;
uint64_t* fiboCache = NULL;
int cacheIndex = 0;
void updateFiboCache(int n)
{
	if (n < cacheIndex)
		return;
	if (fiboCache == NULL)
	{
		fiboCache = new uint64_t[cacheLength]();
		memset(fiboCache, 0, cacheLength * sizeof(uint64_t));
		fiboCache[0] = 0;
		fiboCache[1] = 1;
		cacheIndex = 1;
	}
	while (cacheIndex++ <= n)
	{
		fiboCache[cacheIndex] = fiboCache[cacheIndex - 1] + fiboCache[cacheIndex - 2];
	}
	cacheIndex--;
}

uint64_t fibonacci3(int n)
{
	updateFiboCache(n);
	return fiboCache[n];
}


int main()
{
	int n = 0;
	cout << "enter n\n";
	cin >> n;
	cin.get();
	while (n != -1)
	{
		long beginTime = 0L;
		//beginTime = std::clock();
		//cout << "递归fibonacci(n) = " << fibonacci1(n) << endl;
		//cout << "elapsed time: " << std::clock() - beginTime << "ms" << endl;

		beginTime = std::clock();
		cout << "递推fibonacci(n) = " << fibonacci2(n) << endl;
		cout << "elapsed time: " << std::clock() - beginTime << "ms" << endl;

		beginTime = std::clock();
		cout << "动态规划fibonacci(n) = " << fibonacci3(n) << endl;
		cout << "elapsed time: " << std::clock() - beginTime << "ms" << endl;
		cout << "\nenter n\n";
		cin >> n;
		cin.get();
	}
	
	if (fiboCache != NULL)
	{
		delete(fiboCache);
	}
	return 0;
}