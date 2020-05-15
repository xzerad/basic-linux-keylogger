#include<string>
#include<fstream>

class Parser{

	std::string handler;
	std::ifstream input_file;

	public:
	Parser();	
	std::string kbd_Handler();
	void set_Handler();
	std::string get_handler() const;
	void update();
	~Parser();
};
