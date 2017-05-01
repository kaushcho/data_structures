#include <iostream>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
using namespace std;
int main() { 
	time_t rawtime;
	struct tm *timeinfo;
	char tdt[10];
	rawtime = time (NULL);
	timeinfo = localtime (&rawtime);
	unsigned short l;
    struct tm* now = gmtime(&rawtime);
    if (now != NULL) {
    // convert date into modified julian 
    if ((now->tm_mon + 1 == 1) ||  (now->tm_mon + 1  == 2)) l = 1;
    else l = 0;
    unsigned short MJD = 14956 + now->tm_mday + (unsigned short)((now->tm_year - l) * 365.25) + (unsigned short)((now->tm_mon + 1 + 1 + l * 12) * 30.6001 );
    cout<<"Mday:"<<now->tm_mday<<" Year: "<<now->tm_year<<" Month: "<<now->tm_mon+1<<endl;
	MJD = htons(MJD);
    memcpy(tdt, &MJD, 2);
		             // convert time 
		             unsigned char hour = (now->tm_hour / 10) << 4 | (now->tm_hour % 10);
		             unsigned char minute = (now->tm_min / 10) << 4 | (now->tm_min % 10);
		             unsigned char second = (now->tm_sec / 10) << 4 | (now->tm_sec %10);
		             tdt[2] = hour;
		             tdt[3] = minute;
	cout<<"hour: "<<hour<<"and tm_hour: "<<now->tm_hour<<"min: "<<now->tm_min<<"sec: "<<now->tm_sec<<endl;
		             tdt[4] = second;
					 cout<<sizeof(hour)<<" "<<sizeof(minute)<<" "<<sizeof(second)<<endl;
	}
	cout<<"MJD time is:"<<tdt<<endl;
	return 0;
}


