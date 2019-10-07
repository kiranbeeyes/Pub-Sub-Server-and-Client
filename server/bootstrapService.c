/* 
 * File: bootstrapService.c
 * Purpose: This file contains the bootstrap and teardown implementation.
 */

#include "bootstrapService.h"
#include "queueService.h"
#include "tcpCommunicationService.h"

void boostrapServicesOnServer()
{
    // TODO - run these as new threads and wait for them to finish
    startQueueService();
    startTcpCommunicationService();
}

void teardownServicesOnServer()
{
    stopQueueService();
    stopTcpCommunicationService();
}
