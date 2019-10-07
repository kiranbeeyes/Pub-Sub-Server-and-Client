/* 
 * File: pubSubServer.c
 * Purpose: Starting point for the PubSub Server
 *          Invokes the bootstrap service to initialize all services needed.
 * Compilation: gcc queueService.c bootstrapService.c pubSubServer.c tcpCommunicationService.c -o pubSubServer
 * Execution: ./pubSubServer
 */

#include <stdio.h>
#include "common.h"
#include "bootstrapService.h"

/* Everything starts here */
int main() 
{
    printf("Starting up the PubSub Server\n");
    boostrapServicesOnServer();   //TODO - run this in a new thread and wait for it to finish OR invoke pthread_exit so child process can continue
                                  // Invoke teardownServicesOnServer() before exit
    return SUCCESS;
}
