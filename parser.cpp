#include<string>
#include<fstream>
#include<iostream>
#include"parser.h"
#include<cstring>
#include<unistd.h>

Parser::Parser():input_file("/proc/bus/input/devices", std::ifstream::in){
set_Handler();
}
/*
std::string Parser::kbd_Handler() {
char ch[256];
char ch1[256];

while(input_file.peek() != EOF){
do{
input_file.getline(ch, 256);
}while((ch[0] != 'H')&&(input_file.peek() != EOF));
if(input_file.peek() == EOF)
	return "";

//int pos = input_file.tellg();
do{
input_file.getline(ch1,256);
}while(! std::strstr(ch1, "120013") && (input_file.peek( ) != '\n'));

if(input_file.peek() == '\n')
continue;
break;
}
	auto strptr = std::strstr(ch, "event");
	if (strptr != nullptr){
	std::strcpy(ch, strptr);
	for(int i=0; i <std::strlen(ch); i++){
		if (ch[i] == ' '){
			ch[i] = '\0';
			break;
			}
		}
	

	return std::string(ch);
	}
return "";
}
*/


std::string Parser::kbd_Handler(){
char ch_Handler[200];
char ch_Bev[200];

while(input_file.peek() != EOF){
do{
input_file.getline(ch_Handler, 200);
}while(ch_Handler[0] != 'H');
do{
input_file.getline(ch_Bev, 200);
}while(! std::strstr(ch_Bev, "120013") &&  (input_file.peek() != '\n'));
if(input_file.peek() == '\n')
continue;

auto strptr =  std::strstr(ch_Handler, "event");
if (strptr != nullptr){
std::strcpy(ch_Handler,strptr);
for(auto i = 0; i<std::strlen(ch_Handler); i++){
if (ch_Handler[i] == ' '){
ch_Handler[i] = '\0';
return ch_Handler;
}
}
}
}
return "";

}



void Parser::set_Handler(){
	handler = kbd_Handler();
}

std::string Parser::get_handler() const{
return handler;
}

void Parser::update(){
	input_file.clear();
	input_file.seekg(0, input_file.beg);
	set_Handler();
	
}

Parser::~Parser(){
input_file.close();
}

