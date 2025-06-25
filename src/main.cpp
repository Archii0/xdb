#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/personality.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "debugger.h"
#include "linenoise.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Program name not specified\n";
    return -1;
  }

  auto prog = argv[1];

  auto pid = fork();

  if (pid == 0) {
    // child process
    personality(ADDR_NO_RANDOMIZE); // disable address space randomisation

    ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
    execl(prog, prog, nullptr);
  } else if (pid >= 1) {
    // parent process
    std::cout << "Started debugging process " << pid << '\n';
    debugger dbg(prog, pid);
    dbg.run();
  }
}