#include <stdio.h>
#include <pthread.h>

int a[50], size, min, max, avg;

void *th_avg_num(void *arg) {
        float sum = 0;
        int i;
	for(i = 0; i < size; i++){
		sum = sum + a[i];
        }
	avg = sum/size;
        pthread_exit (NULL);
}

void *th_min_num(void *arg) {
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

void *th_max_num(void *arg) {
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

void *main_thread(void *arg){
        int i;

	printf("Enter number of elements in array: ");
	scanf("%d", &size);

	for(i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	}

        pthread_t thread2, thread3, thread4; 
        pthread_create(&thread2, NULL, &th_avg_num, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread3, NULL, &th_min_num, NULL);
        pthread_join(thread3, NULL);
	pthread_create(&thread4, NULL, &th_max_num, NULL);
        pthread_join(thread4, NULL);

        printf("The average value is: %d", avg);
        printf("\nThe minimum value is %d", min);
        printf("\nThe maximum value is %d\n", max);
        pthread_exit (NULL);
}

int main() {
        pthread_t thread1;
        pthread_create(&thread1, NULL, &main_thread, NULL);
        pthread_join(thread1, NULL);
}
