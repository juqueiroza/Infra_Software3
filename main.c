#include <stdio.h>
#include <pthread.h>

int a[50], size, min, max, avg;

void *thread_avg() {
	float sum = 0;
        int i;

	printf("Enter number of elements in array: ");
	scanf("%d", &size);

	for(i = 0; i< size; i++) {
	        printf("number %d -> ", i + 1);
	        scanf("%d", &a[i]);
                printf("\n");
	}

        i = 0;
	for(i = 0; i < size; i++){
		sum = sum + a[i];
        }

	avg = sum/size;
	printf("The average value is: %d",avg);
}

void *thread_min() {
	int temp = a[0];
        int i = 1;
	for(i = 1; i < size; i++) {
		if(temp > a[i]) {
			temp = a[i];
		}
	}
        min = temp;
	printf("\nThe minimum value is %d",min);

}

void *thread_max() {
	int temp = a[0];
        int i = 1;
	for(i = 1; i < size; i++) {
		if(temp < a[i]){
			temp = a[i];
		}
	}
        max = temp;
	printf("\nThe maximum value is %d",max);
}

int main()
{
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
	pthread_create(&th1, NULL, &thread_avg, NULL);
	pthread_join(th1,NULL);
	pthread_create(&th2, NULL, &thread_min, NULL);
        pthread_join(th2,NULL);
	pthread_create(&th3, NULL, &thread_max, NULL);
        pthread_join(th3,NULL);
}
