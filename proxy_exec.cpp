#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <windows.h>

const std::string PROXY_EXEC_CMD = "PROXY_EXEC_CMD";

std::string get_env(std::string var)
{
	std::string ret = "";
	char* v = getenv(var.c_str());
	return v ? v : "";
}

int main(int argc, char *argv[])
{
	std::string cmdToRun = get_env(PROXY_EXEC_CMD);
	const std::string myName = argv[0];
	const std::string fallbackSuffix = ".real.exe";
	
	if (cmdToRun.length() == 0)
	{
		std::cout << myName << " warning: "
		<< PROXY_EXEC_CMD << " environment variable not set, trying to guess."
		<< std::endl;
		cmdToRun = myName + fallbackSuffix;
	}

	std::stringstream stream;    
	stream << cmdToRun;

	LPTSTR cmd  = GetCommandLine();

    if(int l = strlen(argv[0]); cmd == strstr(cmd, argv[0]))
    {
        cmd = cmd + l;
        while(*cmd && isspace(*cmd))
            ++cmd;
    }
	
	stream << " " << cmd;
	
	std::cout << "proxy_exec.exe actually calling: " << stream.str() << std::endl;
	return system(stream.str().c_str());
}
