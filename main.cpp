#include <iostream>
#include <pthread.h>

using namespace std;

long long int counter = 0;
int iterations = 3;
pthread_t threads[10000];
    	

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
//	cout << "counter = " << counter; 
	return NULL;
}

int main(int argc, char *argv[]) {
    
    int value = atoi(argv[1]);
    
    if(value == 1){
    
    	cout << "\nTypical Program Execution Speed\n";
    	
    	for(int i = 0 ; i < iterations ; i++)
    		fun_ction(NULL);
    }
    else if(value == 2){
    	
    	cout << "\nThreaded Program Execution Speed\n";
    	  	
	for (int i = 0; i < iterations; i++)
		pthread_create(&threads[i], NULL, fun_ction, NULL);
	
	for (int i = 0; i < iterations; i++)
		pthread_join(threads[i], NULL);
    }
    else{
    		cout << "\nIncorrect Input";
    	}
    
    return 0;
}
