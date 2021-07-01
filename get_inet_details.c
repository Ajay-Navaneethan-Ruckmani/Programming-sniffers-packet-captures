/*code for finding the interface and their ips

compiling and executing:
#gcc lookup.c -lpcap
#./a.out

*/

#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<errno.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){

	//intialisation
	char *devive_name, *net_addr, *net_mask; //net_addr is the ip address
	int rcode; //return code.
	char error[PCAP_ERRBUF_SIZE];

	//structure intialsed for net IP
	bpf_u_int32 net_addr_int, net_mask_int; //32 bit unsigned integer used for saving IP addresses.0-255
	struct in_addr addr; //for saving the address which we'll be getting in binaty

	//asks pcap to give a valid etherned based device to sniff on it 
	device_name= pcal_lookupdev(error);
	if(device_name == NULL){ //if no interface is found
		printf("%s\n",error );
		return -1
	}else{ //printing the device name since there is an interface
		printf("Devie name : %s\n",device_name);
	}




	//with the device in place,aquire the ip and subnet mask.
	rcode = pcap_lookupnet(device_name, &net_addr_int,&net_mask_int,error); //get devicename,its addr and mask and error

	if (rcode==-1){ //if return code is eroor
		printf("%s\n", error);
		return -1
	}
	//convert the 32 bit int of IP  to human readable form using the struct that we declared earlier
	addr.s_addr = net_addr_int;
	net_addr = inet_ntoa(addr); //convert the numerical to address..addr is the struct

	if(net_addr==NULL){ //for checking if our IP is coverted
		printf("Error converting IP\n");
		return -1;
	}else{ //since its not NULL we have a converted IP and we print it
		printf("NET %s\n",net_addr );
	}


	//convert the 32 bit int of IP net mask to human readable form using the struct that we declared earlier
	addr.s_addr = net_mask_int;
	net_addr = inet_ntoa(addr);

	if(net_mask == NULL){ //to check if ip is null which means no conversion taken place
		printf("Error converting IP\n");
	}else{
		printf("NET %s\n",net_mask);
	}

}
