#include <stdio.h>
#include <stdlib.h>

void compute_cell_state(int* cell_ptr, int* cell_temp_ptr, int itr, const int cell_size){
    int left, right = 0;
    int *cell_left, *cell_right;
    
   if (itr == 0){
       // For cell[0] which is connected to the last cell (cell[N-1]) in a circle
        cell_left = cell_ptr+cell_size-1;
        cell_right = cell_ptr+1; 
    }else{
        // For cell[1] to cell[N-2]
        cell_left = cell_ptr-1;
        cell_right = cell_ptr+1;
        // For the last cell (cell[N-1]) is connected to the first cell (cell[0])
        if (itr == cell_size-1){
            cell_right = cell_ptr-(cell_size-1);
        }
    }
    
    // Left cell will emit signal if excited
    left = (*cell_left == 1) ? 1 : 0;
    
    // Right cell will emit signal if excited
    right = (*cell_right == 1) ? 1 : 0;
    
    // Set the current cell status based on signal coming from left and Right cell
    if (left == 1){
        *cell_temp_ptr = (right == 0) ? 1 : 0;
    }else{
        *cell_temp_ptr = (right == 0) ? 0 : 1;
    }
} 

void update_cell_state(int* cell_ptr, int* cell_temp_ptr, const int cell_size){
    for (int i=0; i<cell_size; ++i){
        *(cell_ptr+i) = *(cell_temp_ptr+i);
    }
}

void print_usage(){
	printf("Usage: cell <Array length> <K> <Array elements>.\n");
    printf("Example: cell 4 2 1 0 1 1\n");
    exit(0);
}
    
int main(int argc, char *argv[])
{
    if( argc < 2 ) {
    	// 1st check of runtime args
   		print_usage();		 
    }
   int cell_length = atoi(argv[1]);
   
   if (argc < cell_length + 3){
   		// 2nd check of runtime args
   	 	print_usage();
   }
    // K = number of steps
	int k = atoi(argv[2]);
	
	int* cell = (int*) calloc(cell_length, sizeof(int));
    int* cell_temp = (int*) calloc(cell_length, sizeof(int));
    // Store the input array
	for (int x = 0; x<cell_length; ++x){
		*(cell+x) = atoi(argv[x+3]);
	}
	printf("Initial configuration is : \n");
	for (int y= 0; y<cell_length; ++y){
		printf("%d ", *(cell+y));
	}
	printf("\n");
			 
    // Step through the array for K steps
    for (int step = 1; step <= k; ++step){
        for(int i=0; i<cell_length; ++i){
            compute_cell_state(cell+i, cell_temp+i, i, cell_length);
        }
        update_cell_state(cell, cell_temp, cell_length);
        printf("The configuration after step %d is: \n", step);
        for (int j=0; j<cell_length; ++j){
            printf("%d ", *(cell+j));   
        }
        printf("\n");
    }

    return 0;
}
