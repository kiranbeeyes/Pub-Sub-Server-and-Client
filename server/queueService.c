/* 
 * File: queueService.c
 * Purpose: This file contains the Queue implementation.
 */

#include "queueService.h"
#include "common.h"
#include <pthread.h>

QUEUE *globalQ;
pthread_mutex_t queue_update_mutex; // Mutex for synchronisation

QUEUE * initializeQueue()
{
    printf("Queue: Initializing Queue\n");
    QUEUE *q = malloc(sizeof (QUEUE));
    q->firstIndex = 0;
    q->lastIndex = MAX_QUEUE_LENGTH - 1;
    q->currentQueueLen = 0;

    if (pthread_mutex_init(&queue_update_mutex, NULL) != 0) 
    { 
        printf("Queue: Mutex init has failed\n"); // TODO - Handle this failure
    } 
    return q;
}

void destroyQueue(QUEUE *q)
{
    printf("Queue: Destroying Queue\n");
    free(q);
    pthread_mutex_destroy(&queue_update_mutex); 
}

int insertIntoQueue(QUEUE *q, unsigned char *data)
{
    pthread_mutex_lock(&queue_update_mutex);
    if (isQueueFull(q))
    {
        printf("Queue: Queue is full, unable to insert data\n");
        pthread_mutex_unlock(&queue_update_mutex);
	return FAILURE;
    }
    q->lastIndex = (q->lastIndex + 1) % MAX_QUEUE_LENGTH;
    q->currentQueueLen += 1;
    q->queueData[q->lastIndex] = data;
    printf("Queue: Inserted data successfully into queue. Queue size is %d\n", q->currentQueueLen);
    pthread_mutex_unlock(&queue_update_mutex);

    return SUCCESS;
}

unsigned char * retrieveFromQueue(QUEUE *q)
{
    pthread_mutex_lock(&queue_update_mutex);
    if (isQueueEmpty(q))
    {
        printf("Queue: Queue is empty, unable to retrieve data\n");
        pthread_mutex_unlock(&queue_update_mutex);
	return NULL;
    }
    
    unsigned char * data = q->queueData[q->firstIndex];
    q->firstIndex = (q->firstIndex + 1) % MAX_QUEUE_LENGTH;
    q->currentQueueLen -= 1;
    printf("Queue: Retrieved data successfully from queue. Queue size is %d\n", q->currentQueueLen);
    pthread_mutex_unlock(&queue_update_mutex);

    return data;
}

int getCurrentQueueLength(QUEUE *q)
{
    return q->currentQueueLen;
}

int isQueueFull(QUEUE *q)
{
    return (getCurrentQueueLength(q) == MAX_QUEUE_LENGTH);
}

int isQueueEmpty(QUEUE *q)
{
    return (getCurrentQueueLength(q) == 0);
}
