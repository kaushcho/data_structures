#include<iostream>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;
int main(){
	char buffer[188];
    int read_byte=0;
    int fd = open("int.ts",O_RDONLY);
    do {
       	   int this_read = read(fd, buffer + read_byte, 188 - read_byte);
            if (this_read < 0) {
                cout<< "Error reading file"<<endl;
                return -1; 
            }   
            else if (this_read == 0) {  // end of file -- clean up the pkt, and return <-- we are done
                close(fd);   // close the file
                return 0;    // all pkts are finished
            }   
            read_byte += this_read;
        }   
        while (read_byte < 188);  // after this point, we have a raw ts pkt
        // check whether this is a tdt table!
        unsigned short pid;
        memcpy(&pid, buffer + 1, 2); 
        cout<< "PID after memcpy is: "<<pid<<endl;
        pid = ntohs(pid);
        cout<< "PID after ntohs is: "<<pid<<endl;
        pid = pid & 0x1fff;
        cout<< "PID after masking is: "<<pid<<endl;
       return 0;
}
