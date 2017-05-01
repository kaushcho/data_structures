#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
void hourMinuteExtractor(std::string, int &degHr, int &degMt);
int  countAngle(int degHr, int degMt);
int main()
{
    int degreesHourHand = 0;
    int degreesMinuteHand = 0;
    int angleDifference = 0;
    std::string t1;
    
    std::cout << "Enter time:  "<<std::endl;
    std::cin >> t1;
    
    hourMinuteExtractor(t1, degreesHourHand,  degreesMinuteHand);
    std::cout << "The minute hand shows: " << degreesMinuteHand <<std::endl;
    std::cout << "The hour hand shows: " << degreesHourHand <<std::endl;
    std::cout << "The angle between the hour and the minute hand is: "<<countAngle(degreesHourHand,degreesMinuteHand)<<std::endl;
    return 0;
}
void hourMinuteExtractor(std::string t, int & degHr, int & degMt )
{
    size_t npos = t.find(':');
    std::string str2 = t.substr(0,npos);
    std::string str3 = t.substr(npos+1);
    degHr = atoi(str2.c_str());
    degMt = atoi(str3.c_str());
}
int countAngle(int degHr, int degMt)
{
    int mntCoveredByHr  = degHr * 60 + degMt;
    const float anglePerMntByHr = 360.0/(12*60); // calculate degrees covered per minute by hour hand
    const int   anglePerMntByMt = (360/60); // calculate degrees covered per minute by minute hand
    int angleDifference = abs(anglePerMntByHr * mntCoveredByHr - anglePerMntByMt * degMt);
    return angleDifference;
}
