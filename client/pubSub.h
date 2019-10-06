// This file is to be included by the PubSub Client,
// which can be either the Publisher or the Subscriber.
// It provides the the methods available to the PubSub Client(s).
// It will interact with the PubSub Server to get/put to the Queue.

#include <stdio.h>
#include <stddef.h>

#define SUCCESS 0
#define FAILURE 1

/* Enumeration of methods to communicate with the PubSub Server. */
typedef enum communicationMethod
{
    TCP, 
    HTTP
}COMM_METHOD;

/* Method to connect to the PubSub Server.
 * Need to be invoked by the PubSub Client before invoking any other method.
 * Inputs:
 *     The communicationMethod can be TCP or HTTP.
 *     The Hostname and Port where the PubSub Server is listening.
 * Method returns 0 if succesful, 1 in failure.
 */
int connectToPubSubServer(COMM_METHOD method, char *hostName, int port);

/* Method to disconnect from the PubSub Server.
 * PubSub Client can invoke this when he longer needs to use the PubSub Server.
 * Method returns 0 if succesful, 1 in failure.
 */
int disconnectFromPubSubServer();

/* Method to send Data to the PubSub Server, to be put on the Queue
 * Input is the data in the form of byte array. XMl or JSON work well.
 * The Publisher(s) and Subscriber(s) for this data should be aware
 * of the data format and content.
 * Method returns 0 if succesful, 1 in failure.
 */
int sendDataToQueue(unsigned char *data);

/* Method to fetch Data from the PubSub Server.
 * No inputs needed
 * Output will be the data in the form of byte array.
 * The Publisher(s) and Subscriber(s) for this data should be aware
 * of the data format and content.
 * Method returns NULL if not data is found.
 */ 
unsigned char *fetchDataFromQueue();

/* Method to send Data for a specific topic to the PubSub Server.
 * Similar to the sendDataToQueue() method but includes the topic of interest.
 */
int sendDataToQueueWithTopic(unsigned char *data, char *topic);

/* Method to fetch Data for a specific topic from the PubSub Server.
 * Similar to the fetchDataFromQueue() method but includes the topic of interest.
 */ 
unsigned char *fetchDataFromQueueForTopic(char *topic);

/* Method to Subscribe for notification
 * Input is the callback function to be invoked for notification, which will 
 * receive the byte array containing the data.
 * Method returns 0 if subscription is succesful, 1 in unsuccessful.
 */
int subscribeToQueue(void (*processQueueData)(unsigned char *data));

/* Method to Subscribe for notification for specific topic.
 * Similar to the subscribeToQueue() method but includes the topic of interest.
 */
int subscribeToQueueForTopic(char *topic, void (*processQueueData)(unsigned char *data));
