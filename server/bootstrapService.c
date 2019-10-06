/* 
 * File: bootstrapService.c
 * Purpose: This file contains the bootstrap and teardown implementation.
 */

#include "bootstrapService.h"
#include "queueService.h"
#include "communicationService.h"

void boostrapServicesOnServer()
{
    globalQ = initializeQueue();
    initializeCommunicationService(); // TODO - run this in a new thread and wait for it to finish
}

void teardownServicesOnServer()
{
    destroyQueue(globalQ);
    stopCommunicationService();
}
