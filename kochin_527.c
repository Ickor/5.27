#include <stdio.h>
#include <stdlib.h>
float *get (int *n) //ввод массива
{
	float *array;
	int i;
	array=0;
	printf("Введите число элементов\n");
	scanf("%d",n);
	array= (float*) malloc ((*n)*sizeof(float));
	if(array == 0)
      return array;
	for(i=0;i<(*n);i++)
    {
        printf("Введите элемент № %d\n",i+1);
        scanf("%f",(array+i));
    }
    return array;
}
float *func(float *array, int n)
{
	int i;
	printf("Введенный массив:\n");
	for(i=0; i<n; i++)
		printf(" %g",array[i]);
	int k;
	int p=0, q=0;
	for (i=0; i<n; i++)
	{	
		if (array[i]>0)
			p++;
		if (array[i]<0)
			q++;	
	}
	if (p>=q)
		k=q;
	if (p<q)
		k=p;
	printf("\nk=%d\n",k); //k из условия
	int j=0, l=0;
	int nul=0; 
	float buf, c;
	float *xarr;
	float *yarr;
	xarr=0;
	yarr=0;
		/*я создавал отдельные массивы той же размерности
	 для положительных элементов y - yarr
	и отрицательных элементов x - xarr */
	xarr=(float*)malloc(n*sizeof(float));
	yarr=(float*)malloc(n*sizeof(float));
	float sum=0;
	for( i=0; i<n; i++)
	{
		if( array[i]<0)	
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
	for (i=0; i<n/2; i++) //разворот массива положительных чисел
	{
		buf = yarr[i];
		yarr[i] = yarr[n-i-1];
		yarr[n-i-1] = buf;
	}
		for (i=0; i<n; i++) //нахождение на сколько нужно сдвинуть массив влево, чтобы в начале не было нулей после разворота
			if (yarr[i]==0)
				nul++;
		c=yarr[0];
		for(i=0; i<n-1; i++) //сдвиг
			yarr[i]=yarr[i+nul];
		yarr[n-nul]=c;
	for (i=0; i<=k; i++) //вычисление значения 
		sum=sum+xarr[i]*yarr[i];
	printf("Ответ: %f\n", sum);
	return xarr;
	return yarr;
	return array;
}
float main()
{
	float *a;
	int n;
	int k;
	a=get(&n);
	if (a)
	{
		func(a,n);
		free(a);
	}else
		printf("Ошибка выделения памяти и загрузки данных\n");
}
