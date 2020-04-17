#include <iostream>
#include "cot.h"
using namespace std; 
#define  PI 3.14159265358979323846
//#define _USE_MATH_DEFINES
//#include <math.h>     // 3��4�б�֤ʹ��pi��д��M_PI

double cottest(double a)
{	
	int quotient=1;
	// cot��������Ϊpi

	//double��fioat�Ͳ�����%�������� ���� ����(a - int(a) + int(a) % 180)���൱�� a%180  
	if ((a - int(a) + int(a) % 180) == 0)
	{
		return INFINITY;
	/*printf("��������180�ı�������Ϊ��ֵ�����к�������û������ģ�����\n\a");
	exit(0);*/
	}
	else if (a > 180)    //doubleת����int������ȡ��
	{
		
		quotient =a/180;      //��a=365.3����quotient=365/180=2 ��a=365.3-2*180= 5.3 
		a = a - quotient * 180;
	}
	else if(a < -180)     //����ȡ������ -359.7-> 359  ,ĨȥС����
	{
		quotient = a / 180;        //��a=-365.3����quotient=-365/180=-2 ��a=-365.3-��-2��*180 = -5.3 
		a = a - quotient * 180;
	}
	
	//��Ϊ������ -90<x<90
	if(a>90)   
	{
		a = a - 180;
	}
	else if (a < -90)
	{
		a = a + 180;
	}
	//cout << "����a�ĽǶ�ֵ�ǣ�" << a << endl;
	double newa = a * PI / 180.0;
	//cout <<"����a�Ļ���ֵ�ǣ�"<< newa << endl;
	//����cot������̩�չ�ʽչ����ȡǰ���4�
	double t = 1.0 / newa - newa / 3.0 - pow(newa, 3) / 45.0 - 2 * pow(newa, 5) / 945.0 - pow(newa, 7) / 4725 - 2.1377806 * pow(10, -5) * pow(newa, 9)-2.16440629*pow(10,-6)*pow(newa,11);
	//double cotx = 0;
	/*for (int i = 0; i < 6; i++)
	{
		cotx = cotx + reFactorial(-1) * pow(2, 2 * i) * reBernoulli(2 * i) * pow(newa, 2 * i - 1) / reFactorial(2 * i);
	}*/
	//if (flag / number == 0)
	//{
	//////////  С���㾫ȷ����   ///////////////////
	int n = 3;//����nλ��Ч���֡�
	double cotx = t - (int)t;  //ȡС�����֡�
	cotx *= pow(10, n);//С�������ơ�
	if (cotx - (int)cotx >= 0.5)
	{
		cotx += 1; //��������
	}
	cotx = (int)cotx; //ȡ�������֡�
	cotx /= pow(10, n);//С�������ơ�
	cotx += (int)t;//����ԭ������������
	//////////////////////////////////////////////
	/*if (abs(cotx) < 0.008)
	{
		cotx = 0;
	}
	*/
	return cotx;
}

