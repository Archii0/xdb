#include "debugger.h"

#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "linenoise.h"
#include "utils.h"

void debugger::run() {
  int wait_status;
  auto options = 0;
  waitpid(m_pid, &wait_status, options);

  char* line = nullptr;
  while ((line = linenoise("xdb> ")) != nullptr) {
    handle_command(line);
    linenoiseHistoryAdd(line);
    linenoiseFree(line);
  }
}

void debugger::handle_command(const std::string& line) {
  auto args = split(line, ' ');
  auto command = args[0];

  if (is_prefix(command, "cont")) {
    continue_execution();
  } else if (is_prefix(command, "break")) {
    std::string addr{args[1], 2};
    set_breakpoint_at_address(std::stol(addr, 0, 16));
  } else {
    std::cerr << "Unknown command\n";
  }
}

void debugger::continue_execution() {
  ptrace(PTRACE_CONT, m_pid, nullptr, nullptr);

  int wait_status;
  auto options = 0;
  waitpid(m_pid, &wait_status, options);
}

void debugger::set_breakpoint_at_address(std::intptr_t addr) {
  std::cout << "Set breakpoint at address 0x" << std::hex << addr << "\n";
  breakpoint bp{m_pid, addr};
  bp.enable();
  m_breakpoints[addr] = bp;
}
