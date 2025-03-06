#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <windows.h>

const char* PROXY_EXEC_CMD = "PROXY_EXEC_CMD";

int main(int argc, char *argv[])
{
	const char* cmdToRun = getenv(PROXY_EXEC_CMD);
	
	if (cmdToRun == nullptr)
	{
		std::cout << argv[0] << " error: "
		<< "PROXY_EXEC_CMD environment not set, don't know what to run."
		<< std::endl;
		return 1;
	}

	std::stringstream stream;    
	stream << cmdToRun;

	LPTSTR cmd  = GetCommandLine();

    int l = strlen(argv[0]);

    if(cmd == strstr(cmd, argv[0]))
    {
        cmd = cmd + l;
        while(*cmd && isspace(*cmd))
            ++cmd;
    }
	
	stream << " " << cmd;
	
	std::cout << "proxy_exec.exe actually calling: " << stream.str() << std::endl;
	return system(stream.str().c_str());
}
