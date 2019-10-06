#include "pubSub.h"
#include <string.h>

/* Compliation: gcc producer.c -I<path for pubSub.h> -L<path for libpubSub.so> -lpubSub -o producer
 * Execution: ./producer
 */ 

int main()
{
    int retVal = connectToPubSubServer(TCP, "127.0.0.1", 3456);
    if (retVal == SUCCESS)
    {
	printf("Connection with Pub Sub Server successful\n");
        
	char dataString[] = "{Name: \"abcd\", Profession: \"efgh\"}";
	// Convert the string to byte array
	int sizeOfDataStr = strlen(dataString) + 1; // +1 for the NUL char
	unsigned char data[sizeOfDataStr];
        int strIndex = 0;
        for (strIndex = 0; strIndex < sizeOfDataStr; strIndex++)
        {
            data[strIndex] = dataString[strIndex];
        }
	int dataSendStatus = sendDataToQueue(data);
	if (dataSendStatus == SUCCESS)
	{
	    printf("Data sent successfully\n");
	}
	else
	{
	    printf("Failure in sending Data\n");
	}

    } 
    else
    {
	printf("Connection with Pub Sub Server unsuccessful\n");
    }

    return SUCCESS;
}
