/*
 * File: tcpCommunicationService.c
 * Purpose: This file contains the TCP Communication and Queue invocation implementation.
 */                                                                                                   

#include "tcpCommunicationService.h"

void startTcpCommunicationService()
{
    // Open TCP Port and start listening for incoming connections from PubSub Clients.
    // After connect(), if packets are seen i.e. recv(), invoke handlePackets()
}

void stopTcpCommunicationService()
{
   // Close the TCP Port to stop accepting connections
}

void handlePackets()
{
    // If packet is from publisher, invoke insertIntoQueue().
    // If packet is from subscriber, invoke retrieveFromQueue and send it back to subscriber.
    // NOTE: The PubSub Client needs to put in a field to indicate Publisher or Subscriber is
    // sending the packet.
}
