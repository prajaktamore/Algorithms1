#include<stdio.h>

/*Method to swap two varaibles*/
void swap(int *a,int *b);
/*Selection Sort => Ѳ(n2) for selection sort*/
void selectionSort();
/*Printing the array to show the current state*/
void star(int a[], int n);
/*mergeSort Sort => Ѳ(nlgn) for merge sort */
void mergeSort();
/*Counting Sort => Ѳ(n) for counting sort*/
void countingSort();
/* Dividing list into left and right in merge Sort*/
void partition(int a[],int low,int high, int n);
/*Method to swap two varaibles according to low and high current location*/
int quicksort_swap(int a[],int low,int high);
/*According to condition performs recursive call if((high-low)>0)*/
void rquick_Sort(int a[],int low,int high,int n);
/*Quick Sort => Ѳ(nlgn) for Quick sort*/
void quickSort();
/* combining list into one from left and right in merge Sort*/
void merge_Sort(int arr[],int low,int mid,int high);

void main()
{
    int input=0;//Selection of either one of the sorting algorithm
    while(1)
    {
        printf("\n\n\nPlease enter only the numbers from 1 to 4 to select a algorithm, 0 to exit");
        printf("\n0:Exit \n1:Selection Sort \n2:Counting Sort \n3:Merge Sort \n4:Quick Sort\n");
        scanf("\n%d", &input);

        switch(input)
        {
            case 0:
                exit(0);//If 0 is selected exit the program
            case 1:
                selectionSort();//if 2 is selected perform selectionSort
                break;
            case 2:
                countingSort();//if 2 is selected perform counting Sort
                break;
            case 3:
                mergeSort();//if 3 is selected perform merge Sort
                break;
            case 4:
                quickSort();//if 4 is selected perform quick Sort
                break;
            default:
                printf("Please select only numbers from 0 to 4");
        }
    }

}

//Swap is used as pass by referance to swap values of two integers.
void swap(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}

//Star function is used to print star(*) as and when required
void star(int a[], int n)
{
    int i=0,j=0,k=0,l=0;
    if(n<=30)
        {
            printf("\n\n");
            printf("Iteration:\n");
            printf("Array:");
            for(l=0;l<n;l++)
            {
                printf(" %d",a[l]);
            }
            printf("\n");
            for(i=0; i<n; i++)
            {
                k=a[i];
                for(j=0; j<k; j++)
                {

                    printf("*");

                }
                printf("\n\n");
            }
        }
}

/*
Selection sort 	: Selection Sort is that we repeatedly find the smallest element in the unsorted part of the array 
and swap it with the first element in the unsorted part of the array
Best: n^2
Average: n^2 	
Worst: n^2 	
Memory: 1 	
Stable: No 	Selection method only Stable with O(n) extra space, for example using lists
*/
void selectionSort()
{
    int n=0;
    printf("\nYou have selected Selection Sort");
    printf("\n Please specify the number of input data n : ");
    scanf("%d", &n);

    if(n<1 || n>1000)
    {
        printf("\nThe number of input data from 1 to 1000 only");
        return;

    }
    else
    {
        int array[n];
        int i=0;
        int j=0;
        int min=0;
        int temp=0;

        srand (time(NULL));

        printf("\nArray before Sorting: ");
        for(i=0;i<n;i++)
        {
            array[i] = rand()%100;
            printf("%d ", array[i]);

        }

        for(i=0;i<n;i++)
        {
            min = i;
            for(j=i+1;j<n;j++)
            {
                if(array[j] < array[min])
                {
                    min = j;
                }
            }
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            int p,q;

            if(n<=30)
            {
                printf("\n\nAfter %d iteration the sequence is\n",i);
                for(p=0; p<n; p++)
                {
                    q=array[p];
                    for(q=0; q<array[p]; q++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
        }

        printf("\n\nAfter Sorting the sorted element/s is/are: ");
        for(i=0;i<n;i++)
        {
            printf("%d ", array[i]);

        }
    }

}

/*
Counting sort : If r is O(n), then Average is O(n) 
Operates as look at the list, and wherever we find two consecutive elements out of order, we swap them
Best: 
Average: n+r 	
Worst: n+r 	
Memory: n+r 	
Stable: Yes n<<2^k that is n is very very less than 2^k
*/
void countingSort()
{
    printf("\nYou have selected Counting Sort");

    int i,n=0;

    //To initialize random seed
    srand(time(NULL));

    printf("\n\nEnter number of elements you want to sort=");
    scanf("%d",&n);

    int a[n];

    if(n < 1 || n > 1000)
    {
        printf("\nError message: Program runs for n greater than 1 and less than 1000\n");
        return;
    }

    if(n <=  30)
    {
        printf("\n\nThe number/s to be sorted is/are =");
        for( i=0;i<n;i++)
        {
            a[i] = rand() % 20 + 0;
            printf(" %d", a[i]);
        }
    }
    else
    {
        printf("\n\nThe element/s to be sorted is/are =");
        for( i=0;i<n;i++)
        {
            a[i] = rand() % 99;
            printf(" %d", a[i]);
        }
    }

    int j,max_num=0,p=0,q=0;
    int temp_array[1000];
    int sorted_array[1000];

    //for loop to find out the maximum number
    for(i=1;i<n;i++)
    {
        if(max_num<a[i])
        {
          max_num=a[i];
        }
    }

    //for loop to initialize all indexes of array to 0.
	for(i=0;i<=max_num;i++)
	{
		temp_array[i]=0;
		sorted_array[i]=0;
	}

    //for loop to increment the value of temp index array if matching value is found.
	for(j=0;j<n;j++)
	{
		temp_array[a[j]]=temp_array[a[j]]+1;
	}

    //for loop for adding all values in temp_array
	for(i=1;i<=max_num;i++)
	{
		temp_array[i]=temp_array[i-1]+temp_array[i];
	}

    //for loop to perform sorting
	for(j=n-1;j>=0;j--)
	{
		i=a[j];

		sorted_array[temp_array[i]-1]=i;
        if(n<=30)
        {
            /*printf("\nArray Elements:");
            for(i=0;i<n;i++)
            {
                printf(" %d",sorted_array[i]);
            }*/
            star(sorted_array,n);
        }
        temp_array[i]=temp_array[i]-1;

	}

	printf("\n\nAfter Sorting the sorted element/s is/are: ");
	for(i=0;i<n;i++)
	{
		printf(" %d",sorted_array[i]);
	}
}

/*
Merge sort : Merge sort is a so-called divide-and-conquer algorithm with O(log n) 
Best: n (log n)
Average: n (log n)
Worst: n (log n) 	
Memory: n worst case 	
Stable: Yes 
•T(1) =c
•T(n) = 2T(n/2) +dn
*/
void mergeSort()
{
    printf("\nYou have selected Merge Sort");

    int i,n=0;

    //To initialize random seed
    srand(time(NULL));

    printf("\n\nEnter number of elements you want to sort=");
    scanf("%d",&n);

    int a[n];

    if(n < 1 || n > 1000)
    {
        printf("\nError message: Program runs for n greater than 1 and less than 1000\n");
        return;
    }

    if(n <=  30)
    {
        printf("\n\nThe number/s to be sorted is/are =");
        for( i=0;i<n;i++)
        {
            a[i] = rand() % 20 + 0;
            printf(" %d", a[i]);
        }
    }
    else
    {
        printf("\n\nThe element/s to be sorted is/are =");
        for( i=0;i<n;i++)
        {
            a[i] = rand() % 1000 + 1;
            printf(" %d", a[i]);
        }
    }

    //function call partition.
    partition(a,0,n-1,n);

    printf("\n\nAfter Sorting the sorted element/s is/are: ");
    for(i=0;i<n;i++){
         printf("%d ",a[i]);
    }
}
//Partition goes on dividing the input list.
void partition(int a[],int low,int high, int n)
{

    int mid, i=0, j=0, k=0;

    if(low<high)
    {
         mid=(low+high)/2;
         partition(a,low,mid,n);
         partition(a,mid+1,high,n);
         merge_Sort(a,low,mid,high);

        if(n<=30)
        {
            printf("\n\n");
            printf("Iteration:\n");
            for(i=0; i<n; i++)
            {
                k=a[i];
                for(j=0; j<k; j++)
                {

                    printf("*");

                }
                printf("\n\n");
            }
        }
    }
}

//function where actual sorting takes place before merging the elements
void merge_Sort(int arr[],int low,int mid,int high)
{

    int i,m,k,l,temp[high];

    l=low;
    i=low;
    m=mid+1;

    //logic to implement merge sort.
    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

/*
Quick sort : Divide and Conquer up to O(log n)  but in worst case when list is already sorted it is O(n^2). 
So to void it we randomize the algorithm by using random number generator
Best: n (log n)
Average: n (log n)
Worst: n (log n) when it is randomized but if not it is O(n^2)	
Memory: log n on average and n worst case 	
Stable: typical in-place sort is not stable; stable versions exist 
*/
void quickSort()
{
    printf("\nYou have selected Quick Sort");

    int i,j,temp,n=0;
    int p,q;

    //To initialize random seed
    srand(time(NULL));

    printf("\n\nEnter number of elements you want to sort=");
    scanf("%d",&n);

    int a[n];

    if(n < 1 || n > 1000)
    {
        printf("\nError message: Program runs for n greater than 1 and less than 1000\n");
        return;
    }

    if(n <=  30)
    {
        printf("\n\nThe number/s to be sorted is/are =");
        for( i=0;i<n;i++)
        {
            a[i] = rand() % 20 + 0;
            printf(" %d", a[i]);
        }
    }
    else
    {
        printf("\n\nThe element/s to be sorted is/are =");
        for( i=0;i<n;i++)
        {
            a[i] = rand() % 1000 + 1;
            printf(" %d", a[i]);
        }
    }

    rquick_Sort(a,0,n-1,n);

    printf("\n\nAfter Sorting the sorted element/s is/are: ");
    for(i=0; i<n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n\n");
}

void rquick_Sort(int a[],int low,int high,int n)
{
    int i, j, k, p;

    if((high-low)>0)
    {
        p=quicksort_swap(a,low,high);
        //call to function star to print star if elements entered are less than 20
        star(a,n);
        rquick_Sort(a,low,p-1,n);
        rquick_Sort(a,p+1,high,n);
    }
}

//In this method we are 
int quicksort_swap(int a[],int low,int high)
{
    int i,l,k;
    int p;
    int firstlist;

    //To generate a random pivot element in between high and low element.
    p = rand()%(high-low+1)+low;

    //function call swap
    swap(&a[p],&a[high]);
    firstlist=low;
    for(i=low; i<high; i++)
    {
        if(a[i]<a[high])
        {
            swap(&a[i],&a[firstlist]);
            firstlist++;
        }

    }
    swap(&a[high],&a[firstlist]);

    return(firstlist);

}
