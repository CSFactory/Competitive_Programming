#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    float s = 0;
    float p = 0;
    float arr[n];
    for(int i=0;i<n;i++){
            p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
            s=sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
            arr[i] = s;
    }
    //sort the arr
    float temp=0.0,tempa=0.0,tempb=0.0,tempc=0.0;
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(arr[j]>arr[k]){
                temp = arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
                
                tempa=tr[j].a;
                tr[j].a = tr[k].a;
                tr[k].a = tempa;
                
                tempb=tr[j].b;
                tr[j].b = tr[k].b;
                tr[k].b = tempb;
                
                tempc=tr[j].c;
                tr[j].c = tr[k].c;
                tr[k].c = tempc;
            }
        }
    }

}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
