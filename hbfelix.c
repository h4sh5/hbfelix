#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

const char* reset="\033[0m"; //Text Reset

//High Intensity
const char* IBlack="\033[0;90m";  
const char* IRed="\033[0;91m";    
const char* IGreen="\033[0;92m";       
const char* IYellow="\033[0;93m";      
const char* IBlue="\033[0;94m";      
const char* IPurple="\033[0;95m";      
const char* ICyan="\033[0;96m";      
const char* IWhite="\033[0;97m";       

//normal

const char* Black="\033[0;30m";      
const char* Red="\033[0;31m";       
const char* Green="\033[0;32m";        
const char* Yellow="\033[0;33m";       
const char* Blue="\033[0;34m";      
const char* Purple="\033[0;35m";       
const char* Cyan="\033[0;36m";        
const char* White="\033[0;37m";      


void print_coloured(char* string, char* colour) {
    printf("%s%s%s", colour, string, reset);
}

int main(int argc, char* argv[]) {

    const char* colours[] = {IBlack, IRed, IGreen, IYellow, IPurple, IBlue, 
        ICyan, IWhite, Black, Red, Green, Yellow, Blue, Purple, Cyan, White};
    struct timespec ts;
    
    while (1) {
        //compat with macox
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
        clock_serv_t cclock;
        mach_timespec_t mts;
        host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
        clock_get_time(cclock, &mts);
        mach_port_deallocate(mach_task_self(), cclock);
        ts.tv_nsec = mts.tv_nsec;

#else
        clock_gettime(NULL, &ts);
#endif
        srand(ts.tv_nsec);
        // fprintf(stderr, "%i\n", tv.tv_nsec);
        int choices = sizeof(colours) / sizeof(char*);
        const char* c1 = colours[rand() % choices];
        const char* c2 = colours[rand() % choices];
        const char* c3 = colours[rand() % choices];
        
        printf("%sHappy%s %sbirthday%s %sFelix!%s\n", c1, reset, c2, reset, c3, 
                reset);
    }
    
    


}