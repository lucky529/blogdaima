#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<windows.h> 
//double my_pow_2(double n, unsigned int k)
//{
//	double ret;
//	if (k == 0)//如果n为1，多少个1相乘都是1
//		return 1;
//	if (k ==1)
//		return n;
// 
// 
//	ret = my_pow_2(n, k >> 1);// k >> 1将除以2后指数给下一次 
//	ret *=ret;//  表示ret的平方    
//	if ((k & 0x01) == 1)//如果k是个奇数，则结果还要乘上一个n
//		ret *= n;
// 
// 
//	return ret;
//}
// 
// 
//double my_pow1(double n,int k)
//{
//	if (n == 0 && k != 0)
//		return 0;
//	if (k >= 0)
//	{
//		return my_pow_2(n, k);
//	}
//	else if(k<0)
//	{
//		return 1.0/my_pow_2(n, -k);
//	}
//} 
// 
// 
//int main()
//{
//	double buf;
//	buf = my_pow1(2,-1);
//	printf("%lf\n", buf);
//	system("pause");
//	return 0;
//}


//<code class="language-cpp">void add_contacts(struct contacts **pp)//模拟实现一个通讯录  
//{  
//    //临时字符串  
//    char tmp_string[20];  
//    //临时联系人结构体指针  
//    struct contacts *tmp;  
//    //临时联系人结构体指针  
//    struct contacts *tmp_end;  
//  
//  
//    if (*pp == NULL)  
//    {  
//        *pp = (struct contacts *)malloc(sizeof(struct contacts));  
//        tmp = *pp;  
//    }  
//    else  
//    {  
//        tmp = (struct contacts *)malloc(sizeof(struct contacts));  
//        tmp_end = *pp;  
//        while (tmp_end->next )//找到最后一个结点  
//        {  
//            tmp_end = tmp_end->next;  
//        }  
//        tmp_end->next = tmp;//最后一个结点指向新开辟的结点  
//    }  
//  
//  
//  
//  
//    printf("输入姓名\n");  
//    getchar();//接收回车键  
//    gets(tmp_string);  
//    strcpy(tmp->name, tmp_string);  
//  
//  
//    printf("输入地址\n");  
//    gets(tmp_string);  
//    strcpy(tmp->address, tmp_string);  
//  
//  
//    printf("输入年龄\n");  
//    scanf("%d", &(tmp->age));  
//  
//  
//    printf("输入性别 1代表男 2代表女\n");  
//    scanf("%d",&(tmp->sex));  
//  
//  
//    printf("输入电话\n");  
//    getchar();//接收回车键  
//    gets(tmp_string);  
//    strcpy(tmp->phone, tmp_string);  
//  
//    tmp->next = NULL;//最后一个结点的指针指向空，  
//  
//    printf("添加成功\n");  
//    peopple_num++;  
//}</code>

//在一个长度为n的数组里所有的数字都在0-n-1的范围里。
//数组某些数字是重复的，但是不知道有几个数字重复了，
//也不知道重复了几次。请找出数组中重复的数字
//1.首先判断数组指针是否为空，判断数组的长度是否为边界值
//2.进行循环判断数组中的数字有没有没有满足题意的
//3.进行for循环判断每个数是否等于自己的下标
//4.不相等的进行交换
//5.假设下标为5的数字等于下标为2的数字那么找出一个重复的数字
//#include<stdio.h>
//int my_duplicate(int number[],int len,int* dup)
//{
//	int i = 0;
//	int temp = 0;
//	if(number == NULL || len <= 0)
//		return 0;
//	for(i = 0; i<len ; i++)
//	{
//		if(number[i]<0 || number[i]>len-1)
//			return 0;
//	}
//	for(i = 0; i<len; i++)
//	{
//		while(number[i] != i)
//		{
//			if(number[i] == number[number[i]])
//			{
//				*dup = number[i];
//				return 1;
//			}
//			temp = number[i];
//			number[i] = number[temp];
//			number[temp] = temp;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[6] = {3,1,0,2,5,3};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int dup;
//	my_duplicate(arr,sz,&dup);
//	return 0;
//}

#include<stdio.h>
int countrange(const int*numbers,int len, int start, int end)
{
	int count = 0;	
	for(int i = 0; i < len; i++)
	{
		if((numbers[i] <= end) && (numbers[i] >= start))
			++count;
	}
	return count;
}
int getdupliction(int* numbers,int len)
{			
	int start = 1;
	int end = len-1;
	if((numbers == NULL) || len <= 0)
	{
		return -1;
	}
	while(end >= start)
	{		
		int middle = ((end - start) >> 1)+start;
		int count = countrange(numbers, len ,start, middle);
		if(end == start)
		{
			if(count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}
		if(count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {2,3,5,4,3,2,6,7};
	int sz = sizeof(arr)/sizeof(arr[0]);
    getdupliction(arr,sz);
	printf("%d",getdupliction(arr,sz));
	return 0;
}
