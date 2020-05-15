#include<linux/input.h>
#include<string>
#include<fstream>


class Keyboard{
	std::ifstream kbd_handler;
	input_event ev;
public: 
	Keyboard(std::string handler);
	std::string code_key_map();
	input_event get_ev();
	void set_ev();
	std::string get_key_state();
	~Keyboard();

};
