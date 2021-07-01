/*
Packet sniffer basic program

compiling and executing:
#gcc lookup.c -lpcap
#./a.out

*/
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>  //to invoke the libpcap librabry and use its functions

int main(int argc,char *argv[]){

	char error[PCAP_ERRBUF_SIZE]; //error buffer predefined in the buffer of pcap
 	pcap_if_t *interfaces, *temp; //structure 
 	int i=0;
 
 	//function that finds all devices in a system
 	if(pcap_findalldevs(&interfaces,errors == -1){
 		printf("Cannot acquire devices \n");
 		return -1;
 	}

 	printf("available interfaces are:");

	//we intialise in temp and go to next next interface.
 	for(temp=interfaces;temp; temp=temp->next){
 		printf("#d: %s\n",++i,temp->name);
 	}
 	return 0;



