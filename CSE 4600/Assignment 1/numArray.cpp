#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

void *csu(void* nums)
{
	int *num = (int *)nums;
	for(int i = 0;i < 50; i++)
	{
		if(num[i] % 2 == 0)
			cout << "csu ";
	}
	return NULL;
}

void *sb(void* nums)
{
	int *num = (int *)nums;
	for(int i = 0; i < 50; i++)
	{
		if(num[i] % 5 == 0)
			cout << "sb ";
	}
	return NULL;
}

void *csusb(void* nums)
{
	int *num = (int *)nums;
	for(int i = 0; i < 50; i++)
	{
		if(num[i] % 2 == 0 && num[i] % 5 == 0)
			cout << "csusb ";
	}
	return NULL;
}

void *number(void* nums)
{
	int *num = (int *)nums;

	for(int i = 0; i < 50; i++)
		if(num[i] & 2 != 0 && num[i] % 5 != 0)
			cout << num[i] << " ";
	return NULL;
}



int main()
{
	int nums[50];
	for(int i = 1; i <= 50; i++)
	{
		nums[i - 1] = i;
	}

	pthread_t tid1, tid2, tid3, tid4;

	pthread_create(&tid1, NULL, csu, (void* )nums);
	pthread_create(&tid2, NULL, sb, (void *)nums);
	pthread_create(&tid3, NULL, csusb, (void *)nums);
	pthread_create(&tid4, NULL, number, (void *)nums);


	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);

	pthread_exit(NULL);
	return 0;
}
