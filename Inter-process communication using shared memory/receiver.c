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
   			if (shmid == -1) {
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
			  printf("The data read by the receiver is: %s\n", (char *)sharedmemory);
			  return 0;
		}
