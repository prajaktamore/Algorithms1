List of Method

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

****************************************************************************************
Running the program:

PrajaktaMore@PrajaktaMore /cygdrive/d/ALGORITHM/Assignment1
$ cc -c AlgoAssignment1.c

PrajaktaMore@PrajaktaMore /cygdrive/d/ALGORITHM/Assignment1
$ cc -o assign1 AlgoAssignment1.c

PrajaktaMore@PrajaktaMore /cygdrive/d/ALGORITHM/Assignment1
$ ./assign1

Please enter only the numbers from 1 to 4 to select a algorithm, 0 to exit
0:Exit
1:Selection Sort
2:Counting Sort
3:Merge Sort
4:Quick Sort
Enter your selection : 1
You have selected Selection Sort 
Please specify the number of input data n : 5 //Specifiec number of values in array.Visualization works for specific range

*****************************************************************************************
Details about algorithm implmentation

/*
Selection sort 	: Selection Sort is that we repeatedly find the smallest element in the unsorted part of the array 
and swap it with the first element in the unsorted part of the array
Best: n^2
Average: n^2 	
Worst: n^2 	
Memory: 1 	
Stable: No 	Selection method only Stable with O(n) extra space, for example using lists
*/

/*
Counting sort : If r is O(n), then Average is O(n) 
Operates as look at the list, and wherever we find two consecutive elements out of order, we swap them
Best: 
Average: n+r 	
Worst: n+r 	
Memory: n+r 	
Stable: Yes n<<2^k that is n is very very less than 2^k
*/

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

/*
Quick sort : Divide and Conquer up to O(log n)  but in worst case when list is already sorted it is O(n^2). 
So to void it we randomize the algorithm by using random number generator
Best: n (log n)
Average: n (log n)
Worst: n (log n) when it is randomized but if not it is O(n^2)	
Memory: log n on average and n worst case 	
Stable: typical in-place sort is not stable; stable versions exist 
*/
*********************************************************************************************************