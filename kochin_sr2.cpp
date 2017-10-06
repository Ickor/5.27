#include <iostream>

using namespace std;
class Massiv 
{
private:
	float sum;
	float *array;
	int n, p, q, k;
	float *xarr;
	float *yarr;
public:
	Massiv()
	{
		p=q=k=0;
		sum=0;
		cout<<"Введите число элеменов"<<endl;
		cin>>n;
		array=new float [n];
		for(int i=0;i<(n);i++)
		{
			cout<<"Введите элемент №"<<i+1<<endl;
			cin>>array[i];
		}
		cout<<"Введенный массив:"<<endl;
		for(int i=0;i<(n);i++)
		{
			cout<<" "<<array[i];
		}
			cout<<endl;		
	}
	int calc();
	~Massiv ()
	{
		delete [] array;
	}
};
int Massiv::calc()
{
	for(int i=0; i<n; i++)
	{	
		if (array[i]>0) 
			p++;		//считает количество положительных чисел
		if (array[i]<0)
			q++;		//считает количество отрицательных чисел
	}
	if (p>=q)
		k=q;
	if (p<q)
		k=p;
	cout<<"k="<<k<<endl; //число k, равное минимальному из p и q
	xarr = new float [q]; //массив под отрицательные жлементы
	yarr = new float [p]; //массив под положительные
	int j=0;
	int l=0;
	for (int i=0; i<n; i++)
	{
		if (array[i]<0)
		{
			xarr[j]=array[i];
			j++;
		}
		if (array[i]>0)
		{
			yarr[l]=array[i];
			l++;
		}
	}
	
	float buf;	
	for (int i=0; i<p/2; i++) //разворот массива положительных чисел
	{
		buf = yarr[i];
		yarr[i] = yarr[p-i-1];
		yarr[p-i-1] = buf;
	}	
	for (int i=0; i<=k; i++) //вычисление значения 
		sum=sum+xarr[i]*yarr[i];
	cout<<"Ответ: "<<sum<<endl;
	delete [] xarr;
	delete [] yarr;
}
int main()
{
	Massiv a;
	a.calc();
	return 0;
}
