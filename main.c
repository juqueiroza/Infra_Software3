#include <stdio.h>
#include <pthread.h>

int a[50], size, min, max, avg;

void *thread_avg() {
        float sum = 0;
        int i;
	for(i = 0; i < size; i++){
		sum = sum + a[i];
        }
	avg = sum/size;
        pthread_exit (NULL);
}

void *thread_min() {
	int temp = a[0];
        int i;
	for(i = 1; i < size; i++) {
		if(temp > a[i]) {
			temp = a[i];
		}
	}
        min = temp;
        pthread_exit (NULL);
}

void *thread_max() {
	int temp = a[0];
        int i;
	for(i = 1; i < size; i++) {
		if(temp < a[i]){
			temp = a[i];
		}
	}
        max = temp;
        pthread_exit (NULL);
}

void *th(void *arg){
        int i;

	printf("Enter number of elements in array: ");
	scanf("%d", &size);

	for(i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	}

        pthread_t th2;
        pthread_t th3;
        pthread_t th4; 
        pthread_create(&th2, NULL, &thread_avg, NULL);
	pthread_join(th2, NULL);
	pthread_create(&th3, NULL, &thread_min, NULL);
        pthread_join(th3, NULL);
	pthread_create(&th4, NULL, &thread_max, NULL);
        pthread_join(th4, NULL);

        printf("The average value is: %d",avg);
        printf("\nThe minimum value is %d",min);
        printf("\nThe maximum value is %d\n",max);
        pthread_exit (NULL);
}

int main() {
        pthread_t th1;
        pthread_create(&th1, NULL, &th, NULL);
        pthread_join(th1, NULL);
}
