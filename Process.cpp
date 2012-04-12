#include "Process.hpp"
#include <unistd.h>
#include <sys/wait.h>

Process::Process( const std::vector<char*>& process, bool verbose ) {
	
	this->verbose = verbose;
	
	int size = process.size();
	char* argv[size];
	for( int i = 0; i < size; ++i )
		argv[i] = process[i];
	
	m_pid = fork();
	switch(m_pid) {
		case -1: // Can't fork
			std::cerr << "Cannot fork." << std::endl;
			break;
		case 0: // Child
			execvp( argv[0], argv );
			std::cerr << "Did not execute." << std::endl;
			break;
		default: // Parent
			break;
	}	
}

Process::~Process() {

	pid_t pid = 0;
	while( pid != m_pid )
		pid = waitpid( pid, &m_status, 0 );
}

