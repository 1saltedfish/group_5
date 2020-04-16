/*
���Ǻ���tanģ��

��Ҫ������˵����
	f_tan()ʵ����tan�����ļ���
	test_tan()��tan�������в���

��Ҫ�㷨��
	��tan����ʵ�������������չ���������Ǻ�������

�ӿ�˵����
	������ʽ��C����ֱ�ӵ�������ִ��
	f_tan()Ҫ������double���͵Ĵ���Ƕ�ֵ������double���ͽ��
	test_tan()�е���f_tan()�������в���,�������1000�������ԣ�����ֵ��int�ͣ�����1000�������������0.001�Ĵ�����

���ߣ�
	�����

	�޸ģ�
	2020.4.16
		���Է��־��Ȳ�������f_tan���������޸ģ���Ȼʹ���������չ��ʵ�֣����������˽�����1000�β�����ƽ����350��������0.001��

*/
#include "tan_function.h"

#include <stdio.h>

//�������ֵ
#define accuracy 0.001

//�����ֵ
double absolute(double x)
{
	if (x < 0)x = -x;
	return x;
}

//��׳�
double Factorial(int x)
{
	if (x == 1 || x == 0)return 1;
	else
		return 1.0 * x * Factorial(x - 1);
}

//��n�η�
double nth(double x, int n)
{
	if (n > 0)
	{
		return x * nth(x, n - 1);
	}
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return (1 / x) * nth(x, n + 1);
	}
}


//��Ŭ����
double Bernoulli(int x)
{
	int k = x;
	double B = 0;
	if (x == 0)
		return 1;
	else
		if (x > 1 && x % 2 == 1)
		{
			return 0;
		}
		else
		{
			while (k)
			{
				k--;
				B += -1.0 * (Factorial(x) * Bernoulli(k)) / (Factorial(x - k) * Factorial(k) * (x - k + 1));
			}
			return B;
		}
}

double tanx(double x)//tan(x)  ���ȱ���0.000001 �����ٶ�̫��
{
	int i = 1;
	double e = 1, sum = 0;
	while ( i <= 10)//���Ǽ����ٶȣ�����Bernoulli()
	{
		e = 1.0 * (nth(-1, i - 1) * nth(2, 2 * i) * (nth(2, 2 * i) - 1.0) * Bernoulli(2 * i) * nth(x, 2 * i - 1)) / (Factorial(2 * i));
		sum += e;
		i++;
	}
	return sum;
}



/*tan����*/
double f_tan(double input)
{
	//ʹ���������չ������tan������Ĭ�Ͻ���Ϊ10
	double o;
	double x, y;

	if (input > 1048576.0)//�������2^20
		return INFINITY;


	//�������򷵻�INFINITY�������ʾinf
	//if ((fmod(input, 180) == 90) || (fmod(input, 180) == -90))
	//{
	//	return INFINITY;
	//}

	//��������д���ʹ��������-90��+90��Χ��
	//x = fmod(input, 180);//�������ϵĵ�ȫ��ӳ�䵽-180��180��,��ʱx��ȡֵ��ΧΪ-180��180,��Ҫ�ٽ���ѹ��Ϊ-90��90
	//if (x > 90)
	//{
	//	x = x - 180;//��90-180�ϵĵ�ӳ��Ϊ-90-0
	//}
	//else if (x < -90)
	//{
	//	x = x + 180;//��-180--90�ĵ�ӳ��Ϊ0-90
	//}
	while (input < -90) input += 180;
	while (input > 90)  input -= 180;

	if(absolute(input) == 90)
		return INFINITY;

	//��������ֵ
	if (input == 45)
		return 1;
	if (input == -45)
		return -1;

	y = input / 180 * pi;	//���Ƕ�����ת��Ϊ��������
//	o = y + (double(1.0 / 3.0)) * pow(y, 3) + double(2.0 / 15.0) * pow(y, 5) + double(17.0 / 315.0) * pow(y, 7) + double(62.0 / 2835.0) * pow(y, 9);
	o = tanx(y);
	//����С�������λ
	o = int(o * 1000) / 1000.0;

	return o;
}





int tan_test(void)
{
	//TUDO �������1000�������ԣ�����ֵ��int�ͣ�����1000�������������0.001�Ĵ�����
	double n;
	double x, y;
	int cnt = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		n = (rand() % 180) - 90.0;
		
		if (absolute(n) != 90)
		{
			x = tan(n/180.0 * pi);
			y = f_tan(n);
			if (absolute(x - y) >= accuracy)
				cnt++;
		}
	}
	return cnt;
}