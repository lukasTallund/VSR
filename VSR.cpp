#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main( )
{
    //input year, month and day for VSR!
    int year=2013, month=01 ,day=31;
    
    //our objects, "VSR" wich is the time VSR happens and the current time, "now"
    time_t VSR;
    time_t now = time(0);

    
    //since I'm too lazy to learn, i bruteforce the tm structure, if u know
    //how to solve this in a more civilized matter, plz teach me :)
    struct tm * timeinfo;
    time ( &VSR );
    timeinfo = localtime ( &VSR );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour= 22;
    timeinfo->tm_min=0;
    timeinfo->tm_sec=0;
    timeinfo->tm_isdst=0;
    VSR = mktime ( timeinfo );

    //the needed variables for the countdown
    int left, hour, min, sec, days;
    
    //the printout-loop, goes on like justin beiber! :D
  while (1==1)
   {
    now=time(0); //update the current time
    left=difftime(VSR,now); //calculate diffrence in seconds
    
    //convert seconds into acctual days,hours etc
    days=left/(86400);
    left=left%(86400);
    hour=left/3600;
    left=left%3600;
    min=left/60;
    left=left%60;
    sec=left;

    
    //we print our results

    cout << "Nu är det bara " << setfill('0') << setw(3) << days <<" dagar " << setfill('0') << setw(2) <<  hour <<" timmar "<< setfill('0') << setw(2) << min <<" minuter "<< setfill('0') << setw(2) << sec <<" sekunder kvar till VSR!" ;
    cout.flush();
    cout << "\r";
    
    //since we don't calculate anything less than seconds we let beiber sleep for a sec :)
    sleep(1);
};
}
