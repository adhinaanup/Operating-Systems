#include <stdio.h>
	#include <sys/ipc.h>
	#include <sys/shm.h>
	#include <string.h>
	#include <unistd.h>
	int main() {
	 		void *sharedmemory;
    		char buffer[100];
    		int shmid;
    		// Create shared memory segment
    		shmid = shmget((key_t)1666, 1024, 0666 | IPC_CREAT);
    		if (shmid == -1)
		{
       				perror("shmget failed");
       				return 1;
    		}
    		// Attach to the shared memory segment
    		sharedmemory = shmat(shmid, NULL, 0);
    		if (sharedmemory == (void *)-1) {
        			perror("shmat failed");
        			return 1;
    		}
 		printf("The process is attached at %p", sharedmemory);
 		printf("\nEnter the data that you want to add to shared memory: \n");
    // Read input from user
    			read(0, buffer, 100);
    			strcpy(sharedmemory, buffer);
    			printf("The data sent by the sender is: %s\n", (char *)sharedmemory);

    			// Detach from the shared memory segment
    			if (shmdt(sharedmemory) == -1) {
    			   	 perror("shmdt failed");
        				return 1;
    			}
    			return 0;
		}

