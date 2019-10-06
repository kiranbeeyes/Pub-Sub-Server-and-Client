#include "pubSub.h"

/* Compiling this PubSub Client library
 *     gcc -o pubSub.o -c pubSub.c
 *     gcc -shared -o libpubSub.so pubSub.o
 * This creates the shared object file libpubSub.so
 * 
 * The PubSubClient has to include the pubSub.h file during compilation to 
 * have access to these methods. It has to set the LD_LIBRARY_PATH to pick 
 * up this shared object file during execution.
 */ 

// TODO - Store the Connection details(sockFd) got from connectToPubSubServer
// so the packets can be sent and received on this connection

int connectToPubSubServer(COMM_METHOD method, char *hostName, int port)
{
    return SUCCESS;
}

int disconnectFromPubSubServer()
{
    return SUCCESS;
}

int sendDataToQueue(unsigned char *data)
{
    return SUCCESS;
}

unsigned char *fetchDataFromQueue()
{
    return NULL;
}

int sendDataToQueueWithTopic(unsigned char *data, char *topic)
{
    return SUCCESS;
}

unsigned char *fetchDataFromQueueForTopic(char *topic)
{
    return NULL;
}

int subscribeToQueue(void (*processQueueData)(unsigned char *data))
{
    return SUCCESS;
}

int subscribeToQueueForTopic(char *topic, void (*processQueueData)(unsigned char *data))
{
    return SUCCESS;
}

