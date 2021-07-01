#include<stdio.h>
#include<pcap.h>
#include<stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <netinet/if_ether.h> 

void print_available_interfaces(){

	char error[PCAP_ERRBUF_SIZE];
	pcap_if_t *interfaces, *temp;
	int i = 0;
	
	if(pcap_findalldevs(&interfaces, error) == -1){
		printf("Cannot acquire the devices\n");
		return -1;
	}
	
	printf("The available interfaces are: \n");
	for(temp = interfaces; temp; temp=temp->next){
		printf("#%d: %s\n", ++i, temp->name);
	}
	return 0;
}


void print_version(){
	printf("ARP spoof detector v0.1\n");
	exit(1);
}


void print_help(char *bin){
	printf("ARP spoof detector v0.1\n");
	printf("available arguments:\n");
	printf("----------------\n");
	printf("-h or --help:\t\tPrint this help text.\n");
	printf("-l or --lookup:\t\tPrint the available interfaces\n");
	printf("i or --interface:\t\tProvide the interface to sniff on.\n");
	printf("i or --interface:\t\tProvide the interface to sniff on.\n");
	printf("------\n");
	printf("Usage: %s -i <interface> [You can look for the available interfaces using l/--lookup]\n",argv[0]);


}

int sniff_arp(char *device_name){

	char *device_name;
	char error[PCAP_ERRBUF_SIZE];
	pcap_t* pack_desc;
	const u_char *packet;
	struct pcap_pkthdr header;
	struct ether_header *eptr; //net/ethernet.h
	int i;
	u_char *hard_ptr;

}


int int main(int argc, char const *argv[]){
	
	for (int i=0; i<argc; i++){
		printf("argv%s", argv[i]);

	}

	return 0;

}