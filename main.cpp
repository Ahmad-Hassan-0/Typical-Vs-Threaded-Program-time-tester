#include <iostream>
#include <pthread.h>

using namespace std;

long long int counter = 0;

int ackermannSimple(int m, int n) {
//	counter++;
	
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermannSimple(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ackermannSimple(m - 1, ackermannSimple(m, n - 1));
    }
}


void* fun_ction(void*){
	int m = 4, n = 1, ans = 0;
	ans = ackermannSimple(m, n);
	cout << "\nAckermann(" << m << ", " << n << ")" << " = " << ans << endl;
	cout << "counter = " << counter; 
	return NULL;
}

int main(int argc, char *argv[]) {
    
    int value = atoi(argv[1]);
    
    if(value == 1){
    	cout << "\nTypical Program Execution Speed";
    	fun_ction(NULL);
    	fun_ction(NULL); 
    	fun_ction(NULL); 
    }
    else if(value == 2){
    	cout << "\nThreaded Program Execution Speed";
    	pthread_t thread1;
    	pthread_t thread2;
    	pthread_t thread3;
  
   	pthread_create(&thread1, NULL, fun_ction, NULL);
   	pthread_create(&thread2, NULL, fun_ction, NULL);
	pthread_create(&thread3, NULL, fun_ction, NULL);
	
  	pthread_join(thread1, NULL);
   	pthread_join(thread2, NULL); 
   	pthread_join(thread3, NULL); 
    }
    else{
    	cout << "\nIncorrect Input";
    }
    
    return 0;
}
