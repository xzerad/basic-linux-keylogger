#include"keyboard.h"
#include<iostream>




Keyboard::Keyboard(std::string handler): kbd_handler("/dev/input/"+handler){
if(kbd_handler.is_open())
kbd_handler.read((char*)&ev, sizeof(ev));
else
	std::cout<<"erreur"<<std::endl;

}

void Keyboard::set_ev(){
kbd_handler.read((char*)&ev, sizeof(ev));
}

std::string Keyboard::get_key_state(){
switch (ev.value){
	case 0: return "RELEASED";
	case 1: return "PRESSED";
	case 2: return "REPEATED";
	default: return "UNKNOWN";
}


}


std::string Keyboard::code_key_map(){
switch(ev.code){
		case(0):  return "";
		case(1):  return "[ESC]";
		case(2):  return "[key_1]"; 
		case(3):  return "[key_2]";
		case(4):  return "[key_3]";
		case(5):  return "[key_4]";
		case(6):  return "[key_5]";
		case(7):  return "[key_6]";
		case(8):  return "[key_7]";
		case(9):  return "[key_8]";
		case(10): return "[key_9]";
		case(11): return "[key_0]";
		case(12): return "[key_MINUS]";
		case(13): return "[key_EQUAL]";
		case(14): return "[BACKSPACE]";
		case(15): return "[TAB]";
		case(16): return "a";
		case(17): return "z";
		case(18): return "e";
		case(19): return "r";
		case(20): return "t";
		case(21): return "y";
		case(22): return "u";
		case(23): return "i";
		case(24): return "o";
		case(25): return "p";
		case(26): return "[KEY_^]";
		case(27): return "[KEY_$]";
		case(28): return "[ENTER]";
		case(29): return "[LEFTCTRL]";
		case(30): return "q";
		case(31): return "s";
		case(32): return "d";
		case(33): return "f";
		case(34): return "g";
		case(35): return "h";
		case(36): return "j";
		case(37): return "k";
		case(38): return "l";
		case(39): return "m";
		case(40): return "%";
		case(41): return "²";
		case(42): if(get_key_state() == "PRESSED")
			  return "[LEFTSHIFT_PRESSED]";
			  else if(get_key_state() == "RELEASED")
			  return "[LEFTSHIFT_RELEASED]";
		case(43): return "*";
		case(44): return "w";
		case(45): return "x";
		case(46): return "c";
		case(47): return "v";
		case(48): return "b";
		case(49): return "n";
		case(50): return ",";
		case(51): return ";";
		case(52): return ":";
		case(53): return "!";
		case(54): if(get_key_state() == "PRESSED")
			  return "[RIGHTSHIFT_PRESSED]";
			  else if(get_key_state() == "RELEASED")
		      	  return "[RIGHTSHIFT_RELEASED]";
		case(55): return "*";
		case(56): return "[LEFTALT]";
		case(57): return "[SPACE]";
		case(58): return "[CAPSLOCK]";
		case(59): return "[KEY_F1]";
		case(60): return "[KEY_F2]";
		case(61): return "[KEY_F3]";
		case(62): return "[KEY_F4]";
		case(63): return "[KEY_F5]";
		case(64): return "[KEY_F6]";
		case(65): return "[KEY_F7]";
		case(66): return "[KEY_F8]";	
		case(67): return "[KEY_F9]";
		case(68): return "[KEY_F10]";
		case(69): return "[NUMLOCK]";
		case(70): return "[ARRET_DEFIL]";
		case(71): return "7";
		case(72): return "8";
		case(73): return "9";
		case(74): return "-";
		case(75): return "4";
		case(76): return "5";
		case(77): return "6";
		case(78): return "+";
		case(79): return "3";
		case(80): return "2";
		case(81): return "1";
		case(82): return "0";
		case(83): return ".";
		case(87): return "[KEY_F11]";
		case(88): return "[KEY_F12]";
		case(96): return "[ENTER]";
		case(97): return "[RIGHTCTRL]";
		case(98): return "/";
		case(99): return "[Impr-ecran-SystRq]";
		case(100): return "[RIGHTALT]";
		case(102):return "[HOME]";
		case(103):return "[UP_KEY]";
		case(104):return "[PAGEUP]";
		case(105):return "[LEFT_KEY]";
		case(106):return "[RIGHT_KEY]";
		case(107):return "[Fin]";
		case(108):return "[DOWN_KEY]";
		case(109):return "[PAGEDOWN]";
		case(110):return "[INSERT]";
		case(119):return "[PAUSE_ATTN]";
		case(111):return "[DELETE]";
		case(125):return "[DEMARRE]";
		case(126):return "[LEFT_DEMARRE]";
		case(127):return "[COMPOSE]";
		default: return "kbd-code["+std::to_string(ev.code)+"]";

	}}
input_event Keyboard::get_ev(){
return ev;
}

Keyboard::~Keyboard(){
kbd_handler.close();
}



