/* 
 * File: tcpCommunicationService.h
 * Purpose: This file contains the definition for the TCP Service which will listen
 * for packets on a specified IP and Port.
 * The data will be pushed to the Global Queue if packet is from a Publisher
 * The data will be fetched from Global Queue and sent back if packet is from Subscriber
 */

void startTcpCommunicationService();
void stopTcpCommunicationService();
void handlePackets();
